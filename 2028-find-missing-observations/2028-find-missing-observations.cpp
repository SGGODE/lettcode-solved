class Solution {
private:
    vector<int> breakIntoSum(int sum, int n) {
    if(sum > n*6 || sum < 0 || sum < n)return {};
    vector<int>result;
    int x = n;
    while(x!=0 && sum != 0){
        int curr = sum%x == 0 ? (sum/x) : (sum/x)+1;
        result.push_back(curr);
        sum -= curr;
        x--;
    }
    if(sum)return {};
    return result;
}
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = (n+m)*mean;
        int sum = accumulate(rolls.begin(),rolls.end(),0);
        int diff = total - sum;
       // return {4,8};
        return breakIntoSum(diff,n);
    }
};