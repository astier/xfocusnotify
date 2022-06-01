PREFIX ?= /usr/local

CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -O2

all: xfocusnotify

xfocusnotify: xfocusnotify.c Makefile
	$(CC) $(CFLAGS) -o $@ $< -lX11

install: all
	install -D xfocusnotify $(DESTDIR)$(PREFIX)/bin/xfocusnotify

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/xfocusnotify

.PHONY: all install uninstall
