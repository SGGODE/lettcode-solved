// class RangeModule {
// public:
//     set<int>s;
//     RangeModule() {
        
//     }
    
//     void addRange(int left, int right) {
//         for(int i=left;i<right;i++){
//             s.insert(i);
//         }
//     }
    
//     bool queryRange(int left, int right) {
//         for(int i=left;i<right;i++){
//             if(!s.count(i))return 0;
//         }
//         return 1;
//     }
    
//     void removeRange(int left, int right) {
//         for(int i=left;i<right;i++){
//             s.erase(i);
//         }
//     }
// };
class node{
    public:
    int start, end, mid, filled;
    node*left, *right;
    node(int l, int r){
        start=l;
        end=r;
        mid=(l+r)/2;
        left=NULL;
        right=NULL;
        filled=0;
    }
};


class RangeModule {
public:
    node *root;
    RangeModule() {
        root = new node(1, 1000000000);
    }
    
    void addRange(int l, int r, node* curr=NULL, int stk=0) {
        if(stk==0)
        {
            r-=1;
            curr=root;
        }
        if(curr->filled)
            return;
        if(l<=curr->start && r>=curr->end)
        {
            curr->filled=1;
            return;
        }
        if(l<=curr->mid)
        {
            if(curr->left==NULL)
                curr->left = new node(curr->start, curr->mid);
            addRange(l, min(r, curr->mid), curr->left, 1);
        }
        if(r>curr->mid)
        {
            if(curr->right==NULL)
                curr->right = new node(curr->mid+1, curr->end);
            addRange(max(curr->mid+1, l), r, curr->right, 1);
        }
        if(curr->left!=NULL && curr->right!=NULL && curr->left->filled && curr->right->filled)
            curr->filled=1;
    }
    
    
    
    bool queryRange(int l, int r, node* curr=NULL, int stk=0) {
        if(stk==0)
        {
            curr=root;
            r-=1;
        }
        if(curr->filled)
            return 1;
        if(l<=curr->start && r>=curr->end)
            return 0;
        bool x=true, y=true;
        if(l<=curr->mid)
        {
            if(curr->left==NULL)
                curr->left = new node(curr->start, curr->mid);
            x = queryRange(l, min(r, curr->mid), curr->left, 1);
        }
        if(r>curr->mid)
        {
            if(curr->right==NULL)
                curr->right = new node(curr->mid+1, curr->end);
            y = queryRange(max(curr->mid+1, l), r, curr->right, 1);
        }
        return x & y;
    }
    
    
    
    void removeRange(int l, int r, node* curr=NULL, int stk=0) {
        if(stk==0)
        {
            curr=root;
            r-=1;
        }
        if(curr->filled)
        {
            curr->left = new node(curr->start, curr->mid);
            addRange(curr->start, curr->mid, curr->left, 1);
            curr->right = new node(curr->mid+1, curr->end);
            addRange(curr->mid+1, curr->end, curr->right, 1);
        }
        if(l<=curr->start && r>=curr->end)
        {
            curr->filled=0;
            curr->left=NULL;
            curr->right=NULL;
            return;
        }
        if(curr->start==curr->end)
            return;
        if(l<=curr->mid)
        {
            if(curr->left!=NULL)
                removeRange(l, min(r, curr->mid), curr->left, 1);
        }
        if(r>curr->mid)
        {
            if(curr->right!=NULL)
                removeRange(max(curr->mid+1, l), r, curr->right, 1);
        }
        curr->filled=0;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */