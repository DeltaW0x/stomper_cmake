#pragma once
#include <cmath>
#include "engine/common.hpp"

#ifndef VECTOR4_INLINE_IMPL
#define VECTOR4_INLINE_IMPL
#endif


namespace stpm::math
{
    template<typename T>
    struct Vector4
    {
        constexpr Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
        constexpr Vector4(T v) : x(x), y(v), z(v), w(v) {}
        constexpr Vector4(T x, T y, T z) : x(x), y(y), z(z), w(0.0f) {}

        constexpr FORCE_INLINE bool operator==(const Vector4& v) const;

        constexpr FORCE_INLINE Vector4 operator-() const;
        constexpr FORCE_INLINE Vector4 operator+(const Vector4 &rhs) const;
        constexpr FORCE_INLINE Vector4 operator-(const Vector4 &rhs) const;
        constexpr FORCE_INLINE Vector4 operator*(T rhs) const;
        constexpr FORCE_INLINE Vector4 operator/(T rhs) const;

        constexpr FORCE_INLINE Vector4& operator+=(const Vector4 &rhs);
        constexpr FORCE_INLINE Vector4& operator-=(const Vector4 &rhs);
        constexpr FORCE_INLINE Vector4& operator*=(T rhs);
        constexpr FORCE_INLINE Vector4& operator/=(T rhs);

        FORCE_INLINE auto length() const;
        constexpr FORCE_INLINE T sq_length() const;

        FORCE_INLINE Vector4& normalize();
        FORCE_INLINE Vector4 normalized() const;

        union
        {
            struct
            {
                T x, y, z, w;
            };
            struct
            {
                T r, g, b, a;
            };
            T data[4];
        };

        static const Vector4 Zero, One, Up, Down, Left, Right, Forward, Backward;

    private:
        static constexpr f32 m_epsilon = 0.00001f;
    };

    typedef Vector4<u32> Vector4u;
    typedef Vector4<i32> Vector4i;
    typedef Vector4<f32> Vector4f;
    typedef Vector4<f64> Vector4d;

#include "inl/vector4.inl"
} // namespace stpm::math

#undef VECTOR4_INLINE_IMPL