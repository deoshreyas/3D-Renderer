all:
	g++ -I src/include -L src/lib -o main main.cpp Renderer3D.cpp -lmingw32 -lSDL2main -lSDL2