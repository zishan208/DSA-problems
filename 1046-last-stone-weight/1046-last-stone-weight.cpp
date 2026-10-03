// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {

//         priority_queue<int> pq;

//         for(int &i: stones){
//             pq.push(i);
//         }

//         while(pq.size()>1){

//             int s1=pq.top();
//             pq.pop();
//             int s2=pq.top();
//             pq.pop();
//             if(s1!=s2){
//                 pq.push(s1-s2);
//             }

//         }

//         return pq.size()==0 ? 0 :pq.top();
        
//     }
// };

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        
        while (n > 1) {
            // Last two stones (heaviest)
            int i = n - 1;
            int j = n - 2;
            
            if (stones[i] == stones[j]) {
                // Dono destroy ho gaye
                n -= 2;
            } else {
                // Difference nikaalo
                int diff = stones[i] - stones[j];
                
                // Dono ko hatao, diff ko insert karo
                n -= 2; // temporarily reduce size
                
                // Insert diff into sorted array (0 to n-1)
                int k = n - 1;
                while (k >= 0 && stones[k] > diff) {
                    stones[k + 1] = stones[k];
                    k--;
                }
                stones[k + 1] = diff;
                n++; // ek stone add hua
            }
        }
        
        return (n == 0) ? 0 : stones[0];
    }
};