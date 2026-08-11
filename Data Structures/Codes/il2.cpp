#include<iostream>
#include<string>

class Example
{
    public:
        Example()
        {
            std::cout << "Created Entity!" << std::endl;
        }
        Example(int x)
        {
            std::cout << "Created Entity with " << x << "!" << std::endl;
        }
};

class Entity
{
    private:
        std::string m_name;
        Example m_example; 

    public:
        Entity()
            : m_example(8)
        {
            m_name = std::string("Unknown");
//            m_example = Example(8);
        }
        Entity(const std::string& name) {
            m_name = name;
        }

        const std::string& getName() const{
                return m_name; 
        }

};

int main()
{
    Entity e0;
  
    std::cin.get();
}
