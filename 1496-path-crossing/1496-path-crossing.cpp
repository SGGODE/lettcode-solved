class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,int>mp;
        int row = 0,col = 0;
        mp[{0,0}]++;
        for(auto&it:path){
            if(it=='N'){row+=1;col+=1;}
            if(it=='S'){row-=1;col-=1;}
            if(it=='E'){col+=1;}
            if(it=='W'){col-=1;}
            if(mp.count({row,col}))return 1;
             mp[{row,col}]++;
        }
        return 0;
    }
};