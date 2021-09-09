#include<iostream>

using namespace std;
//define Exception class
class Exception{
    public:
        Exception(){//default parametre constructor

        }
        Exception(const string error_):error(error_){//one parametre constructor

        }
        ~Exception(){//destructor of Exception class

        }
        string getError()const{//return string error
            return error;
        }
        void setError(string error_){//set string error
            error=error_;
        }
    private:
        string error;
};

class Account{
    private:
        double balance;

    public:
        Account(){
            balance=0;
        }
        Account(double initialDeposit){
            balance=initialDeposit;
        }
        double getBalance(){
            return balance;
        }
        //returns new balance or -1 if error
        double depoist(double amount){
            if(amount>0){
                balance+=amount;
            }else{
                throw Exception("The amount to be deposited is not negaitf!!!\n");
            }
            return balance;
        }
        //return new balance or -1 if invalid amount
        double withdraw(double amount){
            if((amount>balance)||(amount<0))
                throw Exception("The balance is less than withdrawl amount\n");
            else
                balance-=amount;
            return balance;  
        }
};

int main(){
    try{//test exception in deposit
        Account obje(500);
        obje.depoist(-20);
    }catch(Exception& e){
        cout<<"It is thrown exception "<<e.getError()<<endl;
    }try{//test exception in withdraw
        Account obje2(600);
        obje2.withdraw(1000);
    
    }catch(Exception& e1){
        cout<<"It is thrown exception "<<e1.getError()<<endl;
    }
}