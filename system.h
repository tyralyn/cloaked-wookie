#include "ItemType.h"
#include "tree.h"

class System{ 
public:
	System();
	~System();
	void setupEdges(int n);
	void setupVertices(int n);
	void printEdges();
	void printVertices();
	void addEdge(int a, int b);
	void addVertex(double x, double y);
	void sortVertices();
	void primTree();
	int getPartitionIndex(int leftIndex, int rightIndex);
	void swap(int index1, int index2, edge** e);
	int partition(int leftIndex, int rightIndex, int pivotIndex, edge** e);
	void quicksort(int leftIndex, int rightIndex, edge** e);
	void sortEdges();
	bool checkEdge(edge* e);
	bool checkVertices();
	void printTree();
	void printResults();
	void sortResults();
	void printVertexStatus();
private:
	edge** edges;
	vertex** vertices;
	tree* t;
	edgeNode** t2;
	int traveler;
	int edgeCount;
	int vertexCount;
	int numEdges; 
	int numVertices;
};