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

struct edgeNode {
	edge* e;
	edgeNode* next;
	edgeNode() {
		e = NULL;
		next = NULL;
	}
	edgeNode(edge* edgy) {
		e=edgy;
		next=NULL;
	}
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
		head = NULL;
		tail = NULL;
	};
	
	edge* getShortestEdge() {
		if (numEdgesAdjacent==0)
			return NULL;
		edge* E = head->e;
		edgeNode* traveler = head->next;
		while (traveler) {
			E = (traveler->e->weight < E->weight) ? traveler->e : E;
			traveler = traveler -> next;
		}
		return E;
	}
	
	void addEdge(edge* e) {			
		edgeNode* nEdgeNode = new edgeNode(e);
		if (numEdgesAdjacent == 0) {
			head= nEdgeNode;
			tail= nEdgeNode;
		}
		else {
			nEdgeNode->next = head;
			head = nEdgeNode;
			}
		numEdgesAdjacent++;
	};
	
	void printVertex() {
		if (numEdgesAdjacent ==0)
			return;
		//cout<<"TESTING ADD EDGE "<<vertexIndex<<": ";
		edgeNode* traveler = new edgeNode();
		traveler->next = head;
			while (traveler->next) {
				cout<<"[ "<<traveler->next->e->weight<<" : ("<<traveler->next->e->v1->x<<", "<<traveler->next->e->v1->y<<") ("<<traveler->next->e->v2->x<<", "<<traveler->next->e->v2->y<<") ] ";
				//cout<<traveler->next->e;
				traveler = traveler->next;
			}
		cout<<endl;
	}
	
};

 //inline ostream& operator << (ostream&os, const edge* e) {
	//cout<<e->weight<<" [("<<e->v1->x<<", "<<e->v1->y<<") ("<<e->v2->x<<", "<<e->v2->y<<")]"<<endl;
  //};

#endif
