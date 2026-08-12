// class Solution {
// public:
//     int hIndex(vector<int>& citations) {
        

//         int s=0;
//         int e=citations.size()-1;
//         int ans=0;
//         while(s<=e){
//             int mid=s+(e-s)/2;
//             ans=mid;
//             int left_count=mid-s+1;
//             int right_count=citations.size()-mid;
//             if(citations[mid]<right_count){
//                 s=mid;
//             }else if(citations[mid]>right_count){
//                 e=mid;
//             }



//         }
//         return ans;
        
//     }
// };



class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int s = 0, e = n - 1;
        int ans = 0;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int papers = n - mid;
            
            if (citations[mid] >= papers) {
                ans = papers;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        
        return ans;
    }
};