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

    bool operator<(Point b)
    {
        if (x == b.x)
        {
            return y < b.y;
        }
        return x < b.x;
    }

    T cross(Point b)
    {
        return (x * b.y) - (b.x * y);
    }

    void print()
    {
        cout << x << " " << y << endl;
    }

    // This function returns the Orientation of three Ordered Points
    // If the Orientation is clockwise it returns +ve value
    // If the Orientation is negative it returns -ve value
    // If the the three Points are collinear it returns 0
    friend T Orientation(Point<T> a, Point<T> b, Point<T> c)
    {
        return (c - b).cross(b - a);
    }

    // This function takes the vector of Points and removes all Points
    // that do not lie on the convex hull
    friend void ConvexHull(vector<Point<T>> &a)
    {
        sort(a.begin(), a.end());
        Point<T> A = a.front(); // Leftmost Point
        Point<T> B = a.back();  // Rightmost Point

        vector<Point<T>> up;   // To store points above line AB
        vector<Point<T>> down; // To store points below line AB
        up.push_back(A);
        down.push_back(B);
        for (int i = 1; i < a.size(); i++)
        {

            // For Points above line AB
            if (i == a.size() - 1 || Orientation(A, a[i], B) > 0)
            {

                // While up contains more than 2 elements and Orientation is
                // counterclockwise remove last point from up
                while (up.size() >= 2 && Orientation(up[up.size() - 2], up[up.size() - 1], a[i]) < 0)
                {
                    up.pop_back();
                }
                up.push_back(a[i]);
            }

            // For Points below line AB
            if (i == a.size() - 1 || Orientation(A, a[i], B) < 0)
            {

                // While down contains more than 2 elements and Orientation is
                // Clockwise remove last point from down
                while (down.size() >= 2 && Orientation(down[down.size() - 2], down[down.size() - 1], a[i]) > 0)
                {
                    down.pop_back();
                }
                down.push_back(a[i]);
            }
        }

        // Points are returned in clockwise order
        a.clear();
        for (int i = 0; i < up.size(); i++)
        {
            a.push_back(up[i]);
        }
        for (int i = down.size() - 2; i > 0; i--)
        {
            a.push_back(down[i]);
        }
    }
};

int main()
{
    vector<Point<int>> p;
    p.push_back(Point(-3, -4));
    p.push_back(Point(4, 3));
    p.push_back(Point(-4, 2));
    p.push_back(Point(0, 5));
    p.push_back(Point(2, -3));
    p.push_back(Point(-1, 4));
    ConvexHull(p);
    for (auto it : p)
    {
        it.print();
    }
}