#include<iostream>
#include<vector>
#include<map>
#include<string>

    std::vector<std::string> ans;
    std::string ara;
    std::map<char, int> freq;
    std::map<char, int> track;
    int count;
    
    void gp(std::string& nums) {
        if(ara.size() == nums.size()) {
            ans.push_back(ara);
            count++;
//            std::cout << ara << std::endl;
            return;
        }
        for(const auto& [key, count] : freq) {
            if(track[key] >= freq[key])
                continue;

            ara.push_back(key);
            track[key]++;
            gp(nums);
            ara.pop_back();
            track[key]--;
        }
    }

    std::vector<std::string> permuteUnique(std::string& nums) {
        for(auto x : nums)
            freq[x]++;

        // 
        for(auto& [key, count] : freq) {
            track[key] = 0;
        }

        gp(nums);

        return ans;
    }

int main()
{
    std::string str; std::cin >> str;
//    std::string a = "aab";
    std::vector<std::string> ans;
    ans = permuteUnique(str);

    std::cout << count << std::endl; 
    for(const auto& x : ans)
        std::cout << x << std::endl;

    return 0;
}
