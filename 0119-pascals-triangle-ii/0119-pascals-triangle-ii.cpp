class Solution {
public:
    vector<int> getRow(int row) {
        if(row==0)return {1};
        if(row==1)return {1,1};
        vector<int>temp;temp.push_back(1);temp.push_back(1);
        vector<int>curr;
        for(int i=2;i<=row;i++){
            curr.push_back(1);
            for(int j=1;j<i;j++){
                curr.push_back(temp[j-1]+temp[j]);
            }
            curr.push_back(1);
            temp=curr;
            curr.clear();
        }
        return temp;
    }
};