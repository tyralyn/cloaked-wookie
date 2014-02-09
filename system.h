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
	void swapEdges(int index1, int index2);
	int partitionEdges(int leftIndex, int rightIndex, int pivotIndex);
	void quicksortEdges(int leftIndex, int rightIndex);
	void sortEdges();
	bool checkEdge(edge* e);
	bool checkVertices();
	void printTree();
	void printVertexStatus();
private:
	edge** edges;
	vertex** vertices;
	tree* t;
	int traveler;
	int edgeCount;
	int vertexCount;
	int numEdges; 
	int numVertices;
};