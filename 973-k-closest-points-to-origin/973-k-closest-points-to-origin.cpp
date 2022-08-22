class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>>q;
        for(int i=0;i<points.size();i++){
            int x=points[i][0],y=points[i][1];
            q.push({x*x + y*y,x,y});
            if(q.size()>k)
              q.pop();
        }
        vector<vector<int>> v;
        for(int i=0;i<k;i++){
            vector<int> x=q.top();
            int a=x[1];
            int b=x[2];
            v.push_back({a,b});
            q.pop();
        }
        return v; 
    }
};