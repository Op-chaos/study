#include <iostream>

using namespace std;

class Complex
{
    public:
        double imag, real;
        Complex(int r){                // type constructor
            real = r; imag = 0;
        }
        Complex(double r, double i){  // overload function of constructor
            real = r; imag = i;
        }
        Complex(Complex & c){         // copy constructor
            imag = c.imag; real = c.real;
        }
        ~Complex();
};
Complex::~Complex(){                  // destructor
    cout<<"it's over!"<<endl;
}

int main()
{
    Complex C1(1);
    Complex C2 = {2,3};
    Complex C3(C1);
    Complex C4 = C2;
    // Complex C5(1) = 4;
    C2 = 4;                           // using type constructor
    cout << "Hello World!" << endl;
    return 0;
}
