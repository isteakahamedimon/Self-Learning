#include<iostream>
#include<unordered_map>

int main()
{
    std::vector<int> v = {1, 2, 3, 1, 3};
    std::unordered_map<int, int> mp;
    for(auto x : v)
        mp[x]++;
    for(int i=0; i<mp.size(); i++)
        std::cout << mp[i] << "   " << mp[i] << std::endl;

    return 0;
}
