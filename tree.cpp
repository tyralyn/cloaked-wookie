#include "tree.h"

tree::tree(int n) {
	numEdges = n-1;
	edgeCount = 0;
	edges = new edge*[numEdges];
}

tree::~tree() {
	for (int i = 0; i<numEdges-1; i++)
		delete edges[i];
}

void tree::addEdge(edge* e) {
	edges[edgeCount]=e;
	e->v1->inTree = true;//!e->v1->inTree;
	e->v2->inTree = true;//!e->v2->inTree;
	edgeCount++;
}

void tree::printTree() {
	cout<<"printing tree: "<<numEdges<<endl;
		for (int i = 0; i<edgeCount; i++) {
			cout<<"[ "<<edges[i]->weight<<" : ("<<edges[i]->v1->x<<", "<<edges[i]->v1->y<<") ("<<edges[i]->v2->x<<", "<<edges[i]->v2->y<<") : "<<edges[i]->v1->inTree<<" "<<edges[i]->v2->inTree<<"] \n";
			}
	cout<<endl;
}

void tree::printResults() {
	for (int i = 0; i<edgeCount; i++) {
			cout<<edges[i]->v1->vertexIndex<<" "<<edges[i]->v2->vertexIndex<<endl;
	}
	cout<<endl;
}

int tree::getPartitionIndex(int leftIndex, int rightIndex) {
	int medianIndex = leftIndex+((int)(rightIndex-leftIndex)/2);
	return medianIndex;
}

void tree::swap(int index1, int index2) {
	edge* hold = edges[index1];
	edges[index1]=edges[index2];
	edges[index2]=hold;
}

int tree::partitionX(int leftIndex, int rightIndex, int pivotIndex){
	double pivotValue = edges[pivotIndex]->v1->vertexIndex;
	//cout<<pivotValue<<endl;
	swap(pivotIndex, rightIndex);
	int swappingIndex = leftIndex;
	for (int i=leftIndex; i<rightIndex; i++) {
		if (edges[i]->v1->vertexIndex <= pivotValue) {
			swap(i, swappingIndex);
			swappingIndex++;
		}
	}
	swap(swappingIndex, rightIndex);
	return swappingIndex;
}

void tree::quicksortX(int leftIndex, int rightIndex) {
	if (leftIndex < rightIndex) {
		int pivotIndex = getPartitionIndex(leftIndex, rightIndex);
		int newPivotIndex = partitionX(leftIndex, rightIndex, pivotIndex);
		quicksortX(leftIndex, newPivotIndex-1);
		quicksortX(newPivotIndex+1, rightIndex);
	}
}

int tree::partitionY(int leftIndex, int rightIndex, int pivotIndex){
	double pivotValue = edges[pivotIndex]->v2->vertexIndex;
	//cout<<pivotValue<<endl;
	swap(pivotIndex, rightIndex);
	int swappingIndex = leftIndex;
	for (int i=leftIndex; i<rightIndex; i++) {
		if (edges[i]->v2->vertexIndex <= pivotValue) {
			swap(i, swappingIndex);
			swappingIndex++;
		}
	}
	swap(swappingIndex, rightIndex);
	return swappingIndex;
}

void tree::quicksortY(int leftIndex, int rightIndex) {
	if (leftIndex < rightIndex) {
		int pivotIndex = getPartitionIndex(leftIndex, rightIndex);
		int newPivotIndex = partitionY(leftIndex, rightIndex, pivotIndex);
		quicksortY(leftIndex, newPivotIndex-1);
		quicksortY(newPivotIndex+1, rightIndex);
	}
}

void tree::sortY() {
	int a(0), b(0), val(0);
	for (int i = 0; i<edgeCount; i++) {
		if (edges[i]->v1->vertexIndex != val) {
			quicksortY(a,b);
			val = edges[i]->v1->vertexIndex;
			a = i;
			b=i; 
		}
		else {
			b++;
		}
	}
}
