//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The functions which 
builds the segment tree */
int res[10000];
void segmenttree(int arr[],int index,int low,int high){
    if(low==high){
        res[index]=arr[low];
        return;
    }
    int mid = (low+high)/2;
    segmenttree(arr,2*index+1,low,mid);
    segmenttree(arr,2*index+2,mid+1,high);
    res[index]=min(res[2*index+1],res[2*index+2]);
}

//int res[400000];
int *constructST(int arr[],int n)
{
  //Your code here
  //res.resize((4*n)+2);
  segmenttree(arr,0,0,n-1);
}

int find(int a,int b,int index,int low,int high){
    if(low > b or high < a)return INT_MAX;
    if(low>=a and high<=b) return res[index];
    int mid = (low+high)/2;
    return min(find(a,b,2*index+1,low,mid),find(a,b,2*index+2,mid+1,high));
}
/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
//Your code here
  return find(a,b,0,0,n-1);
}