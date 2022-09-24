class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
    string word;
    vector<string> x;
    while(ss>>word)
     x.push_back(word);
    s.clear();
    for(int i=x.size()-1;i>=0;i--){
        s+=x[i];
      if(i==0)
          continue;
        s+=" ";
    }
        return s;
    }
};