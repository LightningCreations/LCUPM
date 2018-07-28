CXX := g++

SOURCEFILES := main.cpp Terminal.cpp TextComponent.cpp
SOURCEFILES += Random.cpp ShadowRandom.cpp UUID.cpp
SOURCEFILES += Version.cpp JTime.cpp SHA256.cpp StringHelper.cpp
SOURCEFILES += Errors.cpp IOWrapper.cpp Curl.cpp

LIBCURL := curl

CURLINCLUDE := ./curl-master/include

INCLUDEDIRS := -I./ -I$(CURLINCLUDE)
LINKERFILES := -l$(LIBCURL)

PRGARGS := help

FLAGS := -g  -fpermissive

all: lcupm

lcupm: $(SOURCEFILES)
	$(CXX) $(INCLUDEDIRS) $(FLAGS) -o lcupm $(SOURCEFILES) $(LINKERFILES)



run: lcupm
	./lcupm $(PRGARGS)

debug: lcupm
	gdb lcupm

clean:
	rm -f lcupm
	