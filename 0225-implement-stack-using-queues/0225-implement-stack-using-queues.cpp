#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1; // Main queue to hold elements in stack order
    queue<int> q2; // Helper queue used during push operation

public:
    MyStack() {
        // Constructor initializes empty queues
    }

    void push(int x) {
        // Step 1: Push the new element into q2
        q2.push(x);

        // Step 2: Push all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Swap q1 and q2 so that q1 always has the correct order
        swap(q1, q2);
    }
    int top() {
        // Return front of q1 (which is the top of stack)
        if (!q1.empty()) {
            return q1.front();
        }
        return -1; // Or throw exception if needed
    }
    int pop() {
        // Remove the front of q1 (which is the top of stack)
        if (!q1.empty()) {
            int val = q1.front();
            q1.pop();
            return val;
        }
        return -1; // Or throw exception if needed
    }

    

    bool empty() {
        return q1.empty();
    }
};
