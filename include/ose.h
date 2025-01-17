#ifndef OSE_H
#define OSE_H

union SIGNAL;

typedef unsigned char OSPRIORITY;
typedef unsigned char OSBOOLEAN;

typedef unsigned short OSVECTOR;

typedef unsigned long PROCESS;
typedef unsigned long SIGSELECT;
typedef unsigned long OSBUFSIZE;
typedef unsigned long OSUSER;
typedef unsigned long OSERRCODE;
typedef unsigned long OSADDRESS;
typedef unsigned long OSTIME;
typedef unsigned long OSTICK;
typedef unsigned long OSATTREF;
typedef unsigned long OSSEGMENT;

typedef signed long OSFSEMVAL;
typedef signed long OSSEMVAL;

typedef void(OSENTRYPOINT)(void);

typedef OSADDRESS(OSERRH)(OSBOOLEAN, OSERRCODE, OSERRCODE);

typedef enum PROCESS_TYPE
{
	OS_PRI_PROC = 0,
	OS_BG_PROC = 64,
	OS_INT_PROC = 128,
	OS_TI_PROC = 256,
	OS_PHANTOM = 512,
	OS_BLOCK = 1024,
	OS_ZOOMBIE = 2048,
	OS_ILLEGAL = 4096
} PROCESS_TYPE;

#define OS_PROCESS(x) __interwork void x(void)

#endif // OSE_H