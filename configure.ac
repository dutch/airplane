AC_INIT([airplane],
[m4_esyscmd([build-aux/git-version-gen .tarball-version])],
[chris@lamberson.online])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign tar-pax dist-xz no-dist-gzip subdir-objects])
AIRPLANE_INIT
AC_PROG_CC
PKG_CHECK_MODULES([LIBGIT2], [libgit2])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
