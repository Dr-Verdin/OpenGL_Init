flags = -lGL -lGLU -lglut


all: build

run: build
	./run

lean:
	@rm run* *.o

shapes:
	g++ print_basics_shapes.cpp -o run $(flags)
	./run