class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        //to store pattern/count of the chars.
        map<char,int>mp;
        //actually map the present pattern.
        for(auto&it:chars)mp[it]++;
        //to store the possible length
        int len = 0;
        //now lets traverse.
        for(auto&it:words){
            //for every string map its pattern/chars and check weather it is present in `chars` or not
            //if at any moment the pattern in current string donot match with `chars` just make rise flag zero.
            map<char,int>mx;
            bool flag = 1;
            for(auto vt:it){
                mx[vt]++;
                if(!(mp[vt]>=mx[vt]))flag=0;
            }
            // if flag is fine then add.
            if(flag)len+=it.size();
        }
        //return 
        return len;
    }
};