class Solution {
public:
    int fib(int n) {
if (n == 0) return 0;   
        if (n == 1) return 1;   

        vector<int> fibb(n + 1);
        fibb[0] = 0;
     fibb[1] = 1;

        for (int i = 2; i <= n; i++) {
            fibb[i] = fibb[i - 1] + fibb[i - 2];
        }

        return fibb[n];
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