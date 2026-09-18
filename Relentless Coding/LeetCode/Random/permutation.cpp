#include<iostream>

std::vector<int> permutation;
void permute(int n, int limit) {
    if(permutation.size() == limit) {
        
        // printing each permutation
        for(int x : permutation)
            std::cout << x << " ";
        std::cout << std::endl;
        
        return;
    }
    else {
        for(int i=0; i<
        if(chosen[i]) continue;

    }
}

int main()
{
    int n; std::cin >> n;
    int limit; std::cin >> limit;
    std::vector<int>permutation;
    std::vector<bool>chosen(n, false);

    permute(n, limit);

    return 0;
}
