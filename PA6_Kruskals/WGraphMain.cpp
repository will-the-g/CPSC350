#include "WGraph.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char** argv){
  // intializations
  string input = argv[1];
  string output = argv[2];
  fstream inputFile;
  fstream outputFile;
  string line;
  
  
  // Gets the number of nodes
  inputFile.open(input, ios::in);
  int nodes = 0;
  if (inputFile.is_open()){
    while(getline(inputFile, line)){
      nodes = stoi(line);
      break;
    }
  }
  inputFile.close();
  



  WGraph* myWG = new WGraph(nodes);
  // File IO
  int lineCount = 0;
  inputFile.open(input, ios::in);
  if (inputFile.is_open()){
    while(getline(inputFile, line)){
      // if its the end, then break the loop
      if (line == "END"){
        break;
      }
      // gets the number of nodes from the first line and makes a graph with that many nodes
      if (lineCount == 0){
        nodes = stoi(line);
        
      }else{

        int size = line.size();
        int start = 0;
        int nodeNumber = 0;
        // loops through the string to convert each weight to a number
        for (int pos = 0; pos < size; pos++){
          // if a space character is found, take the substring of the start to the space to get the number
          if (line.at(pos) == ' ' || line.at(pos) == '\r'){
            string num = line.substr(start, pos);
            // change start to end of substring + 1 
            start = pos + 1;
            // convert to int
            double weight = stod(num);
            nodeNumber++;

            // if the weight isn't 0, add the edge between the 2 nodes from lineCount (the row) to nodeNumber (the column) 
            if (weight != 0.0){
              //cout << "edge of weight " << weight << " added between " << lineCount - 1<< " and " << nodeNumber - 1<< endl;
              myWG->addEdge(lineCount - 1, nodeNumber - 1, weight);
            }
          }
        }
      }
      lineCount++;
    }
  }
  inputFile.close();


  // gets information for outputting
  double** MST = myWG->computeMST();
  int total = myWG->calcTotalWeight();

  // outputs to file
  outputFile.open(output, ios::out);
  outputFile << "The MST Cost is "<< total << endl;
  outputFile << std::setprecision(1) << std::fixed; // makes sure it's outputting as a double
  for (int i = 0; i < nodes; i++){
    for (int j = 0; j < nodes; j++){
      outputFile << MST[i][j] << " ";
    }
    outputFile << endl;
  }

  return 0;
}
