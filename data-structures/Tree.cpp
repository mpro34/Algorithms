#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

struct Tree {
    /** Must support the following operations
    * Search for a Node
    * Insert a Node
    * Delete a Node
    * Check if valid Binary Search Tree
    * Tree Traversal in-order (L, root, R)
    * Tree Traversal pre-order (root, L, R)
    * Tree Traversal post-order (L, R, root)
    **/

   TreeNode* root;

    Tree() : root(new TreeNode(0)) {};
    Tree(int x) : root(new TreeNode(x)) {};

    bool FindNode(int x)
    { // Return if the node is in the Tree or not

    }

    void InsertNode(TreeNode* node)
    { // Insert the node into the tree, keeping order?

    }
};

int main() {
   std::cout << "Tree" << std::endl;
    return 0;
}
