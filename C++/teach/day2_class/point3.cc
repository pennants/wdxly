#include <iostream>
using std::cout;
using std::endl;

class Point
{
public: 
    Point(int ix=0, int iy=0 )
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int,int)" << endl;
    }

    void print(/* Point * const this */)
    {
        //this = 0x1000;//error
        cout << "(" << this->_ix
             << "," << this->_iy
             << ")" << endl;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }

    //默认情况下，系统也会提供拷贝构造函数
    //这里系统提供的就满足需求了
    Point(const Point &rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy)
    {
        cout << this->_ix << endl;
        cout << "Point(const Point &)" << endl;
    }

    //this指针代表当前对象本身，是隐含的参数
    Point &operator=(const Point &rhs)//赋值运算符函数
    {
        cout << "Point & operator=(const Point &rhs)" << endl;
        _ix = rhs._ix;
        _iy = rhs._iy;

        return *this;
    }

private:
    int _ix;
    int _iy;
};


int test0()
{
    Point pt0;//调用默认构造函数；如果已经显式提供了一个有参构造函数，就必须再显式提供一个无参构造函数
    cout << "pt0=";
    pt0.print();

    Point pt(1,2);//有参构造函数
    cout << "pt=";
    pt.print();

    Point * p1 = new Point(3,4);
    p1->print();
    delete p1;
    
    return 0;
}

void test1()
{
    int a=3;
    int b=a;
    cout << "a = " << a << endl
         << "b = " << b << endl;

    Point pt1(1,2);
    cout << "pt1 = ";
    pt1.print();
    Point pt2 = pt1;
    cout << "pt2 = ";
    pt2.print();
}

void func1(Point pt)//这里也会调复制构造函数
{
    cout << "pt = ";
    pt.print();
}

Point func2()
{
    Point pt(5,6);
    cout << "pt = ";
    pt.print();

    return pt;//这里也会调复制构造函数,但是编译器会优化,省略中间过程，想看到需加编译选项 -fno-elide-constructors
}

void test2()
{
    //Point p(3,4);
    //func1(p);
    
   Point p1 = func2();

}

void test3()
{
    int a = 3, b = 4, c = 5;
    a = b = c;

    Point pt1(1,2), pt2(3,4), pt3(5,6);
    cout << "pt1 = ";
    pt1.print();//等价于 Point::print(&pt1);
    cout << "pt2 = ";
    pt2.print();
    cout << "pt3 = ";
    pt3.print();

    cout << "执行赋值语句后：" << endl;
    pt2 = pt1 = pt3;//调用赋值运算符函数
    //等价于 pt2.operator=(pt1);
    
    cout << "pt2 = ";
    pt2.print();

}

int main()
{
    test3();
    return 0;
}
