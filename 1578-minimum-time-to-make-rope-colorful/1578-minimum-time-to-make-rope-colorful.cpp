class Solution {
//private:
   // int sub()
public:
    int minCost(string colors, vector<int>& need) {
       // return sub(colors,need,0,0)
        int j = 0;
        int total = 0;
        for(int i=1;i<need.size();i++){
            if(colors[i]==colors[i-1]){
                int j = i-1;
                int sum = 0,maxele = 0;
                while(j<need.size()&&colors[j]==colors[i]){
                    sum+=need[j];
                    maxele=max(maxele,need[j]);
                    j++;
                }
                i=j;
                total += (sum-maxele);
            }
        }
        return total;
    }
};