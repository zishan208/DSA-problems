class Solution {
    bool che(vector<int> &arr,int start,vector<bool> &v){

        if(arr[start]==0) return true;
        v[start]=true;

        int idx1=start+arr[start];

        int idx2=start-arr[start];

       if(idx1<arr.size() && !v[idx1]) {
    if (che(arr,idx1,v)) return true;
}
if(idx2>=0 && !v[idx2]) {
    if (che(arr,idx2,v)) return true;
}

        return false;


    }
public:
    bool canReach(vector<int>& arr, int start) {

        vector<bool> v(arr.size(),false);

        return che(arr,start,v);
        
    }
};