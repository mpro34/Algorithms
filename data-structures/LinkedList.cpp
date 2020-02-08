#include <iostream>

struct Node {
  int val;
  Node* next;
  Node(int x) : val(x), next(nullptr) {}
};

struct LinkedList {
/** Should support the following 
* AppendNode (add node to end)
* InsertNode
* DeleteNode
* Reverse
* Search for a Node
* Detect a Loop
**/
  Node* root;
  int length;

  LinkedList() : root(new Node(0)), length(1) {};
  
  LinkedList(int x) : root(new Node(x)), length(1) {};

  void AppendNode(Node* node) 
  {
    Node* head = root;
    while (head->next) 
    {
      head = head->next;
    }

    head->next = node;
    length++;
  }

  void InsertNode(Node* node, int index) 
  { // Insert a node at the specified index
    // Runtime = O(n), Space = O(1)
    Node* head = root;
    while (head) 
    {
      if (index < 2) 
      { // Insert the node here
        Node* temp = head->next;
        head->next = node;
        node->next = temp;
        break;
      }
      index--;
      head = head->next;
    }
    length++;
  }

  void DeleteNodeAt(int index) 
  { // Delete the node at the specified index
    // Runtime = O(index), Space = O(1) 
    Node* head = root;
    while (index > 1) 
    { 
      head = head->next;
      index--; 
    }

    head->next = head->next->next;
    length--;
  }

  int Search(int value)
  { // return the index of the Node or -1 of not found
    // Runtime = O(n), Space = O(1)

    Node* head = root;
    int idx = 0;
    while(head) 
    {
      if (head->val == value) {
        return idx;
      }
      idx++;
      head = head->next;
    }

    return -1;
  }

  void AddCycle()
  { // Set the last->next = root  
    // Runtime = O(n), Space = O(1)
    Node* last = root;
    while(last->next) { last = last->next; }

    last->next = root;
  }

  bool LoopDetected()
  { // Whether a loop is detected or not.
    // Runtime = O(n), Space = O(1)
    // Slow pointer moves 1 node, fast pointer moves 2 nodes.
    Node* slow = root;
    Node* fast = root->next;

    while (fast->next->next) {
      if (slow == fast) {
        return true;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    return false;
  }

  void Reverse() 
  { // Reverse the Linked List!
    // Runtime = O(n), Space = O(1) inplace reversal 
    // Create prev, curr, next pointers

    if (length == 2) 
    {
      Node* curr = root;
      Node* next = curr->next;
      Node* temp = next->next;

      next->next = curr;
      curr->next = temp;

    } 
    else if (length >= 3)
    {
      Node* prev = root;
      Node* curr = root->next;
      Node* next = root->next->next;

      while (prev->next)
      {
        Node* temp = next->next;
        curr->next = prev;
        next->next = curr;
        prev->next = temp;
      }
      root = next;
    }
    else 
    {
      std::cout << "Too small to reverse" << std::endl;
    }

  }

  void PrintList()
  { // Print the linked list values with `->` inbetween each node.
    // Runtime = O(n), Space = O(1)
    Node* head = root;
    while (head) {
      std::cout << head->val;
      if (head->next) std::cout << " -> ";
      head = head->next;
    }
    std::cout << "\n";
  }

};



int main() 
{
    // 5
    LinkedList* mylist = new LinkedList(5);

    // Append a 3 and 10 nodes to the end
    Node* newnode = new Node(3);
    mylist->AppendNode(newnode);
    mylist->AppendNode(new Node(10));
    mylist->PrintList(); // 5 -> 3 -> 10

    // Insert a 2 at index 1
    Node* inserted = new Node(2);
    mylist->InsertNode(inserted, 1); // 5 -> 2 -> 3 -> 10
    mylist->PrintList();

    // Delete the node at index 2 (a 3)
    mylist->DeleteNodeAt(2);
    mylist->PrintList(); // 5 -> 2 -> 10

    // Search the List for a 10
    std::cout << "Search for 10 = " << mylist->Search(10) << std::endl; // 2
    std::cout << "Search for 24 = " << mylist->Search(24) << std::endl; // -1

    // Reverse the LL and print it
    mylist->Reverse();
    mylist->PrintList(); // 10 -> 2 -> 5

    // Detect a Cycle -> False
    std::cout << "A Loop here? " << ((mylist->LoopDetected()) ? "yes" : "no") << std::endl;

    // Add a Cycle
    mylist->AddCycle();
    std::cout << "Loop Added!" << std::endl;

    // Detect a Cycle -> True
    std::cout << "A Loop here? " << ((mylist->LoopDetected()) ? "yes" : "no") << std::endl;

    std::cout << "\nEnd of LinkedList Functions" << std::endl;

    return 0;
}
