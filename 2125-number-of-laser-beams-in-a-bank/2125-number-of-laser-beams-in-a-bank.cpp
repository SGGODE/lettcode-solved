class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        //return 8;
        int last = 0;
        int sum = 0;
        for(int i=0;i<bank.size();i++){
            int curr = 0;
            for(auto&it:bank[i]){
                if(it=='1')++curr;
            }
            sum += (last*curr);
            if(curr!=0)last = curr;
        }
        return sum;
    }
};