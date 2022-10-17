class Solution {
public:
    void reverseString(vector<char>& s) {
       // return reverse(s.begin(),s.end());
        int n=s.size();
    for(int i=0;i<n/2;i++){
        swap(s[i],s[n-i-1]);
    }
        //return s;
    }
};