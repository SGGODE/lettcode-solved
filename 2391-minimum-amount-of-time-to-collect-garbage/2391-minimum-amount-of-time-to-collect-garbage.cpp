class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int prefixsum = 0;
        int lastp = 0,lastm=0,lastg=0;
        for(int i=0;i<garbage.size();i++){
            for(auto&it:garbage[i]){
                if(it=='P')lastp=i;
                else if(it=='G')lastg=i;
                else lastm=i;
            }
        }
        int sum = 0;
        for(int i=0;i<=lastp;i++){
            for(auto&it:garbage[i]){
                if(it=='P')++sum;
            }
            if(i>=1)sum+=travel[i-1];
        }
        for(int i=0;i<=lastm;i++){
            for(auto&it:garbage[i]){
                if(it=='M')++sum;
            }
            if(i>=1)sum+=travel[i-1];
        }
        for(int i=0;i<=lastg;i++){
            for(auto&it:garbage[i]){
                if(it=='G')++sum;
            }
            if(i>=1)sum+=travel[i-1];
        }
        return sum;
    }
};