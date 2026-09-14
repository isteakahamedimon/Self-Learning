#include<iostream>

int main()
{
    int n = 5;
    int ans = 0;
    while(n>=5) {
        ans = ans + n/5;
        n /= 5;
    }
    std::cout << ans << std::endl;
    
    return 0;
}
