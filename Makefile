UNAME := $(shell uname)
SDL2_INCLUDE := "-lSDL2"
ifeq ($(UNAME), Darwin)
	SDL2_INCLUDE :=  -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2
endif

all:
	gcc -g src/main.c submodules/c_resources_manager/src/resources_manager.c src/robot.c submodules/c_geometry/src/transform.c\
	 submodules/c_geometry/src/vector.c\
	 -Iinclude -Isubmodules/c_geometry/include\
	 -Iinclude -Isubmodules/c_resources_manager/include\
	   $(SDL2_INCLUDE) -lm -ldl -o robotsimulator