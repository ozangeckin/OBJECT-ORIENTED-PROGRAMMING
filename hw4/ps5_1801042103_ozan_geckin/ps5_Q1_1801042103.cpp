#include<iostream>
#include<vector>

using namespace std;

class Vector2D//create class
{
    public:
        Vector2D(){//no parametre constructor
            x=0;
            y=0;
        }
        Vector2D(int x_, int y_){//two parametre constructo
            x=x_;
            y=y_;
        }
        void SetXY(int x_, int y_){//set x and y
            x=x_;
            y=y_;
        }
        int GetX(){//return x
            return x;
        }
        int GetY(){//return y
            return y;
        }
        int operator *(const Vector2D &otherVector){//overloading * operator
            return (x*otherVector.x)+(y*otherVector.y);
        }
    private:
        int x,y;
};

int main(){
    //test
    Vector2D v1(3,4),v2(7,8);
     cout << "(" << v1.GetX() << "," << v1.GetY() << ") * (" << v2.GetX()<< "," << v2.GetY() << ") = " << v1*v2 << endl;
}