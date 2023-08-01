class Solution {
private:
    void sub(vector<vector<int>>&res,vector<int>&temp,int n,int k,int index){
        if(temp.size()==k){
            res.push_back(temp);
            return;
          //  temp.clear();
        }
        if(index>n){
            if(temp.size()==k)res.push_back(temp);
            return;
        }
        temp.push_back(index);
        sub(res,temp,n,k,index+1);
        temp.pop_back();
        sub(res,temp,n,k,index+1);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>temp;
        sub(res,temp,n,k,1);
        return res;
    }
};