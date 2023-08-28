class MyStack {
public:
    MyStack() {
        
    }
    deque<int>pq;
    void push(int x) {
        pq.push_back(x);
    }
    
    int pop() {
        int x=pq.back();
        pq.pop_back();
        return x;
    }
    
    int top() {
        return pq.back();
    }
    
    bool empty() {
        return pq.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */