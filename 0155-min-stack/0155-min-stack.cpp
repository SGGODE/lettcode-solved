class MinStack {
public:
    MinStack() {
        
    }
    stack<int>s,v;
   // int mi=INT_MAX;
    void push(int val) {
        if(v.empty()||v.top()>=val){
            v.push(val);
        }
        s.push(val);
    }
    
    void pop() {
        if(v.top()==s.top())v.pop();
        s.pop();
      //  mi=s.top();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        // priority_queue<int,vector<int>,greater<int>>pq;
        // stack<int>st(s);
        // while(!st.empty()){
        //     pq.push(st.top());
        //     st.pop();
        // }
        return v.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */