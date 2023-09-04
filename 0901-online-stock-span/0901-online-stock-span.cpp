class StockSpanner {
public:
    stack<pair<int,int>>s;
    StockSpanner() {
        
    }
    
    int next(int price) {
      // stack<int>st(s);
        int cnt=0;
        while(!s.empty()&&s.top().first<=price){
            cnt+=s.top().second;
            s.pop();
        }
        s.push({price,cnt+1});
        return cnt+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */