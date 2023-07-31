class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int index=-1;
        int n = words.size(); 
        vector<int>res;
        for(int i=0;i<words.size();i++){
            if(words[i]==target){
                res.push_back(i);
            }
        }
        int result=INT_MAX;
        if(res.empty())return -1;
        else{
            for(int i=0;i<res.size();i++){
             result=min(result,min(abs(res[i]-startIndex),min(abs((n-res[i])+startIndex),abs(n-startIndex)+res[i])));
            }
        }
       return result;
    }
};