#include<iostream>

class Counter 
{
    public:
        int count = 0; 
        
        // Prefix: ++c
        Counter& operator++() {
            count ++;
            return *this;
        }

        Counter operator++(int) {
            Counter temp = *this;
            count++;
            return temp;
        };

        friend std::ostream& operator<<(std::ostream& os, const Counter& c);
};

std::ostream& operator<<(std::ostream& os, const Counter& c)
{
    os << c.count;
    return os;
};

int main()
{
    Counter c;

    std::cout << ++c << "\n";
    std::cout << c++ << "\n";
    std::cout << c << "\n";

    std::cin.get();
}
