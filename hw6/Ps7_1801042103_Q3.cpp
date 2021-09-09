#include<iostream>
#include<math.h>
using namespace std;

class Polynomical
{
    public:
        Polynomical();//no parametre constructor
        Polynomical(double coeff);//one parametre constructor
        Polynomical(double *coeff,int deg);//two parametre constructor
        Polynomical(const Polynomical& other);//copy constructor
        ~Polynomical();//destructor
        Polynomical& operator =(const Polynomical& other);//assignment operator overloading
        void setCoeff(double coeff,int exp);//to setter coefficient
        double getCoeff(const int exp);//to getter coefficient
        double evaluate(double x);//to evaluate
        void print();//to print
        friend Polynomical operator+(const Polynomical& o1,const Polynomical& o2);//overloading + operator.
        friend Polynomical operator-(const Polynomical& o1,const Polynomical& o2);//overloading - operator.
        friend Polynomical operator*(const Polynomical& o1,const Polynomical& o2);//overloading * operator.
        
    private:
        double *coefficients;//to keep coefficients of polynomical
        int degree;//degree of the polynominal.
};

Polynomical::Polynomical(){//no parametre constructor
    degree=1;//default degree one
    coefficients=new double[degree];//dynamic memory allocation
    coefficients[0]=0;

}
Polynomical::Polynomical(double coeff){//one parametre constructor(coefficients initial)
    degree=1;//default degree one
    coefficients=new double[degree];//dynamic memory allocation
    coefficients[0]=coeff;
}
Polynomical::Polynomical(double *coeff,int deg){//two parametre constructor
    degree=deg;
    coefficients=new double[degree];//dynamic memory allocation
    for(int i=0;i<degree;i++){
        coefficients[i]=coeff[i];
    }
}
Polynomical::Polynomical(const Polynomical& other){//copy constructor
    if(degree !=other.degree){//to check degree of objects.
        delete[]coefficients;//to delete coefficient double array 
        degree=other.degree;
        coefficients = new double[degree];//dynamic memory allocation
    }
    for(int i=0;i<degree;i++){//to assignment to coefficient
        coefficients[i]=other.coefficients[i];
    }
}
Polynomical::~Polynomical(){//destructor
    delete[] coefficients;
}
void Polynomical::setCoeff(double coeff,int exp){//to set coefficient.
    if(exp>=degree){//error check
        cout<<"Error:You entered a exponent larger than degrees"<<endl;
        exit(1);
    }else{
        coefficients[exp]=coeff;
    }
}
double Polynomical::getCoeff(const int exp){//to getter coefficent.
    if(exp >=degree){//error check
        cout<<"Error:You entered a exponent larger than degrees"<<endl;
        exit(1);
    }
    else{
        return coefficients[exp];
    }

}
double Polynomical::evaluate(double x){//to evaluate
    double result=0;//to keep result
    for(int i=0;i<degree;i++){
        result+=coefficients[i]*pow(x,i);
    }
    return result;
}
Polynomical& Polynomical::operator=(const Polynomical& other){//overloading = operator
    if(degree != other.degree){//to check degree of objects.
        delete[] coefficients;//to delete left object.coefficient
        degree=other.degree;//degree assignment.
        coefficients=new double[degree];//dynamic memory allocation
    }
    for(int i=0;i<degree;i++){//to assignment coefficients
        coefficients[i]=other.coefficients[i];
    }
    return *this;
}
Polynomical operator*(const Polynomical& o1,const Polynomical& o2){//overloading * operator.
    Polynomical result;//to keep product
    result.degree=o1.degree+o2.degree;//new degree assignment
    delete[]result.coefficients;//to delete temporary object's coefficient holder.
    result.coefficients=new double[result.degree];//dynamic memory allocation.
    for(int i=0;i<result.degree;i++){//to prevent If the product is 0 in the result object,junk values is used.
        result.coefficients[i]=0;//zero assingment
    }
    for(int i=0;i<o1.degree;i++){
        for(int j=0;j<o2.degree;j++){
            result.coefficients[i+j] +=o1.coefficients[i]*o2.coefficients[j];
        }
    }
    return result;
}

