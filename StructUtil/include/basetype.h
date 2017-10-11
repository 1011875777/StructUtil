typedef char CHAR;
typedef unsigned char UCHAR;
typedef short SHORT;
typedef unsigned short USHORT;
typedef int INT;
typedef unsigned int UINT;
typedef long LONG;
typedef unsigned long ULONG;
typedef unsigned char BOOL; 

typedef void VOID;

#define NULL  0UL
#define TRUE   (BOOL)1
#define FALSE  (BOOL)0 

#define SUCCESS  0UL
#define FAILED   1UL

#define offsetof(TYPE, MEMBER) ((INT) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({          \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})



