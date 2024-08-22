class Solution {
public:
    int findComplement(int num) {  
     bitset<32> binary(num);
     int numx = 0;
     long long int base = 1;
     size_t index = 31;
     //cout<<binary<<endl;
     while(binary[index]==0)--index;
     for(size_t i = 0; i <= index; ++i){
        int bit = binary[i];  
        if(!bit)numx +=  base;
        base = base * 2;
       // cout<<numx<<endl;
     }
     return numx;
    }
};