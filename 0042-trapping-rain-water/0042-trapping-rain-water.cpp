class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int n = height.size();
        int mele = height[0];
        vector<int>right(n),left(n);
        for(int i=0;i<n;i++){
            mele = max(mele,height[i]);
            right[i]=mele;
        }
        mele = height[n-1];
        for(int i=n-1;i>=0;i--){
            mele = max(mele,height[i]);
            left[i]=mele;
        }
        for(int i=0;i<n;i++){
            water += (min(right[i],left[i])-height[i]);
        }
        return water;
    }
};