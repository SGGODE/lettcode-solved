class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    map<int,int>mp;
    SmallestInfiniteSet() {
      for(int i=1;i<=1000;i++){
          pq.push(i);
          mp[i]++;
        }  
    }
    
    int popSmallest() {
        int c=pq.top();
        pq.pop();
        --mp[c];
        if(mp[c]==0)mp.erase(c);
        return c;
    }
    
    void addBack(int num) {
        if(!mp.count(num)){
            mp[num]++;
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */