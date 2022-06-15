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
    int f(MountainArray &mountainArr) {
        int l = 0, r = mountainArr.length() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (mountainArr.get(m) < mountainArr.get(m + 1)) l = m + 1;
            else r = m;
        }
        return l;
    }
    
    int orderAgnosticBS(int l, int r, MountainArray &mountainArr, int target) {
        bool isAsc = mountainArr.get(l) < mountainArr.get(r);
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (isAsc) {
                if (mountainArr.get(m) < target) l = m + 1;
                else if (mountainArr.get(m) > target) r = m - 1;
                else return m;
            }
            else {
                if (mountainArr.get(m) < target) r = m - 1;
                else if (mountainArr.get(m) > target) l = m + 1;
                else return m;
            }
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = f(mountainArr);
        int res = orderAgnosticBS(0, peak, mountainArr, target);
        if (res != -1) return res;
        else return orderAgnosticBS(peak + 1, mountainArr.length() - 1, mountainArr, target);
    }
};
