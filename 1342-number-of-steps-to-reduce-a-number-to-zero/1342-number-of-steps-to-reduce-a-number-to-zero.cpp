class Solution {
private:
 int step=0;
void helper(int n){
        if(n==0){
            return;
        }
        if(n%2==0){
            n=n/2;
            step++;
            helper(n);
        }
        else{
            n=n-1;
            step++;
            helper(n);
        }
       // return 0;
    }
public:
    int numberOfSteps(int num) {
        helper(num);
        return step;
    }
};