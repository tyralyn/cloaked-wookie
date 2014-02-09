#include <iostream>
#ifndef ITEMTYPE_H
#define ITEMTYPE_H
using namespace std;

struct vertex;

struct edge { 
  double weight;
  vertex* v1;
  vertex* v2;  
};

struct vertex {
	int vertexIndex;
	float x,y;
	bool inTree;
	vertex() {
		inTree = false;
	};
	
};

#endif
