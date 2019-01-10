/*
Author: Sagar Gupta
E mail: sagar.june97p@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

// This recursive function performs FFT and reverse FFT.
// To store complex numbers we use complex type in C++ STL
// (defined in the header file <complex> )

typedef complex<double> base;
#define PI 3.14159

void FFT(vector<base> &a, bool invert = false)
{
    int n = a.size();
    if (n == 1)
    {
        return;
    }

    vector<base> a0(n / 2), a1(n / 2);
    // a0 stores the even coefficients and a1 stores
    // odd coefficients.
    for (int i = 0, j = 0; i < n; i += 2, j++)
    {
        a0[j] = a[i];
        a1[j] = a[i + 1];
    }

    // Recursively calling FFT function on a0 and a1
    FFT(a0, invert);
    FFT(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    base w(1), wn(cos(ang), sin(ang));

    for (int i = 0; i < n / 2; i++)
    {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];

        if (invert == true)
        {
            // divide by 2 at each recursion step,
            // at the end all elements are divided by n
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

// This function multiplies two polynomials using Fast Fourier
// transform. It works with integer coefficients but can also
// be modified to work with fractional numbers.

void multiply(vector<int> &a, vector<int> &b, vector<int> &res)
{
    int n = 1;

    // The vectors fa and fb will store the fourier transform
    // of a and b.
    vector<base> fa(a.begin(), a.end());
    vector<base> fb(b.begin(), b.end());

    // here n will be the size of the vector fa and fb as
    // well as res. So n should be sufficient enough to store
    // all possible degrees of resultant polynomial
    // of multiplication of a and b.
    while (n < max(a.size(), b.size()))
    {
        n <<= 1;
    }
    n <<= 1;
    fa.resize(n);
    fb.resize(n);

    // Calling FFT() on fa and fb to obtain their fourier transform.
    FFT(fa);
    FFT(fb);
    // Storing the result of their multiplication in fa
    for (int i = 0; i < n; i++)
    {
        fa[i] *= fb[i];
    }

    // Calling FFT() to obtain inverse fourier transform of fa.
    FFT(fa, true);

    // Storing the result in vector res.
    res.resize(n);
    for(int i = 0;i<n;i++)
    {
        res[i] = int(round(fa[i].real()));
    }
}

int main()
{
    int n = 4;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        b[i] = n - i;
    }
    cout << "The content of vector a" << endl;
    for(auto i: a)
    {
        cout << i << " " ;
    }
    cout << endl;
    cout << "The content of vector b" << endl;
    for(auto i:b)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> res;
    multiply(a,b,res);
    cout << "The content of resultant vector" << endl;
    for(auto i:res)
    {
        cout << i << " " ;
    }
    return 0;
}
