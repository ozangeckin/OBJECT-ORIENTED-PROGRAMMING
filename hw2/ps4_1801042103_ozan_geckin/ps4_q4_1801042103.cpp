#include<iostream>

using namespace std;

class Pizza{
    public:
        Pizza();//constructor
        const void outputDescription();//print
        const double computePrice();//compute
        void setType(int x);//set Type
        void setSize(int x);//set Size
        void setPer(int per);//set peperron or cheese topping
    private:
        const string typenames[3]={"Deep dish","Hand tossed","Pan"};
        const string sizenames[3]={"Small","Medium","Large"};
        int typenumber=0;
        int sizenumber=0;
        int pertopping=0;   
};
    Pizza::Pizza(){}
    const void Pizza::outputDescription(){
        cout<<"Type "<<typenames[typenumber]<<" size "<<sizenames[sizenumber]<<" the number of sauces it contains "<<pertopping<<" price of pizza $"<<computePrice()<<endl;
    }
    const double Pizza::computePrice(){
        double price=0;
        if(sizenumber==0){
            price=10+(pertopping*2);
        }
        else if(sizenumber==1){
            price=14+(pertopping*2);
        }
        else if(sizenumber=2){
            price=17+(pertopping*2);
        }
        return price;
    }
    void Pizza::setType(int x){
        if(x>-1 && x<3){
            typenumber=x;
        }
        else{
            cout<<"Please enter 0-1-2"<<endl;
            cin>>x;
            setType(x);
        }
    }
    void Pizza::setSize(int x){
        if(x>-1 && x<3){
            sizenumber=x;
        }
        else{
            cout<<"Please enter 0-1-2"<<endl;
            cin>>x;
            setSize(x);
        }  
    }
    void Pizza::setPer(int per){
        pertopping=per;
    }
int main(){
    Pizza a,b,c;//created obje
    //test 
    a.setSize(0);
    a.setType(0);
    a.setPer(1);
    a.outputDescription();

    b.setSize(1);
    b.setType(1);
    b.setPer(2);
    b.outputDescription();

    c.setSize(2);
    c.setType(2);
    c.setPer(3);
    c.outputDescription();
}