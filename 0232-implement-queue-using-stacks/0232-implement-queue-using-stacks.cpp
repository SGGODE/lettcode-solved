class MyQueue {
public:
    stack<int>st;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int>sp;
        while(st.size()>1){
            sp.push(st.top());
            st.pop();
        }
        int top = st.top();
        st.pop();
        while(!sp.empty()){
            st.push(sp.top());
            sp.pop();
        }
        return top;
    }
    
    int peek() {
        stack<int>sp(st);
        while(sp.size()>1)sp.pop();
        return sp.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */