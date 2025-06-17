#include "Ring.h"
Ring::Ring(int x0, int y0, int r0, int r2)
:Circle( x0, y0, (r0<r2)? r0:r2)
{
    this->r2= (r0<r2)? r2:r0;
}
Ring::Ring(const Circle& c1, int r2): Circle(c1)
{
    this->r2=r2;
}
ostream& operator<<(ostream& out,const Ring& p)
{
    out<<"("<<p.x<<", "<<p.y<<", "<<p.r<<", "<<p.r2<<")\n";
    return out;
}
istream& operator>>(istream& in, Ring& p)
{
    int x0, y0, r0, r2;
    in>>x0>>y0>>r0>>r2;
    if (r0>r2)
    {
        int swap =r0;
        r0=r2;
        r2=swap;
    }
    p = Ring(x0, y0, r0, r2);
    return in;
}
bool operator^(const Ring& p1, const Ring& p2)
{
    return p1.r2+p2.r2==p1-p2|| abs(p1.r2-p2.r2)==p1-p2;
}
bool operator|(const Ring& p1, const Ring& p2)
{
    return p1-p2>p1.r2+p2.r2;
}
bool operator&(const Ring& p1, const Ring& p2)
{
    return p1.r2+p2.r2<p1-p2;
}
bool operator%(const Ring& p1, const Ring& p2)
{
    return p1-p2<abs(p1.r2-p2.r2);
}
int Ring::width(const Ring& p) const
{
    return p.r2-p.r;
}
Ring::~Ring(){}