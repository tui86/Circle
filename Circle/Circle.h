#include <iostream>
#pragma once
using namespace std;
class Circle
{
protected:
    int x, y;
    int r;
public:
    Circle();
    Circle(int x0, int y0, int r);
    Circle(int r);
    Circle(const Circle &p);
    int getX()const{return x;};
    int getY()const{return y;};
    int getR()const{return r;};
    friend ostream& operator<<(ostream& out, const Circle& p);//Toán tử chèn, xuất theo dạng (x, y, r)
    friend istream& operator>>(istream& in, Circle& p);//Toán tử tách, cho phép nhập 1 đường tròn dạng (x, y, r)
    friend double operator-(const Circle& p1, const Circle& p2);//Tính khoảng cách tâm c1 và c2
    friend bool operator==(const Circle& p1, const Circle& p2);//Hai đường tròn có cùng tâm hay không
    friend bool operator!=(const Circle& p1, const Circle& p2);//Hai đường tròn có khác tâm hay không
    bool operator<(const Circle& p) const;//so sánh 2 bán kính, dùng để sắp xếp
    friend bool operator^(const Circle& p1, const Circle& p2);//kiểm tra c1 tiếp xúc c2
    friend bool operator|(const Circle& p1, const Circle& p2);//kiểm tra c1 nằm rời c2
    friend bool operator&(const Circle& p1, const Circle& p2);//kiểm tra c1 cắt c2
    friend bool operator%(const Circle& p1, const Circle& p2);//kiểm tra c2 có nằm trong c1
    ~Circle();
};

