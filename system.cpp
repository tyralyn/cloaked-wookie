#include "System.h"

System::System() {
	numEdges = 0;
	numVertices = 0;
	edgeCount = 0;
	vertexCount = 1;
}

System::~System() {

}

void System::setupEdges(int n) {
	numEdges =  n;
	if (numEdges==0){
		int newNumEdges = 0;
		for (int i = 1; i<=numVertices; i++) {
			for (int j=i+1; j<=numVertices; j++) {
				newNumEdges++;
			}
		}
		edges = new edge*[newNumEdges+1];
		numEdges =  newNumEdges;
		for (int i = 1; i<=numVertices; i++) {
			for (int j=i+1; j<=numVertices; j++) {
				addEdge(i,j);
			}
		}
	}
	else 
		edges = new edge*[numEdges];
	t = new tree(numEdges);
}

void System::setupVertices(int n){
	numVertices = n;
	vertices = new vertex*[numVertices+1];
}

int System::getPartitionIndex(int leftIndex, int rightIndex) {
	int medianIndex = leftIndex+((int)(rightIndex-leftIndex)/2);
	return medianIndex;
}

void System::swap(int index1, int index2, edge** e) {
	edge* hold = e[index1];
	e[index1]=e[index2];
	e[index2]=hold;
}

int System::partition(int leftIndex, int rightIndex, int pivotIndex, edge** e){
	double pivotValue = e[pivotIndex]->weight;
	//cout<<pivotValue<<endl;
	swap(pivotIndex, rightIndex, e);
	int swappingIndex = leftIndex;
	for (int i=leftIndex; i<rightIndex; i++) {
		if (e[i]->weight <= pivotValue) {
			swap(i, swappingIndex, e);
			swappingIndex++;
		}
	}
	swap(swappingIndex, rightIndex, e);
	return swappingIndex;
}

void System::quicksort(int leftIndex, int rightIndex, edge** e) {
	if (leftIndex < rightIndex) {
		int pivotIndex = getPartitionIndex(leftIndex, rightIndex);
		int newPivotIndex = partition(leftIndex, rightIndex, pivotIndex, e);
		quicksort(leftIndex, newPivotIndex-1, e);
		quicksort(newPivotIndex+1, rightIndex, e);
	}
}

void System::sortEdges() { 
	quicksort(0, numEdges-1, edges);
}

void System::sortResults() {
	t->sortTree();
}

bool System::checkVertices() {
	for (int i =1; i<numVertices+1; i++) {
		if (vertices[i]->inTree==false)
			return false;
	}
	return true;
}

void System::printVertexStatus() {
	cout<<"VERTEX STATUS: ";
	for (int i = 1; i<numVertices+1; i++) {
		cout<<i<<": "<<vertices[i]->inTree<<"; ";
	}
	cout<<"\n";
}

void System::primTree() {
	edgeCount = 0;
	t->addEdge(edges[0]);
	for (int i = 0; i < numEdges; i++) {
		if (checkVertices())
			return;
		if (edges[i]->v1->inTree && edges[i]->v2->inTree || !edges[i]->v1->inTree && !edges[i]->v2->inTree) {
			continue;
		}
		
		t->addEdge(edges[i]);
	}
}

void System::printTree() {
	sortResults();
	t->printTree();
}

void System::printResults() {
	//sortResults();
	t->printResults();
}

void System::printEdges() {
	cout<<"EDGES: "<<numEdges<<endl;
	for (int i = 0; i<edgeCount; i++)
		cout<<vertices[edges[i]->v1->vertexIndex]->vertexIndex<<"-"<<vertices[edges[i]->v2->vertexIndex]->vertexIndex<<" ("<<vertices[edges[i]->v1->vertexIndex]->x<<", "<<vertices[edges[i]->v1->vertexIndex]->y<<") ("<<vertices[edges[i]->v2->vertexIndex]->x<<", "<<vertices[edges[i]->v2->vertexIndex]->y<<") : "<<edges[i]->weight<<endl;
}

void System::printVertices() {
	cout<<"VERTICES"<<endl;
	for (int i = 1; i<vertexCount;i++) {
		cout<<vertices[i]->x<<" "<<vertices[i]->y<<endl;
		//vertices[i]->printVertex();
		}
}

void System::addEdge(int A, int B) {
	//cout<<"ad ding edge "<<a<<" "<<b<<endl;
	int a = (A<B) ? A : B;
	int b = (A<B) ? B : A;
	edge* newEdge = new edge();
	newEdge->v1 = vertices[a];
	newEdge->v2 = vertices[b];
	double x1=vertices[a]->x;
	double y1=vertices[a]->y;
	double x2=vertices[b]->x;
	double y2=vertices[b]->y;
	newEdge->weight = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
	edges[edgeCount]=newEdge;
	edgeCount++;
}

void System::addVertex(double x, double y) {
	vertex* newVertex = new vertex();
	newVertex->vertexIndex = vertexCount;
	newVertex->x = x;
	newVertex->y = y;
	vertices[vertexCount]=newVertex;
	vertexCount++;
}

void System::sortVertices() {

}