#pragma once
#include <cmath>
#include "engine/common.hpp"

#ifndef VECTOR3_INLINE_IMPL
#define VECTOR3_INLINE_IMPL
#endif


namespace stpm::math
{
    template<typename T>
    struct Vector3
    {
        constexpr Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
        constexpr Vector3(T v) : x(x), y(v), z(v) {}
        constexpr Vector3(T x, T y, T z) : x(x), y(y), z(z) {}

        constexpr FORCE_INLINE bool operator==(const Vector3& v) const;

        constexpr FORCE_INLINE Vector3 operator-() const;
        constexpr FORCE_INLINE Vector3 operator+(const Vector3 &rhs) const;
        constexpr FORCE_INLINE Vector3 operator-(const Vector3 &rhs) const;
        constexpr FORCE_INLINE Vector3 operator*(T rhs) const;
        constexpr FORCE_INLINE Vector3 operator/(T rhs) const;

        constexpr FORCE_INLINE Vector3& operator+=(const Vector3 &rhs);
        constexpr FORCE_INLINE Vector3& operator-=(const Vector3 &rhs);
        constexpr FORCE_INLINE Vector3& operator*=(T rhs);
        constexpr FORCE_INLINE Vector3& operator/=(T rhs);

        FORCE_INLINE auto length() const;
        constexpr FORCE_INLINE T sq_length() const;

        FORCE_INLINE Vector3& normalize();
        FORCE_INLINE Vector3 normalized() const;

        constexpr static FORCE_INLINE T dot(const Vector3 &lhs, const Vector3 &rhs);
        constexpr static FORCE_INLINE Vector3 cross(const Vector3 &lhs, const Vector3 &rhs);

        union
        {
            struct
            {
                T x, y, z;
            };
            struct
            {
                T u, v, w;
            };
            struct
            {
                T r, g, b;
            };
            T data[3];
        };

        static const Vector3 Zero, One, Up, Down, Left, Right, Forward, Backward;

    private:
        static constexpr f32 m_epsilon = 0.00001f;
    };

    typedef Vector3<i32> Vector3i;
    typedef Vector3<u32> Vector3u;
    typedef Vector3<f32> Vector3f;
    typedef Vector3<f64> Vector3d;

#include "inl/vector3.inl"
} // namespace stpm::math

#undef VECTOR3_INLINE_IMPL