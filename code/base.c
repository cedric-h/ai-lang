
#define MACRO_CONCAT(a,b) a##b

#define STR_(a) #a
#define MACRO_STR(a) STR_(a)

#if defined(__clang__)
  #define COMPILER_CLANG
  #define COMPILER_NAME "Clang"
#elif defined(__INTEL_COMPILER)
  #define COMPILER_INTEL
  #define COMPILER_NAME "Intel"
#elif defined(_MSC_VER)
  #define COMPILER_MSVC
  #define COMPILER_NAME "MSVC"
#elif defined(__TINYC__)
  #define COMPILER_TCC
  #define COMPILER_NAME "TCC"
#elif defined(__GNUC__)
  #define COMPILER_GCC
  #define COMPILER_NAME "GCC"
#else
  #error "Error: unknown compiler."
#endif

#if  defined(_WIN32)
  #define OS_WINDOWS
  #define OS_NAME "Windows"
#elif defined(__linux__)
  #define OS_LINUX
  #define OS_NAME "Linux"
#elif defined(__APPLE__)
  #define OS_DARWIN
  #define OS_NAME "Darwin"
#else
  #error "Error: unknown OS."
#endif

#ifdef __cplusplus
  #define CEXTERN extern "C"
#else
  #define CEXTERN extern
#endif

#ifdef COMPILER_MSVC
  #define FINLINE __forceinline
#else
  #define FINLINE inline __attribute__((always_inline))
#endif

#include <stdint.h>
#if UINTPTR_MAX == UINT64_MAX
  #define BITS 64
#elif UINTPTR_MAX == UINT32_MAX
  #define BITS 32
#elif UINTPTR_MAX == UINT16_max
  #define BITS 16
#else
  #error "Unknown pointer size or missing size macros!"
#endif

#if UINTPTR_MAX != SIZE_MAX
  #error "bread.h assumes pointer and size_t sizes are equal."
#endif

int8_t   typedef I8;
uint8_t  typedef U8;
int16_t  typedef I16;
uint16_t typedef U16;
int32_t  typedef I32;
uint32_t typedef U32;
int64_t  typedef I64;
uint64_t typedef U64;
I64      typedef Int;
U64      typedef UInt;

float    typedef F32;
double   typedef F64;
F32      typedef Float;

U8       typedef Bool;
U8       typedef Byte;
U16      typedef Word;
U32      typedef Long;
U32      typedef Rune;

void     typedef Void;
void     typedef Proc;
void     typedef *Ptr;

char     typedef Char;

#define DEFCONST(thing) enum{ thing }

#define true  ((Bool)1)
#define false ((Bool)0)
#define nil   ((Ptr)0)

#define kb    1024
#define mb    1024*kb
#define gb    1024*mb
#define tb    1024*tb

#if defined(OS_WINDOWS)
  #define IntLit(lit)  MACRO_CONCAT(lit, LL)
  #define UIntLit(lit) MACRO_CONCAT(lit, ULL)
#else
  #define IntLit(lit)  MACRO_CONCAT(lit, L)
  #define UIntLit(lit) MACRO_CONCAT(lit, UL)
#endif

#define arrCount(arr)  (sizeof(arr) / sizeof((arr)[0]))
#define until(x)       while(!(x))

const Int  int8Min   = -IntLit(0x80);
const Int  int16Min  = -IntLit(0x8000);
const Int  int32Min  = -IntLit(0x80000000);
const Int  int64Min  = -IntLit(0x8000000000000000);
const Int  intMin    = -IntLit(0x8000000000000000);

const Int  int8Max   = IntLit(0x7F);
const Int  int16Max  = IntLit(0x7FFF);
const Int  int32Max  = IntLit(0x7FFFFFFF);
const Int  int64Max  = IntLit(0x7fffffffffffffff);
const Int  intMax    = IntLit(0x7fffffffffffffff);

const UInt uint8Max  = UIntLit(0xFF);
const UInt uint16Max = UIntLit(0xFFFF);
const UInt uint32Max = UIntLit(0xFFFFFFFF);
const UInt uint64Max = UIntLit(0xffffffffffffffff);
const UInt uintMax   = UIntLit(0xffffffffffffffff);
