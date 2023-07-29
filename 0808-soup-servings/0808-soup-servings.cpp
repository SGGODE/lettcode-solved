class Solution {
public:
    vector<pair<int,int>> serves{{100,0},{75,25},{50,50},{25,75}};
       
    vector<vector<double>> t;
    double probability(double a,double b){

        if(a<=0 && b<=0)
            return 0.5;
        if(a<=0) 
            return 1;
        if(b<=0) 
            return 0.0;

        if(t[a][b] != -1.0)
            return t[a][b];

        double prob=0.0;
        for(auto &p:serves)
        {
            int ataken = p.first;
            int btaken = p.second;

            prob+= probability(a-ataken,b-btaken);
        }
        return t[a][b]=0.25*prob;

    }
    double soupServings(int n) {
        if(n >= 6000)
            return 1.0;
        
        t.resize(n+1, vector<double>(n+1, -1.0));
        return probability(n,n);
    }
};