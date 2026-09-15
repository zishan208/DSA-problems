

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();

        if(k==1) return {1,arr[n-1]};

        priority_queue<
            tuple<double, int, int>,
            vector<tuple<double, int, int>>,
            greater<tuple<double, int, int>>
        > pq;

        for (int i = 0; i < n-1; i++) {
            double val=(double)arr[i]/arr[n-1];
            pq.push({val,i,n-1});
        }

     
        for (int count = 0; count < k - 1; count++) {
            auto [val, i, j] = pq.top();
            pq.pop();
            if (j - 1 > i) {
                double newVal = (double)arr[i] / arr[j - 1];
                pq.push({newVal, i, j - 1});
            }
        }

        auto[val,r,c]=pq.top();

        

        return {arr[r],arr[c]};
        
    }
};
