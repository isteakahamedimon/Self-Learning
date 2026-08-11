#include <iostream>

class Fraction 
{
    private:
        int num, den;
    public:
        Fraction(int x, int y) : 
            num(x), den(y) {}

        friend int operator==(const Fraction& f1, const Fraction& f2);
};

int operator==(const Fraction& f1, const Fraction& f2)
{
    if(f1.num * f2.den == f1.den * f2.num)
        return 1;
    else
        return 0;
}

int main()
{
    Fraction f1(1, 2);
    Fraction f2(2, 6);

    std::cout << (f1 == f2);

    return 0;
}
