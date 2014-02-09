#include "ItemType.h"

using namespace std;

class tree {
	private:
		edgeNode* head;
		edgeNode* tail;
		int numEdges;
	public:
		tree();
		~tree();
		void setup(edge* e);
		void printTree();
		void printResults();
		void addEdge(edge* e);
		void getMinEdge(const edge* current, edge* min);
		edge* getNextEdge(edge* e);
};














//#endif