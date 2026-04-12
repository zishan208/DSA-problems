
#include <queue>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int re;
        for(int i:nums){

            pq.push(i);
        }
        while(k){
            re=pq.top();
            pq.pop();
            k--;

        }
        return re;
        
    }
};