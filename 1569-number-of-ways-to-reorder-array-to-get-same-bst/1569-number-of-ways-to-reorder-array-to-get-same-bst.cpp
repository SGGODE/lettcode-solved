#define MOD 1000000007

class Node {
public:
    int size,flag;
    Node *l,*r;
    Node(int s=1,Node* a=NULL,Node* b=NULL):size(s),flag(0),l(a),r(b){}
};

class Solution {
public:
    int numOfWays(vector<int>& nums) {
            int n=nums.size();
        int inv[n+1];inv[1]=1;
        long long s=1;
        for(int i=2;i<=n;i++)
        {
            inv[i]=((long long)(MOD-MOD/i)*inv[MOD%i])%MOD;
            s=(s*i)%MOD;
        }
        Node p[n+2];
        for(int i=0;i<=n+1;i++)
        {
            p[i].l=p+i-1;
            p[i].r=p+i+1;
        }
        for(auto it=nums.rbegin();it<nums.rend();it++)
        {
            Node& t=p[*it];t.flag=1;
            if(t.l->flag){t.l->l->r=&t;t.size+=t.l->size;t.l=t.l->l;}
            if(t.r->flag){t.r->r->l=&t;t.size+=t.r->size;t.r=t.r->r;}
            if(t.size>1)s=(s*inv[t.size])%MOD;
        }
        return (s+MOD-1)%MOD;
    }
  
};