#include<iostream>

using namespace std;
//define exception class
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

int getProductId(int ids[],string names[],int numProduct,string target){
    for(int i=0;i<numProduct;i++){
        if(names[i]==target)
            return ids[i];
    }
    throw Exception(target);
}

int main(){//Sample code to test the getProductID function
    int productIds[]={4,5,8,10,13};
    string products[]={"computer","flash drive","mouse","printer","camera"};
    try{
        cout<<getProductId(productIds,products,5,"mouse")<<endl;
        cout<<getProductId(productIds,products,5,"camera")<<endl;
        cout<<getProductId(productIds,products,5,"laptop");
    }catch(Exception& e){ 
        cout<<e.getError()<<" product is not found"<<endl;
        exit(1);
    }
    return 0;
}