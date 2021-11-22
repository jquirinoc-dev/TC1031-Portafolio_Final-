#include "Graph.h"

Graph::Graph(int representa, std::istream& input) {
    if (representa == 1) {
      loadGraphList(input);
      representation = 1;
    }
    else {
      loadGraphMatrix(input);
      representation = 2;
    }
    visited.resize(numNodes+1);
}

Graph::~Graph() {
  if (representation == 1) {
    adjList.clear();
  }
  else {
    for (int i = 0; i < numNodes+1; i++) 
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
  visited.clear();
}

void Graph::loadGraphList(std::istream& input) {
    std::string line;
    int i = 0;
    while (std::getline(input, line)) {
      if (i == 0) {
        i++;
        continue;
      }
      if (i == 1) {
        std::vector<int> res;
        split(line, res);
        numNodes = res[0];
        numEdges = res[2];
        // Reservar memoria para la lista de adyacencia
        adjList.resize(numNodes+1);
        i++;
        continue; 
      }
      std::vector<int> res;
      split(line, res);
      int u = res[0];
      int v = res[1];
      // Grafos no dirigidos
      adjList[u].push_back(v);
      adjList[v].push_back(u);
      i++;
    }
}

void Graph::loadGraphMatrix(std::istream& input) {
    std::string line;
    int i = 0;
    while (std::getline(input, line)) {
      if (i == 0) {
        i++;
        continue;
      }
      if (i == 1) {
        std::vector<int> res;
        split(line, res);
        numNodes = res[0];
        numEdges = res[2];
        // Reserva memoria para los renglones de la matriz de adyacencia
        adjMatrix = new int*[numNodes+1];
        // Para cada renglon reserva memoria para las columnas de la matriz de adyacencia
        for (int j=0; j < numNodes+1; j++) {
          adjMatrix[j] = new int[numNodes+1];
	        for (int k = 0; k < numNodes+1; k++)
            adjMatrix[j][k] = 0;
        }
        i++;
        continue; 
      }
      std::vector<int> res;
      split(line, res);
      int u = res[0];
      int v = res[1];
      // Grafos no dirigidos
      adjMatrix[u][v] = 1;
      adjMatrix[v][u] = 1;
      i++;
    }
  }

void Graph::split(std::string line, std::vector<int> & res) {
    size_t strPos = line.find(" ");
    size_t lastPos = 0;
    while (strPos != std::string::npos) {
      res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
      lastPos = strPos + 1;
      strPos = line.find(" ", lastPos);
    }
    res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

void Graph::printAdjList(){
	  std::cout << "Adjacency List" << std::endl;
		for (int i = 1; i <= numNodes; i++){
	        std::cout << "vertex " << i << ": ";
	        for (int j = 0; j < (int)adjList[i].size(); j ++){
							 std::cout << " " << adjList[i][j];
					}
	        std::cout << std::endl;
    }
}

void Graph::printAdjMatrix(){
    std::cout << "Adjacency Matrix" << std::endl;
		for (int i = 1; i < numNodes+1; i++){
	    for (int j = 1; j < numNodes+1; j++) {
        std::cout << adjMatrix[i][j] << " ";
			}
	    std::cout << std::endl;
    }
}

void Graph::printGraph() {
  if (representation == 1)
    printAdjList();
  else
    printAdjMatrix();
}

void Graph::explore(int v) {
  visited[v] = true;
  std::cout << v << " ";
  // Lista de adyacencia
  if (representation == 1) {
    // Recorrer nodos adyacente a v
    for (int j = 0; j < (int)adjList[v].size(); j ++) {
      int u = adjList[v][j];
      if (!visited[u])
        explore(u);
		}
  }
  else { // Matriz de adyacencia
    // Recorrer nodos adyacentes a v
    for (int j = 1; j < numNodes+1; j++) {
      int c = adjMatrix[v][j];
      if (c != 0) {
        if (!visited[j])
          explore(j);
			}
    }
  }
}

void Graph::DFS(int v) {
  int i;
  for (i = 0; i < numNodes+1; i++)
    visited[i] = false;
  std::cout << "Recorrido DFS " << std::endl;
  visited[v] = true;
  explore(v);
  for (i = 1; i < numNodes+1; i++) {
    if (!visited[i])
      explore(i);
  }
  std::cout << std::endl;
}