#include<iostream>
using namespace std;
class Point
{
    private:
       int m_x{};
       int m_y{};
       int m_z{};
    public:
    Point(int x, int y,int z) : m_x{x}, m_y{y}, m_z{z}
    {

    }
    friend ostream& operator<<(ostream& out, const Point& p)
    {
        return out << "Point("<< p.m_x<< ", "<<p.m_y<<", "<<p.m_z<<')';

    }
};