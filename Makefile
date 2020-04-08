all:
	gcc -g src/main.c submodules/c_resources_manager/src/resources_manager.c src/robot.c submodules/c_geometry/src/transform.c\
	 submodules/c_geometry/src/vector.c\
	 -Iinclude -Isubmodules/c_geometry/include\
	 -Iinclude -Isubmodules/c_resources_manager/include\
	   -lSDL2-2.0 -lm -ldl -o robotsimulator