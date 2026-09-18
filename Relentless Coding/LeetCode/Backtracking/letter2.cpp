#include<iostream>

class Solution {
public:

    // std::string ans;
    // std::vector<bool> chosen(a, false);
        
    void solve(std::string& digits, std::unordered_map<char, std::string>& mp, int& len, std::vector<string>& ans, std::vector<bool>& chosen, std::string& temp)
    {
        if(temp.size() == len) {
            // std::cout << temp << std::endl;
            ans.push_back(temp);
            return;
        }
        else {
            for(int i=0; i<len; i++) {
                if(chosen[i]) continue;
                // chosen[i] = true;
                for(int j=0; j<mp[digits[i]].size(); j++) {
                    // std::cout << mp[digits[i]][j] << std::endl;
                    temp.push_back(mp[digits[i]][j]);
                    chosen[i] = true;
                    solve(digits, mp, len, ans, chosen, temp);
                    chosen[i] = false;
                    temp.pop_back();
                    // std::cout << "chosen[" << i << "]: " << chosen[i] << std::endl;
                }
                break;
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        std::unordered_map<char, std::string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        int len = digits.size();
        std::vector<string>ans;
        std::vector<bool> chosen(10, false);
        std::string temp;
        solve(digits, mp, len, ans, chosen, temp);

        return ans;
    }
};

int main()
{
    Solution s;
    std::vector<string> ans;
    ans = s.letterCombinations("23");

    for(auto str : ans)
        std::cout << str << std::endl;

    return 0;
}
