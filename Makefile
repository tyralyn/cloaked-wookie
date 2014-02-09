all: prog2.cpp System.cpp tree.cpp
	g++ prog2.cpp System.cpp tree.cpp -o prog2

clean:
	rm prog2
