all: utils.o
	g++ --shared -o libutils.so utils.o -Wl,--version-script,libutils.vers
	g++ -o play main.cpp -L ./ -lutils -Wl,-rpath .

utils.o:
	g++ -fPIC -c utils.cpp

clean:
	rm -rf *.so *.o play

end:
	# 部分的接口对外
	g++ -fPIC -Wl,--version-script libutils.vers --shared -o libutils.so utils.cpp
	# 全部的接口都对外
	g++ -fPIC --shared -o libutils.so utils.cpp
	# 其他
	g++ -fPIC -Wl,--version-script libutils.vers --shared -o libutils.so main.cpp
	g++ -fPIC -Wl,--version-script libutils.vers -Wl,-soname -Wl,libutils.so.0.1 -o libutils.so main.cpp
	nm libutils.so | c++filt

display:
	readelf -Ws -u libutils.so | c++filt
