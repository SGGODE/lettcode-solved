class Solution {
public:
    // vector<string> fullJustify(vector<string>&nums, int maxWidth) {
    //     vector<string>res;
    //     int n = nums.size();
    //     vector<bool>vis(n,0);
    //     for(int i=0;i<n;i++){
    //         string temp;bool flag=0;
    //         for(int j=i;j<n;j++){
    //             if(!vis[j]&&(temp.size()+(nums[j].size()+1)<=maxWidth||temp.size()+nums[j].size()<=maxWidth)){
    //                if(temp.size()+(nums[j].size()+1)<=maxWidth){
    //                    temp.append(nums[j]);
    //                    temp.push_back(' ');
    //                    vis[j]=1;
    //                }else{
    //                   temp.append(nums[j]);
    //                    vis[j]=1;
    //                }
    //                 flag=1;
    //             }else break;
    //         }
    //         if(temp.size()!=maxWidth&&temp.size()!=0){
    //             while(temp.size()<maxWidth){
    //                 temp.push_back(' ');
    //             }
    //           //  res.push_back(temp);
    //         }
    //         if(flag)res.push_back(temp);
    //     }
    //     return res;
    // }
    void spaceJustify(string &s,int maxWidth,bool lastLine)
    {
        if(s.length()==maxWidth)return;
        int no_of_spaces=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')no_of_spaces++;
        }
        int spaces_to_be_inserted=maxWidth-s.length();
        if(no_of_spaces==0 || lastLine)
        {
            s.insert(s.length(),spaces_to_be_inserted,' ');
            return;
        }
        int left_addition=(spaces_to_be_inserted)%(no_of_spaces);
        int common_addition=(spaces_to_be_inserted)/(no_of_spaces);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ' &&(left_addition>0 || common_addition))
            {
                int spaces=common_addition;
                if(left_addition)
                {
                    spaces+=1;
                    left_addition--;
                }
                s.insert(i,spaces,' ');
                i+=spaces;
            }
        }
        return ;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
       int n=words.size();
       vector<string>res;
       string line=words[0];
       for(int i=1;i<n;i++)
       {
           if(line.size()+words[i].length()+1<=maxWidth)
           {
               line+=" "+words[i];
           }
           else
           {
               spaceJustify(line,maxWidth,false);
               res.push_back(line);
               line=words[i];
           }
       }
        
       spaceJustify(line,maxWidth,true);
       res.push_back(line); 
       return res;
    }
};