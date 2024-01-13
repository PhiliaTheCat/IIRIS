CPP = cl
LK = link
RM = del

CPPFLAGS = /nologo /EHa /c /GL /MD /O2 /W3 /D_CRT_SECURE_NO_DEPRECATE /D_CRT_SECURE_NO_WARNINGS
LKFLAGS = /nologo /ltcg

ESSENCE = src\PNG_Interface.obj src\Pic.obj lib\libPNG.lib lib\zlib.lib

bin\Test.exe: src\Test.obj $(ESSENCE)
	$(LK) $(LKFLAGS) /out:$@ src\Test.obj $(ESSENCE)

src\PNG_Interface.obj: src\PNG_Interface.cpp
	$(CPP) $(CPPFLAGS) /Fo$@ src\PNG_Interface.cpp

src\Pic.obj: src\Pic.cpp
	$(CPP) $(CPPFLAGS) /Fo$@ src\Pic.cpp

src\Test.obj: src\Test.cpp
	$(CPP) $(CPPFLAGS) /Fo$@ src\Test.cpp

.PHONY: clean test

clean:
	$(RM) src\*.obj
	$(RM) bin\*.exe

test: bin\Test.exe
	bin\Test.exe
