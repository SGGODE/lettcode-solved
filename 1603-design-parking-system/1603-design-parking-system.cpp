class ParkingSystem {
public:
    map<int,int>mp;
    ParkingSystem(int big, int medium, int small) {
        mp[1]=big;
        mp[2]=medium;
        mp[3]=small;
    }
    
    bool addCar(int carType) {
        if(mp[carType]==0)mp.erase(carType);
        if(mp.count(carType)){
            --mp[carType];
            if(mp[carType]==0)mp.erase(carType);
            return 1;
        }
        return 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */