#include <iostream>

/**
 * struct GraphNode {
 *     int val;
 *     GraphNode *next;
 *     GraphNode(int x) : val(x), next(NULL) {}
 * };
 *  struct GraphNode
    {
        int val;
        GraphNode* next;
    };
    struct Graph
    {
        int numVertices;
        GraphNode** adjLists;    

        OR

        int numVertices;
        list<int> *adjLists;    
    };
 */

class Graph {
    /** Must support the following operations
     * Note: A Graph consists of V Vertices and E Edges between each vertex.
    * Add edge
    * Remove edge
    * Print graph - DFS
    * Print graph - BFS
    * Detect a cycle
    **/
private:

public:
    Graph() {};

};

int main() {
    std::cout << "Graph - Adjacency List format" << std::endl;
    return 0;
}
