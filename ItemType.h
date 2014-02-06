#include <iostream>
#ifndef ITEMTYPE_H
#define ITEMTYPE_H
using namespace std;

struct edgeNode {
	int edgeIndex;
	edgeNode* next;
};

struct vertex {
	int vertexIndex;
	float x,y;
	bool inTree;
	int numEdgesAdjacent;
	edgeNode* head;
	edgeNode* tail;
	vertex() {
		inTree = false;
		numEdgesAdjacent = 0;
		head = tail = NULL;
	}
	void addEdge(int x) {
		edgeNode* e = new edgeNode();
		e->edgeIndex = x;
		e->next = NULL;
		tail ->next = e;
		numEdgesAdjacent = 0;
	};

};

struct edge { 
  //int edgeIndex;
  double weight;
  int v1;
  int v2;
  bool checkEdge() {
	if (
  }
};

#endif
