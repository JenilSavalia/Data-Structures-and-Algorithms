class MyQueue {
public:
    // MyQueue() {

    // }
    stack<int> s;

    void push(int x) {
        stack<int> temp;
        // Temporarily move all existing elements to `temp` (this reverses the
        // order)
        while (!s.empty()) {
            temp.push(s.top());
            s.pop();
        }
        // Add the new element (it becomes the new "bottom")
        s.push(x);
        // Move everything back from `temp` to `s` (this reverses again,
        // restoring the relative order of old elements)
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }

    int pop() {
        int n = s.top();
        s.pop();
        return n;
    }

    int peek() { return s.top(); }

    bool empty() { return s.size() == 0; }
};

