#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

//create a graph class
class Graph {
private:
    int vertices;
    vector<vector<int>> adjList; // using Adjacency list

public:
    Graph(int v) : vertices(v) {
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // DFS traversal
    void dfs(int start) {
        vector<bool> visited(vertices, false);
        stack<int> s;

        s.push(start);
        cout << "DFS Traversal: ";
        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";
                // Add neighbors to the stack
                for (auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it) {
                    if (!visited[*it]) {
                        s.push(*it);
                    }
                }
            }
        }
        cout << endl;
    }

    // BFS traversal
    void bfs(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " ";
            // Add neighbors to the queue
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(6); // Graph with 6 vertices
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    // Perform traversals
    g.dfs(0);
    g.bfs(0);

    return 0;
}
