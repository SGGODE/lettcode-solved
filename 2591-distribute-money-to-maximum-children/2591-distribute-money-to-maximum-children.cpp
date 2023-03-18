class Solution {
public:
    int distMoney(int money, int children) {
        if(children>money)return -1;
        if(children==money)return 0;
        if(money<8)return 0;
        if(money==8&&children==1)return 1;
        if(money==8&&children>1)return 0;
        // if(money%8==0){
        //     return money/8;
        // }
        int cnt=0;
        while(money>=8&&children!=1){
            ++cnt;
            --children;
            money-=8;
        } 
        if(money==8&&children==1)return cnt+1;
        if(children>money||(money==4&&children==1)){
            while(children>money||money==4){
                --cnt;
                ++children;
                money+=8;
            }
        }
        return cnt;
    }
};