#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(src/main.cpp)
AM_INIT_AUTOMAKE(bijutsukan, SVN)
AC_CONFIG_HEADER(config.h)

# Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
#AC_HEADER_STDBOOL

AM_OPTIONS_WXCONFIG

AM_PATH_WXCONFIG(2.6.0, wxWin=1)
	if test "$wxWin" != 1; then
        AC_MSG_ERROR([
               wxWidgets must be installed on your system
               but wx-config script couldn't be found.

               Please check that wx-config is in path, the directory
               where wxWidgets libraries are installed (returned by
               'wx-config --libs' command) is in LD_LIBRARY_PATH or
              equivalent variable and wxWidgets version is 2.3.4 or above.
        ])
	fi

# Checks for library functions.

CPPFLAGS="$CPPFLAGS $WX_CPPFLAGS"
CXXFLAGS="$CXXFLAGS $WX_CXXFLAGS_ONLY"
CFLAGS="$CFLAGS $WX_CFLAGS_ONLY"
LDFLAGS="$LDFLAGS $WX_LIBS"

AC_LANG_CPLUSPLUS

AC_OUTPUT([Makefile panels/Makefile src/Makefile libbackend/Makefile])
