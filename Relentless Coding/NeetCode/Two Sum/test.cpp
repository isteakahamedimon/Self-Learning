#include<iostream>

int main()
{
    std::unordered_map<int, int> mp;
    // mp[key] = value;

    mp[7] = 0;
    mp[6] = 1;
    mp[5] = 2;
    
    for(auto p : mp) {
        std::cout << p.first << "   " << p.second << "\n";
    }

    auto it = mp.find(5);
    if(it != mp.end())
        std::cout << it->first << "  " << it->second << "\n";
    else
        std::cout << "Not found" << std::endl;

    return 0;
}
