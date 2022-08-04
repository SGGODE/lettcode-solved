class MyCircularQueue {
public:
    vector<int>q;
    int c=0;
    MyCircularQueue(int k) {
        c=k;
    }
    
    bool enQueue(int value) {
      if(q.size()<c){
         q.insert(q.end(),value);
          return true;
      }
      return false;
    }
    
    bool deQueue() {
       if(q.size()>0){
          q.erase(q.begin());
           return true;
       }
        return false;
    }
    
    int Front() {
        if(q.empty())
          return -1;
      return q[0];
    }
    
    int Rear() {
        if(q.empty())
          return -1;
      return q[q.size()-1];
    }
    
    bool isEmpty() {
          if(q.empty())
             return 1;
         return 0;
    }
    
    bool isFull() {
        return q.size()==c;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */