CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -Wextra
EXEC = raytracer
OBJECTS = main.o vec3.o pixel.o ray.o g_object.o sphere.o camera.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
