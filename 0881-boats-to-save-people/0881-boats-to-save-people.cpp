class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // int s=*max_element(people.begin(),people.end());
        // int e=10000000000000;
        sort(people.begin(),people.end());
        int s=0;
        int e=people.size()-1;
        int cnt=0;
        while(s<=e){
           //  int mid=s+(e-s)/2;
           //  int cnt=0;int sum=0;
           //  int total=0;
           //  for(int i=0;i<people.size();i++){
           //      if(sum<limit&&cnt<2){
           //          ++cnt;
           //          sum+=people[i];
           //          if(sum>limit){
           //              sum=people[i];
           //              cnt=1;
           //              ++total;
           //          }
           //      }else{
           //          sum=people[i];
           //          cnt=1;
           //          ++total;
           //      }
           //  }
           // if(sum!=0)++total;
           //  if(total>mid){
           //      s=mid+1;
           //  }else{
           //      e=mid-1;
           //  }
            if(people[s]+people[e]<=limit){
                ++s;
                --e;
            }
            else --e;
            ++cnt;
        }
        return cnt;
    }
};