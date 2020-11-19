bin_PROGRAMS = %D%/airplane
%C%_airplane_CPPFLAGS = $(LIBGIT2_CFLAGS)
%C%_airplane_SOURCES = %D%/airplane.c
%C%_airplane_LDADD = $(LIBGIT2_LIBS)
dist_man_MANS = %D%/airplane.1
