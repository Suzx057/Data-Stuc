#include <iostream>
using namespace std;

class Graph
{
private:
    int vertices;    // จำนวนจุดยอด
    int **adjMatrix; // เมทริกซ์เก็บน้ำหนักของขอบ
    bool *visited;   // ติดตามสถานะการเยี่ยมชม

public:
    // Constructor: สร้างเมทริกซ์และอาร์เรย์สำหรับสถานะการเยี่ยมชม
    Graph(int v)
    {
        vertices = v;

        // จองหน่วยความจำสำหรับเมทริกซ์แบบไดนามิก
        adjMatrix = new int *[vertices];
        for (int i = 0; i < vertices; i++)
        {
            adjMatrix[i] = new int[vertices](); // กำหนดค่าเริ่มต้นเป็น 0
        }

        // จองหน่วยความจำสำหรับสถานะการเยี่ยมชม
        visited = new bool[vertices]();
    }

    // เพิ่มขอบพร้อมน้ำหนัก
    void addEdge(int u, int v, int weight)
    {
        adjMatrix[u][v] = weight;
    }

    // รีเซ็ตสถานะการเยี่ยมชม
    void resetVisited()
    {
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = false;
        }
    }

    // DFS Traversal
    void DFS(int start)
    {
        resetVisited();
        dfsUtil(start);
        cout << endl;
    }

    // ฟังก์ชันย่อยสำหรับ DFS
    void dfsUtil(int v)
    {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < vertices; i++)
        {
            if (adjMatrix[v][i] != 0 && !visited[i])
            {
                dfsUtil(i);
            }
        }
    }

    // BFS Traversal
    void BFS(int start)
    {
        resetVisited();
        int queue[100]; // กำหนดขนาดคงที่
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        while (front != rear)
        {
            int current = queue[front++];
            cout << current << " ";

            for (int i = 0; i < vertices; i++)
            {
                if (adjMatrix[current][i] != 0 && !visited[i])
                {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }
        cout << endl;
    }

    // จัดการคำสั่งจากผู้ใช้
    void processCommand()
    {
        char command;
        int u, v, weight;
        while (cin >> command)
        {
            switch (command)
            {
            case 'e': // เพิ่มขอบ
                cin >> u >> v >> weight;
                addEdge(u, v, weight);
                break;
            case 'd': // DFS จากจุดยอดที่กำหนด
                cin >> u;
                DFS(u);
                break;
            case 'b': // BFS จากจุดยอดที่กำหนด
                cin >> u;
                BFS(u);
                break;
            case 'q': // จบการทำงาน
                return;
            }
        }
    }


};

int main()
{
    int numVertices;
    cin >> numVertices;

    // สร้างออบเจ็กต์ Graph
    Graph g(numVertices);

    // เรียก processCommand() เพื่อจัดการคำสั่งจากผู้ใช้
    g.processCommand();

    // คืนหน่วยความจำที่จองไว้
    // g.freeMemory(g, numVertices);

    return 0;
}
