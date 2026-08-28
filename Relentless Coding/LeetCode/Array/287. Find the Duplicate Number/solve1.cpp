#include<iostream>

int main()
{
    std::vector<int> nums = {1,3,4,2,2};
    std::vector<int>v(nums.size()+1);
    for(size_t i=0; i<nums.size(); i++) {
        ++v[nums[i]];
        if(v[nums[i]] > 1) return v[nums[i]];
    }

    for(size_t i=0; i<=v.size(); i++)
        std::cout << v[i] << "  ";
    std::cout << std::endl;

    return 0;
}
