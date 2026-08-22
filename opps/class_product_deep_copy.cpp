#include <cstring>
#include <iostream>
using namespace std;

class ProductCopy
{
    int id;           // 4 bytes
    char *name;   // 100 bytes
    int mrp;          // 4 bytes
    int sellingPrice; // 4 bytes

public:
    // ProductCopy()
    // {
    //     cout << "Inside  Empoty Constructor" << endl;
    // }
    
    /// Paramertrisd Constructor
    /// This is called Constructor overloading
    ProductCopy(int id, const char *name, int mrp, int sellingPrice)
    {
        cout << "Inside COnstructor which accepts param which will set attributes of the Product : " << name << endl;
        this->id = id;
        this->mrp = mrp;
        this->sellingPrice = sellingPrice;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // Deep copy constructor: without this, the compiler-generated copy
    // constructor would copy just the `name` pointer, leaving camera1 and
    // camer2 sharing (and eventually double-freeing) the same heap buffer.
    ProductCopy(const ProductCopy &source)
    {
        cout << "Inside Copy Constructor (deep copy)" << endl;
        this->id = source.id;
        this->mrp = source.mrp;
        this->sellingPrice = source.sellingPrice;
        this->name = new char[strlen(source.name) + 1];
        strcpy(this->name, source.name);
    }

    ~ProductCopy()
    {
        delete[] this->name;
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

    void setName(const char *name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
};

int main()
{
    ProductCopy camera1(1, "GO PRO", 55000, 58000);
    cout << "Size o fthe camera 1 objest is : " << sizeof(camera1) << "Bytes" << endl;
    camera1.printDetails();

    cout << "Making a Duplicate Object of Product Class " << endl;
    ProductCopy camer2(camera1);
    camer2.printDetails();
    cout << endl;
    cout << "Now Updating the name of the camera2" << endl;
    camer2.setName("Go_Pro_Max_2");

    cout << endl;
    camer2.printDetails();

    cout << endl << "camera1 should be unaffected by the change to camer2:" << endl;
    camera1.printDetails();

    return 0;
}