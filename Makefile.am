AUTOMAKE_OPTIONS = subdir-objects


noinst_LIBRARIES=libparallel.a
libparallel_a_SOURCES=src/quicksort.cpp include/quicksort.h
libparallel_a_CPPFLAGS=-std=c++11 -I$(top_srcdir)/include
include_HEADERS=include/quicksort.h

TESTS = quicksort_test

check_PROGRAMS=quicksort_test
quicksort_test_SOURCES=test/test.cpp
quicksort_test_CPPFLAGS=-std=c++11 -I$(top_srcdir)/include
quicksort_test_LDADD=libparallel.a 
quicksort_testdir=$(top_distdir)
