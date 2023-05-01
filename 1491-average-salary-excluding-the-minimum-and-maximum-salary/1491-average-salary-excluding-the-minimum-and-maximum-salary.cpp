class Solution {
public:
    double average(vector<int>& salary) {
        int m=*max_element(salary.begin(),salary.end());
        int mi=*min_element(salary.begin(),salary.end());
        double cnt=0;
        double sum=0;
        for(int i=0;i<salary.size();i++){
            if(m==salary[i]||mi==salary[i])continue;
            else{
                ++cnt;
                sum+=salary[i];
            }
        }
        return sum/cnt;
    }
};