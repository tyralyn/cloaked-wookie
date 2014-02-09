#include "ItemType.h"

using namespace std;

class tree {
	private:
		//edge** edges;
		int numEdges;
		int edgeCount;
	public:
		tree(int n);
		~tree();
		void setup(edge* e);
		void printTree();
		void printResults();
		void addEdge(edge* e);
		void getMinEdge(const edge* current, edge* min);
		edge* getNextEdge(edge* e);
		edge** getTree() {return edges;};
		edge** edges;
		int getPartitionIndex(int leftIndex, int rightIndex);
		void swap(int index1, int index2);
		int partitionX(int leftIndex, int rightIndex, int pivotIndex);
		void quicksortX(int leftIndex, int rightIndex);
		int partitionY(int leftIndex, int rightIndex, int pivotIndex);
		void quicksortY(int leftIndex, int rightIndex);
		void sortTree() { quicksortX(0, edgeCount-1); sortY();};
		void sortY();
};














//#endif