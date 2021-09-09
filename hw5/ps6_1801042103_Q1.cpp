#include<iostream>

using namespace std;

class Complex
{
    public:
        Complex();
        Complex(double real_);
        Complex(double real_,double imag_);
        Complex operator +(const Complex& other) const;
        Complex operator -(const Complex& other) const;
        bool operator ==(Complex& other) const;
        Complex operator*(const Complex& other) const;
        double getReal();
        double getImag();
        void setReal(double real_);
        void setImag(double imag_);
        friend istream & operator>>(istream &intput, Complex & number);
        friend ostream & operator<<(ostream &output, const Complex & number); 
    private:
        double real;
        double imag;
};
const Complex i(0,1);
Complex::Complex(){
    setReal(0);
    setImag(0);
}
Complex::Complex(double real_){
    setReal(real_);
    setImag(0);
}
Complex::Complex(double real_,double imag_){
    setReal(real_);
    setImag(imag_);
}
void Complex::setReal(double real_){
    real=real_;
}
void Complex::setImag(double imag_){
    imag=imag_;
}
double Complex::getImag(){
    return imag;
}
double Complex::getReal(){
    return real;
}
ostream& operator<<(ostream & output, const Complex & number)
{
    if(number.imag<0){
    output<<"(" <<number.real<<""<<number.imag<<"i)";
    }else{
    output<<"(" <<number.real<<"+"<<number.imag<<"i)";
    }
    return output;
}
istream& operator >>(istream & input,Complex & number){
  double real, imag;
   input>>real;  //read real part   
   input>>imag;  //read imaginary part
   if (input.good())
   {
       number.real = real;
       number.imag = imag;
   }
   return input;
}
bool Complex::operator ==(Complex& other )const{
    if(this->real==other.getReal() && this->imag==other.getImag()){
        return true;
    }else{
        return false;
    }
}
Complex Complex::operator+(const Complex& other) const{
    Complex result=*this;
    result.real +=other.real;
    result.imag +=other.imag;
    return result;
}
Complex Complex::operator-(const Complex& other)const{
    Complex result =*this;
    result.real -=other.real;
    result.imag -=other.imag;
    return result;
}
Complex Complex::operator*(const Complex& other)const{
    Complex result=*this;
    result.real=(this->real*other.real) - (this->imag *other.imag);
    result.imag=(this->real*other.imag) +(other.real*this->imag);
    return result;
}
int main(){
    //test
    Complex obje1;
    cout<<"No parameter constructor "<<obje1<<endl;
    Complex obje2(5);
    cout<<"One parameter constructor "<<obje2<<endl;
    Complex obje3(3,2);
    Complex obje4(1,6);
    cout<<obje3<<"+"<<obje4<<"="<<obje3+obje4<<endl;
    cout<<obje3<<"-"<<obje4<<"="<<obje3-obje4<<endl;
    if(obje3==obje4){
        cout<<obje3<<" , "<<obje4<<"complex numbers are equal"<<endl;
    }else{
        cout<<"Complex number are not equal"<<endl;
    }
    cout<<obje3<<"*"<<obje4<<"="<<obje3*obje4<<endl;
    cout<<"Enter a complex number a+bi: "<<endl;
    cin>>obje1;
    cout<<"a="<<obje1<<endl;
}
