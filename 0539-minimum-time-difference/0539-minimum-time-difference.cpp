class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>time;
        for(int i=0;i<timePoints.size();i++){
            string x=timePoints[i];
            int c=stoi(x.substr(0,3));
            int p=stoi(x.substr(3,6));
            //cout<<c<<" "<<p<<endl;
            time.push_back((c*60)+p);
        }
        sort(time.begin(),time.end());
     //   for(auto&it:time)cout<<it<<" ";
     //   cout<<endl;
        int res=INT_MAX;
        for(int i=0;i<time.size();i++){
            for(int j=i+1;j<time.size();j++){
                res=min(res,min(abs(1440-time[j])+time[i],abs(time[j]-time[i])));
            }
        }
        return res;
    }
};