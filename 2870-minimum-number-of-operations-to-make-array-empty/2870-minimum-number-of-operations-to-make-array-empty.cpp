class Solution{
private:
    int minimumtime(int x){
        if(x==2||x==4)return x/2;
        if(x==3)return 1;
        int sum = 0;
        while(x!=0){
            if(x==2||x==4){sum+=(x/2);break;}
            x-=3;
            ++sum;
        }
        return sum;
    }
public:
     int minOperations(vector<int>&nums){
         map<int,int>mp;
         for(auto&it:nums)mp[it]++;
         int sum = 0;
         for(auto&it:mp){
             if(it.second==1)return -1;
             else sum+=minimumtime(it.second);
         }
         return sum;
     }
};