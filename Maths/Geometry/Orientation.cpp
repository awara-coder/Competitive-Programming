/*
Author: Sagar Gupta
E mail: sagar.june97p@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Point
{
    T x;
    T y;

  public:
    Point(T x, T y) : x(x), y(y) {}

    T dot(Point b)
    {
        return x * b.x + y * b.y;
    }

    T norm(void)
    {
        return x * x + y * y;
    }

    double length(void)
    {
        return sqrt(norm());
    }
    double projection(Point b)
    {
        return dot(b) / length(b);
    }

    double angle(Point b)
    {
        return acos(double(dot(b)) / double(length() * b.length()));
    }

    Point operator-(Point b)
    {
        Point p(*this);
        p.x -= b.x;
        p.y -= b.y;
        return p;
    }

    T cross(Point b)
    {
        return (x * b.y) - (b.x * y);
    }

    // This function returns the Orientation of three Ordered Points
    // If the Orientation is clockwise it returns +ve value
    // If the Orientation is negative it returns -ve value
    // If the the three Points are collinear it returns 0
    friend T Orientation(Point<T> a, Point<T> b, Point<T> c)
    {
        return (c - b).cross(b - a);
    }
};

int main()
{
    Point a(0, 0), b(0, 8), c(8, 8);
    cout << Orientation(a, b, c);
}