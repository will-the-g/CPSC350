#ifndef WGraph_H
#define WGraph_H

#include <cstdlib>
#include <deque>
#include <set>
#include <stack>
#include <iostream>
#include <limits> // allows us to get min and max
#include <iomanip>
using namespace std;

//a weighted, undirected WGraph implemented with adjacency matrix
//fixed size

typedef unsigned int VertexID;

class WGraph{
public: 
  WGraph();
  WGraph(unsigned int sz);
  ~WGraph();
  void addEdge(VertexID i, VertexID j, double w); // now includes a double for the weight of the edge
  void removeEdge(VertexID i, VertexID j);
  bool areAdjacent(VertexID i, VertexID j);
  double cheapestCost(VertexID i, VertexID j); // will give us the cheapest path between two vertices
  void calcFW(); // will calculate the Floyd-Warshall algo and create a connectivity matrix that gives us the shortest path from every node to every other node
  double** computeMST(); 
  int calcTotalWeight();

private:
  double** m_adj; // Adjacency matrix: is there an edge between two vertices and what's the weight of the edge
  double** m_conn; // Connectivity matrix: more general, is there a path between a start and a finish and what's the cost (all parts summed)
  unsigned int m_size; // number of nodes in WGraph (fixed) 
  bool recalcFW;
  double** adjMatrixMST;

};

#endif