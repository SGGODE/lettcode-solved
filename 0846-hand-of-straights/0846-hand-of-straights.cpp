class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize)return 0;
        map<int,int>hash;
        set<int>number;
        for(auto&it:hand){
            hash[it]++;
            number.insert(it);
        }
        while(!number.empty()){
            int it = *number.begin();
            int k = groupSize;
            while(k!=0&&number.count(it)){
                hash[it]--;
                if(hash[it]==0)number.erase(it);
                k--;it++;
            }
            if(k!=0)return 0;
        }
        return 1;
    }
};