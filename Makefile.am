INCLUDES = -I$(srcdir)/include -I$(srcdir)/linux

AM_CFLAGS = -g -Wall -D_GNU_SOURCE -DSYSCONFDIR=\"$(sysconfdir)\" -DBINDIR=\"$(bindir)\" -DRDMADIR=\"@rdmadir@\"

bin_PROGRAMS = util/ib_acme
sbin_PROGRAMS = svc/ibacm
svc_ibacm_SOURCES = src/acm.c
util_ib_acme_SOURCES = src/acme.c linux/acme_linux.c src/libacm.c linux/libacm_linux.c src/parse.c
svc_ibacm_CFLAGS = $(AM_CFLAGS)
util_ib_acme_CFLAGS = $(AM_CFLAGS)

ibacmincludedir = $(includedir)/infiniband

ibacminclude_HEADERS = include/infiniband/acm.h

man_MANS = \
	man/ib_acme.1 \
	man/ibacm.1 \
	man/ibacm.7

EXTRA_DIST = src/acm_mad.h src/libacm.h ibacm.init.in \
	     linux/osd.h linux/dlist.h ibacm.spec.in $(man_MANS) ibacm_opts.cfg \
	     ibacm_addr.cfg

install-exec-hook:
	install -D -m 755 ibacm.init $(DESTDIR)$(sysconfdir)/init.d/ibacm;

dist-hook: ibacm.spec
	cp ibacm.spec $(distdir)
