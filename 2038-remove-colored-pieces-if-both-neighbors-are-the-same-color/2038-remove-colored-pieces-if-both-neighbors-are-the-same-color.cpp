class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0;
        int bob = 0;
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                int j = i-1;
                while(j<colors.size()&&colors[i]==colors[j]){
                    j++;
                }
                if((j-i)+1>=3){
                    if(colors[i]=='A'){
                        alice += ((j-i)+1)-2;
                    }else{
                        bob += ((j-i)+1)-2;
                    }
                }
                i=j-1;
            }
        }
       // if(alice==0)return 0;
        return alice>bob;
    }
};