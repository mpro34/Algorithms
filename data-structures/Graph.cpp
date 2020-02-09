#include <iostream>
#include <list>

using namespace std;

class Graph {
    private:
        int _V; // Number of verticies

        // Each vertex has an associated list of integers that represent the vertices that are connected to it.
        list<int> *adj_list;

    public:

        Graph(int v) 
        {
            _V = v;
            adj_list = new list<int>[v];
        };

        void AddEdge(int v, int w)
        {
            adj_list[v].push_back(w);
        };

        void BFS(int s)
        { // Traverse the graph from source "s" in a Breadth-First manner. Uses a Queue
            //Start with all nodes not visited
            bool* visited = new bool[_V];
            for (int i=0; i<_V; i++) {
                visited[i] = false;
            }

            // Create a queue for BFS
            list<int> queue;

            // Initialize first element as visited
            visited[s] = true;
            queue.push_back(s);

            // Continue until queue is empty
            while (!queue.empty())
            {
                //Get front of queue and remove it
                s = queue.front();
                queue.pop_front();
                cout << "Checking adjacent verticies for " << s << endl;
                // Get all adjacent vertices from "s" and add to queue for later processing
                for (auto i=adj_list[s].begin(); i!=adj_list[s].end(); i++)
                {
                    // We only care about nodes not visited yet.
                    if (!visited[*i])
                    {
                        cout << "Visit and enqueue " << *i << endl;
                        visited[*i] = true;
                        // Add current node to queue to check all of *i's adjacent verticies
                        queue.push_back(*i);
                    }
                    
                }
            }
        }

        void DFS_helper(int s, bool* visited)
        { // Helper function for DFS recursion
            // Visited the passed in node
            cout << "Visiting node " << s << endl;
            visited[s] = true;

            // Go through node "s" adjacency list and then recurse through all unvisited adjacent nodes.
            for (auto i = adj_list[s].begin(); i != adj_list[s].end(); i++)
            {   // We only care about unvisited nodes
                if (!visited[*i])
                {
                    cout << "Visiting node " << *i << endl;

                    // Recurse on the current visited node
                    DFS_helper(*i, visited);
                }
            }

        }

        void DFS(int s)
        { // Traverse and print the graph from source "s" in a Depth-First manner. Uses a Stack
            // Runtime is O(V + E) with V verticies and E Edges
            // Init a visited array with all as false
            bool* visited = new bool[_V];
            for (int i=0; i<_V; i++) {
                visited[i] = false;
            }

            // Call DFS helper to recurse with init data
            DFS_helper(s, visited);

        }

};

int main()
{
    // Graph with only 3 nodes connected like: 1 - 2
    //                                         \   /
    //                                           3
    Graph* myg = new Graph(3); 
    myg->AddEdge(1, 2);
    myg->AddEdge(1, 3);
    myg->AddEdge(2, 3);

    cout << "BFS Start:" << endl;
    myg->BFS(1);
    cout << "BFS End" << endl;

    cout << "DFS Start:" << endl;
    myg->DFS(1);
    cout << "DFS End:" << endl;

    cout << "Finished Graph Algorithms" << endl;
    return 0;
}