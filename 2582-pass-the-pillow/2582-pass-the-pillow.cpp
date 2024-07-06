class Solution {
public:
    int passThePillow(int n, int time) {
        int result = 0;
        int curr = 0;
        int node = 1;
        int nt = 0 , p = 1; 
        while(curr<time){
            ++curr;
            if(p)++node;
            if(nt)--node;
            if(node==n){nt=1;p=0;}
            if(node==1){nt=0;p=1;}
        }
        return node==0?n:node;
    }
};