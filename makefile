hw2 : circle.o triangle.o rectangle.o composedshape.o 161044069_main.o
	g++ -o hw2 161044069_main.o circle.o triangle.o rectangle.o composedshape.o

circle.o : circle.cpp
	g++ -c -std=c++0x -Wall circle.cpp

triangle.o : triangle.cpp
	g++ -c -std=c++0x -Wall triangle.cpp

rectangle.o : rectangle.cpp
	g++ -c -std=c++0x -Wall rectangle.cpp

composedshape.o : composedshape.cpp
	g++ -c -std=c++0x -Wall composedshape.cpp
		
161044069_main.o : 161044069_main.cpp
	g++ -c -std=c++0x -Wall 161044069_main.cpp

clean:
	rm *.o hw2
