class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();
        int l = 0,h = 0;
        while(l<n||h<m){
            int x=0,y=0;
            while(l<n&&version1[l]!='.'){x=x*10+int(version1[l]-'0');l++;}
            while(h<m&&version2[h]!='.'){y=y*10+int(version2[h]-'0');h++;}
            if(x<y)return -1;
            if(x>y)return 1;
            h++;
            l++;
        }
        return 0;
    }
};