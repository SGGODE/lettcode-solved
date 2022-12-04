class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
     long long int sum=0;
      int n=skill.size(); sort(skill.begin(),skill.end()); 
      int target=skill[n-1]+skill[0];
        int  s=0,e=n-1;
       while(s<e){
           if((skill[e]+skill[s])!=target){
               return -1;
           }
           sum+=(skill[e]*skill[s]);
           s++;e--;
       }
        return sum;
    }
};