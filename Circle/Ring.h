#include "Circle.h"
#pragma once
class Ring: public Circle
{
private:
    int r2;
public:
    Ring(int x, int y, int r, int r2);
    Ring(const Circle& c1, int r2);
    int getR2() const {return r2;};
    friend ostream& operator<<(ostream& out,const Ring& p);
    friend istream& operator>>(istream& in, Ring& p);
    friend bool operator^(const Ring& p1, const Ring& p2);
    friend bool operator|(const Ring& p1, const Ring& p2);
    friend bool operator&(const Ring& p1, const Ring& p2);
    friend bool operator%(const Ring& p1, const Ring& p2);
    int width(const Ring& p) const;
    ~Ring();
};

