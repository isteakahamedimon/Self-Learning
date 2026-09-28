#include<iostream>

class Solution {
public:
    std::vector<std::vector<int>> ans;
    std::vector<int> ara;
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        
        ans.push_back(ara);

        int len = nums.size();
        for(int i=1; i<=len; i++) {
            backtracking(nums, i, 0);
        }

        return ans;
    }

private:
    void backtracking(std::vector<int>& nums, int len, int indx) {
        if(ara.size() == len) {
            ans.push_back(ara);

            for(auto& x : ara)
                std::cout << x << " ";
            std::cout << "\n";

            return;
        }

        for(int i=indx; i<nums.size(); i++) {
            ara.push_back(nums[i]);
            backtracking(nums, len, i+1);
            ara.pop_back();
        }
    }
};


int main()
{
    Solution s;

    std::vector<std::vector<int>> ans;
    std::vector<int> nums = {1, 2, 3};

    ans = s.subsets(nums);
    std::cout << "Size: " << ans.size() << "\n";

    return 0;
}
