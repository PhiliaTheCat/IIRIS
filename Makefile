cc = cl
lk = link
rm = del

ccflags = /nologo /MD /EHa /c /GL /O2 /W3 /D_CRT_SECURE_NO_WARNINGS /D_CRT_SECURE_NO_DEPRECATE
lkflags = /nologo /LTCG

zlib = lib\zlib.lib
libpng = lib\libpng.lib
lib = $(libpng) $(zlib)
essence = src\PNG_Interface.obj src\Pic.obj $(lib)

bin\Demo.exe:

.PHONY: clean test

bin\Test.exe: src\Test.obj $(essence)
	$(lk) $(lkflags) /out:$@ src\Test.obj $(essence)

src\Test.obj: src\Test.cpp
	$(cc) $(ccflags) /Fo$@ src\Test.cpp 

src\PNG_Interface.obj: src\PNG_Interface.cpp
	$(cc) $(ccflags) /Fo$@ src\PNG_Interface.cpp 

src\Pic.obj: src\Pic.cpp
	$(cc) $(ccflags) /Fo$@ src\Pic.cpp 

clean:
	cd src
	$(rm) *.obj
	cd ..\bin
	$(rm) *.exe
	cd ..

test: bin\Test.exe
	bin\Teest.exe
