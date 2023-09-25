class Solution {
private:
    map<pair<int,int>,double>mp;
    void sub(int row,int col,double sum,int tr,int tc){
        if(row>=tr)return;
       // if(sum<=0)return
       if(row==0&&col==0){
           if(sum>1){
               mp[{row,col}]=1;
               mp[{row+1,col}]+=(sum-1)/2;
               mp[{row+1,col+1}]+=(sum-1)/2;
               sub(row+1,col,(sum-1)/2,tr,tc);
               sub(row+1,col+1,(sum-1)/2,tr,tc);
           }
       }else{
           if(mp[{row,col}]>1){
               double x = mp[{row,col}];
               double d = abs(1-x);
               mp[{row+1,col}]+=(d)/2;
               mp[{row+1,col+1}]+=(d)/2;
               sub(row+1,col,d/2,tr,tc);
               sub(row+1,col+1,d/2,tr,tc);
           }
       }
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // //sum-=1;
        // sub(0,0,sum,query_row,query_glass);
        // return mp.count({query_row,query_glass})?mp[{query_row,query_glass}]:0;
        if (poured==0) return 0;
        vector<vector<double>> A(query_row+2, vector<double>(query_row+2 , 0));
        A[0][0]=poured;
        for(int i=0; i<=query_row; i++){
            for(int j=0; j<=i; j++){
                double A_ij=A[i][j];
                if ( A_ij<=1) continue;
                double excess=(A_ij-1)/2.0;
                A[(i+1)][j]+= excess;
                A[(i+1)][j+1]+= excess;
            }
        }
        return min(1.0, A[query_row][query_glass]);
    }
};