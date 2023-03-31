//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>>res;
        queue<vector<string>>pq;
        pq.push({beginWord});
        vector<string>used;
        unordered_set<string>st(wordList.begin(),wordList.end());
        int level=0;
        while(!pq.empty()){
            vector<string>ves=pq.front();
            pq.pop();
            if(ves.size()>level){
                ++level;
                for(auto it:used){
                    st.erase(it);
                }
               // used.erase();
            }
            string word=ves.back();
            if(word==endWord){
                if(res.size()==0)res.push_back(ves);
                else if(res[0].size()==ves.size()){
                res.push_back(ves);
              }
            }
            for(int i=0;i<word.size();i++){
                string x=word;
                for(int j=0;j<26;j++){
                    x[i]='a'+j;
                    if(st.find(x)!=st.end()){
                        ves.push_back(x);
                        used.push_back(x);
                        pq.push(ves);
                        ves.pop_back();
                    }
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends