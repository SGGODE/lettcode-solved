class Solution {
public:
    int totalMoney(int n) {
        int start = 1;
        int last = 1;
        int total = 1;
        int step = 1;
        --n;
        while(n!=0){
            ++step;
            ++start;
            --n;
            if(step%8==0){
                start = last+1;
                last=start;
                step=1;
            }
            total+=start;
        }
        return total;
    }
};