//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        string yes=startWord;
        bool flag=0;
        queue<pair<string,int>>pq;
        set<string>s(wordList.begin(),wordList.end());
        pq.push({yes,1});
        while(!pq.empty()){
           string temp=pq.front().first;
           int dist=pq.front().second;
           pq.pop();
           string x=temp;
           if(temp==targetWord)return dist;
           for(int i=0;i<temp.size();i++){
               string v=x;
               for(int j=0;j<26;j++){
                   v[i]='a'+j;
                   if(s.find(v)!=s.end()){
                       pq.push({v,dist+1});
                       s.erase(v);
                   }
               }
           }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends