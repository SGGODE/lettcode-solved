class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int count = 1;
        string word;
        stringstream ss(sentence);
        while(ss >> word){
            int start = word.find(searchWord);
            if(word.find(searchWord) != string::npos && start == 0){
                return count;
            }
            ++count;
        }
        return -1;
    }
};