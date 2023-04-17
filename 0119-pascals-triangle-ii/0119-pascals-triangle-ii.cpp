class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0)return {1};
        if(rowIndex==1)return {1,1};
        vector<int>res;
        vector<int>prev{1,2,1};
        for(int i=3;i<=rowIndex;i++){
            vector<int>curr(i+1,0);
            curr[0]=1;curr[i]=1;
            for(int j=1;j<i;j++){
                 curr[j]=prev[j-1]+prev[j];
            }
            prev.clear();
            prev=curr;
        }
        return prev;
    }
};