class Solution {
private:
    int hs(vector<int>& piles, int speed) {
        int hours = 0;
        for (int p : piles) {
            hours += (p + speed - 1) / speed; 
        }
        return hours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            int hours = hs(piles, mid);

            if (hours <= h) {
                high = mid;    
            } else {
                low = mid + 1;  
            }
        }
        return low;
    }
};