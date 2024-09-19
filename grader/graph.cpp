#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;        
    int **adjMatrix;      
    bool *visited;        

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjMatrix = new int*[v];
        for (int i = 0; i < v; i++) {
            adjMatrix[i] = new int[v];
            for (int j = 0; j < v; j++) {
                adjMatrix[i][j] = 0;  
            }
        }
        visited = new bool[v];
    }

   
    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
        delete[] visited;
    }

  
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;  
    }

    
    void resetVisited() {
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }
    }

  
    void DFS(int start) {
        resetVisited();
        dfsUtil(start);
        cout << endl;
    }

    
    void dfsUtil(int v) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[v][i] != 0 && !visited[i]) {
                dfsUtil(i);
            }
        }
    }

    
    void BFS(int start) {
        resetVisited();
        int queue[100];
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        while (front != rear) {
            int current = queue[front++];
            cout << current << " ";

            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[current][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }
        cout << endl;
    }

    
    void processCommand() {
        char command;
        int u, v, weight;
        while (cin >> command) {
            if (command == 'e') {  
                cin >> u >> v >> weight;
                addEdge(u, v, weight);
            } else if (command == 'd') {  
                cin >> u;
                DFS(u);
            } else if (command == 'b') {  
                cin >> u;
                BFS(u);
            } else if (command == 'q') {  
                break;
            }
        }
    }
};


int main() {
    int numVertices;

    cin >> numVertices;

    Graph g(numVertices);


    g.processCommand();

    return 0;
}