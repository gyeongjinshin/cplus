#include <iostream>

using namespace std;

class First
{
private:
    int num1;
    int num2;
public:
    First(int n1=0, int n2=0):num1(n1), num2(n2)
    {
    }
    First& operator=(const First &ref)
    {
        cout<<"First operator=() is callsed"<<endl;
        num1+=ref.num1;
        num2+=ref.num2;
        return *this;
    }
    void print()
    {
        cout<<"n1:"<<num1<<" n2:"<<num2;
    }
};

class Second : public First
{
private:
    int num3;
    int num4;
public:
    Second(int n1, int n2, int n3, int n4):
        First(n1, n2), num3(n3), num4(n4)
    {
    }

    Second& operator=(const Second &ref)
    {
        cout<<"Second operator=() is callsed"<<endl;
        First::operator=(ref);
        num3+=ref.num3;
        num4+=ref.num4;
        return *this;
    }

    void print()
    {
        First::print();
        cout<<" n3:"<<num3<<" n4:" <<num4<<endl;
    }
};

int main()
{
    Second second1(1,2,3,4);
    Second second2(0,0,0,0);
    second2 = second1;
    second2.print();

}
