/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* dfs(vector<vector<int>>& grid,int n,int i,int j){
        bool same=1;
        for(int k=i;k<n;k++){
            for(int m=j;m<n;m++){
                if(grid[i][j]!=grid[k][m]){
                    same=0;
                    break;
                }
            }
        }
        Node* result;
        if(same){
            result=new Node(grid[i][j],1);
            return result;
        }
        n=n/2;
        result=new Node();
        result->topLeft=dfs(grid,n,i,j);
        result->topRight=dfs(grid,n,i,j+n);
        result->bottomLeft=dfs(grid,n,i+n,j);
        result->bottomRight=dfs(grid,n,i+n,j+n);
        //result =new Node(0,0,topleft,topright,bottomleft,bottomright);
        return result;
    }
      Node* helper(vector<vector<int>>&grid,int up,int down,int left,int right){
        bool allsame=true;
        for(int i=up;i<down;i++)
            for(int j=left;j<right;j++)
                if(grid[i][j]!=grid[up][left]){allsame=false;break;}
        Node*result;
        if(allsame){
            result = new Node(grid[up][left],1);
        }
        else{
            result = new Node();
            int midrightleft=(left+right)/2;
            int midupdown=(up+down)/2;
            result->topLeft = helper(grid,up,midupdown,left,midrightleft);
            result->topRight = helper(grid,up,midupdown,midrightleft,right);
            result->bottomLeft = helper(grid,midupdown,down,left,midrightleft);
            result->bottomRight = helper(grid,midupdown,down,midrightleft,right);
        }
        return result;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
       // return dfs(grid,n,0,0);
           return helper(grid,0,grid.size(),0,grid.size());
    }
};