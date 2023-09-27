class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // string res;
        // //cout<<res.max_size()<<endl;
        // long long curr = 0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]>='0'&&s[i]<='9'){
        //         long long int num = 0;
        //         while(i<s.size()&&s[i]>='0'&&s[i]<='9'){
        //             int last = s[i]-'0';
        //             num = num*10+last;
        //             i++;
        //         }
        //         //cout<<num<<" "<<i<<endl;
        //         --i;
        //         --num;
        //         string temp = res;
        //       //  cout<<curr+(num*curr)<<endl;
        //         if((long long)curr+(num*curr)==k||(curr+(num*curr)>=k&&k%curr==0)){
        //             string x;
        //             x.push_back(res[curr-1]);
        //             return x;
        //         }else if((long long)curr+(num*curr)>k){
        //             string x;
        //             x.push_back(res[(k%curr)-1]);
        //             return x;
        //         }else{
        //            while(num!=0){
        //               res.append(temp);
        //               --num;
        //               if(res.size()>=k){
        //                  string x;x.push_back(res[k-1]);
        //                  return x;
        //               }
        //           }
        //            // curr=res.size();
        //         }
        //         if(res.size()>=k){
        //             string x;
        //             x.push_back(res[k-1]);
        //             return x;
        //         }
        //     }else{
        //         res.push_back(s[i]);
        //         //curr=res.size();
        //         if(res.size()>=k){
        //             string x;
        //             x.push_back(res[k-1]);
        //             return x;
        //         }
        //     }
        //   //  cout<<res<<endl;
        //     curr=res.size();
        // } 
        // string x;
        // x.push_back(res[k-1]);
        // return x;
          long long length = 0;
        int i = 0;
        
        while (length < k) {
            if (isdigit(s[i])) {
                length *= s[i] - '0';
            } else {
                length++;
            }
            i++;
        }
        
        for (int j = i - 1; j >= 0; j--) {
            if (isdigit(s[j])) {
                length /= s[j] - '0';
                k %= length;
            } else {
                if (k == 0 || k == length) {
                    return std::string(1, s[j]);  // Convert char to std::string
                }
                length--;
            }
        }
        
        return ""; 
    }
};