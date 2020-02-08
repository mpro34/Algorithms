#include <iostream>

struct Node {
  int val;
  Node* next;
  Node(int x) : val(x), next(nullptr) {}
};

class LinkedList {
/** Should support the following 
* AppendNode (add node to end)
* InsertNode
* DeleteNode
* Reverse
* Search for a Node
* Detect a Loop
**/
private:
  Node* root;

public:
  LinkedList() { root = new Node(0); };
  
  LinkedList(int x) { root = new Node(x); };

  void AppendNode(Node* node) { root->next = node; }

  void InsertNode(Node* node, int index) 
  {
    // Insert a node at the specified index

  }

  void Delete(int index) 
  {
    // Delete the node at the specified index
  
  }

  void Reverse() 
  {
    // Reverse the Linked List!

  }

  int Search(Node* node)
  {
    // return the index of the Node or -1 of not found

    return -1;
  }

  bool LoopDetected()
  {
    // Whether a loop is detected or not.
    
    return false;
  }

};



int main() 
{
  
    LinkedList* mylist = new LinkedList(5);
    Node* newnode = new Node(3);
    mylist->AppendNode(newnode);

    
    std::cout << "LinkedList" << std::endl;
    return 0;
}
