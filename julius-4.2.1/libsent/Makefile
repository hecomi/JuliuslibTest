# Generated automatically from Makefile.in by configure.
# Copyright (c) 1991-2011 Kawahara Lab., Kyoto University
# Copyright (c) 2000-2005 Shikano Lab., Nara Institute of Science and Technology
# Copyright (c) 2005-2011 Julius project team, Nagoya Institute of Technology
# All rights reserved
#
# $Id: Makefile.in,v 1.11 2011/04/29 05:09:15 sumomo Exp $
#

SHELL=/bin/sh

.SUFFIXES:
.SUFFIXES: .c .o .a
.c.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

CC=gcc
CFLAGS=-O6 -fomit-frame-pointer
CPPFLAGS=-Iinclude   -DHAVE_CONFIG_H
# LDFLAGS= 
RM=/bin/rm -f
AR=/usr/bin/ar r
RANLIB=ranlib
TARGET=libsent.a

## install
prefix=/usr/local
exec_prefix=${prefix}
bindir=${exec_prefix}/bin
libdir=${exec_prefix}/lib
includedir=${prefix}/include
INSTALL=/usr/bin/install -c
INSTALL_DATA=${INSTALL} -m 644
INSTALL_PROGRAM=${INSTALL}

## rules
OBJ = \
src/adin/adin_file.o \
src/adin/adin_sndfile.o \
src/adin/adin_tcpip.o \
src/adin/zc-e.o \
src/adin/zmean.o \
src/adin/ds48to16.o \
src/anlz/param_malloc.o \
src/anlz/rdparam.o \
src/anlz/paramselect.o \
src/anlz/paramtypes.o \
src/anlz/strip.o \
src/anlz/strip_mfcc.o \
src/anlz/wrsamp.o \
src/anlz/wrwav.o \
src/dfa/init_dfa.o \
src/dfa/rddfa.o \
src/dfa/dfa_lookup.o \
src/dfa/cpair.o \
src/dfa/mkcpair.o \
src/dfa/mkterminfo.o \
src/dfa/dfa_util.o \
src/dfa/dfa_malloc.o \
src/hmminfo/rdhmmdef.o \
src/hmminfo/rdhmmdef_data.o \
src/hmminfo/rdhmmdef_mpdf.o \
src/hmminfo/rdhmmdef_dens.o \
src/hmminfo/rdhmmdef_options.o \
src/hmminfo/rdhmmdef_state.o \
src/hmminfo/rdhmmdef_trans.o \
src/hmminfo/rdhmmdef_var.o \
src/hmminfo/rdhmmdef_streamweight.o \
src/hmminfo/rdhmmdef_tiedmix.o \
src/hmminfo/rdhmmdef_regtree.o \
src/hmminfo/hmm_lookup.o \
src/hmminfo/check_hmm_restriction.o \
src/hmminfo/check_hmmtype.o \
src/hmminfo/put_htkdata_info.o \
src/hmminfo/rdhmmlist.o \
src/hmminfo/cdhmm.o \
src/hmminfo/guess_cdHMM.o \
src/hmminfo/cdset.o \
src/hmminfo/init_phmm.o \
src/hmminfo/chkhmmlist.o \
src/hmminfo/write_binhmm.o \
src/hmminfo/read_binhmm.o \
src/hmminfo/write_binhmmlist.o \
src/hmminfo/read_binhmmlist.o \
src/net/rdwt.o \
src/net/server-client.o \
src/ngram/init_ngram.o \
src/ngram/ngram_read_arpa.o \
src/ngram/ngram_read_bin.o \
src/ngram/ngram_write_bin.o \
src/ngram/ngram_compact_context.o \
src/ngram/ngram_access.o \
src/ngram/ngram_lookup.o \
src/ngram/ngram_util.o \
src/ngram/ngram_malloc.o \
src/phmm/outprob_init.o \
src/phmm/outprob.o \
src/phmm/gms.o \
src/phmm/gms_gprune.o \
src/phmm/calc_mix.o \
src/phmm/calc_tied_mix.o \
src/phmm/gprune_common.o \
src/phmm/gprune_none.o \
src/phmm/gprune_safe.o \
src/phmm/gprune_heu.o \
src/phmm/gprune_beam.o \
src/phmm/addlog.o \
src/phmm/mkwhmm.o \
src/phmm/vsegment.o \
src/util/endian.o \
src/util/jlog.o \
src/util/mymalloc.o \
src/util/mybmalloc.o \
src/util/ptree.o \
src/util/aptree.o \
src/util/readfile.o \
src/util/gzfile.o \
src/util/mystrtok.o \
src/util/strcasecmp.o \
src/util/confout.o \
src/util/qsort.o \
src/voca/init_voca.o \
src/voca/voca_load_htkdict.o \
src/voca/voca_load_wordlist.o \
src/voca/voca_lookup.o \
src/voca/voca_malloc.o \
src/voca/voca_util.o \
src/wav2mfcc/ss.o \
src/wav2mfcc/wav2mfcc-buffer.o \
src/wav2mfcc/wav2mfcc-pipe.o \
src/wav2mfcc/mfcc-core.o \
src/wav2mfcc/para.o \
  src/adin/adin_pulseaudio.o src/adin/adin_mic_linux_alsa.o src/adin/adin_mic_linux_oss.o src/adin/adin_esd.o src/adin/adin_mic_linux.o

############################################################

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) $@ $?
	$(RANLIB) $@

############################################################

install: install.lib install.include install.bin

install.lib: $(TARGET)
	${INSTALL} -d ${libdir}
	${INSTALL_DATA} $(TARGET) ${libdir}

install.include:
	${INSTALL} -d ${includedir}/sent
	${INSTALL_DATA} include/sent/*.h ${includedir}/sent

install.bin: libsent-config-dist
	${INSTALL} -d ${bindir}
	${INSTALL_PROGRAM} libsent-config-dist ${bindir}/libsent-config

clean:
	$(RM) *~ src/*/*~ src/*/*.o src/*/*/*.o src/*/*/*/*.o src/*/*/*/*/*.o include/sent/*~ 
	$(RM) config.log config.cache

distclean:
	$(RM) *~ src/*/*~ src/*/*.o src/*/*/*.o src/*/*/*/*.o src/*/*/*/*/*.o include/sent/*~ 
	$(RM) config.log config.cache
	$(RM) libsent-config libsent-config-dist
	$(RM) config.status include/sent/config.h
	$(RM) $(TARGET)
	$(RM) Makefile
