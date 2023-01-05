// class Solution {
// public:
//     int findMinArrowShots(vector<vector<int>>& points) {
//         // sort(points.begin(),points.end());
//         // for(auto it:points){
//         //     for(auto vt:it){
//         //         cout<<vt<<" ";
//         //     }cout<<endl;
//         // }
// //         //vector<bool>vis(n,0);
//         int n=points.size();
// // //         vector<bool>vis(n,0);
// // //         set<pair<int,int>>s;
// // //         int cnt=0;
// // //         for(int i=0;i<points.size()-1;i++){
// // //             if(points[i][1]>=points[i+1][0]){
// // //                 vis[i]=1;
// // //                 vis[i+1]=1;
// // //                 ++cnt;
// // //                s.insert({points[i][0],points[i+1][1]});
// // //              //  i+=1;
// // //             }else s.insert({points[i][0],points[i][1]});
// // //         }
        
// // //         if(points[n-1][0]<=points[n-2][1])++cnt;
// // //      //   cout<<points[n-1][0]<<" "<<points[n-2][1]<<endl;
// // //         //for(auto it:s)cout<<it.first<<" "<<it.second<<endl;
// // //         return cnt;
// //         vector<pair<int,int>>pair;
// //         int j=0;
// //         for(int i=0;i<n;i++){
// //            if(i==0){
// //                if(points[i][1]>=points[i+1][0]){
// //                    pair.push_back({points[i][0],max(points[i+1][1],points[i][1])});
// //                }else pair.push_back({points[i][0],points[i][1]});
// //                ++j;
// //            }else{
// //                if(pair[j-1].second>=points[i][1]){
// //                    pair[j-1].second=max(points[i][1],pair[j-1].second);
// //                }else{
// //                   pair.push_back({points[i][0],points[i][1]});
// //                    ++j;
// //                }
// //            }
// //         }for(auto it:pair)cout<<it.first<<" "<<it.second<<" ";
// //         cout<<endl;
// //         int cnt=pair.size();
// //       // if(pair[j-1].second<=points[n-1][0])++cnt;
// //         return cnt;
//         //return 2;
//         sort(points.begin(),points.end(),cmp);
//         int end=points[0][1];
//         for(int i=0;i<n;i++){
            
//         }
//     }
//     bool cmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];}
// };
bool cmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];}
class Solution {
public:  
    int findMinArrowShots(vector<vector<int>>& segments) {
        sort(segments.begin(), segments.end(), cmp);
        int ans = 0, arrow = 0;
        for (int i = 0; i < segments.size(); i ++) {
            if (ans == 0 || segments[i][0] > arrow) {
                ans ++;
                arrow = segments[i][1];
            }
        }
        return ans;
    }
};