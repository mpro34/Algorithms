#include <iostream>

#include <stack>
#include <queue>

using namespace std;

void RunStackFuncs()
{
  stack<int> test;
  test.push(1);
  test.push(2);
  test.push(3);

  cout << "Top of stack should be 3: " << test.top() << endl;
  test.pop();
  cout << "Now top should be 2: " << test.top() << endl;
}

void RunQueueFuncs()
{
  queue<int> test;
  test.push(1);
  test.push(2);
  test.push(3);

  cout << "Front of queue should be 1: " << test.front() << endl;
  test.pop();
  cout << "After dequeing, front should be 2: " << test.front() << endl;

  priority_queue<int> pq;
  pq.push(10);
  pq.push(1);
  pq.push(25);

  cout << "Front of pq should be greatest(25): " << pq.top() << endl;
  pq.pop();
  cout << "After dequeing, front should be 10: " << pq.top() << endl;

  cout << "Priority Queue in ascending (Min Heap) or min at top" << endl;
  priority_queue<int, vector<int>, greater<int>> newpq;
  newpq.push(10);
  newpq.push(1);
  newpq.push(25);

  cout << "Front of pq should be greatest(1): " << newpq.top() << endl;
  newpq.pop();
  cout << "After dequeing, front should be 10: " << newpq.top() << endl;
}

int main()
{
    RunStackFuncs();
    RunQueueFuncs();
    cout << "Container Adapters from Sequence Container base classes." << endl;
    return 0;
}

