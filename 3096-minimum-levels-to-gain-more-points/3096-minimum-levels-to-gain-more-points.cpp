class Solution {
private:
    int existsPartition(std::vector<int>& arr) {
    int n = arr.size();
    
    int leftSum = 0, rightSum = 0;

    // Calculate the total sum of the array
    int totalSum = 0;
    for(int num : arr) {
        totalSum += num;
    }

    // Iterate through the array to find the partition
    for(int i = 0; i < n-1; i++) {
        leftSum += arr[i];
        rightSum = totalSum - leftSum;

        if(leftSum > rightSum) {
            return i+1;
        }
    }

    return -1;
}
public:
    int minimumLevels(vector<int>& possible) {
        // int sum = 0;
        // bool pos = 0;
        // for(auto&it:possible){
        //     sum+=it;
        //     if(sum>0)pos=1;
        // }
        // if(!pos)return -1;
        // int csum = 0;
        // for(int i=0;i<possible.size();i++){
        //     csum+=possible[i];
        //     if(csum>(sum-csum))return i+1;
        // }
        // return -1;
        for(int i=0;i<possible.size();i++){
           if(possible[i]==0)possible[i]=-1;
        }
        return existsPartition(possible);
    }
};