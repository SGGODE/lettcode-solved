class MyStack {
public:
    MyStack() {
        
    }
    queue<int>pq;
    void push(int x) {
        pq.push(x);
    }
    
    int pop() {
        vector<int>v;
        //queue<int>px(pq);
        while(!pq.empty()){
            v.push_back(pq.front());
            pq.pop();
        }int n=v.size();
        //pq.clear();
        for(int i=0;i<n-1;i++){
          pq.push(v[i]);   
        }
        return v[n-1];
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