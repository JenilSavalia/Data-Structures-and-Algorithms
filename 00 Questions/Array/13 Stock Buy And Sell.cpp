class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        // Brute Force Approach O(n^2)

        // int profit = 0;
        // int n = prices.size();
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         profit = max(profit,prices[j]-prices[i]);
        //     }
        // }
        // if(profit<0){
        //     return 0;
        // }else{
        //     return profit;
        // }




        
        // Optimal approach O(n)

        // what we do here is we keep track of minimum price till now (current element), as maximum profit can be achieved
        // when buy price is minimum,

        // basically what we do is , we iterate every element that is the sell price,
        // for every sell price to get profit , we need mininum buy price before that sell price

        // ex : [7,1,5,3,6,4]

        // for getting profit at index 3 (element is 3)
        // note that 3 is the sell price, to get profit we need a buy price before 3 which is least (so profit is maximum)

        int min_price = INT_MAX;
        int max_profit = INT_MIN;

        for (int x : prices)
        {
            min_price = min(x, min_price);

            max_profit = max(x - min_price, max_profit);
        }

        return max_profit;
    }
};