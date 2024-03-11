#include "WGraph.h"

WGraph::WGraph(){
  m_size = 0;
  m_adj = NULL;
  m_conn = NULL;
}

WGraph::WGraph(unsigned int sz){
  m_size = sz;
  //allocate sz * sz adj matrix
  m_adj = new double*[sz];
  m_conn = new double*[sz];
  for(int i = 0; i < m_size; ++i){
    m_adj[i] = new double[sz];
    m_conn[i] = new double[sz];
  }
  //start with edges
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_adj[i][j] = std::numeric_limits<double>::max();
      m_conn[i][j] = std::numeric_limits<double>::max();  
    }
  }
  recalcFW = false;
}

WGraph::~WGraph(){
  // release memory - let's actually do it in class for once
  for (int i = 0; i < m_size; ++ i){
    delete m_adj[i];
    delete m_conn[i];
  }
  delete[] m_adj;
  delete[] m_conn;
}

void WGraph::addEdge(VertexID i, VertexID j, double w){
  if(i < m_size && j < m_size){
    m_adj[i][j] = w;  
    m_adj[j][i] = w;
  }
  // calcFW(); // not very efficient since we'd have to re-calculate it every time we add or remove an edge
  recalcFW = true;
}

void WGraph::removeEdge(VertexID i, VertexID j){
  if(i < m_size && j < m_size){
    m_adj[i][j] = std::numeric_limits<double>::max();
    m_adj[j][i] = std::numeric_limits<double>::max();
  }
  // calcFW(); // not very efficient since we'd have to re-calculate it every time we add or remove an edge
  recalcFW = true;
}

bool WGraph::areAdjacent(VertexID i, VertexID j){
  return (m_adj[i][j] < std::numeric_limits<double>::max());
}

void WGraph::calcFW(){
  // set the conn matrix equal to adj matrix 
  for (int i = 0; i < m_size; ++i){
    for (int j = 0; j < m_size; ++j){
      m_conn[i][j] = m_adj[i][j];
    }
  }

  // start FW
  for (int im = 0; im < m_size; ++im){ // intermediate points 
    for (int source = 0; source < m_size; ++source){ // source -> starting point
      for (int sink = 0; sink < m_size; ++sink){ // sink -> ending point 
        if (source == sink){
          continue;
        } else if ( m_conn[source][im] != std::numeric_limits<double>::max() &&
                    m_conn[im][sink] != std::numeric_limits<double>::max() &&
                    m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){
                  
                   m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];

        }
      }
    }
  }
	recalcFW = false;
}

double WGraph::cheapestCost(VertexID i, VertexID j){
  if (recalcFW){
    calcFW();
  }
  return m_conn[i][j]; 
}

double** WGraph::computeMST(){
  int count = 0;
  int node1 = -1;
  int node2 = -1;
  // intialize an array of false booleans for visited nodes.
  bool* visitedNodes = new bool[m_size];
  for (int i = 0; i < m_size; i++){
    visitedNodes[i] = false;
  }

  // creates MST adjecency matrix
  this->adjMatrixMST = new double*[m_size];
  for (int i = 0; i < m_size; i++){
    adjMatrixMST[i] = new double[m_size];
  }
  // Populates the matrix with zeroes
  for (int i = 0; i < m_size; i++){
    for (int j = 0; j < m_size; j++){
      adjMatrixMST[i][j] = 0.0;
    }
  }
  // while loop to find least edges
  while(true){
    double leastEdge = 99999.0;

    // checks if all nodes have been visited (Break condition)
    int visitCount = 0;
    for (int i = 0; i < m_size; i++){
      if (visitedNodes[i] == true){
        visitCount++;
      }
    }
    if (visitCount == m_size){
      break;
    }

    // finds the least edge in the adjecency where both nodes haven't been visited yet
    for (int i = 0; i < m_size; i++){
      for (int j = i + 1; j < m_size; j++){ // since it's undirected, you can start at the diagonal + 1, since it will symmetrical
        if ((m_adj[i][j] < leastEdge && m_adj[i][j] != 0) && (visitedNodes[i] == false || visitedNodes[j] == false)){
          leastEdge = m_adj[i][j];
          node1 = i;
          node2 = j;
        }
      }
    }
    // once the least edge is found, put it in the MST matrix and update the visited nodes to true.
    adjMatrixMST[node1][node2] = leastEdge;
    adjMatrixMST[node2][node1] = leastEdge;
    visitedNodes[node1] = true;
    visitedNodes[node2] = true;
  }
  return adjMatrixMST;



}



int WGraph::calcTotalWeight(){
  int total = 0;
  for (int i = 0; i < m_size; i++){
    for (int j = i; j < m_size; j++){
      total += adjMatrixMST[i][j];
    }
  }
  return total;
}