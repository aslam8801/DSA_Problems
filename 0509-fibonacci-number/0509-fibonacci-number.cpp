class Solution {
public:
    int fibb(int n){
        if(n == 0 || n == 1){
            return n;
        }

        return fibb(n-1) + fibb(n-2);
    }
    int fib(int n) {
        return fibb(n);
    }
};