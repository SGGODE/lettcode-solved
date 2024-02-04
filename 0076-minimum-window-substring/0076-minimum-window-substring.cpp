class Solution {
public:
    string minWindow(string s, string t) {
        int fs[256]={0};
        int fp[256]={0};
        for(int i=0;i<t.size();i++)
            fp[t[i]]++;
        
        int c=0;
        int start=0;
        int window_size;
        int start_idx=-1;
        int min_so_far=INT_MAX;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            fs[ch]++;
            if(fs[ch]!=0 && fs[ch] <= fp[ch])
                c++;
            if(c==t.length()){
                while(fp[s[start]]==0 || fs[s[start]] > fp[s[start]]){
                    fs[s[start]]--;
                    start++;
                }
                window_size=i-start+1;
                if(window_size < min_so_far){
                  min_so_far=window_size;
                    start_idx=start;
                }
            }
        }
        if(start_idx==-1)
            return "";
        
        return s.substr(start_idx,min_so_far);
    }
};