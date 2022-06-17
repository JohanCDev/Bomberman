/**
 * @file Vec2.hpp
 * @author Johan Chrillesen (johan.chrillesen@epitech.eu)
 * @brief 2D vectors implementation
 * @version 0.1
 * @date 2022-05-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INDIE_VEC2_HPP_
#define INDIE_VEC2_HPP_

namespace indie
{
    /// A 2D vector.
    template <typename T> struct vec2 {
        /// x coordinate.
        T x;
        /// y coordinate.
        T y;

        /// Direct vector casting support.
        /// @returns The new vector.
        template <typename U> explicit constexpr operator vec2<U>() const
        {
            return vec2<U>{static_cast<U>(x), static_cast<U>(y)};
        }

        /// Add vectors
        /// @returns The sum of the two vectors.
        constexpr vec2<T> operator+() const
        {
            return *this;
        }

        /// Substract vectors
        /// @returns The result of the two vectors.
        constexpr vec2<T> operator-() const
        {
            return vec2<T>{-x, -y};
        }

        /// Add vectors
        /// @param v Vector to add.
        /// @returns The result of the two vectors.
        constexpr vec2<T> operator+(T const &v) const
        {
            return vec2<T>{x + v, y + v};
        }

        /// Add vectors
        /// @param v Vector to add.
        /// @returns New vector.
        constexpr vec2<T> operator+(vec2<T> const &v) const
        {
            return vec2<T>{x + v.x, y + v.y};
        }

        /// Substract vectors
        /// @param v Vector to substract.
        /// @returns New vector.
        constexpr vec2<T> operator-(T const &v) const
        {
            return vec2<T>{x - v, y - v};
        }

        /// Substract vectors
        /// @param v Vector to substract.
        /// @returns New vector.
        constexpr vec2<T> operator-(vec2<T> const &v) const
        {
            return vec2<T>{x - v.x, y - v.y};
        }

        /// Multiply vectors
        /// @param v Vector to product.
        /// @returns New vector.
        constexpr vec2<T> operator*(T const &v) const
        {
            return vec2<T>{x * v, y * v};
        }

        /// Dot product.
        /// @param v Vector to product.
        /// @returns New vector.
        constexpr T operator*(vec2<T> const &v) const
        {
            return x * v.x + y * v.y;
        }

        /// Divide vectors
        /// @param v Vector to divide.
        /// @returns New vector.
        constexpr vec2<T> operator/(T const &v) const
        {
            return vec2<T>{x / v, y / v};
        }

        /// Add vectors
        /// @param v Vector to add.
        /// @returns New vector.
        constexpr vec2<T> &operator+=(T const &v)
        {
            x += v;
            y += v;
            return *this;
        }

        /// Add vectors
        /// @param v Vector to add.
        /// @returns New vector.
        constexpr vec2<T> &operator+=(vec2<T> const &v)
        {
            x += v.x;
            y += v.y;
            return *this;
        }

        /// Substract vectors
        /// @param v Vector to substract.
        /// @returns New vector.
        constexpr vec2<T> &operator-=(T const &v)
        {
            x -= v;
            y -= v;
            return *this;
        }

        /// Substract vectors
        /// @param v Vector to substract.
        /// @returns New vector.
        constexpr vec2<T> &operator-=(vec2<T> const &v)
        {
            x -= v.x;
            y -= v.y;
            return *this;
        }

        /// Multiply vectors
        /// @param v Vector to Multiply.
        /// @returns New vector.
        constexpr vec2<T> &operator*=(T const &v)
        {
            x *= v;
            y *= v;
            return *this;
        }

        /// Divide vectors
        /// @param v Vector to divide.
        /// @returns New vector.
        constexpr vec2<T> &operator/=(T const &v)
        {
            x /= v;
            y /= v;
            return *this;
        }

        /// Check equality between vectors
        /// @param v Vector to compare.
        /// @returns true if they are the same.
        constexpr bool operator==(vec2<T> const &v) const
        {
            return x == v.x && y == v.y;
        }

        /// Check inequality between vectors
        /// @param v Vector to compare.
        /// @returns true if they are not the same.
        constexpr bool operator!=(vec2<T> const &v) const
        {
            return x != v.x || y != v.y;
        }
    };

    /// A 2D vector of unsigned ints.
    using vec2u = vec2<unsigned int>;

    /// A 2D vector of ints.
    using vec2i = vec2<int>;

    /// A 2D vector of floats.
    using vec2f = vec2<float>;

    /// A 2D vector of doubles.
    using vec2d = vec2<double>;
} // namespace indie

#endif // !defined(ARCADE_TYPES_HPP_)
