#include<iostream>

class VendingMachine{
private:
    std::string name;
public:
    VendingMachine(std::string name) {
        this->name = name;
    }

    void showName() {
        std::cout << this->name << std::endl;
    }

    std::vector<std::string>products;
    std::vector<int> prices;
    void addProduct(std::string newName, int price = 0) {
        bool exists = false;
        for(size_t i=0; i<products.size(); i++) {
            if(newName == products[i]) {
                exists = true;
                std::cout << newName << " already exists. Try to add a new product." << std::endl;
                break;
            }
        }
        if(exists == false) {
            products.push_back(newName);
            prices.push_back(price);
        }
    }

    void showProducts() {
        std::cout << "Showing the products of " << this->name << ":" << std::endl;
        for(size_t i=0; i<products.size(); i++) {
            std::cout << i+1 << ". " << products[i] << " : " << prices[i] << "\n";
        }
    }

    ~VendingMachine() {

    }
    
};

int main()
{
    std::cout << "Trying to build a self-sufficient Vending Machine System" << std::endl;

    VendingMachine v1("Male Hall-1 Vending Machine");
    v1.showName();

    while(1) {
        std::cout << "--------------Select your operation(using number)---------------" << std::endl;
        std::cout << "1. Add Product" << std::endl;
        std::cout << "2. Remove Product" << std::endl;
        std::cout << "3. Change Price" << std::endl;
        
        std::cout << "Press 0 to exit" << std::endl;

        int n;
        std::cout << "Select your option: ";
        std::cin >> n;
        switch (n)
            case 1: break;
            default: break;
    }

    return 0;
}
