class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int f_l = n - 1;
        int s_f = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                s_f = i + 1;
                f_l = i;
                break;
            }
        }

        int s, e;

        if (target >= nums[0]) {
          s = 0;
            e = f_l;
        } else {
            s = s_f;
            e = n - 1;
        }

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) return true;

            if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return false;
    }
};