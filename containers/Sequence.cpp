#include <iostream>

#include <vector>
#include <deque>
#include <forward_list>
#include <list>

using namespace std;

void RunVectorMethods(int n)
{
  vector<int> test(n, 0);
  test.push_back(5);
  cout << test.back() << " Should be 5" << endl;

  cout << test.at(0) << endl;
}

void RunPairMethods(int x, int y)
{
  pair<int, int> test = make_pair(x, y);

  cout << "first = " << test.first << ", second = " << test.second << endl;
}

void RunListMethods(int n)
{
  list<int> test(n, -1);

  test.push_back(9);
  test.push_front(5);

  cout << "Should be 5 at front = " << test.front() << endl;
  cout << "Should be 9 at back = " << test.back() << endl;
}


int main()
{
  // TODO: Also include Runtime for each method!
  cout << "Vector:" << endl;
  RunVectorMethods(3);
  // RunDequeuMethods() - Double-Ended Queue
  // RunForwardListMethods() - Singly Linked List
  cout << "\nList:" << endl;
  RunListMethods(10);       // - Doubly Linked List
  cout << "\nPair:" << endl;
  RunPairMethods(5, 9);
  
  cout << "End Example Sequence Containers" << endl;
  return 0;
}
