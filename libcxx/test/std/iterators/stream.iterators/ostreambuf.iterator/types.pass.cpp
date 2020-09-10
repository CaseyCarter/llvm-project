//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <iterator>

// template <class charT, class traits = char_traits<charT> >
// class ostreambuf_iterator
//   : public iterator<output_iterator_tag, void, void, void, void>
// {
// public:
//   typedef charT                          char_type;
//   typedef traits                         traits_type;
//   typedef basic_streambuf<charT, traits> streambuf_type;
//   typedef basic_ostream<charT, traits>   ostream_type;
//   ...

#include <cstddef>
#include <iterator>
#include <string>
#include <type_traits>

#include "test_macros.h"

int main(int, char**)
{
    typedef std::ostreambuf_iterator<char> I1;
#if TEST_STD_VER <= 14
    static_assert((std::is_convertible<I1,
        std::iterator<std::output_iterator_tag, void, void, void, void> >::value), "");
#else
    static_assert((std::is_same<I1::iterator_category, std::output_iterator_tag>::value), "");
    static_assert((std::is_same<I1::value_type, void>::value), "");
#if TEST_STD_VER <= 17 || defined(_LIBCPP_VERSION)
    static_assert((std::is_same<I1::difference_type, void>::value), "");
#else
    static_assert((std::is_same<I1::difference_type, std::ptrdiff_t>::value), "");
#endif
    static_assert((std::is_same<I1::pointer, void>::value), "");
    static_assert((std::is_same<I1::reference, void>::value), "");
#endif
    static_assert((std::is_same<I1::char_type, char>::value), "");
    static_assert((std::is_same<I1::traits_type, std::char_traits<char> >::value), "");
    static_assert((std::is_same<I1::streambuf_type, std::streambuf>::value), "");
    static_assert((std::is_same<I1::ostream_type, std::ostream>::value), "");

    typedef std::ostreambuf_iterator<wchar_t> I2;
#if TEST_STD_VER <= 14
    static_assert((std::is_convertible<I2,
        std::iterator<std::output_iterator_tag, void, void, void, void> >::value), "");
#else
    static_assert((std::is_same<I2::iterator_category, std::output_iterator_tag>::value), "");
    static_assert((std::is_same<I2::value_type, void>::value), "");
#if TEST_STD_VER <= 17 || defined(_LIBCPP_VERSION)
    static_assert((std::is_same<I2::difference_type, void>::value), "");
#else
    static_assert((std::is_same<I2::difference_type, std::ptrdiff_t>::value), "");
#endif
    static_assert((std::is_same<I2::pointer, void>::value), "");
    static_assert((std::is_same<I2::reference, void>::value), "");
#endif
    static_assert((std::is_same<I2::char_type, wchar_t>::value), "");
    static_assert((std::is_same<I2::traits_type, std::char_traits<wchar_t> >::value), "");
    static_assert((std::is_same<I2::streambuf_type, std::wstreambuf>::value), "");
    static_assert((std::is_same<I2::ostream_type, std::wostream>::value), "");

  return 0;
}
