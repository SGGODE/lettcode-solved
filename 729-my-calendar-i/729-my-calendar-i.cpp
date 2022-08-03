class MyCalendar {
public:
   // set<pair<int,int>>s
    vector<pair<int,int>>s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
      /*if(s.find(start+1)==s.end()&&s.find(end-1)==s.end()){
        //   int c=0;
           for(int i=start;i<=end;i++){
               s.insert({i,c});
           }
           c++;
           return true;
       } 
        return false;*/
      for(auto i:s){
          if(max(i.first,start)<min(i.second,end))
              return false;
      } 
     s.push_back(make_pair(start,end));
     return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */