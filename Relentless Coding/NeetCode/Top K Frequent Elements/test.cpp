#include<iostream>
#include<map>
#include<algorithm>

void topKFrequent(std::vector<int>& nums, int k)
{
    std::unordered_map<int, int> count;
    for(int num : nums) {
        count[num]++;
    }

//     for(auto [key, value] : count)
//         std::cout << key << "   " << value << std::endl;

    std::vector<std::pair<int, int>> arr;
    for(const auto& p : count) {
        arr.push_back({p.second, p.first});
    }
    std::sort(arr.rbegin(), arr.rend());

//     for(auto [value, key] : arr)
//         std::cout << key << "   " << value << std::endl;

    std::vector<int> ans;
    for(int i=0; i<k; i++) {
        ans.push_back(arr[i].second);
    }
    
    return ans;
}

int main()
{
    std::vector<int>nums = {1, 2, 2, 3, 3, 3, 3, 1, 1};
    // std::vector<int> ans = topKFrequent(nums, 2);
    topKFrequent(nums, 2);


    
    return 0;
}
