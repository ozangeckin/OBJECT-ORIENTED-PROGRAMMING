#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> vec;//decleration vector
    int a=0;//how many suitors to hold
    int c=0;//counter 3 to count 3 sooner
    int temp=0;
    cout<<"Please enter suitor of numbers:";
    cin>>a;
    for(int i=1;i<a+1;i++){//I fill the vector
        vec.push_back(i);
    }
    for(auto it=vec.begin();it!=vec.end();it++){//I'm printing the first version
        cout<<*it;
    }
    cout<<" initial list of  suitors,start counting from "<<vec[0]<<endl;
    do{//I'm counting 3 people and eliminating them
        for(auto it_=vec.begin();it_!=vec.end();it_++){
            c++;
            if(c==3){
            temp=*it_;
            vec.erase(it_);
            if(it_==vec.end()){
            it_=vec.begin();
            }
            for(auto it=vec.begin();it!=vec.end();it++){
                cout<<*it;
            }
            if(vec.size()==1){
            cout<<" suitor "<<temp<<" eliminated, "<<vec[0]<<" is the lucky winner"<<endl;
            break;
            }else{
            cout<<" suitor "<<temp<<" eliminated,continue counting from "<<*it_<<endl;
            c=1;
            }
           }
          
        } 
    } while(vec.size()!=1);          
}

