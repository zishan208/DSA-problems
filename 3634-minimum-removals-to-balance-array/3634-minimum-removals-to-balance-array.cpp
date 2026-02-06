

// class Solution {
//  private:
//   unordered_map<long long,int> memo;

//   int calcu(vector<int>& nums, int k,int MIN, int MAX){
//       if (MIN > MAX) return 0;
//       if ((long long)nums[MIN] * k >= nums[MAX]) return 0;
// \\cwscw





//     long long key = ((long long)MIN << 32) | MAX;
//     if (memo.count(key)) return memo[key];

//       int removeMax = 1 + calcu(nums, k, MIN, MAX - 1);
//       int removeMin = 1 + calcu(nums, k, MIN + 1, MAX);
//   int ans = std::min(removeMax, removeMin);
//       memo[key] = ans;
//       return ans;
//   }

//  public:
//   int minRemoval(vector<int>& nums, int k) {
//       sort(nums.begin(), nums.end());
//       memo.clear();
//       return calcu(nums, k, 0, nums.size() - 1);
//   }
// };


class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, maxLen = 0;

     for (int right = 0; right < n; ++right) {
            while (left <= right && (long long)nums[left] * k < nums[right]) {
                left++;
            }
    maxLen = max(maxLen, right - left + 1);
        }

        return n - maxLen;
    }
};
