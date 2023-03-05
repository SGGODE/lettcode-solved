class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       int s=1;
        int e=1000000000;
        while(s<e){
            int m=(s+e)/2;
            int total=0;
            for(auto it:nums){
                int x=it/m;
                if(x*m<it)x+=1;
                total+=x;
            }
            if(total>threshold){
                s=m+1;
            }else{
                e=m;
            }
        }
        return s;
    }
};