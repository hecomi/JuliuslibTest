# Generated automatically from Makefile.in by configure.
# Copyright (c) 1991-2011 Kawahara Lab., Kyoto University
# Copyright (c) 2000-2005 Shikano Lab., Nara Institute of Science and Technology
# Copyright (c) 2005-2011 Julius project team, Nagoya Institute of Technology
# All rights reserved

## Makefile for mkfa, DFA compiler
## *** Needs GNU bison and flex ***
SHELL=/bin/sh
.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

CC=gcc
CFLAGS=-O6 -fomit-frame-pointer
CPPFLAGS=  -DHAVE_LIBFL=1 -DHAVE_MALLOC_H=1 
LDFLAGS= -lfl 
RM=/bin/rm -f
#BISON=@BISON@
#FLEX=@FLEX@
prefix=/usr/local
exec_prefix=${prefix}
INSTALL=/usr/bin/install -c

######################################################################
#YACS = gram.y
#FLEXS = gram.l
OBJS = gram.tab.o main.o voca.o nfa.o dfa.o triplet.o

TARGET=mkfa

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

#gram.tab.c: $(YACS)
#	$(BISON) $(YACS)
#
#lex.yy.c: $(FLEXS)
#	$(FLEX) $(FLEXS)

install: install.bin

install.bin:
	${INSTALL} -d ${exec_prefix}/bin
	${INSTALL} $(TARGET) ${exec_prefix}/bin

clean:
	$(RM) *.o *~ core
	$(RM) $(TARGET) $(TARGET).exe

distclean:
	$(RM) *.o *~ core
	$(RM) $(TARGET) $(TARGET).exe
	$(RM) Makefile

# dependencies
gram.tab.o : gram.tab.c lex.yy.c mkfa.h
gram.tab.c : gram.y
$(OBJS) : mkfa.h
