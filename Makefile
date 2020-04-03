all:
	gcc src/main.c -Iinclude -Isubmodules/c_geometry/include  -lSDL2-2.0 -o robotsimulator