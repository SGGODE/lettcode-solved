class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=num;i++){
            int x=i,y=0;
            string s=to_string(x);
            reverse(s.begin(),s.end());
           // y=stoi(s);
            if(x+stoi(s)==num) return 1;
        }
        return 0;
    }
};