/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int _search(MountainArray &mountainArr,int start,int end,int target){
        while(start<=end){
            int mid = (start+end)/2;
            //cout<<start<<" "<<end<<" "<<mid<<endl;
            int res = mountainArr.get(mid);
            //cout<<res<<" "<<target<<endl;
            if(res==target)return mid;
            else if(res<target){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return 1e9+7;
    }
      int _bsearch(MountainArray &mountainArr,int start,int end,int target){
        while(start<=end){
            int mid = (start+end)/2;
            int res = mountainArr.get(mid);
            if(res==target)return mid;
            else if(res<target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return 1e9+7;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int s = 0;
        int e = n-1;
        int pick = -1;
        while(s<=e){
            int mid = (s+e)/2;
            int res =  mountainArr.get(mid);
            int front =  mountainArr.get(mid+1);
            if(res>front&&mountainArr.get(mid-1)<res){
                pick = mid;
                break;
            }
            else if(res<front){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        cout<<pick<<endl;
       int res =  min(_search(mountainArr,0,pick,target),_bsearch(mountainArr,pick,n-1,target));
       return res>=1e9+7?-1:res;
    }
};