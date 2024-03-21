class Solution {
private:
    bool cost(string&s,int start,int end){
        while(start<end){
            if(s[start]!=s[end])return 0;
            ++start;
            --end;
        }
        return 1;
    }
    int sub(string&s,int index, int k,int n){
        if(k==0)return cost(s,index,n-1);
        int ans = 0;
        for(int i=index;i<s.size()-1;i++){
           if(cost(s,index,i)){
               ans = max(ans,sub(s,i+1,k-1,n));
           }
        }
        return ans;
    }
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        return sub(s,0,2,n);
    }
};