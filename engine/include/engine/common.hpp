#pragma once
#include <cstdint>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;

#if defined(_MSC_VER)
#define FORCE_INLINE __forceinline
#elif defined(__GNUC__) || defined(__clang__)
#define FORCE_INLINE inline __attribute__((always_inline))
#else
#define FORCE_INLINE inline
#endif

#define MAKE_HANDLE(name)                                                                                              \
    typedef struct name                                                                                                \
    {                                                                                                                  \
    private:                                                                                                           \
        u64 compound_index = 0;                                                                                        \
                                                                                                                       \
    public:                                                                                                            \
        u32 get_index() const                                                                                          \
        {                                                                                                              \
            return static_cast<u32>(compound_index & 0xFFFFFFFFull);                                                   \
        }                                                                                                              \
        u32 get_generation() const                                                                                     \
        {                                                                                                              \
            return static_cast<u32>(compound_index >> 32);                                                             \
        }                                                                                                              \
    } name;
