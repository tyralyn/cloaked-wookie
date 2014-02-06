#include<iostream>
#include<sstream>
#include<string>
#include <stdlib.h>
#include "System.h"

#define MAX_SIZE 500000

using namespace std;

void parseEdges (string query, System* s)
{
  istringstream iss(query);
  string token[1000];
  int i, numTokens;
  i=0; numTokens=0;
  do {
    iss >> token[i];
    i++;
    numTokens++;
  } while (iss);
  double value;
  const char * ptr;
  if (numTokens>1) {
    string k=token[1];
    value=atoi(k.c_str());
  }
  int x = atoi(token[0].c_str());
  int y = atoi(token[1].c_str());
  s->addEdge(x,y);
}

void parseVertices (string query, System* s)
{
  istringstream iss(query);
  string token[1000];
  int i, numTokens;
  i=0; numTokens=0;
  do {
    iss >> token[i];
    i++;
    numTokens++;
  } while (iss);
  double value;
  const char * ptr;
  if (numTokens>1) {
    string k=token[1];
    value=atof(k.c_str());
  }
  double x = atof(token[0].c_str());
  double y = atof(token[1].c_str());
  s->addVertex(x,y);
}

int main() {
  string line;
  getline(cin, line);
  System* mySystem = new System();
  int numvertices = atoi(line.c_str());
  mySystem->setupVertices(numvertices);
  for (int i=0; i<numvertices; i++) {
    getline(cin, line);
    parseVertices(line, mySystem);
  }
  
  mySystem->printVertices();
  
  getline(cin, line);
  int numedges = atoi(line.c_str());
  mySystem->setupEdges(numedges);
  if (numedges!=0) {
	for (int i=0; i<numedges; i++) {
		getline(cin, line);
		parseEdges(line, mySystem);
	}
  }	

  mySystem->printEdges();
  mySystem->sortEdges();
  mySystem->printEdges();
	
}


