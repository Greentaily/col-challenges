#include <iostream>

int flips(int n, int p)
{
	return (p < n ? (std::min(p, n-p+1) / 2) : 0);
}

int main()
{
    int a = flips(5,3);
    int b = flips(10,1);
    int c = flips(400,15);
    int f = flips(10,6);
    int d = flips(10,10);
    int e = flips(10,9);
    int g = flips(10,4);
    int h = flips(10,5);
    std::cout <<
            a << std::endl <<
            b << std::endl << 
            c << std::endl << 
            f << std::endl <<
            d << std::endl << 
            e << std::endl <<
            g << std::endl <<
            h;
    return 0;
}
