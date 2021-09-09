//I have defined the required classes for my program.
#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>

using namespace std;

//I initialized the function I used 
int* convert(string number,int limit,int numArr[]);//I wrote the convert function to convert the incoming string to int
string input(int limit);//I used to get the number from the user
bool solved(int secretNumber[],int inputNumber[],int limit,const int trialNumber,int trialCounter);//Compares the number estimated with the secret number
bool checkNumber(string number);//here I check if the numbers are different
void game(int number[],int trialNumber,int trialCounter,int numberOfDigit);//I wrote to play the game
int* random(int secretNumber[],int numberOfDigit);//I wrote to generate a random number
void checkNumberCharacter(string number,int numberOfDigit);//I check if there is any other character in the number other than the number

int main(int argc,char *argv[])
{
    srand((unsigned)time(NULL));//I used it to generate random numbers..
    const char argv1[3]= "-r";//I have defined the command line to compare strings
    const char argv2[3]= "-u";//I have defined the command line to compare strings
    int trialCounter=0;//I defined to keep the number of times the user tried
    const int trialNumber=100;//I have defined trialnumber to give the user 100 trial rights fixed..

    if(argc!=3)//I have defined it to check if there are more than 3 parameters from the command line line.
    {
        cerr<<"E0"<<endl;
        exit(1);
    }
    else
    {
    if(strcmp(argv[1],argv1)==0)// If the -r entry comes from the command line, I made a check to enter if here.
    { 
       if(argv[2][1]>10 || argv[2][1]<0)//check number of digit.
       {
           cerr<<"E0"<<endl;
           exit(1);
       }
        int  numberOfDigit = stoi(argv[2]);//converting incoming number of digits string to integera
        int secretNumber1[numberOfDigit];//I defined the integer array to keep the secret number I will create randomly.
        checkNumberCharacter(argv[2],1);
        game(random(secretNumber1,numberOfDigit),trialNumber,trialCounter,numberOfDigit);
    }
    else if(strcmp(argv[1],argv2) ==0)// If the -u entry comes from the command line, I made a check to enter if here. .
    {
        // I'm checking the secret number from the command line
        string n=argv[2];//I defined it to hold the secret number from the command line
        int nu[n.length()];
        checkNumberCharacter(n,n.length());
        if(checkNumber(n))
        {
            cerr<<"E0"<<endl;
            exit(1);
        }
           game(convert(n,n.length(),nu),trialNumber,trialCounter,n.length());
    }else
    {
        cerr<<"E0"<<endl;
        exit(1);
    }
    }
}
int* convert(string number,int limit,int numArr[])//I convert the incoming string into integer array..takes string number, number of digit and return integer as parameter
{
    int num=stoi(number);
    for(int i=limit-1;-1<i;i--)
    {
        numArr[i]=num%10;
        num=num/10;  
    }
    return numArr;
}
string input(int limit)//I get string input from user .takes number of digits as parameters
{
    string inputNumber="";
    cin>>inputNumber;
    bool cntrl=false;
    for(int i=0;i<inputNumber.length();i++)// I check if there is anything other than numbers in the number from the user.
    {
        if(inputNumber[i]=='0'||inputNumber[i]=='1'||inputNumber[i]=='2'||inputNumber[i]=='3'||inputNumber[i]=='4'||inputNumber[i]=='5'||inputNumber[i]=='6'||inputNumber[i]=='7'||inputNumber[i]=='8'||inputNumber[i]=='9')
        {
            cntrl=true;
        }
        else 
        {
            cout<<"E2"<<endl;
            exit(1);        
        }
    }
    if(checkNumber(inputNumber)){
        cerr<<"E1"<<endl;
        exit(1);
    }
    if(inputNumber.length()==limit && inputNumber[0]!='0')
    {
        cntrl=true;
    }
     if(inputNumber.length() !=limit )// I check the number of digits in the first digit 0 or number.
    {
        cerr<<"E1"<<endl;
        exit(1);
    }
    if(cntrl==true)// If the controller is correct, I return the number I get as a string.
    {
        return inputNumber;
    }  
}
bool solved(int secretNumber[],int inputNumber[],int limit,const int trialNumber,int trialCounter)//Compares the number estimated with the secret number..takes secretNumber,input number,number of digit and trial number as parameters.
{
    int count=0;//first count 
    int countp=0;//second count
    while(trialCounter<trialNumber && count!=limit)//I make the controls whether the game can be solved or not using the while loop.
    {
    for(int i=0;i<limit;i++)
    {     
            if(secretNumber[i]==inputNumber[i])
            { 
                count++;//I am increasing the first count if there is the same number in the same digit.
            }       
    }
    for(int i=0;i<limit;i++)
    {
        for(int j=0;j<limit;j++)
        {
            if(i!=j)
            {
                if(secretNumber[i]==inputNumber[j])
                {
                    countp++;//I am increasing the second count if there is the same number in different digits 
                }
            }   
        }
    }
        if(count==limit)//if the correct number is found, it enters the if condition.
        {
            cout<<"FOUND "<<trialCounter<<endl;
            exit(1);
        }
        else{
            cout<<count<<" "<<countp<<endl;
            return false; 
        }     
    }  
    if(trialCounter==trialNumber)//If the trial fails until trialNumber, it goes down below.
    {
        cout<<"FAILED"<<endl;
    }
}
bool checkNumber(string number)//here I check if the numbers are different
{
    for(int i=0;i<number.length();i++){
        for(int j=number.length()-1;j>0;j--){
            if(i==j){
                continue;
            }
            if(number[i]==number[j] || number[0]=='0'){
                return true;
            }
        }
    }
}
void game(int number[],int trialNumber,int trialCounter,int numberOfDigit)//I take secret number, trial number, maximum try, number of digits as a parameter.
{
        string numB="";// to keep the input number
        int nu[numberOfDigit];//I use it to keep secret numbers after converting.
        int nu1[numberOfDigit];//I use it to keep input numbers after converting.
        bool cn=false;
        while(cn !=true)
        {
            trialCounter++;
            numB=input(numberOfDigit);
            cn=solved(number,convert(numB,numB.length(),nu1),numberOfDigit,trialNumber,trialCounter);
        }

}
int* random(int secretNumber[],int numberOfDigit)//I use it to generate random secret numbers, and it takes the number of digits with an empty array as a parameter, and it fills and returns that empty arra.
{
    int r;//I have defined random numbers to keep them temporarily.
    bool used[numberOfDigit] = { 0 }; //I used it to compare when I was throwing a random number to be unique.
    for(int i=0;i<numberOfDigit;i++)
        {
        bool cnt=false;
        while(!cnt)
        {
            r=rand()%10;
            cnt =!used[r];
            if(cnt){
                if(i==0)
                {
                    if(r==0)
                    {
                        cnt=false;
                    }
                }
                secretNumber[i]=r;
                used[r]=true;
            } 
        }
    }
    return secretNumber;
}
void checkNumberCharacter(string number,int numberOfDigit)//takes the number and length as parameters
{
    for(int i=0;i<numberOfDigit;i++)//I check if there is anything other than numbers in the secret number in the if condition here.
    {
        if(number[0]=='0' || (number[i]!='0' && number[i]!='1' && number[i]!='2' && number[i]!='3' && number[i]!='4' && number[i]!='5' && number[i]!='6' && number[i]!='7' && number[i]!='8' && number[i]!='9'))
        {
            cerr<<"E0"<<endl;
            exit(1); 
        }
    }
}