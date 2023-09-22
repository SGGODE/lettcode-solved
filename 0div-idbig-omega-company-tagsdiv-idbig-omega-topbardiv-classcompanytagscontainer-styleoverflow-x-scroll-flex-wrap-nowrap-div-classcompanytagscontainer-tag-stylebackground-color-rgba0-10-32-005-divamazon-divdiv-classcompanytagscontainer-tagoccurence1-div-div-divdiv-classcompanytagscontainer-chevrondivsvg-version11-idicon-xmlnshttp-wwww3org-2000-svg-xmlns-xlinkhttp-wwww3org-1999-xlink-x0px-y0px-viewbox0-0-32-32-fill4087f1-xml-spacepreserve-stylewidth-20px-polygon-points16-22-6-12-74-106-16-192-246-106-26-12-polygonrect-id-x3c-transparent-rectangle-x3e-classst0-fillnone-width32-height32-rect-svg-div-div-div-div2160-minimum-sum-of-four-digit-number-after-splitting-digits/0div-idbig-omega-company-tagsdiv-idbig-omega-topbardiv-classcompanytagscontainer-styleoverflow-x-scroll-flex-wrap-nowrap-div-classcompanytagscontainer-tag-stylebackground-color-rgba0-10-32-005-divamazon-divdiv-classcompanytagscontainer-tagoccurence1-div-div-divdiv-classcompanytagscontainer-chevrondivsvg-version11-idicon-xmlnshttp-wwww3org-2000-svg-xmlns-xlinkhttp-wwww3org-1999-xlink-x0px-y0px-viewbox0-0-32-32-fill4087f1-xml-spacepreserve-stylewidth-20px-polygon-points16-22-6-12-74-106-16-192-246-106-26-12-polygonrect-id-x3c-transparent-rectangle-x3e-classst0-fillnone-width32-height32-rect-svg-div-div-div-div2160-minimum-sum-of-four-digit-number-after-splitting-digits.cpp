class Solution {
public:
    int minimumSum(int num) {
        int newnum = 0;
        int sum = INT_MAX;
        string res = to_string(num);
        string temp;
        sort(res.begin(),res.end());
      //  string curr=res;
      //  res.reverse
        return (res[0]-'0'+res[1]-'0')*10+res[2]-'0'+res[3]-'0';
    }
};