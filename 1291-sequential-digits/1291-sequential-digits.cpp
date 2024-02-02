class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int>res;
        for(int i=0;i<s.size();i++){
            string temp;
            for(int j=i;j<s.size();j++){
                temp.push_back(s[j]);
                int val = stoi(temp);
                if(val>=low && val<=high)res.push_back(val);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};