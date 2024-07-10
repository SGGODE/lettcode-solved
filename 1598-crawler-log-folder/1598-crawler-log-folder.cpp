class Solution {
public:
    int minOperations(vector<string>& logs) {
        unordered_map<string , int>fileindex;
        int level = 0;
        for(auto & it : logs){
            if(it == "../"){
                if(level!=0)--level;
            }else if(it != "./"){
                ++level;
            }
        }
        return level;
    }
};