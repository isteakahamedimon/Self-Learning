#include<iostream>

int maxProduct(std::vector<int>& nums) {
    int ans = INT_MIN;
    int mul = 1;
    int subMul = 1;
    bool division = true;

    for(size_t i=0; i<nums.size(); i++) {
        
        mul *= nums[i];
        subMul *= nums[i];

        ans = std::max(ans , std::max(mul, subMul));

        if(nums[i] < 0 && division) {
            subMul = 1;
            division = false;
        }
        if(nums[i] == 0) {
            mul = subMul = 1;
            division = true;
        }
    }

    return ans;
}

int main()
{
    std::vector<int>ara = {-5, 0, 2};
    std::vector<int>ara2 = {-2, 3, -2, 5};
    int ans = maxProduct(ara);
    std::cout << "Ans: " << ans << std::endl;

    return 0;
}
