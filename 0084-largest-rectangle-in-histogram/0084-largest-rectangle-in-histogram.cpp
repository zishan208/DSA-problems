class Solution {
private:
    vector<int> left(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> ans(n);

        st.push(-1); // sentinel for no smaller element

        for (int i = 0; i < n; i++) {
            while (st.top() != -1 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            ans[i] = st.top(); // index of previous smaller
            st.push(i);
        }
        return ans;
    }

    vector<int> right(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> ans(n);

        st.push(-1);

        for (int i = n - 1; i >= 0; i--) {
            while (st.top() != -1 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            ans[i] = st.top(); // index of next smaller
            st.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = right(heights, n);
        vector<int> prev = left(heights, n);

        int area = 0;

        for (int i = 0; i < n; i++) {
            int rightBound = (next[i] == -1 ? n : next[i]);
            int width = rightBound - prev[i] - 1;
            int currArea = heights[i] * width;
            area = max(area, currArea);
        }

        return area;
    }
};
