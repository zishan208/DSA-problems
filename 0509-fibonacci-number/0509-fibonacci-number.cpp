class Solution {

private:
        int fibonacci(int n, vector<int> &p) {
    if (n == 0 || n == 1) return n;
    if (p[n] != -1) return p[n];

    p[n] = fibonacci(n - 1, p) + fibonacci(n - 2, p);
    return p[n];
}

public:
    int fib(int n) {

        vector<int> p(n+1,-1);
        
       
        return fibonacci(n,p);
    }
};