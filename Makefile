run: main.cpp
	g++ -o main -I. -g main.cpp 

clean: main
	rm ./main

remake: clean run