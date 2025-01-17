# elf2vkp: https://github.com/siemens-mobile-hacks/elf2vkp

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
add_compile_options(-mcpu=arm926ej-s -mthumb-interwork -msoft-float -mlittle-endian -fshort-wchar)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_link_options(-Wl,-z,max-page-size=1)

set(CMAKE_C_FLAGS "-nostdlib -nostdinc")
set(CMAKE_CXX_FLAGS "-nostdlib -nostdinc -fno-exceptions")
set(CMAKE_ASM_FLAGS "-nostdlib -nostdinc")
set(FULLFLASHES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/firmware)

set(VKP_COMMAND elf2vkp)
if(WIN32)
	set(ELF2VKP "${CMAKE_CURRENT_SOURCE_DIR}/elf2vkp")
	set(ENV{PATH} "$ENV{PATH};${ELF2VKP}")
	set(VKP_COMMAND ${ELF2VKP}/elf2vkp)
endif()

function(define_patch phone svn platform chipset base_address)
	set(target ${phone}_${svn}_${PROJECT_NAME})
	set(firmware ${phone}_${svn})

	set_property(TARGET ${target} PROPERTY POSITION_INDEPENDENT_CODE OFF)
	set_property(TARGET ${target} PROPERTY SUFFIX ".elf")
	target_compile_definitions(${target} PUBLIC ${target} ${firmware})
	target_link_options(${target} PUBLIC -Wl,-T,${CMAKE_CURRENT_SOURCE_DIR}/linker/${firmware}.ld)

	add_custom_command(TARGET ${target} PRE_BUILD
		COMMENT "Removing old VKP file"
		COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/${target}_${PROJECT_NAME}.vkp
	)

	add_custom_command(
		TARGET ${target} POST_BUILD
		COMMENT "Generating VKP file"
		COMMAND ${VKP_COMMAND}
				--header "\;${firmware}"
				--header-from-file ${CMAKE_CURRENT_SOURCE_DIR}/header.txt
				-b ${base_address}
				-f ${FULLFLASHES_PATH}/${firmware}.bin
				-i ${target}.elf
				-o ${target}.vkp
				--format sony-ericsson
	)

	if (chipset STREQUAL "DB2000" OR 
		chipset STREQUAL "DB2010" OR 
		chipset STREQUAL "DB2020" OR 
		chipset STREQUAL "DB3150v1" OR
		chipset STREQUAL "DB3150v2" OR
		chipset STREQUAL "DB3200" OR 
		chipset STREQUAL "DB3210" OR 
		chipset STREQUAL "DB3350" OR
		chipset STREQUAL "PNX5230")
		message("Compiling for target ${target} (SE ${chipset})")
		target_compile_definitions(${target} PUBLIC ${platform} ${chipset} ${firmware})
	else()
		message(FATAL "Invalid chipset: ${chipset}")
	endif()
endfunction()