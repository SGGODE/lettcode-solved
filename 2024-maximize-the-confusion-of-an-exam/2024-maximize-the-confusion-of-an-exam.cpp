class Solution {
private:
    int sub(string&nums,char last,int magicpins,int index,int remain){
        if(index==nums.size())return 0;
        if(magicpins==0&&nums[index]!=last)return 0;
        int notpick=sub(nums,'-1',remain,index+1,remain);
        int pick=0;
        if(nums[index]==last||last=='-1'){
            pick=max(pick,1+sub(nums,nums[index],magicpins,index+1,remain));
        }
        if(nums[index]!=last){
            pick=max(pick,1+sub(nums,nums[index],magicpins-1,index+1,remain));
        }
        return max(pick,notpick);
    }
public:
    int maxConsecutiveAnswers(string nums, int k) {
        int len=0;
        int n =nums.size();
        int j=0;int cnt=0;
        for(int i=0;i<n;i++){
          if(nums[i]=='F')++cnt;
           while(cnt>k){
              if(nums[j]=='F'){
                  --cnt;
              }
               ++j;
           }
            len=max(len,(i-j)+1);
        }
        j=0,cnt=0;
         for(int i=0;i<n;i++){
          if(nums[i]=='T')++cnt;
           while(cnt>k){
              if(nums[j]=='T'){
                  --cnt;
              }
               ++j;
           }
            len=max(len,(i-j)+1);
        }
       
        return len;
    }
};