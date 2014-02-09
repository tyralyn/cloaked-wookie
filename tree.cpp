#include "tree.h"

tree::tree() {
	head = NULL;
	tail = NULL;
	numEdges = 0;
}

tree::~tree() {
	while (head) {
		head = head->next;
		delete head; 
	}
}

void tree::setup(edge *e) {
	head = new edgeNode(e);
	numEdges++;
}

void tree::addEdge(edge* e) {
	/*edgeNode* n = new edgeNode(e);
	edgeNode* t = head;
	cout<<t->next<<endl;
	while (t->next) {
		t=t->next;
	}
	t->next = n;
	e->v1->inTree = true;//!e->v1->inTree;
	e->v2->inTree = true;//!e->v2->inTree;
	numEdges++;*/
	edgeNode* n = new edgeNode(e);
	//n->next = head;
	//head = n;
	if (numEdges==0) {
		head = n;
		tail = n;
	}
	else {
		tail->next = n;
		tail = n;
	}
	e->v1->inTree = true;//!e->v1->inTree;
	e->v2->inTree = true;//!e->v2->inTree;
	numEdges++;
}

void tree::getMinEdge(const edge* current, edge* min) {
cout<<"minEdge\n";
	if (current->v1->inTree && current->v2->inTree  ||  !current->v1->inTree && !current->v2->inTree  ) {
		return;
	}
	else {
		edge* edge1;
		if (current->v1->inTree)
			edge1 = current->v1->getShortestEdge();
		else
			edge1 = current->v2->getShortestEdge();
		min = (min->weight < edge1->weight) ? min : edge1;
	}
}

edge* tree::getNextEdge(edge* e) {
	cout<<"nextEdge\n";
	edgeNode* traveler = head;
	edge* minEdge;
	addEdge(e);
	minEdge = head->e;
	while (traveler) {
		cout<<"inLoop\n";
		getMinEdge(traveler->e, minEdge);
		cout<<"traveler incremented\n";
		traveler=traveler->next;
	}
	return minEdge;
}

void tree::printTree() {
	cout<<"printing tree: "<<numEdges<<endl;
		if (numEdges ==0)
			return;
		//cout<<"TESTING ADD EDGE "<<vertexIndex<<": ";
		edgeNode* traveler = new edgeNode();
		traveler->next = head;
			while (traveler->next) {
				cout<<"[ "<<traveler->next->e->weight<<" : ("<<traveler->next->e->v1->x<<", "<<traveler->next->e->v1->y<<") ("<<traveler->next->e->v2->x<<", "<<traveler->next->e->v2->y<<") : "<<traveler->next->e->v1->inTree<<" "<<traveler->next->e->v2->inTree<<"] \n";
				//cout<<traveler->next->e;
				traveler = traveler->next;
			}
		cout<<endl;
}

void tree::printResults() {
	if (numEdges ==0)
		return;
	//cout<<"TESTING ADD EDGE "<<vertexIndex<<": ";
	edgeNode* traveler = new edgeNode();
	traveler->next = head;
		while (traveler->next) {
			cout<<traveler->next->e->v1->vertexIndex<<" "<<traveler->next->e->v2->vertexIndex<<endl;
			traveler = traveler->next;
		}
	cout<<endl;
}

