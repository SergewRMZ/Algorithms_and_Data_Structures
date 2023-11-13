/**
 * DFS: Depth First Search. 
 * Ejercicio del laberinto resuelto.
 * (Algorithms in a Nutshell)
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

    void DFS (int start) {
        vector<bool> visit(V, false); // No visitados
        stack<int> pila;

        visit[start] = true;
        pila.push(start);

        cout << "Depth First Search: " << endl;

        while (!pila.empty()) {
            int currentNode = pila.top();
            pila.pop();
            cout << "Nodo: " << currentNode << endl;

            // Visitar los nodos vecinos
            for (int neighbor : adyacentList[currentNode]) {
                if (!visit[neighbor]) {
                    visit[neighbor] = true;
                    pila.push(neighbor);
                }
            }
        }
    }
};

void showGraph (Graph &g) {
    for (int i = 0; i < g.V; i++) {
        cout << "Nodo " << i << ": ";
        for (int neighbor : g.adyacentList[i]) {
            cout << neighbor << " ";
        }

        cout << endl;
    }
}

int main () {
    Graph g(16);

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

    // showGraph(g);
    g.DFS(0);
}