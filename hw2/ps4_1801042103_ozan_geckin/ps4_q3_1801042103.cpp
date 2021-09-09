#include<iostream>

using namespace std;

class Point{
    public:
    Point(){//no parametre contructor
        x=0;
        y=0;
    }
    Point(int x_,int y_){//two parametre constructor
        setX(x_);
        setY(y_);
    }
    void move(int vertical,int horizontal)//Takes 2 parameters and moves
    {
        int tempX=x+vertical;
        int tempY=y+horizontal;
        x=tempX;
        y=tempY;
        cout<<x<<','<<y<<endl;
    }
    void rotate(){//90 degrees clockwise
     
        cout<<x<<','<<-y<<endl;
    }
    int getX(){//return x
        return x;
    }
    int getY(){//return y
        return y;
    }
    void getPoint(){//return points

        cout<<x<<','<<y<<endl;
    }
    void setX(int x_)//set x
    {
        x=x_;
    }
    void setY(int y_){//set y
        y=y_;
    }
    private:
    int x;
    int y;

};
int main(){
    Point a,b(2,3);//create obje
    int q,j,k;
    int hor,ver;
    //test
    cout<<"How many enter points?"<<endl;
    cin>>k;
    for(int i=0;i<k;i++){
        cout<<"Point "<<i+1<<endl;
        cout<<"Please enter point in x:";
        cin>>q;
        cout<<"Please enter point in y:";
        cin>>j;
        Point x(q,j);
        cout<<"*Location:";
        x.getPoint();
        cout<<"*Please enter how much you want to move"<<endl;
        cout<<"Vertical: ";
        cin>>ver;
        cout<<"Horizontal: ";
        cin>>hor;
        cout<<"*New Location:";
        x.move(ver,hor);
        //cout<<endl;
        cout<<"*Rotate the point by 90 degrees clockwise around the origin :";
        x.rotate();
       // cout<<endl;
     
   }
   
}

