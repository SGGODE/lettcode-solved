class FoodRatings {
public:
    map<string,set<pair<int,string>>>cuisin;
    map<string,string>food;
    map<string,int>rat;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            cuisin[cuisines[i]].insert({-ratings[i],foods[i]});
            food[foods[i]]=cuisines[i];
            rat[foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food_name, int newRating) {
        string cui = food[food_name];
        int ra = rat[food_name];
        cuisin[cui].erase({-ra,food_name});
        cuisin[cui].insert({-newRating,food_name});
        rat[food_name] = newRating;
    }
    
    string highestRated(string cuisine) {
        // priority_queue<pair<int,string>>pq;
        // for(auto&it:cuisin[cuisine]){
        //     pq.push({it.second,it.first});
        // }
        // string res = pq.top().second;
        // int rate = pq.top().first;
        // pq.pop();
        // while(rate==pq.top().first&&!pq.empty()){
        //     res = min(res,pq.top().second);
        //     pq.pop();
        // }
        // return res;
        pair<int,string> p = *cuisin[cuisine].begin();
        return p.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */