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
		edges = new edge*[numEdges+1];
}

void System::setupVertices(int n){
	numVertices = n;
	vertices = new vertex*[numVertices+1];
}

int System::getPartitionIndex(int leftIndex, int rightIndex) {
	int medianIndex = leftIndex+((int)(rightIndex-leftIndex)/2);
	return medianIndex;
}

void System::swapEdges(int index1, int index2) {
	//cout<<"swapping "<<index1<<" "<<index2<<endl;
	edge* hold = edges[index1];
	edges[index1]=edges[index2];
	edges[index2]=hold;
}

int System::partitionEdges(int leftIndex, int rightIndex, int pivotIndex){
	//cout<<"calledpartition\n";
	double pivotValue = edges[pivotIndex]->weight;
	swapEdges(pivotIndex, rightIndex);
	int swappingIndex = leftIndex;
	//cout<<"partitionLoop\n";
	for (int i=leftIndex; i<rightIndex; i++) {
		//cout<<"inPartitionLoop "<<i<<endl;
		//cout<<edges[i]->weight<<endl;
		if (edges[i]->weight <= pivotValue) {
			swapEdges(i, swappingIndex);
			swappingIndex++;
		}
	}
	swapEdges(swappingIndex, rightIndex);
	//cout<<"endpartition\n";
	return swappingIndex;
}

void System::quicksortEdges(int leftIndex, int rightIndex) {
	//cout<<"calledQuicksort "<<leftIndex<<" "<<rightIndex<<" "<<numEdges<<"\n";
	if (leftIndex < rightIndex) {
		//cout<<"quicksort1\n";
		int pivotIndex = getPartitionIndex(leftIndex, rightIndex);
		//cout<<"quicksort2\n";
		int newPivotIndex = partitionEdges(leftIndex, rightIndex, pivotIndex);
		//cout<<"quicksort3\n";
		quicksortEdges(leftIndex, newPivotIndex-1);
		//cout<<"lefted\n";
		quicksortEdges(newPivotIndex+1, rightIndex);
		//cout<<"righted\n";
	}
}

bool System::checkEdge(edge* e) {
}

void System::sortEdges() { 
	quicksortEdges(0, numEdges-1);
}

//void System::primTree() {
	//reference to tree of some kind
	//get smallest edge
	//check all connectable nodes, find the smallest edged one with one vertex in tree and one not in tree
	//end when ended
//}

//void System::

void System::printEdges() {
	cout<<"EDGES: "<<numEdges<<endl;
	for (int i = 0; i<edgeCount; i++)
		cout<<vertices[edges[i]->v1->vertexIndex]->vertexIndex<<"-"<<vertices[edges[i]->v2->vertexIndex]->vertexIndex<<" ("<<vertices[edges[i]->v1->vertexIndex]->x<<", "<<vertices[edges[i]->v1->vertexIndex]->y<<") ("<<vertices[edges[i]->v2->vertexIndex]->x<<", "<<vertices[edges[i]->v2->vertexIndex]->y<<") : "<<edges[i]->weight<<endl;
}

void System::printVertices() {
	cout<<"VERTICES"<<endl;
	for (int i = 1; i<vertexCount;i++) {
		cout<<vertices[i]->x<<" "<<vertices[i]->y<<endl;
		vertices[i]->printVertex();
		}
}

void System::addEdge(int a, int b) {
	//cout<<"ad ding edge "<<a<<" "<<b<<endl;
	edge* newEdge = new edge();
	newEdge->v1 = vertices[a];
	newEdge->v2 = vertices[b];
	//cout<<a<<" "<<b<<" "<<numVertices<<endl;
	double x1=vertices[a]->x;
	double y1=vertices[a]->y;
	double x2=vertices[b]->x;
	double y2=vertices[b]->y;
	newEdge->weight = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
	edges[edgeCount]=newEdge;
	vertices[a]->addEdge(newEdge);
	vertices[b]->addEdge(newEdge);
	//cout<<"TESTING ADD EDGE: ";
	edgeCount++;
}

void System::addVertex(double x, double y) {
	//cout<<"adding vertex "<<x<<" "<<y<<endl;
	vertex* newVertex = new vertex();
	//cout<<"here1\n";	
	newVertex->vertexIndex = vertexCount;
	//cout<<"here2\n";	
	newVertex->x = x;
	//cout<<"here3\n";
	newVertex->y = y;
	//cout<<"here4\n";
	vertices[vertexCount]=newVertex;
	//cout<<"here5\n";
	vertexCount++;
}

void System::sortVertices() {

}