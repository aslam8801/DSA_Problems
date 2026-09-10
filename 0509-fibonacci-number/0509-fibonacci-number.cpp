class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }

        int first = 0, sec = 1;

        for(int i = 2; i < n+1; i++){
            int ans = first + sec;
            first = sec;
            sec = ans;
        }
        return sec;
    }
};