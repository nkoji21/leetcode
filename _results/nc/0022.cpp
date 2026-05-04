#include <bits/stdc++.h>
using namespace std;

class MinStack {
 public:
  stack<int> st;
  stack<int> minSt;
  MinStack() {}

  void push(int val) {
    st.push(val);
    val = min(val, minSt.empty() ? val : minSt.top());
    minSt.push(val);
  }

  void pop() {
    st.pop();
    minSt.pop();
  }

  int top() { return st.top(); }

  int getMin() { return minSt.top(); }
};

int main() {
  MinStack minStack;

  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);

  cout << minStack.getMin() << endl;

  minStack.pop();

  cout << minStack.top() << endl;
  cout << minStack.getMin() << endl;

  return 0;
}
