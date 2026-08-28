// class Solution {
// private:
//     void decode(string& s, string& mapping, int index, string temp, int& count, map<string, bool>& trace) {
     
//         if (index == s.length()) {
           
//             if (trace.find(temp) == trace.end()) {
//                 trace[temp] = true;
//                 count++;
//             }
//             return;
//         }

    
//         if (s[index] == '0') return;

       
//         int oneDigit = s[index] - '0';
//         string temp1 = temp + mapping[oneDigit];
//         decode(s, mapping, index + 1, temp1, count, trace);

       
//         if (index + 1 < s.length()) {
//             int twoDigit = (s[index] - '0') * 10 + (s[index + 1] - '0');
//             if (twoDigit >= 10 && twoDigit <= 26) {
//                 string temp2 = temp + mapping[twoDigit];
//                 decode(s, mapping, index + 2, temp2, count, trace);
//             }
//         }
//     }

class Solution {
private:
    int solve(int idx, string& s, vector<int>& dp) {
        if (idx == s.length()) return 1;

        if (s[idx] == '0') return 0;
       if (dp[idx] != -1) return dp[idx];
        int ways = 0;
        ways += solve(idx + 1, s, dp);

      if (idx + 1 < s.length()) {
            int twoDigit = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
         if (twoDigit >= 10 && twoDigit <= 26) {
                      ways += solve(idx + 2, s, dp);
            }
        }

  return dp[idx] = ways;
    }

public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        vector<int> dp(s.length(), -1);
      return solve(0, s, dp);
    }
};