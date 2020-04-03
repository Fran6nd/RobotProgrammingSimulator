all:
	gcc -g src/main.c src/resources.c src/robot.c submodules/c_geometry/src/transform.c\
	 submodules/c_geometry/src/vector.c\
	 -Iinclude -Isubmodules/c_geometry/include\
	   -lSDL2-2.0 -lm -ldl -o robotsimulator