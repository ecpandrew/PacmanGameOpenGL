CPP = g++
OPTS = -I "irrklang/include" -L "/usr/lib" irrklang/bin/linux-gcc-64/libIrrKlang.so -pthread

all:
	$(CPP) pacmanGame.cpp -o example -lGL -lGLU -lglut  $(OPTS)





clean:
	rm example
