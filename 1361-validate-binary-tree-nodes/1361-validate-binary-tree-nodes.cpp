class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>degree(n,0);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1)degree[leftChild[i]]++;
            if(rightChild[i]!=-1)degree[rightChild[i]]++;
        }
        int par = -1;
        for(int i=0;i<n;i++){
            if(degree[i]==0){
                if(par==-1)par=i;
                else return 0;
            }
        }
        if(par==-1)return 0;
        queue<int>pq;
        set<int>s;
        pq.push(par);
        while(!pq.empty()){
            int node = pq.front();
            pq.pop();
            if(s.find(node)!=s.end())return 0;
            s.insert(node);
            if(leftChild[node]!=-1){
                pq.push(leftChild[node]);
            }
            if(rightChild[node]!=-1){
                 pq.push(rightChild[node]); 
            }
        }
        return s.size()==n;
    }
};