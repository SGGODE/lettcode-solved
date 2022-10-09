class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
       /* vector<int>v;
        v.push_back(pref[0]);
        for(int i=1;i<pref.size();i++){
            int so=pref[i];
            for(int j=0;j<i;j++){
                so^=v[j];
            }
            v.push_back(so);
        }
        return v;*/
        int n=pref.size();
        for(int i=n-1;i>0;--i){
            pref[i]^=pref[i-1];
        }
      return  pref;
    }
};