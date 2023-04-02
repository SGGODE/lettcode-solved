class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        vector<int>res(n,0);
        for(int i=0;i<spells.size();i++){
            int s=0;
            int e=potions.size()-1;
            while(s<=e){
                int mid=s+(e-s)/2;
                long long product=(long long)spells[i]*potions[mid];
                if(product>=success){
                    e=mid-1;
                }else{
                    s=mid+1;
                }
            }
            int m=potions.size();
            res[i]=m-e-1;
        }
        return res;
    }
};