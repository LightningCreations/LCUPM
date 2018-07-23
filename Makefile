CXX := g++

SOURCEFILES := main.cpp Terminal.cpp TextComponent.cpp
SOURCEFILES += Random.cpp ShadowRandom.cpp UUID.cpp
SOURCEFILES += Version.cpp JTime.cpp SHA256.cpp StringHelper.cpp

LIBCURL := ./Libs/libcurl.so

CURLINCLUDE := ./curl-master/include

INCLUDEDIRS := -I./ -I$(CURLINCLUDE)
LINKERFILES := -L$(LIBCURL)

FLAGS := -g  -fpermissive

all: lcupm

lcupm: $(SOURCEFILES)
	$(CXX) $(INCLUDEDIRS) $(LINKERFILES) $(FLAGS) -o lcupm $(SOURCEFILES)



run: lcupm
	./lcupm

debug: lcupm
	gdb lcupm

clean:
	rm -f lcupm
	