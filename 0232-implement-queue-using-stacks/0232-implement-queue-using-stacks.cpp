#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> st1; // input stack
    stack<int> st2; // output stack

    MyQueue() {
    }

    void push(int x) {
        st1.push(x); // just push to st1
    }

    int pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        if (!st2.empty()) {
            int val = st2.top();
            st2.pop();
            return val;
        }

        return -1;
    }

    int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        if (!st2.empty()) {
            return st2.top();
        }

        return -1;
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};
