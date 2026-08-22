class Solution {
public:
    int fib(int n) {
        int p1 = 0, p2 = 1;

        for(int i = 2; i <= n; i++){
            int curr = p1 + p2;
            p1 = p2;
            p2 = curr;
        }

        return (n <= 1 ? n : p2);
    }
};