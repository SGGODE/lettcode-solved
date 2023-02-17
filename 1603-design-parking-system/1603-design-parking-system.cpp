class ParkingSystem {
public:
    int b=0,m=0,s=0;
    ParkingSystem(int big, int medium, int small) {
       b=big;m=medium;s=small; 
    }
    
    bool addCar(int carType) {
       if(carType==1&&b>0){
           --b;
           return 1;
       }else if(carType==3&&s>0){
           --s;
           return 1;
       }else if(carType==2&&m>0){
           --m;
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