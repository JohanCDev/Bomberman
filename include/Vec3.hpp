/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** types
*/

/// @file
///
/// Misc types.

#ifndef INDIE_VEC3_HPP_
#define INDIE_VEC3_HPP_

namespace indie
{
    /// A 3D vector.
    template <typename T> struct vec3 {
        /// x coordinate.
        T x;
        /// y coordinate.
        T y;
        /// z coordinate.
        T z;

        /// Direct vector casting support.
        template <typename U> explicit constexpr operator vec3<U>() const
        {
            return vec3<U>{static_cast<U>(x), static_cast<U>(y), static_cast<U>(z)};
        }

        constexpr vec3<T> operator+() const
        {
            return *this;
        }

        constexpr vec3<T> operator-() const
        {
            return vec3<T>{-x, -y, -z};
        }

        constexpr vec3<T> operator+(T const &v) const
        {
            return vec3<T>{x + v, y + v, z + v};
        }

        constexpr vec3<T> operator+(vec3<T> const &v) const
        {
            return vec3<T>{x + v.x, y + v.y, z + v.z};
        }

        constexpr vec3<T> operator-(T const &v) const
        {
            return vec3<T>{x - v, y - v, z - v};
        }

        constexpr vec3<T> operator-(vec3<T> const &v) const
        {
            return vec3<T>{x - v.x, y - v.y, z - v.z};
        }

        constexpr vec3<T> operator*(T const &v) const
        {
            return vec3<T>{x * v, y * v, z * v};
        }

        /// Dot product.
        constexpr T operator*(vec3<T> const &v) const
        {
            return x * v.x + y * v.y + z * v.z;
        }

        constexpr vec3<T> operator/(T const &v) const
        {
            return vec3<T>{x / v, y / v, z / v};
        }

        constexpr vec3<T> &operator+=(T const &v)
        {
            x += v;
            y += v;
            z += v;
            return *this;
        }

        constexpr vec3<T> &operator+=(vec3<T> const &v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        constexpr vec3<T> &operator-=(T const &v)
        {
            x -= v;
            y -= v;
            z -= v;
            return *this;
        }

        constexpr vec3<T> &operator-=(vec3<T> const &v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }

        constexpr vec3<T> &operator*=(T const &v)
        {
            x *= v;
            y *= v;
            z += v;
            return *this;
        }

        constexpr vec3<T> &operator/=(T const &v)
        {
            x /= v;
            y /= v;
            z /= v;
            return *this;
        }

        constexpr bool operator==(vec3<T> const &v) const
        {
            return x == v.x && y == v.y && z == v.z;
        }

        constexpr bool operator!=(vec3<T> const &v) const
        {
            return x != v.x || y != v.y || z != v.z;
        }
    };

    /// A 3D vector of unsigned ints.
    using vec3u = vec3<unsigned int>;

    /// A 3D vector of ints.
    using vec3i = vec3<int>;

    /// A 3D vector of floats.
    using vec3f = vec3<float>;

    /// A 3D vector of doubles.
    using vec3d = vec3<double>;
} // namespace arcade

#endif // !defined(ARCADE_TYPES_HPP_)
