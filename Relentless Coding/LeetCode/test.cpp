#include<iostream>
#include<unordered_map>

int maxProfit(std::vector<int>& prices) {
    int len = prices.size();
    int maxNum = 0;

    for(int i=0; i<len; i++) {

        int pivot = -prices[i];
        bool noNeg = true;

        for(int j=i; j<len; j++) {
            int temp = prices[j] + pivot;
            if(temp < 0) noNeg = false;
            maxNum = std::max(maxNum, temp);
            prices[j] = temp;
//            std::cout << prices[j] << "     ";

        }
        
 //       for(int m=0; m<len; m++) {
 //           std::cout << prices[m] << "     ";
 //       }
 //       std::cout << std::endl;

        if(noNeg) {
//            std::cout << "Answer: " << maxNum << std::endl;
            break;
        }
    }
    return maxNum;
}

int main()
{
    std::vector<int>v = {7,1,5,3,6,4};
    int ans = maxProfit(v);
    std::cout << "Answer: " << ans << std::endl;

    return 0;
}
