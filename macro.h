/**
  @author  Kambiz Asadzadeh
  @details Patch for MSVC compilers (https://developercommunity.visualstudio.com/content/problem/169519/-cplusplus-macro-is-wrong.html)
*/

#ifndef MACRO_H
#define MACRO_H

#if defined(__clang__)
/* Clang/LLVM. ---------------------------------------------- */
#   undef  __GENESIS_COMPILER__
#   define __GENESIS_COMPILER__    "Clang/LLVM"
#   undef  __GENESIS_COMPILER_VER__
#   define __GENESIS_COMPILER_VER__    __clang_version__
#elif defined(__ICC) || defined(__INTEL_COMPILER)
/* Intel ICC/ICPC. ------------------------------------------ */
#   define __GENESIS_COMPILER__    "Intel ICC/ICPC"
#   define __GENESIS_COMPILER___VER    __INTEL_COMPILER_BUILD_DATE
#elif defined(__MINGW32__) && !defined (__amd64__) && !defined (__amd64) && !defined (__ia64__)
/* __MINGW32__. ------------------------------------------------- */
#   undef  __GENESIS_COMPILER__
#   define __GENESIS_COMPILER__    "MinGW-w86 (x86) 32 Bit"
#   undef  __GENESIS_COMPILER_VER__
#   define __GENESIS_COMPILER_VER__    __MINGW32_MAJOR_VERSION << "." << __MINGW32_MINOR_VERSION
#elif defined(__MINGW32__)
/* __MINGW64_32__. ------------------------------------------------- */
#   undef  __GENESIS_COMPILER__
#   define __GENESIS_COMPILER__    "MinGW-w64 (x86_64) 32-64 Bit"
#   undef  __GENESIS_COMPILER_VER__
#   define __GENESIS_COMPILER_VER__    __MINGW32_MAJOR_VERSION << "." << __MINGW32_MINOR_VERSION
#elif defined(__MINGW64__)
/* __MINGW64__. ------------------------------------------------- */
#   undef  __GENESIS_COMPILER__
#   define __GENESIS_COMPILER__    "MinGW-w64 (x64) 64 Bit"
#   undef  __GENESIS_COMPILER_VER__
#   define __GENESIS_COMPILER_VER__    __MINGW64_MAJOR_VERSION << "." << __MINGW64_MINOR_VERSION
#elif defined(__GNUC__) || defined(__GNUG__)
/* GNU GCC/G++. --------------------------------------------- */
#   undef  __GENESIS_COMPILER__
#   define __GENESIS_COMPILER__    "GNU GCC/G++"
#   undef  __GENESIS_COMPILER_VER__
#   define __GENESIS_COMPILER_VER__    __GNUC__ << "." << __GNUC_MINOR__ <<"."<< __GNUC_PATCHLEVEL__
#elif defined(__HP_cc) || defined(__HP_aCC)
/* Hewlett-Packard C/aC++. ---------------------------------- */
#   define __GENESIS_COMPILER__    "Hewlett-Packard C/aC++"
#   define __GENESIS_COMPILER_VER__    __HP_aCC
#elif defined(__IBMC__) || defined(__IBMCPP__)
/* IBM XL C/C++. -------------------------------------------- */
#   define __GENESIS_COMPILER__    "IBM XL C/C++"
#   define __GENESIS_COMPILER_VER__    __xlC_ver__
#elif defined(_MSC_VER)
/* Microsoft Visual Studio. --------------------------------- */
#   undef  __GENESIS_COMPILER__
#   define __GENESIS_COMPILER__  "MSVC++ "
#   undef  __GENESIS_COMPILER_VER__
#define    __GENESIS_COMPILER_VER__ _MSC_VER
#elif defined(__PGI)
/* Portland Group PGCC/PGCPP. ------------------------------- */
#   define __GENESIS_COMPILER__    "PGCC/PGCPP"
#   define __GENESIS_COMPILER_VER__    __VERSION__
#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
/* Oracle Solaris Studio. ----------------------------------- */
#   define __GENESIS_COMPILER__    "Oracle Solaris"
#   define __GENESIS_COMPILER_VER__    __SUNPRO_CC
#endif

