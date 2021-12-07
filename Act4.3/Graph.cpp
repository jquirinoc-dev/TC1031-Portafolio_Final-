#include "Graph.h"

Graph::Graph(std::string fileName) {  
  loadGraphList(fileName);      
}

Graph::~Graph() {
  adjList.clear();
  ipVector.clear();
}

int Graph::loadGraphList(std::string fileName) {
    std::ifstream inputFile;
    std::string line;
    std::pair<ipAddress, ipAddress> tmpPair;
    std::vector<std::pair<ipAddress, ipAddress>> lineas;
    std::string ipaOrig, ipaDest;
    int i = 0;
    std::cout << "fileName: " << fileName << std::endl;
    
    inputFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
      inputFile.open(fileName);
    }
    catch(std::ifstream::failure e) {
      std::cout << "Error: no se pudo abrir el archivo con ese nombre." << std::endl;
      return 0;
    }
    while (!inputFile.eof()) {
        getline(inputFile, line);
        if (i == 0){
          std::cout << "line0: " << line << std::endl;
          std::vector<int> res;
          split(line, res);
          numNodes = res[0];
          numEdges = res[1];
          // Reservar memoria para la lista de adyacencia
          adjList.resize(numNodes+1);
        }
        else if (i > 0 && i <= numNodes) { // lee nodos
          ipAddress tmpIpAd(line + ":0000");
          ipVector.push_back(tmpIpAd);
        }
        else {  // lee aristas
          // 1. Extraer cada ip de la linea (son dos, IPorigen e IPdestino)
          std::vector<std::string> res;
          splitString(line, res);

          ipaOrig = res[3] + ":0000";
          ipaDest = res[4] + ":0000";

          ipAddress ip1(ipaOrig);
          ipAddress ip2(ipaDest);
          // 2. Crear un par(pair) temporal con (IPorigen, IPdestino)
          tmpPair.first = ip1;
          tmpPair.second = ip2;
          // 3. hacer push_back del par temporal en vector lineas
          lineas.push_back(tmpPair);

        }
        i++;
    }
    inputFile.close(); 
    // 1. Ordenamos las ip para buscar con binary search rapidamente

    quickSort(ipVector, 0, ipVector.size() - 1);
    
    std::cout << "\nPasó el ipVector quickSort\n";

    quickSortPair(lineas, 0, lineas.size() - 1);
    std::cout << "\nPasó el lineas quickSort\n";

    //2. Para cada elemento en el vector lineas
    // 2.a Buscar con binary search la ipOrigen, eso es u
    // 2.b Buscar con binary search la ipDestino, eso es v

    int u, v;

    ipAddress tempIp = lineas[0].first;

    u = binarySearch(ipVector, ipVector.size(), lineas[0].first);
    
    int counter = 0; 
    for (int i = 0; i < lineas.size(); i++) {

      if (lineas[i].first != tempIp){
        u = binarySearch(ipVector, ipVector.size(), lineas[i].first);
        tempIp = lineas[i].first; 
      } 
      
      v = binarySearch(ipVector, ipVector.size(), lineas[i].second);

      adjList[u].push_back(v);
      ipVector[u].addToDegree(); 
  
    }
    
    // Ejemplo con linea 1: 36.29.138.97 (posicion 8 en vector ordenado) 5.30.79.115 (posicion 4 en vector ordenado)

    MaxHeap<ipAddress> myMaxHeap(13371);

    for (int i = 0; i < ipVector.size(); i++){
      myMaxHeap.push(ipVector[i]);
    }

    myMaxHeap.writeToNewTxt("grados_ips.txt", 0, myMaxHeap.getSize() - 1);
    
    myMaxHeap.writeFive("mayores_grados_ips.txt");

  
    return 1;
}

int Graph::binarySearch(std::vector<ipAddress> vectorLogs, int n, ipAddress k) {
  int low = 0;
  int high = n - 1;

  while (low <= high) {
    int m = low + (high - low) / 2;

    if (k.getNumericIp() == vectorLogs[m].getNumericIp()){
        return m;
    }else if (k.getNumericIp() < vectorLogs[m].getNumericIp()) {
        high = m - 1;
    }else {
        low = m + 1;
    }
      
  }
  return -1;
}

void Graph::swap(ipAddress& a, ipAddress& b){
    ipAddress t = a;
    a = b;
    b = t;
}

int Graph::partition(std::vector<ipAddress> &arr, int low, int high){
    
    ipAddress pivot = arr[high];
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++){

        ipAddress ipIndx = arr[j];

        if (ipIndx <= pivot){
            i++;    
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void Graph::quickSort(std::vector<ipAddress> &arr, int low, int high){
    if (low < high){

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void Graph::swapPair(std::pair<ipAddress, ipAddress>& a, std::pair<ipAddress, ipAddress>& b){
    std::pair<ipAddress, ipAddress> t = a;
    a = b;
    b = t;
}

int Graph::partitionPair(std::vector<std::pair<ipAddress, ipAddress>>& lineas, int low, int high){
    
    ipAddress pivot = lineas[high].first;
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++){

        ipAddress ipIndx = lineas[j].first;

        if (ipIndx <= pivot){
            i++;    
            swapPair(lineas[i], lineas[j]);
        }
    }
    swapPair(lineas[i + 1], lineas[high]);
    return (i + 1);
}

void Graph::quickSortPair(std::vector<std::pair<ipAddress, ipAddress>>& lineas, int low, int high){
    if (low < high){

        int pi = partitionPair(lineas, low, high);

        quickSortPair(lineas, low, pi - 1);
        quickSortPair(lineas, pi + 1, high);
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

void Graph::splitString(std::string line, std::vector<std::string> & res) {
    size_t strPos = line.find(" ");
    size_t lastPos = 0;
    while (strPos != std::string::npos) {
      res.push_back(line.substr(lastPos, strPos - lastPos));
      lastPos = strPos + 1;
      strPos = line.find(" ", lastPos);
    }
    res.push_back(line.substr(lastPos, line.size() - lastPos));
}

void Graph::printGraph(){
	  std::cout << "Adjacency List" << std::endl;
		for (int i = 0; i < numNodes; i++){
	        std::cout << "vertex " << i << ": ";
	        for (int j = 0; j < (int)adjList[i].size(); j ++){
							 std::cout << " " << adjList[i][j];
					}
	        std::cout << std::endl;
    }
}

