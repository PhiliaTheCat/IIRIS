cc = cl
lk = link
rm = del

ccflags = /nologo /MD /c /GL /O2 /W3 /D_CRT_SECURE_NO_WARNINGS /D_CRT_SECURE_NO_DEPRECATE
lkflags = /nologo /LTCG

zlib = lib/zlib.lib
libpng = lib/libpng.lib
lib = $(libpng) $(zlib)
demo = bin/Demo.exe
test = bin/Test.exe

$(test): src/Test.obj src/PNG_Interface.obj src/Pic.obj $(lib)
	$(lk) $(lkflags) /out:$@ src/Test.obj src/PNG_Interface.obj src/Pic.obj $(lib) 

src/Test.obj: src/Test.cpp
	$(cc) $(ccflags) /Fo$@ src/Test.cpp 

src/PNG_Interface.obj: src/PNG_Interface.cpp
	$(cc) $(ccflags) /Fo$@ src/PNG_Interface.cpp 

src/Pic.obj: src/Pic.cpp
	$(cc) $(ccflags) /Fo$@ src/Pic.cpp 

.phony: clean all test

clean:
	cd src
	$(rm) *.obj
	cd ../bin
	$(rm) *.exe
	cd ../

all: clean $(demo)

test: clean $(test)
	$(test)
