class Solution {
private:
    int largestRectangleArea(vector<int>&nums) {
        int sum=0;
        int n = nums.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<pair<int,int>>s1,s2;
        for(int i=n-1;i>=0;i--){
            if(s1.empty()){
                s1.push({nums[i],i});
                left[i]=i;
            }else{
                while(!s1.empty()&&s1.top().first>=nums[i]){
                    s1.pop();
                }
                if(s1.empty()){
                    left[i]=n-1;
                    s1.push({nums[i],i});
                }else{
                    left[i]=s1.top().second-1;
                    s1.push({nums[i],i});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(s2.empty()){
                s2.push({nums[i],i});
                right[i]=i;
            }else{
                while(!s2.empty()&&s2.top().first>=nums[i]){
                    s2.pop();
                }
                if(s2.empty()){
                    right[i]=0;
                    s2.push({nums[i],i});
                }else{
                    right[i]=s2.top().second+1;
                    s2.push({nums[i],i});
                }
            }
        }
        for(int i=0;i<n;i++){
            int curr = (left[i]-right[i])+1;
            sum=max(sum,curr*nums[i]);
        }
        return sum;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        for(int i=0;i<matrix.size();i++){
            vector<int>store(matrix[i].size(),0);
            for(int k=0;k<matrix[i].size();k++){
                int cnt=0;
               for(int j=i;j>=0;j--){
                   if(matrix[j][k]=='1')++cnt;
                   else break;
                }
               store[k]=cnt;
            }
             res=max(res,largestRectangleArea(store));
        }
      return res;  
    }
};