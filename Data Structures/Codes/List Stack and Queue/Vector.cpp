#include<algorithm>
#include<iostream>

template <typename Object>
class Vector
{
    private:
        int theSize;
        int theCapacity;
        Object* objects;
    
    public:
        static const int SPARE_CAPACITY = 16;
        int temp = 100;

        explicit Vector(int initSize = 0)
            : theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
        {
            objects = new Object[theCapacity];
        }
        
        // Copy Constructor or Deep Copy
        Vector(const Vector& rhs)
            : theSize(rhs.theSize), theCapacity(rhs.theCapacity), objects(nullptr)
        {
            objects = new Object[theCapacity];
            for(int k=0; k<theSize; ++k)
                objects[k] = rhs.objects[k];
        }

        Vector& operator= (const Vector& other)
        {
            Vector copy = other;
            std::swap(*this, copy);
            return *this;
        }

        ~Vector()
        {
            delete [] objects;
        }

};

/*
void showTen(Vector<int> & v)
{
    std::cout << v.temp << std::endl;
}
*/

int main()
{
    Vector<int> v1(5);
    Vector<int> v2;

    v2 = v1;

    return 0;
}
