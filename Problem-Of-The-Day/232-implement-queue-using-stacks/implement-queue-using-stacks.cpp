class MyQueue {
public:
    // Push element x to the back of queue.
    stack<int> s1, s2;
    void push(int x) { s1.push(x); }

    // Removes the element from in front of queue.
    int pop(void) {
        while (s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }
        int r = s1.top();
        s1.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return r;
    }

    // Get the front element.
    int peek() {
        while (s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }
        int r = s1.top();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return r;
    }

    // Return whether the queue is empty.
    bool empty() { return s1.empty(); }
};