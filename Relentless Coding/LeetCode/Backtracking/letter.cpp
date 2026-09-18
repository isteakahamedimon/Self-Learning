#include<iostream>
#include<unordered_map>

std::string ans;
std::vector<bool> chosen(10, false);
    
void solve(std::string& digits, std::unordered_map<char, std::string>& mp, int& len)
{
    if(ans.size() == len) {
        std::cout << ans << std::endl;
        return;
    }
    else {
        for(int i=0; i<len; i++) {
            if(chosen[i]) continue;
            // chosen[i] = true;
            for(int j=0; j<mp[digits[i]].size(); j++) {
                // std::cout << mp[digits[i]][j] << std::endl;
                ans.push_back(mp[digits[i]][j]);
                chosen[i] = true;
                solve(digits, mp, len);
                chosen[i] = false;
                ans.pop_back();
                // std::cout << "chosen[" << i << "]: " << chosen[i] << std::endl;
            }
            break;
        }
    }
}

int main()
{
    std::unordered_map<char, std::string>mp;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    std::string digits = "67";
    int len = digits.size();
    solve(digits, mp, len);


    // for(char i='2'; i<='9'; i++) {
    //     for(int j=0; j<mp[i].size(); j++) {
    //         std::cout << mp[i][j] << " ";
    //     } std::cout << std::endl;
    // }
    

    return 0;
}
