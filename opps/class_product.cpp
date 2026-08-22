#include <cstring>
#include <iostream>
using namespace std;

class Product
{
    int id;           // 4 bytes
    char name[100];   // 100 bytes
    int mrp;          // 4 bytes
    int sellingPrice; // 4 bytes

public:
    Product()
    {
        cout << "Inside  Empoty Constructor" << endl;
    }
    
    /// Paramertrisd Constructor
    /// This is called Constructor overloading
    Product(int id, const char *name, int mrp, int sellingPrice)
    {
        cout << "Inside COnstructor which accepts param which will set attributes of the Product : " << name << endl;
        this->id = id;
        this->mrp = mrp;
        this->sellingPrice = sellingPrice;
        strcpy(this->name, name);
    }

    const int getMRP()
    {
        return this->mrp;
    }

    const int getSellingPrice()
    {
        return this->sellingPrice;
    }

    const void showMrp()
    {
        cout << "MRP is : " << this->mrp << endl;
    }

    const char *getProductName()
    {
        return this->name;
    }

    void printDetails()
    {
        cout << "==================================== " << endl;
        cout << "Name of the product is : " << this->name << endl;
        cout << "MRP is : " << this->mrp << endl;
        cout << "Selling Price is : " << this->sellingPrice << endl;
        
    }
};

int main()
{
    Product camera1(1, "GO PRO", 55000, 58000);
    cout << "Size o fthe camera 1 objest is : " << sizeof(camera1) << "Bytes" << endl;
    camera1.printDetails();
    return 0;
}