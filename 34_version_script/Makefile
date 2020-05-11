all:
	g++ -fPIC -Wl,--version-script libutils.vers --shared -o libutils.so utils.cpp

clean:
	rm -rf *.so *.o

end:
	g++ -fPIC -Wl,--version-script libutils.vers --shared -o libutils.so main.cpp
	g++ -fPIC -Wl,--version-script libutils.vers -Wl,-soname -Wl,libutils.so.0.1 -o libutils.so main.cpp
	nm libutils.so | c++filt

display:
	readelf -s libutils.so | c++filt
