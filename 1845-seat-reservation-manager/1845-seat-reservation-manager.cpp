class SeatManager {
public:
    vector<int>res;
    set<int>s;
    SeatManager(int n) {
        res.resize(n+1);
        for(int i=1;i<=n;i++)s.insert(i);
    }
    
    int reserve() {
        auto it=s.begin();
        int num=*it;
        // for(int i=1;i<res.size();i++){
        //     if(!res[i]){
        //         res[i]=1;
        //         num=i;
        //         break;
        //     }
        // }
        s.erase(num);
        return num;
    }
    
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */