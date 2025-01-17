#ifndef BASIC_TYPES_H
#define BASIC_TYPES_H

// base types and constants ----------------------------------------------------

typedef int BOOL;
typedef unsigned long LRESULT;
typedef int jmp_buf[11];

typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
typedef unsigned int uint32_t;
typedef signed int int32_t;
typedef signed long long int64_t;
typedef unsigned long long uint64_t;

typedef uint32_t time_t;
typedef uint32_t size_t;
typedef uint32_t color_t;

#ifndef __cplusplus
typedef unsigned char bool;
#endif

#ifndef __cplusplus
typedef unsigned short wchar_t;
#endif

#ifndef __cplusplus
typedef unsigned long LPARAM;
#else
class LPARAM
{
	unsigned long data;

public:
	LPARAM(int a) { data = a; }
	LPARAM(void *a) { data = reinterpret_cast<unsigned long>(a); }
	operator int() { return data; }
	operator void *() { return reinterpret_cast<void *>(data); }
};
#endif

#ifndef _NULL
#define _NULL 0
#endif
#ifndef NULL
#define NULL _NULL
#endif

#define TRUE 1
#define FALSE 0
#define ON 1
#define OFF 0

// if( GetChipID( ) &CHIPID_MASK == CHIPID_DB... )
#define CHIPID_MASK 0xFE00
#define CHIPID_DB2000 0x7000
#define CHIPID_DB2010 0x8000
#define CHIPID_DB2020 0x9800
#define CHIPID_PNX5230 0xD000
#define CHIPID_DB3150 0xC800
#define CHIPID_DB3200 0xD800
#define CHIPID_DB3210 0xE800
#define CHIPID_DB3350 0xF000

#define MAXELEMS(x) (sizeof(x) / sizeof(x[0]))

#ifdef __cplusplus
template <typename BASETYPE, typename CHILDTYPE>
void INHERITANCECHECK()
{
	if (static_cast<BASETYPE *>(0) == static_cast<CHILDTYPE *>(0));
}
#endif

#define ARM32 __attribute__((target("arm")))
#define THUMB16 __attribute__((target("thumb")))

#endif // BASIC_TYPES_H
