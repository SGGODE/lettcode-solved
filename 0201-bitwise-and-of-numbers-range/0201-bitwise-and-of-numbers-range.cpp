class Solution {
private:
    string decToBinary(int n){ 
    // array to store binary number 
    int binaryNum[32]; 
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    string s;
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        s.push_back(binaryNum[j]+'0');
        
    return s;
} 
public:
    int rangeBitwiseAnd(int left, int right) {
        string lt = decToBinary(left);
        string rt = decToBinary(right);
        int n = lt.size();
        int m = rt.size();
        string result;
        result.push_back('0');
        if(n==m){
            for(int i=0;i<n;i++){
                if(lt[i]!=rt[i])break;
                result.push_back(lt[i]);
            }
            int x = result.size()-1;
            while(x<n){
               result.push_back('0');
                ++x;
            }
        }
        return stoi(result, 0, 2);
    }
};