#if defined (_MSC_VER) && _MSC_VER == 1400
#   undef  __GENESIS_MSVC__
#   define __GENESIS_MSVC__  "MSVC++ 8.0"
#elif defined (_MSC_VER) && _MSC_VER == 1500
#   undef  __GENESIS_MSVC__
#   define __GENESIS_MSVC__  "MSVC++ 9.0"
#elif defined (_MSC_VER) && _MSC_VER == 1600
#   undef  __GENESIS_MSVC__
#   define __GENESIS_MSVC__  "MSVC++ 10.0"
#elif defined (_MSC_VER) && _MSC_VER == 1700
#   undef  __GENESIS_MSVC__
#   define __GENESIS_MSVC__  "MSVC++ 11.0"
#elif defined (_MSC_VER) && _MSC_VER == 1800
#   undef  __GENESIS_MSVC__
#   define __GENESIS_MSVC__  "MSVC++ 12.0"
#elif defined (_MSC_VER) && _MSC_VER == 1900
#   undef  __GENESIS_MSVC__
#   define __GENESIS_MSVC__  "MSVC++ 14.0"
#elif defined (_MSC_VER) && _MSC_VER == 1910
#   undef  __GENESIS_MSVC__
#   define __GENESIS_MSVC__  "MSVC++ 15.0"
#elif defined (_MSC_VER) && _MSC_VER == 1911
#   undef  __GENESIS_MSVC__
#   define __GENESIS_MSVC__  "MSVC++ 15.3"
#elif defined (_MSC_VER) && _MSC_VER == 1912
#   undef  __GENESIS_MSVC__
#   define __GENESIS_MSVC__  "MSVC++ 15.5"
#elif defined (_MSC_VER) && _MSC_VER == 1913
#   undef  __GENESIS_MSVC__
#   define __GENESIS_MSVC__  "MSVC++ 15.6"
#elif defined (_MSC_VER) && _MSC_VER == 1914
#   undef  __GENESIS_MSVC__
#   define __GENESIS_MSVC__  "MSVC++ 15.7"
#endif

#if __cplusplus == 199711L && !defined (_MSC_VER)
/* C++98:  __cplusplus is 19971L.*/
#   undef  __GENESIS_CPP_VERSION__
#   define __GENESIS_CPP_VERSION__  98
#   undef  __GENESIS_CPP_VALUE__
#   define __GENESIS_CPP_VALUE__  "19971L"
#elif __cplusplus == 201103L
/* C++11:  __cplusplus is 201103L.*/
#   undef  __GENESIS_CPP_VERSION__
#   define __GENESIS_CPP_VERSION__ 11
#   undef  __GENESIS_CPP_VALUE__
#   define __GENESIS_CPP_VALUE__  "201103L"
#elif __cplusplus == 201402L
/* C++14:  __cplusplus is 201402L.*/
#   undef  __GENESIS_CPP_VERSION__
#   define __GENESIS_CPP_VERSION__  14
#   undef  __GENESIS_CPP_VALUE__
#   define __GENESIS_CPP_VALUE__  "201402L"
#elif __cplusplus == 201702L || __cplusplus == 201703 || __cplusplus == 199711L && defined(__GENESIS_COMPILER_VER__) && __GENESIS_COMPILER_VER__ > 1900 && defined__GENESIS_COMPILER_VER__ < 1914
/* C++17:  __cplusplus is c++1z.*/
#   undef  __GENESIS_CPP_VERSION__
#   define __GENESIS_CPP_VERSION__  17
#   undef  __GENESIS_CPP_VALUE__
#   define __GENESIS_CPP_VALUE__  "201703"
#elif __cplusplus == 201704 || __cplusplus == 201709
/* C++20:  __cplusplus is c++2a.*/
#   undef  __GENESIS_CPP_VERSION__
#   define __GENESIS_CPP_VERSION__  20
#   undef  __GENESIS_CPP_VALUE__
#   define __GENESIS_CPP_VALUE__  "201709"
#elif __embedded_cplusplus
#   undef  __GENESIS_CPP_VERSION__
#   define __GENESIS_CPP_VERSION__ "Embedded C++"
#   undef  __GENESIS_CPP_VALUE__
#   define __GENESIS_CPP_VALUE__  "19971L"
#else
#   undef  __GENESIS_CPP_VERSION__
#   define __GENESIS_CPP_VERSION__  0
#   undef  __GENESIS_CPP_VALUE__
#   define __GENESIS_CPP_VALUE__  "Unknown"
#endif

#include <iostream>
#include <string>

class Macro
{
public:
    Macro();
    /**
     * @brief get__cplusplus
     * @param flag returns compiler name when it's true
     * @return string value of c++ standard version.
     */
    std::string get__cplusplus(const bool &flag);
};

#endif // MACRO_H