Polynomical operator-(const Polynomical& o1,const Polynomical& o2){//overloading - operator.
    Polynomical result;//to keep subtraction
    if(o1.degree>=o2.degree){//to check degree
        result.degree=o1.degree;
    }else{
        result.degree=o2.degree;
    }
    delete[] result.coefficients;//to delete temporary object's coefficient holder.
    result.coefficients=new double[result.degree];//dynamic memory allocation.
    for(int i=0;i<result.degree;i++){
        if(i<o1.degree){
            result.coefficients[i] +=o1.coefficients[i];
        }
        if(i<o2.degree){
            result.coefficients[i] -=o2.coefficients[i];
        }
    }
    return result;
}
Polynomical operator+(const Polynomical& o1,const Polynomical& o2){//overloading + operator.
    Polynomical result;//to keep sum
    if(o1.degree>=o2.degree){//to check degree 
        result.degree=o1.degree;
    }else{
        result.degree=o2.degree;
    }
    delete[] result.coefficients;//to delete temporary object's coefficient holder.
    result.coefficients=new double[result.degree];//dynamic memory allocation.
    for(int i=0;i<result.degree;i++){
        if(i<o1.degree){
            result.coefficients[i] +=o1.coefficients[i];
        }
        if(i<o2.degree){
            result.coefficients[i] +=o2.coefficients[i];
        }
    }
    return result;
}
void Polynomical::print(){//to print the polynomial console.
    bool cntl=false;//to check polynomial is 0.
    for (int i = 0; i < degree; i++)//to access the polynomial from head to tail.
    {
        if(coefficients[degree-i-1]!=0){//to check coefficient (0)
            cout<<coefficients[degree-i-1];
            cntl=true;
            if((degree-i-1)!=0){//to check degree (0)
                cout<<"x^"<<degree-i-1;
            }
        }
        if((cntl==true) && (i<(degree-1))){
            cout<<"+";
        }
    }
    if(cntl==false){
        cout<<"0";
    }  
}

int main(){

    //test;
    Polynomical obje1,obje2(5),obje5,sum,diff,pro;
    double tCoeff[]={6,3,1,2};
    double t2Coeff[]={5,1,3};
    Polynomical obje3(tCoeff,4),obje4(t2Coeff,3);
    cout<<"Obje created by the default constructor obje1 ";
        obje1.print();
        cout<<endl;
    cout<<"Obje created by one parameter constructor obje2 ";
        obje2.print();
        cout<<endl;
    cout<<"Obje created by two parameter constructor obje3 ";
        obje3.print();
        cout<<endl;
    cout<<"Obje created by two parameter constructor obje4 ";
        obje4.print();
        cout<<endl<<endl;
    cout<<"obje3 + obje4 = ";
        sum=obje3+obje4;
        sum.print();
        cout<<endl;
    cout<<"obje3 - obje4 = ";
        diff=obje3-obje4;
        diff.print();
        cout<<endl;
    cout<<"obje3 * obje4 = ";
        pro=obje3*obje4;
        pro.print();
        cout<<endl;
    cout<<endl;
      cout<<"obje1 + obje2 = ";
        sum=obje1+obje2;
        sum.print();
        cout<<endl;
    cout<<"obje1 - obje2 = ";
        diff=obje1-obje2;
        diff.print();
        cout<<endl;
    cout<<"obje1 * obje2 = ";
        diff=obje1*obje2;
        diff.print();
        cout<<endl<<endl;
    cout<<"obje 1 Evaluate : ";
        obje5=obje1.evaluate(2);
        obje5.print();
        cout<<endl;
    cout<<"obje 2 Evaluate : ";
        obje5=obje2.evaluate(2);
        obje5.print();
        cout<<endl;
    cout<<"obje 3 Evaluate : ";
        obje5=obje3.evaluate(2);
        obje5.print();
        cout<<endl;
     cout<<"obje 4 Evaluate : ";
        obje5=obje4.evaluate(2);
        obje5.print();
        cout<<endl<<endl;



}