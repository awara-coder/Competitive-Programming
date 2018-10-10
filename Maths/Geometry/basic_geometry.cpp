/*
Author: Sagar Gupta
E mail: sagar.june97p@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class point
{
    T x;
    T y;

  public:
    point(T x, T y) : x(x), y(y) {}

    T dot(point b)
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
    double projection(point b)
    {
        return dot(b) / length(b);
    }

    double angle(point b)
    {
        return acos(double(dot(b)) / double(length() * b.length()));
    }

};