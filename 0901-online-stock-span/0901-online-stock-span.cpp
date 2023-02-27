class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>>s;
    int next(int price) {
      int span=1; 
      //stack<pair<int,int>>st(s);
      //st.pop();
      //if(!st.empty()){
      while(!s.empty()&&s.top().first<=price){
          span+=s.top().second; s.pop();
          //if(st.empty())break;
      }s.push({price,span});
      return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */