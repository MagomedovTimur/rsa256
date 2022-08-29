/*
 *  (C) Copyright Nick Thompson 2018.
 *  Use, modification and distribution are subject to the
 *  Boost Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef BOOST_INTEGER_EXTENDED_EUCLIDEAN_HPP
#define BOOST_INTEGER_EXTENDED_EUCLIDEAN_HPP
#include <limits>
#include <stdexcept>
#include <boost/throw_exception.hpp>
#include <boost/core/swap.hpp>
#include <boost/core/enable_if.hpp>

namespace boost {
    namespace integer {

        // From "The Joy of Factoring", Algorithm 2.7, with a small optimization to remove tmps from Wikipedia.
        // Solves mx + ny = gcd(m,n). Returns tuple with (gcd(m,n), x, y).

        struct euclidean_result_t
        {
            boost::multiprecision::uint1024_t gcd;
            boost::multiprecision::uint1024_t x;
            boost::multiprecision::uint1024_t y;
        };

        euclidean_result_t extended_euclidean(boost::multiprecision::uint1024_t m, boost::multiprecision::uint1024_t n)
        {
            if (m < 1 || n < 1)
            {
                BOOST_THROW_EXCEPTION(std::domain_error("extended_euclidean: arguments must be strictly positive"));
            }

            bool swapped = false;
            if (m < n)
            {
                swapped = true;
                boost::swap(m, n);
            }
            boost::multiprecision::uint1024_t u0 = m;
            boost::multiprecision::uint1024_t u1 = 1;
            boost::multiprecision::uint1024_t u2 = 0;
            boost::multiprecision::uint1024_t v0 = n;
            boost::multiprecision::uint1024_t v1 = 0;
            boost::multiprecision::uint1024_t v2 = 1;
            boost::multiprecision::uint1024_t w0;
            boost::multiprecision::uint1024_t w1;
            boost::multiprecision::uint1024_t w2;
            while (v0 > 0)
            {
                boost::multiprecision::uint1024_t q = u0 / v0;
                w0 = u0 - q * v0;
                w1 = u1 - q * v1;
                w2 = u2 - q * v2;
                u0 = v0;
                u1 = v1;
                u2 = v2;
                v0 = w0;
                v1 = w1;
                v2 = w2;
            }

            euclidean_result_t result;
            result.gcd = u0;
            if (!swapped)
            {
                result.x = u1;
                result.y = u2;
            }
            else
            {
                result.x = u2;
                result.y = u1;
            }

            return result;
        }

    }
}
#endif
