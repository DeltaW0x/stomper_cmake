#pragma once
#include <cmath>
#include "engine/common.hpp"

#ifndef VECTOR3_INLINE_IMPL
#define VECTOR3_INLINE_IMPL
#endif


namespace stmp::math
{
    struct Vector3f
    {
        constexpr Vector3f();
        constexpr Vector3f(float v);
        constexpr Vector3f(float x, float y, float z);

        constexpr FORCE_INLINE bool operator==(const Vector3f& v) const;

        constexpr FORCE_INLINE Vector3f operator-() const;
        constexpr FORCE_INLINE Vector3f operator+(const Vector3f &rhs) const;
        constexpr FORCE_INLINE Vector3f operator-(const Vector3f &rhs) const;
        constexpr FORCE_INLINE Vector3f operator*(float rhs) const;
        constexpr FORCE_INLINE Vector3f operator/(float rhs) const;

        constexpr FORCE_INLINE Vector3f& operator+=(const Vector3f &rhs);
        constexpr FORCE_INLINE Vector3f& operator-=(const Vector3f &rhs);
        constexpr FORCE_INLINE Vector3f& operator*=(float rhs);
        constexpr FORCE_INLINE Vector3f& operator/=(float rhs);

        FORCE_INLINE auto length() const;
        constexpr FORCE_INLINE float sq_length() const;

        FORCE_INLINE Vector3f& normalize();
        FORCE_INLINE Vector3f normalized() const;

        constexpr static FORCE_INLINE float dot(const Vector3f &lhs, const Vector3f &rhs);
        constexpr static FORCE_INLINE Vector3f cross(const Vector3f &lhs, const Vector3f &rhs);

        union
        {
            struct
            {
                float x, y, z;
            };
            struct
            {
                float u, v, w;
            };
            struct
            {
                float r, g, b;
            };
            float data[3];
        };

        static const Vector3f Zero, One, Up, Down, Left, Right, Forward, Backward;

    private:
        static constexpr f32 m_epsilon = 0.00001f;
    };

#include "inl/vector3.inl"
} // namespace stpm::math

#undef VECTOR3_INLINE_IMPL