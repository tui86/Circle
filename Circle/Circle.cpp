#include"Circle.h"
#include <cmath>
Circle::Circle()
{
    x=0;
    y=0;
    r=1;
}
Circle::Circle(int x0, int y0, int r0)
{
    x=x0;
    y=y0;
    r=r0;
}
Circle::Circle(int r)
{
    x=0;
    y=0;
    this->r=r;
}
Circle::Circle(const Circle &p)
{
    x=p.x;
    y=p.y;
    this->r=p.r;
}
ostream& operator<<(ostream& out, const Circle& p)
{
    return out<<"("<<p.x<<", "<<p.y<<", "<<p.r<<")";
}
istream& operator>>(istream& in, Circle& p)
{
    while(true)
    {
        in>>p.x>>p.y>>p.r;
        if(p.r<=0)
        {
            cout<<"Lỗi, vui lòng nhập lại!\n";
        }
        else break;
    }
    return in;
}
double operator-(const Circle& p1, const Circle& p2)
{
    return sqrt(pow((p2.x-p1.x), 2)+pow((p2.y-p1.y), 2));
}
bool operator==(const Circle& p1, const Circle& p2)
{
    return p1.x==p2.x&&p1.y==p2.y;
}
bool operator!=(const Circle& p1, const Circle& p2)
{
    return p1.x!=p2.x||p1.y!=p2.y;
}
bool Circle::operator<(const Circle& p) const
{
    return this->r <p.r; 
}
bool operator^(const Circle& p1, const Circle& p2)
{
    return p1.r+p2.r==p1-p2||abs(p1.r-p2.r)==p1-p2;
}
bool operator|(const Circle& p1, const Circle& p2)
{
    return p1.r+p2.r<p1-p2;
}
bool operator&(const Circle& p1, const Circle& p2)
{
    return p1.r+p2.r>p1-p2;
}
bool operator%(const Circle& p1, const Circle& p2)
{
    return p1-p2<abs(p1.r-p2.r);
}
Circle::~Circle(){}
