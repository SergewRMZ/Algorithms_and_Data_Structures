/**
 * DFS: Depth First Search. 
 * Ejercicio del laberinto resuelto.
 * (Algorithms in a Nutshell)
 * Buscar todas las rutas que nos llevan al punto final
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    public: 
    int V;
    vector<vector<int>> adyacentList; 
    Graph(int vertex) : V(vertex), adyacentList(vertex) {}

    void addEdge(int v, int w) {
        adyacentList[v].push_back(w);
        adyacentList[w].push_back(v);
    }

    void DFS(int currentNode, int end, vector<int> &path, vector<vector<int>> &allPaths, vector<bool> &visit) {
        path.push_back(currentNode);
        visit[currentNode] = true;

        if (currentNode == end) {
            allPaths.push_back(path);
        } else {
            for (int neighbor : adyacentList[currentNode]) {
                if (!visit[neighbor]) {
                    DFS(neighbor, end, path, allPaths, visit);
                }
            }
        }

        visit[currentNode] = false;
        path.pop_back();
    }
};

void showGraph (Graph &g) {
    cout << "Rutas Encontradas: ";
    for (int i = 0; i < g.V; i++) {
        cout << "Nodo " << i << ": ";
        for (int neighbor : g.adyacentList[i]) {
            cout << neighbor << " ";
        }

        cout << endl;
    }
}

void showPaths (const vector<vector<int>> &allPaths) {

    // const auto: Declarar variable donde su tipo se autoinfiere
    for (const auto &path : allPaths) {
        for (int node : path) {
            cout << node << " ";
        }

        cout << endl;
    }
}

// EL punto inicial es 0 y el final del recorrido es 15
int main () {
    Graph g(16);
    vector <int> path;
    vector <vector<int>> allPaths;
    vector <bool> visit(g.V, false);

    // Construir el grafo que representa el laberinto
    g.addEdge(0, 1);
    g.addEdge(0, 6);
    g.addEdge(0, 8);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 11);
    g.addEdge(2, 10);
    g.addEdge(3, 12);
    g.addEdge(3, 4);
    g.addEdge(4, 13);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(5,9);
    g.addEdge(6, 7);
    g.addEdge(7, 9);
    g.addEdge(7, 8);
    g.addEdge(8, 14);
    g.addEdge(9, 15);

    g.DFS(0, 15, path, allPaths, visit);

    showPaths(allPaths);
}