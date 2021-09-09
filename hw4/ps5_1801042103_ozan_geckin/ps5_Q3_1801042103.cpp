#include<iostream>

using namespace std;

class PrimeNumber{//create class
    public:
        PrimeNumber(){//no parametre constructor
            pri=1;
        }
        PrimeNumber(int x){//one parametre constructor
                pri=x;
        }
        void setPri(int x){//set prime number
            if(checkPrime(x)==true){
                pri=x;
            }
            else{
                cout<<"Not prime number"<<endl;
                exit(1);
            }
        }
        int getPri(){//return prime number
            return pri;
        }
        bool checkPrime(int num){//check prime number or not prime number
            if(num<2)
            {
                return false;
            }else if(num==2)
            {
                return true;
            }else
            {
                for(int i=2;i<=num/2;i++){
                    if(num%i==0){
                        return false;
                        break;
                    }
                }
            }
            return true;
        }
        PrimeNumber operator ++(int){//postfix ++ overloading
            int temp=pri +=1;
            while(!checkPrime(pri)){
                temp=pri;
                pri++;
            }
            return temp;
        }
        PrimeNumber operator --(int){//postfix -- overloading
            int temp=pri -=1;
            while(!checkPrime(pri)){
                temp=pri;
                pri--;
            }
            return temp;
        }
        PrimeNumber operator ++(){//prefix ++ overloading
            pri +=1;
            while(!checkPrime(pri)){
                pri++;
            }
            return pri;
        }
        PrimeNumber operator --(){//prefix -- overloading
            pri -=1;
            while(!checkPrime(pri)){
                pri--;
            }
            return pri;
        }
    private:
        int pri;
};

int main(){
    //test
        int a;
    do{
    cout<<"Enter prime number until -1"<<endl;
    cin>>a;
    PrimeNumber num;
    num.setPri(a);
    PrimeNumber c=num++;//postfix
    cout<<"1-Postfix ++ "<<num.getPri()<<endl;
    PrimeNumber v=++num;//prefix
    cout<<"2-Prefix ++ "<<num.getPri()<<endl;
    PrimeNumber b=num--;
    cout<<"3-Postfix -- "<<num.getPri()<<endl;
    PrimeNumber n=--num;
    cout<<"4-Prefix -- "<<num.getPri()<<endl;
    }while(a!=-1);
   
    


}