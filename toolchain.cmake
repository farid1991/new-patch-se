# elf2vkp-go: https://github.com/farid1991/elf2vkp-go

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_LIBRARY_ARCHITECTURE arm-none-eabi)

find_program(ARM_C_COMPILER arm-none-eabi-gcc${CMAKE_EXECUTABLE_SUFFIX} NO_CACHE REQUIRED)
find_program(ARM_CXX_COMPILER arm-none-eabi-g++${CMAKE_EXECUTABLE_SUFFIX} NO_CACHE REQUIRED)

set(CMAKE_C_COMPILER ${ARM_C_COMPILER} CACHE INTERNAL "CMAKE_C_COMPILER")
set(CMAKE_CXX_COMPILER ${ARM_CXX_COMPILER} CACHE INTERNAL "CMAKE_CXX_COMPILER")
add_compile_options(-mcpu=arm926ej-s 
					-mthumb-interwork 
					-msoft-float
					-mlittle-endian 
					-ffreestanding
					-fno-jump-tables
					-fno-tree-switch-conversion
					-fshort-wchar
)

add_link_options(-Wl,-z,max-page-size=1)

set(CMAKE_C_FLAGS "-nostdlib -nostdinc")
set(CMAKE_CXX_FLAGS "-nostdlib -nostdinc -fno-exceptions")
set(CMAKE_ASM_FLAGS "-nostdlib -nostdinc")
set(FULLFLASHES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/firmware)

set(VKP_COMMAND elf2vkp-go CACHE STRING "elf2vkp tool command")
find_program(VKP_COMMAND ${VKP_COMMAND} REQUIRED)

function(define_patch phone svn platform chipset base_address)

	set(target ${phone}_${svn}_${PROJECT_NAME})
	set(firmware ${phone}_${svn})
	set(FW_DIR "${FULLFLASHES_PATH}/${firmware}")

	set_property(TARGET ${target} PROPERTY POSITION_INDEPENDENT_CODE OFF)
	set_property(TARGET ${target} PROPERTY SUFFIX ".elf")

	# -------------------------------------------------------
	# Chipset validation
	# -------------------------------------------------------

	set(VALID_CHIPSETS
		DB2000
		DB2010
		DB2020
		DB3150v1
		DB3150v2
		DB3200
		DB3210
		DB3350
		PNX5230
	)

	list(FIND VALID_CHIPSETS ${chipset} CHIPSET_INDEX)

	if (CHIPSET_INDEX EQUAL -1)
		message(FATAL_ERROR "Invalid chipset: ${chipset}")
	endif()

	if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/linker/${firmware}.ld")
		message(FATAL_ERROR "Missing linker script: ${firmware}.ld")
	endif()

	message("Compiling for target ${target} (SE ${chipset})")
	target_compile_definitions(${target} PUBLIC ${target} ${platform} ${chipset} ${firmware})
	target_link_options(${target} PUBLIC -Wl,-T,${CMAKE_CURRENT_SOURCE_DIR}/linker/${firmware}.ld)

	# -------------------------------------------------------
	# Firmware auto-detection
	# -------------------------------------------------------

	set(FW_ARGS "")
	set(HAS_FW FALSE)

	if(EXISTS "${FW_DIR}")

		file(GLOB CXC_FILES "${FW_DIR}/*.cxc")
		file(GLOB MBN_FILES "${FW_DIR}/*.mbn")
		file(GLOB RAW_FILES "${FW_DIR}/*.raw")
		file(GLOB BIN_FILES "${FW_DIR}/*.bin")

		if(CXC_FILES)
			message("Detected CXC firmware for ${firmware}")
			list(SORT CXC_FILES)
			foreach(fw ${CXC_FILES})
				list(APPEND FW_ARGS -f "${fw}")
			endforeach()
			set(HAS_FW TRUE)

		elseif(MBN_FILES)
			message("Detected MBN firmware for ${firmware}")
			list(APPEND FW_ARGS -f "${MBN_FILES}")
			set(HAS_FW TRUE)

		elseif(RAW_FILES)
			message("Detected RAW firmware for ${firmware}")
			list(APPEND FW_ARGS -f "${RAW_FILES}")
			set(HAS_FW TRUE)

		elseif(BIN_FILES)
			message("Detected BIN firmware for ${firmware}")
			list(APPEND FW_ARGS -f "${BIN_FILES}")
			set(HAS_FW TRUE)
		endif()

	endif()

	if(NOT HAS_FW)
		message("No firmware found for ${firmware}. Generating patch without old bytes.")
	endif()

	# -------------------------------------------------------
	# Remove old VKP
	# -------------------------------------------------------

	add_custom_command(TARGET ${target} PRE_BUILD
		COMMENT "Removing old ${target}.vkp file"
		COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/${target}.vkp
	)

	# -------------------------------------------------------
	# Generate VKP
	# -------------------------------------------------------

	add_custom_command(
		TARGET ${target} POST_BUILD
		COMMENT "Generating VKP file"
		COMMAND "${VKP_COMMAND}"
			--header "${firmware}"
			--header-from-file ${CMAKE_CURRENT_SOURCE_DIR}/header.txt
			-b "${base_address}"
			${FW_ARGS}
			-i "${target}.elf"
			-o "${target}.vkp"
	)

endfunction()
