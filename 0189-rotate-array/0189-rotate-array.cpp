
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        if (k == 0) return;

        vector<bool> visited(size, false); 

        for (int s= 0; s < size; s++) {
            if (visited[s]) continue;

            int curr = s;
            int prev = nums[curr];

            while (!visited[curr]) {
                visited[curr] = true;

                int next = (curr + k) % size; 

        
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;

                curr = next;
            }
        }
    }
};