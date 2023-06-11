class SnapshotArray {
public:
    int cnt=0;
    vector<vector<pair<int,int>>>curr;
    SnapshotArray(int length) {
        curr.resize(length);
       for(int i=0;i<length;i++)curr[i].push_back({0,0});
    }
    void set(int index, int val) {
         curr[index].push_back({cnt,val});
    }
    int snap(){
       // ++cnt;
       return cnt++;
    }
    int get(int index, int snap_id) {
        auto it = upper_bound(curr[index].begin(),curr[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
        //return curr[index][snap_id].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */