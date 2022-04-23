#include <iostream>

class Parent
{
private:
    /* data */
public:
    Parent(/* args */)
    {
        std::cout << "Parent Constructor" << '\n';
    }
    virtual ~Parent()
    {
        std::cout << "Parent Deconstructor" << '\n';
    }
};

class Child : public Parent
{
private:
    int a;

public:
    Child() : a(10)
    {
        std::cout << "Child Constructor" << '\n';
    }
    virtual ~Child()
    {
        std::cout << "Child Deconstructor" << '\n';
    }
};

int main()
{
    Parent* p = new Parent();
}