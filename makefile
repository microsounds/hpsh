 #
 #  makefile
 #  This file is part of hpsh.
 #  See hpsh.c for copyright or LICENSE for license information.
 #

CC=gcc
CFLAGS=-O2 -ansi
LDFLAGS=-lm
SRCDIR=src
INCLUDES=include
INSTALLDIR=/usr/local/bin
OUTPUT=hpsh
INPUT=$(wildcard $(SRCDIR)/*.c)

.PHONY: all clean install uninstall remove

all: $(INPUT)
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $(OUTPUT) $(INPUT) $(LDFLAGS)
	
clean:
	rm -rf $(OUTPUT)
	
install: all
	mv $(OUTPUT) $(INSTALLDIR)

uninstall:
	rm -rf $(INSTALLDIR)/$(OUTPUT)

remove: uninstall
