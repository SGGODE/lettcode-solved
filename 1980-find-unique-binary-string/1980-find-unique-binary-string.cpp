class Solution {
private:
    void sub(string&temp,string&res,set<string>&st,int index){
        if(st.find(temp)==st.end()){res=temp;return;}
        if(index==temp.size())return;
        sub(temp,res,st,index+1);
        temp[index]='1';
        sub(temp,res,st,index+1);
        temp[index]='0';
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string temp;
        int n = nums.size();
        int i = 0;
        while(i<n){
            temp.push_back('0');
            ++i;
        }
       // cout<<temp<<endl;
        set<string>s;
        for(auto&it:nums)s.insert(it);
        if(s.find(temp)==s.end())return temp;
        string res;
        sub(temp,res,s,0);
        return res;
    }
};