#include<iostream>

using namespace std;
 
class Rational{
    public:
    Rational(){
        numerator=0;
        denominator=1;
    }
    Rational(int num){
        numerator=num;
        denominator=1;
    }
    Rational(int num,int den){
        numerator=num;
        denominator=den;
    }
    Rational operator *(const Rational& otherNum){
        Rational temp;
        temp.numerator=this->numerator*otherNum.numerator;
        temp.denominator=this->denominator*otherNum.denominator;
        return temp;
    }
    Rational operator /(const Rational& otherNum){
        Rational temp;
        temp.numerator=this->numerator*otherNum.denominator;
        temp.denominator=this->denominator*otherNum.numerator;
        return temp;
    }
    bool operator ==(const Rational& otherNum){
        if((this->numerator*otherNum.denominator)==(this->denominator*otherNum.numerator)){
            return true;
        }else{
            return false;
        }
    }
    bool operator <=(const Rational& otherNum){
        if((this->numerator*otherNum.denominator)<=(this->denominator*otherNum.numerator)){
            return true;
        }else{
            return false;
        }
    }
    bool operator <(const Rational& otherNum){
        if((this->numerator*otherNum.denominator)<(this->denominator*otherNum.numerator)){
            return true;
        }else{
            return false;
        }
    }
    bool operator >(const Rational& otherNum){
        if((this->numerator*otherNum.denominator)>(this->denominator*otherNum.numerator)){
            return true;
        }else{
            return false;
        }
    }
    bool operator >=(const Rational& otherNum){
        if((this->numerator*otherNum.denominator)>=(this->denominator*otherNum.numerator)){
            return true;
        }else{
            return false;
        }
    }
    Rational operator+(const Rational& otherNum){
        Rational result;
        Rational temp1;
        Rational temp2;
        if(this->denominator == otherNum.denominator){
            result.numerator=this->numerator+otherNum.numerator;
            result.denominator=this->denominator;
        }else{
            temp1.numerator=this->numerator*otherNum.denominator;
            temp1.denominator=this->denominator*otherNum.denominator;
            temp2.numerator=otherNum.numerator*this->denominator;
            temp2.denominator=otherNum.denominator*this->denominator;
            result.numerator=temp1.numerator+temp2.numerator;
            result.denominator=temp1.denominator;
        }
        return result;
    }
    Rational operator-(const Rational& otherNum){
        Rational temp1;
        Rational temp2;
        Rational result;
        if(this->denominator == otherNum.denominator){
            if(this->numerator > otherNum.numerator){
                result.numerator = this->numerator - otherNum.numerator;
                result.denominator=this->denominator;
            }else{
                result.numerator=otherNum.numerator-this->numerator;
                result.denominator=this->denominator;
            }
        }else{
            temp1.numerator=this->numerator*otherNum.denominator;
            temp1.denominator=this->denominator*otherNum.denominator;
            temp2.numerator=otherNum.numerator*this->denominator;
            temp2.denominator=otherNum.denominator*this->denominator;
            if(temp1.numerator > temp2.numerator){
                result.numerator=temp1.numerator-temp2.numerator;
                result.denominator=temp1.denominator;
            }else{
                result.numerator=temp1.numerator-temp2.numerator;
                result.denominator=temp1.denominator;
            }
        }
        return result;
    }

    friend ostream& operator << (ostream& output,Rational& number);
    friend istream& operator >> (istream& input, Rational& number);
   	friend Rational check(Rational& number);

    private:
    int numerator;
    int denominator;
};
ostream& operator << (ostream& output,Rational& number){
    output<<number.numerator<<"/"<<number.denominator;
    return output;
}
istream& operator >>(istream& input, Rational& number)
{
	int topNumber;
	int bottomNumber;
	char one_char;
		
	input >> topNumber;
	input >> one_char;
	if (one_char == '/')
	{
		input >> bottomNumber;
	}
	else
	{
		bottomNumber = 1;
	}
	number.numerator = topNumber;
	number.denominator = bottomNumber;
	number = check(number);
	return input;
}
Rational check(Rational& number)
 {
	Rational temp;
	if (number.denominator < 0)
	{
		temp.numerator = -number.numerator;
		temp.denominator = -number.denominator;
	}
	else 
	{
		temp.numerator = number.numerator;
		temp.denominator = number.denominator;
	}
	return temp;
 }


int main(){
    Rational a(4,3);
    Rational b(1,8);
    Rational c,sum,sub,imp,com;
    cout<<c<<endl;
    cout<<"Please enter relation number"<<endl;
    cin>>c;
    cout<<"c = "<<c<<endl;
    cout<<"Obje a "<<a<<endl;
    cout<<"Obje b "<<b<<endl;  
    sum=a+b;
    cout<<"obje a"<<a<<"+"<<"obje b"<<b<<"="<<sum<<endl;
    sub=a-b;
    cout<<"obje a"<<a<<"-"<<"obje b"<<b<<"="<<sub<<endl;
    imp=a*b;
    cout<<"obje a"<<a<<"*"<<"obje b"<<b<<"="<<imp<<endl;
    com=a/b;
    cout<<"obje a"<<a<<"/"<<"obje b"<<b<<"="<<com<<endl;
    if(a>=b){
        cout<<a<<">="<<b<<" true"<<endl;
    }else{
        cout<<a<<">="<<b<<" false"<<endl;
    }
    if(a<=b){
        cout<<a<<"<="<<b<<" true"<<endl;
    }else{
        cout<<a<<"<="<<b<<" false"<<endl;
    }
    if(a>b){
        cout<<a<<">"<<b<<" true"<<endl; 
    }else{
        cout<<a<<">"<<b<<" false"<<endl;
    }
    if(a<b){
        cout<<a<<"<"<<b<<" true"<<endl;
    }else{
        cout<<a<<"<"<<b<<" false"<<endl;
    }
    if(a==b){
        cout<<a<<"=="<<b<<" true"<<endl;
    }else{
        cout<<a<<"=="<<b<<" false"<<endl;

    }
}
