class Solution {
private:
    
    // int sub(vector<int>&work,vector<int>&make,vector<int>&able,int index){
    //     if(index==able.size())return 0;
    //     int ans = 0;
    //     for(int i=0;i<work.size();i++){
    //         if(work[i]<=able[index]){
    //             ans = max(ans,make[i]+sub(work,make,able,index+1));
    //         }
    //     }
    //     //cout<<ans<<endl;
    //     return ans;
    // }
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
      //  return sub(difficulty,profit,worker,0);
        int sum = 0;
        for(int i=0;i<worker.size();i++){
            int val = 0;
            for(int j=0;j<profit.size();j++){
                if(difficulty[j]<=worker[i]){
                    val = max(val,profit[j]);
                }
            }
            sum+=val;
        }
        return sum;
    }
};