class Solution {
public:
    int hammingWeight(uint32_t n) {
        //to count total number of set bits.
        int cnt = 0;
        while(n!=0){//while number not become zero run the loop
            if(n&1!=0)++cnt;//simply check weather the current bit at place 1 is set or not it set increment the counter.
            n>>=1;//shift the bits by place one.
        }
        return cnt;//return final count.
    }
};