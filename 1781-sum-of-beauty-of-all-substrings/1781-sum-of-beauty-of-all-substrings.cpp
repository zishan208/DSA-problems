class Solution {
private:
    // Now returns the actual beauty value (max - min)
    int calculateBeauty(string s) {
        int arr[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';
            arr[index]++;
        }

        int maxVal = 0;
        int minVal = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) {
                if (arr[i] > maxVal) {
                    maxVal = arr[i];
                }
                if (arr[i] < minVal) {
                    minVal = arr[i];
                }
            }
        }

        return maxVal - minVal;
    }

public:
    int beautySum(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                string extract = s.substr(i, j + 1 - i);
                // Add the beauty value of the substring to the total count
                count += calculateBeauty(extract);
            }
        }
        return count;
    }
};