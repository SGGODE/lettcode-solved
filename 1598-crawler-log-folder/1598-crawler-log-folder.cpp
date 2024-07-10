class Solution {
public:
    int minOperations(vector<string>& logs) {
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