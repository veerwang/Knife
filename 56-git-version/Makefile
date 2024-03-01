
#CODE_VERSION="ef123456"

CODE_VERSION="$(shell git tag | awk 'END{print}')$(shell git rev-parse --short=16 HEAD)"
all:

	g++ '-DVERSION=$(CODE_VERSION)' -std=c++11 -o play main.cpp

clean:
	rm -rf *.o play
