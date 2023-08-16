class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int>res;
        // deque<int>s;
        // //deque<int>::iterator maxElementIt = max_element(myDeque.begin(), myDeque.end());
        // for(int i=0;i<nums.size();i++){
        //     s.push_back(nums[i]);
        //     if(s.size()==k){                                                                                                                                   
        //         deque<int>::iterator it = max_element(s.begin(), s.end());
        //         res.push_back(*it);
        //     }
        //     if(s.size()>k){
        //         s.pop_front();
        //         deque<int>::iterator it = max_element(s.begin(), s.end());
        //         res.push_back(*it);
        //     }
        // }
        // return res;
        vector<int>res;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        res.push_back(pq.top().first);
        for(int i=k;i<nums.size();i++){
            pq.push({nums[i],i});
            // if(pq.size()==k){
            //     res.push_back(pq.top().first);
            // }
            //if(pq.size()>k){
                while(!(pq.top().second>(i-k))){
                    pq.pop();
                }
                 res.push_back(pq.top().first);
            //}
        }
        return res;
    }
};