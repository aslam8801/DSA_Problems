class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1){
            return n;
        }
        
        int first = 0, second = 1;
        int i = 2;
        while(i <= n){
            int ans = first + second;
            first = second;
            second = first;
            second = ans;
            i += 1;
        }

        return second;
    }
};