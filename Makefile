cc = cl
lk = link

ccflags = /c /nologo /EHa /std:c++14 /MD /O2 /W3 /D_CRT_SECURE_NO_WARNINGS /D_CRT_SECURE_NO_DEPRECATE
lkflags = /nologo

zlib = lib\zlib.lib
libpng = lib\libpng.lib
demo = bin\Demo.exe
test = bin\Test.exe

all: clean

test: $(test)

$(test): src\Test.obj src\PNG_Interface.obj $(libpng) $(zlib)
	$(lk) $(lkflags) src\Test.obj src\PNG_Interface.obj $(libpng) $(zlib) /out:$(test)

src\Test.obj: src\Test.cpp
	$(cc) $(ccflags) src\Test.cpp /Fosrc\Test.obj

src\PNG_Interface.obj: src\PNG_Interface.cpp
	$(cc) $(ccflags) src\PNG_Interface.cpp /Fosrc\PNG_Interface.obj

src\Pic.obj: src\Pic.cpp
	$(cc) $(ccflags) src\Pic.cpp /Fosrc\Pic.obj

clean:
	del src\*.obj
	del bin\*.exe
