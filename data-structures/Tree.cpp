#include <iostream>
#include <queue>

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

    Tree() : root(NULL) {};
    Tree(int x) : root(new TreeNode(x)) {};

    bool FindNode(int x)
    { // Return if the node is in the Tree or not

        return false;
    }

    void InsertNode(TreeNode* temp, int key)
    { // Insert key into the Tree in level order
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();

            if (curr)
            {
                if (curr->left)
                {
                    if (key < curr->left->val)
                    {
                        q.push(curr->left);
                    }
                } 
                else 
                {
                    curr->left = new TreeNode(key);
                    break;
                }

                if (curr->right)
                {
                    if (key > curr->right->val)
                    {
                        q.push(curr->right);
                    }                  
                }
                else
                {
                    curr->right = new TreeNode(key);
                    break;
                }
            }
        }

    }

    void PrintInOrder(TreeNode* top)
    { // Print the left subtrees, root, then right subtrees
        if (!top) return; 
        
        PrintInOrder(top->left);
        std::cout << top->val << " ";
        PrintInOrder(top->right);        
    }

    void PrintPreOrder(TreeNode* temp)
    { // Print the root, left then right
        if (!temp) return;

        std::cout << temp->val << " ";
        PrintPreOrder(temp->left);
        PrintPreOrder(temp->right);
    }

    void PrintPostOrder(TreeNode* temp)
    { // L, R, root
        if (!temp) return;

        PrintPostOrder(temp->left);
        PrintPostOrder(temp->right);
        std::cout << temp->val << std::endl;
    }

    bool ValidBST(TreeNode* temp)
    { // Perform an in-order traveral and check that for each root node, the left < root and right > root.
        if (!temp) return true;

        if (temp->left && temp->left->val > temp->val) return false;

        if (temp->right && temp->right->val < temp->val) return false;

        if (!ValidBST(temp->left) || !ValidBST(temp->right)) return false;

        return true;
    }
};

int main() {
    
    Tree* mytree = new Tree();

    mytree->root = new TreeNode(10);
    mytree->root->left = new TreeNode(8);
    mytree->root->left->left = new TreeNode(6);
    mytree->root->right = new TreeNode(16);
    mytree->root->right->right = new TreeNode(23);
    mytree->root->left->right = new TreeNode(9);
        
    // Print the Binary tree in-order
    std::cout << "Printing in order!" << std::endl;
    mytree->PrintInOrder(mytree->root);
    std::cout << "\n Done printing in-order" << std::endl;

    std::cout << "Valid BST = " << mytree->ValidBST(mytree->root) << std::endl;

    // Print the Binary tree in pre-order
    std::cout << "Printing in pre-order!" << std::endl;
    mytree->PrintPreOrder(mytree->root);
    std::cout << "\n Done printing in pre-order" << std::endl;

    // Add nodes to the tree
    mytree->InsertNode(mytree->root, 5);
    mytree->InsertNode(mytree->root, 31);
    mytree->InsertNode(mytree->root, 1);

    std::cout << "Valid BST now? = " << mytree->ValidBST(mytree->root) << std::endl;

    // Print the Binary tree in-order after Inserting
    std::cout << "Printing in order!" << std::endl;
    mytree->PrintInOrder(mytree->root);
    std::cout << "\n Done printing in-order" << std::endl;
    
    std::cout << "Tree" << std::endl;
    return 0;
}
