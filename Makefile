SRCS=src/liste/liste.c src/file/file.c src/dict/dict.c
INCS=-Isrc
all: clear build

clear:
	rm -rf build
build:
	mkdir build || true
	gcc -o build/libkuesji.so -shared -fPIC $(INCS) $(SRCS)
check:
	gcc -o build/test test/test.c `pkg-config --cflags --libs kuesji`
install:
	mkdir -p $(DESTDIR)/usr/include/kuesji/file
	mkdir -p $(DESTDIR)/usr/include/kuesji/dict
	mkdir -p $(DESTDIR)/usr/include/kuesji/liste
	install src/liste/liste.h $(DESTDIR)/usr/include/kuesji/liste/liste.h
	install src/dict/dict.h $(DESTDIR)/usr/include/kuesji/dict/dict.h
	install src/file/file.h $(DESTDIR)/usr/include/kuesji/file/file.h
	install build/libkuesji.so $(DESTDIR)/usr/lib/libkuesji.so
	install src/kuesji.pc $(DESTDIR)/usr/lib/pkgconfig/kuesji.pc
