class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string result;
        for(int i=0;i<n;i++){
            int j = i,cnt=0;
            while(j<n&&word[i]==word[j]&&cnt<10){if(cnt+1<10)++j;++cnt;}
            if(cnt<10){
                result.append(to_string(cnt));
                result.push_back(word[i]);
                i=j-1;
            }else{
                result.push_back('9');
                result.push_back(word[i]);
                i=j-1;
            }
            
        }
        return result;
    }
};