class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int>res(n,0);
        int curr=1;
        while(candies>0){
            for(int i=0;i<n&&candies>0;i++){
                if(candies>=curr){
                  res[i]+=curr;
                  candies-=curr;
                   ++curr;
                }else{
                     res[i]+=candies;
                     candies=0;
                }
            }
        }
        return res;
    }
};