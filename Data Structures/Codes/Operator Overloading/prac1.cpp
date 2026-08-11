#include <iostream>

class Complex
{
    private:

    public:
        
        int x, y;

        Complex(int x, int y) : 
            x(x), y(y) { };

        void show()
        {
            // std::cout << this->x << " " << this->y << "\n";
        }
        
        Complex operator+(const Complex& other) const
        {
            return Complex(x + other.x, y + other.y);
        }
};

std::ostream& operator<<(std::ostream& stream, const Complex& other)
{
    stream << other.x << " + " << other.y << "i";
    return stream;
}

int main()
{
    Complex c1(2, 3);
    Complex c2(1, 4);
    Complex c3 = c1 + c2;

    std::cout << c3;

    std::cin.get();
}
