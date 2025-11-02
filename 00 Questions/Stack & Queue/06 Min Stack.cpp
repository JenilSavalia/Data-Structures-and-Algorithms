class MinStack {
public:
    // MinStack() {

    // }

    class Node {
    public:
        int value;
        int min;

        Node(int val, int m) {
            value = val;
            min = m;
        }
    };

    stack<Node*> s;

    int min(int a, int b) { return a > b ? b : a; }

    // int minimum = INT_MAX;
    void push(int val) {
        int currentMin = s.empty() ? val : min(val, s.top()->min);
        Node* node = new Node(val, currentMin);
        s.push(node);
    }

    void pop() { s.pop(); }

    int top() { return s.top()->value; }

    int getMin() { return s.top()->min; }
};

