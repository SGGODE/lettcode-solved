class Solution {
private:
    int sub(vector<int>&arr1,vector<int>&arr2,int index,map<pair<int,int>,int>&mp,int prev){
        if(index==arr1.size())return 0;
        if(mp.find({index,prev})!=mp.end())return mp[{index,prev}];
        int res=INT_MAX/2;
        int pointer=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        if(arr1[index]>prev)res=min(res,sub(arr1,arr2,index+1,mp,arr1[index]));
        if(pointer<arr2.size())res=min(res,sub(arr1,arr2,index+1,mp,arr2[pointer])+1);
        return mp[{index,prev}]=res;
    }
public:
   int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
      map<pair<int,int>,int>mp;sort(arr2.begin(),arr2.end());
       int res=sub(arr1,arr2,0,mp,INT_MIN);
      return res>=INT_MAX/2?-1:res;
   }
};