class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double>res;
        for(int i=0;i<dist.size();i++){
            res.push_back((double)dist[i]/speed[i]);
        }
        sort(res.begin(),res.end());
        //for(auto&it:res)cout<<it<<" ";
       // cout<<endl;
        double cnt = 0;
        for(int i=0;i<dist.size();i++){
            if(cnt<res[i]){
                cnt+=1;
            }else{
                return i;
            }
        }
        return dist.size();
    }
};