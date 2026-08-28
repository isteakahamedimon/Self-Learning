#include<iostream>
#include<algorithm>

int maxProfit(std::vector<int>& prices) {
    int maxProfit = INT_MIN;
    int profit = 0;

    if(prices.size() == 1) return 0;
    for(size_t i=1; i<prices.size(); i++) {
        profit += prices[i] - prices[i-1];
        if(profit<0) profit = 0;
        maxProfit = std::max(maxProfit, profit);
    }
    return maxProfit;
}

int main()
{
    std::vector<int>v = {7,1,5,3,6,4};
    int a = maxProfit(v);
    std::cout << a << std::endl;

    return 0;
}
