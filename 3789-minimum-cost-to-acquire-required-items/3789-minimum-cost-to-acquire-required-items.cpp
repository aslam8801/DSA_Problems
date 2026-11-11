class Solution {
public:
    
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long finalCost = 0;

        int t = min(need1, need2);

        finalCost += 1LL*min(costBoth, cost1 + cost2) * t;

        need1 -= t;
        need2 -= t;

        if(need1 != 0){
            finalCost += 1LL*min(costBoth, cost1)*need1;
        }

        if(need2 != 0){
            finalCost += 1LL*min(costBoth, cost2)*need2;
        }

        return finalCost;
    }
};