class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
      map<int,int>mp;
        for(auto it:tasks)mp[it]++;
       set<int>s(tasks.begin(),tasks.end());
        int cnt=0;
        for(auto it:s){
            //cout<<mp[it]<<endl;
            if(mp[it]>=2){
              int x=mp[it];
              if(x%3==0){
                  cnt+=(x/3);
                 // cout<<"cnt "<<cnt<<endl;
                  //continue;
              }else if(x%2==0){
                 // cout<<"hi 2"<<endl;
                 int dump=0;int dcnt=0;
                  while(dump<=x){
                      dump=dump+3;
                      ++dcnt;
                  }
                  //dump-=3;
                  cnt+=dcnt;
                 // cout<<dcnt<<" "<<cnt<<endl;
                  //continue;
              }else{
                  int dump=0;int dcnt=0;
                  while(dump<=x){
                      dump=dump+3;
                      ++dcnt;
                  }
                  //dump-=3;
                  cnt+=dcnt;
                 // cout<<dcnt<<" "<<cnt<<endl;
              }
            }else return -1;
        }
        return cnt;
    }
};