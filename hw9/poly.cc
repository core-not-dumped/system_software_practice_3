#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<string>
using namespace std;

class Poly{
    public:
        Poly(int poly_num, int *poly);
        ~Poly();
        Poly operator + (Poly &rhs);
        Poly operator - (Poly &rhs);
        Poly operator * (Poly &rhs);
        void operator = (Poly rhs);
        void print_poly();

    private:
        int* coefficient;
        int max_exp;
};

Poly::Poly(int poly_num, int *poly) : max_exp(poly_num)
{
    coefficient = new int[max_exp];
    for(int i=0;i<max_exp;i++)
        coefficient[i] = poly[i];
}

Poly::~Poly()
{
    delete [] coefficient;
}

Poly Poly::operator +(Poly &rhs)
{
    int max_length = (*this).max_exp > rhs.max_exp ? (*this).max_exp : rhs.max_exp;
    int *coe = new int[max_length];

    for(int i=0;i<max_length;i++)
    {
        int num1, num2;
        if(i >= (*this).max_exp)    num1 = 0;
        else                        num1 = (*this).coefficient[i];

        if(i >= rhs.max_exp)    num2 = 0;
        else                    num2 = rhs.coefficient[i];

        coe[i] = num1 + num2;
    }

    Poly result(max_length, coe);
    return result;
}

Poly Poly::operator -(Poly &rhs)
{
    int max_length = (*this).max_exp > rhs.max_exp ? (*this).max_exp : rhs.max_exp;
    int *coe = new int[max_length];

    for(int i=0;i<max_length;i++)
    {
        int num1, num2;
        if(i >= (*this).max_exp)    num1 = 0;
        else                        num1 = (*this).coefficient[i];

        if(i >= rhs.max_exp)    num2 = 0;
        else                    num2 = rhs.coefficient[i];
        
        coe[i] = num1 - num2;
    }

    Poly result(max_length, coe);
    return result;
}

Poly Poly::operator *(Poly &rhs)
{
    int max_length = (*this).max_exp - 1 + rhs.max_exp - 1 + 1;
    int *coe = new int[max_length];

    for(int i=0;i<max_length;i++)
        coe[i] = 0;

    for(int i=0;i<(*this).max_exp;i++)
    {
        for(int j=0;j<rhs.max_exp;j++)
        {
            int plus_num = (*this).coefficient[i] * rhs.coefficient[j];
            coe[i + j] += plus_num;
        }
    }

    Poly result(max_length, coe);
    return result;
}

void Poly::operator =(Poly rhs)
{
    (*this).max_exp = rhs.max_exp;
    (*this).coefficient = new int[rhs.max_exp];
    for(int i=0;rhs.max_exp;i++)
        (*this).coefficient[i] = rhs.coefficient[i];
}

void Poly::print_poly()
{
    for(int i=0;i<max_exp;i++)
    {
        if(i == 0)      cout << coefficient[i];
        else            cout << " " << coefficient[i];
    }
}

int main(int argc, char *argv[])
{
    int poly1_num = atoi(argv[1]);
    int *poly1 = new int[poly1_num];
    for(int i=0;i<poly1_num;i++)
        poly1[i] = atoi(argv[i + 2]);

    int poly2_num = atoi(argv[2 + poly1_num]);
    int *poly2 = new int[poly2_num];
    for(int i=0;i<poly2_num;i++)
        poly2[i] = atoi(argv[3 + poly1_num + i]);

    Poly first(poly1_num, poly1);
    Poly second(poly2_num, poly2);

    char op = argv[3 + poly1_num + poly2_num][0];
    if(op == '+')
    {
        Poly r = (first + second);
        r.print_poly();
    }
    else if(op == '-')
    {
        Poly r = (first - second);
        r.print_poly();
    }
    else
    {
        Poly r = (first * second);
        r.print_poly();
    }

    return 0;
}

