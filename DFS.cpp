#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    // Number of vertices
    int V;
    // Adjacency list to store graph
    vector<list<int> > adj;

    // Utility function for DFS traversal
    void DFSUtil(int v, vector<bool>& visited)
    {
        // Mark the current node as visited
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent to this
        // vertex
        for (int i : adj[v]) {
            if (!visited[i])
                // Recur for the unvisited adjacent nodes
                DFSUtil(i, visited);
        }
    }

public:
    // Constructor to initialize graph with V vertices
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) { adj[v].push_back(w); }

    // DFS traversal of the vertices reachable from v
    void DFS(int v)
    {
        // Mark all vertices as not visited
        vector<bool> visited(V, false);
        // Call the recursive helper function to print DFS
        // traversal
        DFSUtil(v, visited);
    }
};

int main()
{
    // Create a graph with 4 vertices
    Graph g(4);
    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    // Print the DFS traversal starting from vertex 2
    cout << "Depth First Traversal (starting from vertex "
            "2): ";
    g.DFS(2);
    cout << endl;

    return 0;
}
