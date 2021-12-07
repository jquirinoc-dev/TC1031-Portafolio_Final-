#ifndef __GRAPH_H_
#define __GRAPH_H_
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include "ipAddress.h"
#include "MaxHeap.h"

class Graph {
  private:
    int numNodes;
    int numEdges;
    std::vector<ipAddress> ipVector;
    // Lista de adyacencia (vector de vectores)
    std::vector<std::vector<int>> adjList;



    void swap(ipAddress& a, ipAddress& b);
    void swapPair(std::pair<ipAddress, ipAddress>& a, std::pair<ipAddress, ipAddress>& b);
    int partition(std::vector<ipAddress> &arr, int low, int high);
    int partitionPair(std::vector<std::pair<ipAddress, ipAddress>> &lineas, int low, int high);
    void quickSort(std::vector<ipAddress> &arr, int low, int high);
    void quickSortPair(std::vector<std::pair<ipAddress, ipAddress>> &lineas, int low, int high);
    int binarySearch(std::vector<ipAddress> vectorLogs, int n, ipAddress k);
    std::pair<std::string, std::string> readEnd(std::ifstream fileName);

    int loadGraphList(std::string fileName);
    void split(std::string line, std::vector<int> & res);
    void splitString(std::string line, std::vector<std::string> & res);
    void printAdjList();


  
  public:
    Graph(std::string fileName);
    ~Graph();
    void printGraph();

};

#endif