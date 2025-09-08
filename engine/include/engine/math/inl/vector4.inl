#pragma once

#ifndef VECTOR4_INLINE_IMPL
#error "Do not include vector4.inl, include engine/math/vector4.hpp instead"
#else

template<typename T>
constexpr Vector4<T> Vector4<T>::Zero = Vector4(0.0f, 0.0f, 0.0f, 0.0f);

template<typename T>
constexpr Vector4<T> Vector4<T>::One = Vector4(1.0f, 1.0, 1.0f, 1.0f);

template<typename T>
constexpr Vector4<T> Vector4<T>::Up = Vector4(0.0f, 1.0f, 0.0f, 0.0f);

template<typename T>
constexpr Vector4<T> Vector4<T>::Down = Vector4(0.0f, std::is_signed_v<T> ? -1.0f : 0.0f, 0.0f, 0.0f);

template<typename T>
constexpr Vector4<T> Vector4<T>::Left = Vector4(std::is_signed_v<T> ? -1.0f : 0.0f, 0.0f, 0.0f, 0.0f);

template<typename T>
constexpr Vector4<T> Vector4<T>::Right = Vector4(1.0f, 0.0f, 0.0f, 0.0f);

template<typename T>
constexpr Vector4<T> Vector4<T>::Forward = Vector4(0.0f, 0.0f, 1.0f, 0.0f);

template<typename T>
constexpr Vector4<T> Vector4<T>::Backward = Vector4(0.0f, 0.0f, std::is_signed_v<T> ? -1.0f : 0.0f, 0.0f);

template<typename T>
constexpr bool Vector4<T>::operator==(const Vector4 &v) const
{
    return x == v.x && y == v.y && z == v.z && w == v.w;
}

template<typename T>
constexpr Vector4<T> Vector4<T>::operator-() const
{
    static_assert(std::is_signed_v<T>, "You can't negate an unsigned vector");
    return Vector4(-x, -y, -z, -w);
}

template<typename T>
constexpr Vector4<T> Vector4<T>::operator+(const Vector4 &rhs) const
{
    return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

template<typename T>
constexpr Vector4<T> Vector4<T>::operator-(const Vector4 &rhs) const
{
    return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

template<typename T>
constexpr Vector4<T> Vector4<T>::operator*(T rhs) const
{
    return Vector4(x * rhs, y * rhs, z * rhs, w * rhs);
}

template<typename T>
constexpr Vector4<T> operator*(T lhs, const Vector4<T> &rhs)
{
    return Vector4(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);
}

template<typename T>
constexpr Vector4<T> Vector4<T>::operator/(T rhs) const
{
    return Vector4(x / rhs, y / rhs, z / rhs, w / rhs);
}

template<typename T>
constexpr Vector4<T> &Vector4<T>::operator+=(const Vector4 &rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;
    return *this;
}

template<typename T>
constexpr Vector4<T> &Vector4<T>::operator-=(const Vector4 &rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;
    return *this;
}

template<typename T>
constexpr Vector4<T> &Vector4<T>::operator*=(T rhs)
{
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    w *= rhs.w;
    return *this;
}

template<typename T>
constexpr Vector4<T> &Vector4<T>::operator/=(T rhs)
{
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    w /= rhs.w;
    return *this;
}

template<typename T>
auto Vector4<T>::length() const
{
    return std::sqrt(x * x + y * y + z * z + w * w);
}

template<typename T>
constexpr T Vector4<T>::sq_length() const
{
    return x * x + y * y + z * z + w * w;
}

template<typename T>
Vector4<T> &Vector4<T>::normalize()
{
    if (auto len = length(); len > m_epsilon)
    {
        auto inv = 1.0f / len;
        return *this *= inv;
    }
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 0.0f;
    return *this;
}

template<typename T>
Vector4<T> Vector4<T>::normalized() const
{
    if (auto len = length(); len > m_epsilon)
    {
        auto inv = 1.0f / len;
        return Vector4(x * inv, y * inv, z * inv, w * inv);
    }
    return Vector4(0.0f, 0.0f, 0.0f, 0.0f);
}

#endif
