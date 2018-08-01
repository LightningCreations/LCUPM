CXX := g++

SOURCEFILES := main.cpp Terminal.cpp TextComponent.cpp
SOURCEFILES += Random.cpp ShadowRandom.cpp UUID.cpp
SOURCEFILES += Version.cpp JTime.cpp SHA256.cpp StringHelper.cpp
SOURCEFILES += Errors.cpp IOWrapper.cpp Curl.cpp

LIBCURL := curl
LIBOPENSSL := ssl

CURLINCLUDE := ./curl-master/include

INCLUDEDIRS := -I./ -I$(CURLINCLUDE) -I/usr/include
LINKERFILES := -l$(LIBCURL) -l$(LIBOPENSSL)

PRGARGS := fetch https://www.sample-videos.com/audio/mp3/crowd-cheering.mp3

FLAGS := -g  -fpermissive -O3

all: lcupm

lcupm: $(SOURCEFILES)
	$(CXX) $(INCLUDEDIRS) $(FLAGS) -o lcupm $(SOURCEFILES) $(LINKERFILES)



run: lcupm
	./lcupm $(PRGARGS)

debug: lcupm
	gdb lcupm

clean:
	rm -f lcupm
	