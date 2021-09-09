#include<iostream>

using namespace std;
 
void towersOfHanoi(int diskNumber,char disk1,char disk2,char disk3);

int main(){
    int number;
    cout<<"Enter number of disk : ";
    cin>>number;
    towersOfHanoi(number,'A','C','B');

}

void towersOfHanoi(int diskNumber,char disk1,char disk2,char disk3){
    if(diskNumber==1){
        cout<<"Move disk 1 from post "<<disk1<<" to post "<<disk2<<endl;
        return;
    }else{
        towersOfHanoi(diskNumber-1,disk1,disk3,disk2);
        cout<<"Move disk "<<diskNumber<<" from post "<<disk1<<" to post "<<disk2<<endl;
        towersOfHanoi(diskNumber-1,disk3,disk2,disk1);
    }
}
