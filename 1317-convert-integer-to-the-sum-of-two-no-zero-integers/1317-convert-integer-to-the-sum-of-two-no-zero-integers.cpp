class Solution {
bool check(int x,int y){
    bool flag1=1;
    bool flag2=1;
    while(x!=0){
        int last=x%10;
        if(last==0)return 0;
        x=x/10;
    }
    while(y!=0){
        int last=y%10;
        if(last==0)return 0;
        y=y/10;
    }
    return 1;
}
public:
    vector<int> getNoZeroIntegers(int n) {
        //if()
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(i+j==n&&check(i,j)){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};