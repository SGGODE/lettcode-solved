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
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int s = 0;
        int e = n-1;
        int mid = (s+e)/2;
        int index=-1;
        while(s<=e){
            int element=mountainArr.get(mid);
            int x=mountainArr.get(mid+1);
            if(element>x&&element>mountainArr.get(mid-1)){
                index=mid;
                break;
            }
            else if(element<x){
                s=mid+1;
            }else{
                e=mid-1;
            }
            mid=(s+e)/2;
        }
        s=0;
        e=index;
        mid=(s+e)/2;
        while(s<=e){
            int element=mountainArr.get(mid);
            if(element==target)return mid;
            else if(element<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
            mid=(s+e)/2;
        }
        s=index;
        e=n-1;
        mid=(s+e)/2;
         while(s<=e){
            int element=mountainArr.get(mid);
            if(element==target)return mid;
            else if(element>target){
                s=mid+1;
            }else{
                e=mid-1;
            }
            mid=(s+e)/2;
        }
        return -1;
    }
};