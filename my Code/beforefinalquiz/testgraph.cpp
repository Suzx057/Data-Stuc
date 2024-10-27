#include<iostream>
using namespace std;

class Graph{
    private:
        int vertex;
        int **adjm;
        bool *visited;
        
    public:
        Graph(int v){
            vertex = v;
            adjm = new int*[vertex];
            for(int i = 0 ; i < vertex ; i ++){
                adjm[i] = new int[vertex]();
            }
            visited = new bool[vertex]();
        }
        void addEdge(int u, int v , int weight){
          
                adjm[u][v] = weight;
            
            
        }
        void resetvisited(){
            for(int i = 0 ; i< vertex; i++){
                visited[i] = false;
            }
        }
        void dfsUtil(int v){
            visited[v] = true;
            cout<<v<<" ";
            for(int i = 0 ; i< vertex ; i++){
                if(adjm[v][i] != 0 && !visited[i] ){
                    dfsUtil(i);
                }
            }
        }
        void DFS(int start){
            resetvisited();
            dfsUtil(start);
            cout<<endl;
        }
        void BFS(int start){
            resetvisited();
            int queue[100];
            int rear = 0 ;
            int front = 0;

            visited[start] = true;
            queue[rear++] = start;

            while(front != rear){
                int current = queue[front++];
                cout<<current<<" ";
                for(int i = 0 ; i< vertex ; i++){
                    if(adjm[current][i] != 0 && !visited[i]){
                        visited[i] = start;
                        queue[rear++] = i;
                    }
                }
            }
            
            cout<<endl;
            
            
        }

        void Comm(){
            char command;
            int u , v ,weight;
            while(cin>>command){
                switch(command){
                    case 'e':
                        cin>>u>>v>>weight;
                        addEdge(u,v,weight);
                        break;
                    case 'b':
                        cin>>u;
                        BFS(u);
                        break;
                    case 'd':
                        cin>>u;
                        DFS(u);
                    case 's':
                        break;
                    case 'q':
                        return;
                    
                }
            }
        }
};

int main(){
    int num;
    cin>>num;
    Graph g(num);
    g.Comm();
    return 0;
}