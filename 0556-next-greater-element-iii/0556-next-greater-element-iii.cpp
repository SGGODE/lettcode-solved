class Solution {
private:
    long long int mx = 9223372036854775807;
    long long int sub(string&s,int index,int n){
        if(index>=s.size()){
            return (stoll(s)>n)?stoll(s):mx;
        }
        long long int ans = mx;
        ans = min(ans,sub(s,index+1,n));
        for(int i=index+1;i<s.size();i++){
            swap(s[index],s[i]);
            ans = min(ans,sub(s,index+1,n));
            swap(s[i],s[index]);
        }
        return ans;
    }
public:
    int nextGreaterElement(int n) {
         string x = to_string(n);
        long long int res = sub(x,0,n);
        return res>INT_MAX?-1:res;
        // next_permutation(x.begin(),x.end());
        // return (stoll(x)>INT_MAX||stoll(x)<n)?-1:stoll(x);
    }
};