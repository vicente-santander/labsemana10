#include <iostream>
#include <vector>
using namespace std;

class grafo {
	
	public:
		
		void addEdge(vector<vector<int>>& graph, int u, int v) {
			graph[u][v] = 1;
			graph[v][u] = 1;
		}

		void printGraph(const vector<vector<int>>& graph) {
			cout << "Adjacency Matrix:\n";
			for (const auto& row : graph) {
				for (int val : row) {
					cout << val << " ";
				}
			cout << '\n';
			}
		}
		
		bool areAdjacent(const vector<vector<int>>& graph, int u, int v) {
		    return graph[u][v] == 1 && graph[v][u] == 1;
		}
		
};

class grafoDirigido {
	
	public:
		
		void addEdge2(vector<vector<int>>& graph, int u, int v) {
			graph[u][v] = 1;
			
		}

		void printGraph(const vector<vector<int>>& graph) {
			cout << "Adjacency Matrix:\n";
			for (const auto& row : graph) {
				for (int val : row) {
					cout << val << " ";
				}
			cout << '\n';
			}
		}
		
		bool areAdjacent(const vector<vector<int>>& graph, int u, int v) {
		    return graph[u][v] == 1;
		}
		
	


};


int main(){
	vector<vector<int>> graph(8, vector<int>(8, 0));
	
	grafo graf;
		
	graf.addEdge(graph,0,1);
	graf.addEdge(graph,0,2);
	graf.addEdge(graph,1,3);
	graf.addEdge(graph,1,4);
	graf.addEdge(graph,1,5);
	graf.addEdge(graph,2,3);
	graf.addEdge(graph,2,5);
	graf.addEdge(graph,2,6);
	graf.addEdge(graph,3,4);
	graf.addEdge(graph,4,5);
	graf.addEdge(graph,4,7);
	graf.addEdge(graph,5,6);
	graf.addEdge(graph,5,7);
	graf.addEdge(graph,6,7);
	
	graf.printGraph(graph);
	
	int vertex1 = 2;
    int vertex2 = 3;

    if (graf.areAdjacent(graph, vertex1, vertex2)) {
        cout << "Los vertices " << vertex1 << " y " << vertex2 << " son adyacentes.\n";
    } else {
        cout << "Los vertices " << vertex1 << " y " << vertex2 << " no son adyacentes.\n";
    }
    cout << endl;
    //---------------------------------------------------------------------------------------
    
    vector<vector<int>> graph2(8, vector<int>(8, 0));
    
    grafoDirigido graf2;

    graf2.addEdge2(graph2, 0, 1);
    graf2.addEdge2(graph2, 0, 2);
    graf2.addEdge2(graph2, 1, 3);
    graf2.addEdge2(graph2, 1, 4);
    graf2.addEdge2(graph2, 1, 5);
    graf2.addEdge2(graph2, 2, 3);
    graf2.addEdge2(graph2, 2, 5);
    graf2.addEdge2(graph2, 2, 6);
    graf2.addEdge2(graph2, 3, 4);
    graf2.addEdge2(graph2, 4, 5);
    graf2.addEdge2(graph2, 4, 7);
    graf2.addEdge2(graph2, 5, 6);
    graf2.addEdge2(graph2, 5, 7);
    graf2.addEdge2(graph2, 6, 7);
    
    // Agregar una arista dirigida que crea un ciclo desde el vértice 7 al vértice 2
    graf2.addEdge2(graph2, 6, 2);
    
    // Agregar una arista dirigida hacia el vértice 7 (que no puede ser alcanzado desde otros vértices)
    graf2.addEdge2(graph2, 7, 7);
    
    graf2.printGraph(graph2);
    
	
	return 0;
}
