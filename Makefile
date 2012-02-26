LIBSENT=./julius-4.2.1/libsent
LIBJULIUS=./julius-4.2.1/libjulius

CC=g++-4.6
CFLAGS=-g -O2 -std=c++0x

CPPFLAGS=-I$(LIBJULIUS)/include -I$(LIBSENT)/include  `$(LIBSENT)/libsent-config --cflags` `$(LIBJULIUS)/libjulius-config --cflags`
LDFLAGS= -L$(LIBJULIUS) `$(LIBJULIUS)/libjulius-config --libs` -L$(LIBSENT) `$(LIBSENT)/libsent-config --libs`

############################################################

all: test

test: test.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -o test test.cpp $(LDFLAGS)

clean:
	$(RM) *.o *.bak *~ core TAGS

distclean:
	$(RM) *.o *.bak *~ core TAGS
	$(RM) test
