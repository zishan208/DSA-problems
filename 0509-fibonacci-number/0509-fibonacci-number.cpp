class Solution {
public:
    int fib(int n) {
if (n == 0) return 0;   
        if (n == 1) return 1;   

        vector<int> fibb(n + 1);
        int prev1 = 0;
     int prev2= 1;

        for (int i = 2; i <= n; i++) {
            int curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;

        }

        return prev2;
    }
};



// class Solution {

// private:
//         int fibonacci(int n, vector<int> &p) {
//     if (n == 0 || n == 1) return n;
//     if (p[n] != -1) return p[n];

//     p[n] = fibonacci(n - 1, p) + fibonacci(n - 2, p);
//     return p[n];
// }

// public:
//     int fib(int n) {

//         vector<int> p(n+1,-1);
        
       
//         return fibonacci(n,p);
//     }
// };