class MyCircularDeque {
public:
    list<int>ls;int size=0;
    MyCircularDeque(int k) {
        size=k;
    }
    
    bool insertFront(int value) {
        if(ls.size()<size){
            ls.push_front(value);
            return 1;
        }
        return 0;
    }
    
    bool insertLast(int value) {
        if(ls.size()<size){
            ls.push_back(value);
            return 1;
        }
        return 0;
    }
    
    bool deleteFront() {
        if(ls.empty())return 0;
        ls.pop_front();
        return 1;
    }
    
    bool deleteLast() {
        if(ls.empty())return 0;
        ls.pop_back();
        return 1;
    }
    
    int getFront() {
        if(ls.empty())return -1;
        return ls.front();
    }
    
    int getRear() {
         if(ls.empty())return -1;
        return ls.back();
    }
    
    bool isEmpty() {
        return ls.empty();
    }
    
    bool isFull() {
        return ls.size()==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */