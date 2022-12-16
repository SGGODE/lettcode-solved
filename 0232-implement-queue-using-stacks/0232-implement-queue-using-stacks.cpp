class MyQueue {
public:
    MyQueue() {
        
    }
    //queue<int>pq;
    stack<int>s;
    void push(int x) {
      // pq.push(x); 
        s.push(x);
    }
    int pop() {
       //  int x=pq.front();
       //  pq.pop();
       // return x;
        stack<int>dump(s); vector<int>v;
      while(!dump.empty()){
          v.push_back(dump.top());
          dump.pop();
      }
        reverse(v.begin(),v.end());
       // dump.clear();
        for(int i=1;i<v.size();i++)dump.push(v[i]);
      //  s.clear();
        while(!s.empty()){
         // v.push_back(dump.top());
          s.pop();
      }
        s=dump;
        return v[0];
    }
    
    int peek() {
        stack<int>dump(s);
        vector<int>v;
      while(!dump.empty()){
          v.push_back(dump.top());
          dump.pop();
      }reverse(v.begin(),v.end());
        return v[0];
       // return pq.front();
    }
    
    bool empty() {
       // return pq.empty();
        return s.empty();
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