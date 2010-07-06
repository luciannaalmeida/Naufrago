#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.64])
AC_INIT([naufrago], [1.0])
AC_CONFIG_SRCDIR([src/coral.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_MAKE_SET

# Checks for libraries.
# Verifica se a biblioteca alleg-4.2.2 esta disponivel.
AC_CHECK_LIB([alleg-4.2.2], [blit],, AC_MSG_ERROR(project requires Allegro to be installed))

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h unistd.h])
# Verifica se o header do allegro esta' disponivel.
AC_CHECK_HEADER([allegro.h],,
[AC_SUBST([ALLEGTEST], [[NO_ALLEG]=1])])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
