class Solution {
public:
    map<string,string>mp;
    int cnt = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string x="https://tiny"+to_string(cnt);
        ++cnt;
        mp[x]=longUrl;
        return x;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));