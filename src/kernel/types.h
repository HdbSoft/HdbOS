#ifndef GINGER_TYPES_H
#define GINGER_TYPES_H

typedef void   (*void_ptr)   (void);
typedef void*  (**value_ptr) (void*);

typedef int    (*int_ptr)    (int);

typedef float  (*float_ptr)  (float);
typedef double (*double_ptr) (double);

typedef char   (*char_ptr)   (char);
typedef char*  (**str_ptr)   (char*);

typedef void*       var;
typedef const void* val;

typedef char      i8;
typedef short     i16;
typedef int       i32;
typedef long      i64;
typedef long long i128;

typedef unsigned char      Ui8;
typedef unsigned short     Ui16;
typedef unsigned int       Ui32;
typedef unsigned long      Ui64;
typedef unsigned long long Ui128;

typedef signed char      Si8;
typedef signed short     Si16;
typedef signed int       Si32;
typedef signed long      Si64;
typedef signed long long Si128;

typedef char           str[];
typedef char*          String;

#endif
//ginger data types