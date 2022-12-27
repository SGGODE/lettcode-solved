class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int cnt=0;
        int n=capacity.size();
        // sort(capacity.begin(),capacity.end());
        // sort(rocks.begin(),rocks.end());
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({capacity[i],rocks[i]});
        }
        vector<int>diff;
        
       // sort(vec.begin(),vec.end());
        for(auto it:vec){
            diff.push_back(abs(it.first-it.second));
        }
        sort(diff.begin(),diff.end());
        // for(int i=0;i<n;i++){
        //     if(vec[i].first==vec[i].second){
        //         ++cnt;
        //        // continue;
        //     }else{
        //         if((additionalRocks-(vec[i].first-vec[i].second))>=0){
        //             cnt++;
        //             additionalRocks-=(vec[i].first-vec[i].second);
        //         }
        //     }
        // }
        int sum=0;
        for(int i=0;i<n;i++){
          if(sum+diff[i]<=additionalRocks){
              sum+=diff[i];
          }  else return i;
        }
        return n;
    }
};