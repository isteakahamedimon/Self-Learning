#include<iostream>

int diff(int a, int b) {
    if(a>b) return a-b;
    else    return b-a;
}

int maxArea(std::vector<int>& height) {

    std::vector<std::pair<int, int>> v;
    for(size_t i=0; i<height.size(); i++) {
        v.push_back({height[i], i});
    }

    std::sort(v.begin(), v.end());

    int ans = 0;
    for(size_t i=0; i<v.size(); i++) {
        // std::cout << v[i].first << "    " << v[i].second << std::endl;
        int differ = 0;
        for(size_t j=i+1; j<v.size(); j++) {
            differ = std::max(differ, diff(v[i].second, v[j].second));
        }
        ans = std::max(ans, differ*v[i].first);
    }
    
    return ans;
}

int main()
{
    std::vector<int> height = {1,2,5,25,24,5,3};
    
    std::cout << maxArea(height) << std::endl;

    return 0;
}
