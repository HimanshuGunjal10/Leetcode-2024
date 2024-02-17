#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int left = 0, right = 0;
        int maxProfit;
        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i] < prices[left])
            {
                left = i;
            }
            if(prices[i] > prices[right])
            {
                right = i;
            }
            if(left < right)
                maxProfit = max(maxProfit, prices[right] - prices[left]);
        }
        return maxProfit;
    }
/*
sliding window - start both at 0 left - min and right max. if left > right then right = left | O(n) O(1)
*/


/* brute force - resulted in exceeding time limit for large input */
#if 0
    int maxProfit(vector<int>& prices)
    {
        int size = prices.size();
        if(size == 1)
            return 0;
        
        int left = 0, right = 0;
        int max_profit = 0, profit = 0;

        /* two pointer algo */
        for(left = 0; left < size; left++)
        {
            for(right = left+1; right < size; right++)
            {
                profit = prices[right] - prices[left];
                max_profit = max(max_profit, profit);
            }
        }
        return max_profit;
    }

/* two pointers with one pass */
    int maxProfit(vector<int>& prices)
    {
        int size = prices.size();
        int profit = 0, max_profit = 0;

        int left = 0, right = 1;
        for(int i = 1; i < size; i++)
        {
            if(left>right)
                right = left;
            if(prices[i] < prices[left])
                left = i;
            if(prices[i] >= prices[right])
                right = i;
            if(left < right)
                profit = prices[right] - prices[left];
            max_profit = max(max_profit, profit);
        }
        return max_profit;
    }

/* my own old solution - much better */
    int maxProfit(vector<int>& prices)
    {
        int min_price = INT_MAX;
        int max_profit = 0;

        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i] < min_price)
                min_price = prices[i];
            else if((prices[i] - min_price) > max_profit)
                max_profit = prices[i] - min_price;
        }
        return max_profit;
    }

    #endif
};

int main()
{
    vector<int> v = {3,3,5,0,0,3,1,4};

    Solution sol;
    int ans = sol.maxProfit(v);

    cout << "max profit: " << ans;

    cout << endl << "La Fin!" << endl;
    return 0;
}