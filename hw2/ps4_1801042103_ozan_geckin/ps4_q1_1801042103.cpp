#include<iostream>

using namespace std;

class Student{
    public:
    Student(){

    }
    void setQuiz1(int quiz){//Sets the 1st quiz grade
        if(quiz>-1 && quiz<11){
            quiz1=quiz;
        }
        else{
            cout<<"Please enter between 0 and 10 number"<<endl;
            cin>>quiz;
            setQuiz1(quiz);
        }
    }
     void setQuiz2(int quiz){//Sets the 1st quiz grade
        if(quiz>-1 && quiz<11){
            quiz2=quiz;
        }
        else{
            cout<<"Please enter between 0 and 10 number"<<endl;
            cin>>quiz;
            setQuiz2(quiz);
        }
    }
    int getQuiz1(){//Returns the 1st quiz note
        return quiz1;
    }
    int getQuiz2(){//Returns the 2st quiz note
        return quiz2;
    }
    void setMid(int midt){//sets midterm grade
        if(midt>-1 && midt<101){
            midterm=midt;
        }else{
            cout<<"Please enter between 0 and 100 number"<<endl;
            cin>>midt;
            setMid(midt);
        }
            
    }
    void setFinal(int final_){//sets final grade
           if(final_>-1 && final_<101){
            final=final_;
        }else{
            cout<<"Please enter between 0 and 100 number"<<endl;
            cin>>final_;
            setFinal(final_);
        }
    }
    int getMid(){//returns midterm
        return midterm;
    }
    int getFinal(){//returns final
        return final;
    }
    void compute(){//calculate notes
        double temp=0;
        temp=(final/2)+(midterm/4)+((((quiz1*10)+(quiz2*10))/2)/4);
        if(temp>=90 && temp<=100){
            cout<<"Grade A"<<endl;
        }
        else if(temp<90 && temp>=80){
            cout<<"Grade B"<<endl;
        }
        else if(temp<80 && temp>=70){
            cout<<"Grade C"<<endl;
        }
        else if(temp<70 && temp>=60){
            cout<<"Grade D"<<endl;
        }
        else{
            cout<<"Grade F"<<endl;
        }
    }
    private:
    int quiz1;
    int quiz2;
    int midterm;
    int final;
};

int main(){
    Student stu1,stu2,stu3,stu4,stu5;//created obje
    //test 
    stu1.setQuiz1(7);
    stu1.setQuiz2(10);
    stu1.setMid(90);
    stu1.setFinal(95);
    cout<<"student 1 ";
    stu1.compute();

    stu2.setQuiz1(9);
    stu2.setQuiz2(8);
    stu2.setMid(90);
    stu2.setFinal(80);
    cout<<"student 2 ";
    stu2.compute();

    stu3.setQuiz1(7);
    stu3.setQuiz2(8);
    stu3.setMid(70);
    stu3.setFinal(80);
    cout<<"student 3 ";
    stu3.compute();

    stu4.setQuiz1(5);
    stu4.setQuiz2(8);
    stu4.setMid(50);
    stu4.setFinal(70);
    cout<<"student 4 ";
    stu4.compute();

    stu5.setQuiz1(4);
    stu5.setQuiz2(0);
    stu5.setMid(40);
    stu5.setFinal(35);
    cout<<"student 5 ";
    stu5.compute();
}
