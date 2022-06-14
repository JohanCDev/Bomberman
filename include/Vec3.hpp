/**
 * @file Vec3.hpp
 * @author Johan Chrillesen (johan.chrillesen@epitech.eu)
 * @brief 3D Vectors
 * @version 0.1
 * @date 2022-05-16
 *
 * @copyright Copyright (c) 2022
 *
 */

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
        /// @returns The new vector.
        template <typename U> explicit constexpr operator vec3<U>() const
        {
            return vec3<U>{static_cast<U>(x), static_cast<U>(y), static_cast<U>(z)};
        }

        /// Add vectors
        /// @returns The sum of the two vectors.
        constexpr vec3<T> operator+() const
        {
            return *this;
        }

        /// Substract vectors
        /// @returns The result of the two vectors.
        constexpr vec3<T> operator-() const
        {
            return vec3<T>{-x, -y, -z};
        }

        /// Add vectors
        /// @param v Vector to add.
        /// @returns The result of the two vectors.
        constexpr vec3<T> operator+(T const &v) const
        {
            return vec3<T>{x + v, y + v, z + v};
        }

        /// Add vectors
        /// @param v Vector to add.
        /// @returns New vector.
        constexpr vec3<T> operator+(vec3<T> const &v) const
        {
            return vec3<T>{x + v.x, y + v.y, z + v.z};
        }

        /// Substract vectors
        /// @param v Vector to substract.
        /// @returns New vector.
        constexpr vec3<T> operator-(T const &v) const
        {
            return vec3<T>{x - v, y - v, z - v};
        }

        /// Substract vectors
        /// @param v Vector to substract.
        /// @returns New vector.
        constexpr vec3<T> operator-(vec3<T> const &v) const
        {
            return vec3<T>{x - v.x, y - v.y, z - v.z};
        }

        /// Multiply vectors
        /// @param v Vector to multiply.
        /// @returns New vector.
        constexpr vec3<T> operator*(T const &v) const
        {
            return vec3<T>{x * v, y * v, z * v};
        }

        /// Dot product.
        /// @param v Vector to product.
        /// @returns The dot product.
        constexpr T operator*(vec3<T> const &v) const
        {
            return x * v.x + y * v.y + z * v.z;
        }

        /// Divide vectors.
        /// @param v Vector to divide.
        /// @returns New vector.
        constexpr vec3<T> operator/(T const &v) const
        {
            return vec3<T>{x / v, y / v, z / v};
        }

        /// Add vectors.
        /// @param v Vector to add.
        /// @returns New vector.
        constexpr vec3<T> &operator+=(T const &v)
        {
            x += v;
            y += v;
            z += v;
            return *this;
        }

        /// Add vectors.
        /// @param v Vector to add.
        /// @returns New vector.
        constexpr vec3<T> &operator+=(vec3<T> const &v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        /// Substract vectors.
        /// @param v Vector to substract.
        /// @returns New vector.
        constexpr vec3<T> &operator-=(T const &v)
        {
            x -= v;
            y -= v;
            z -= v;
            return *this;
        }

        /// Substract vectors.
        /// @param v Vector to substract.
        /// @returns New vector.
        constexpr vec3<T> &operator-=(vec3<T> const &v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }

        /// Multiply vectors.
        /// @param v Vector to multiply.
        /// @returns New vector.
        constexpr vec3<T> &operator*=(T const &v)
        {
            x *= v;
            y *= v;
            z += v;
            return *this;
        }

        /// Divide vectors.
        /// @param v Vector to divide.
        /// @returns New vector.
        constexpr vec3<T> &operator/=(T const &v)
        {
            x /= v;
            y /= v;
            z /= v;
            return *this;
        }

        /// Equality operator.
        /// @param v Vector to compare.
        /// @returns True if the two vectors are equal.
        constexpr bool operator==(vec3<T> const &v) const
        {
            return x == v.x && y == v.y && z == v.z;
        }

        /// Inequality operator.
        /// @param v Vector to compare.
        /// @returns True if the two vectors are not equal.
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
} // namespace indie

#endif // !defined(ARCADE_TYPES_HPP_)
