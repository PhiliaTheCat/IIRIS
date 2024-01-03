cc = cl
lk = link

ccflags = /c /nologo /EHa /std:c++14 /MD /O2 /W3 /D_CRT_SECURE_NO_WARNINGS /D_CRT_SECURE_NO_DEPRECATE
lkflags = /nologo

zlib = lib\zlib.lib
libpng = lib\libpng.lib
demo = bin\Demo.exe
test = bin\Test.exe

.phony: clean all test

test: $(test)

$(test): src\Test.obj src\PNG_Interface.obj $(libpng) $(zlib)
	$(lk) $(lkflags) src\Test.obj src\PNG_Interface.obj $(libpng) $(zlib) /out:$(test)

src\Test.obj:
	$(cc) $(ccflags) src\Test.cpp /Fosrc\Test.obj

src\PNG_Interface.obj:
	$(cc)$(ccflags) src\PNG_Interface.cpp /Fosrc\PNG_Interface.obj

clean:
	del src\*.obj
	del bin\*.exe
