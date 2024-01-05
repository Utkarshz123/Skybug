
#include<iostream>
#include <cstdlib>
#include<climits>
#include<cmath>
using namespace std;
int main()
{
   int random_number = rand();
  long  int x;
  
  if(random_number>100)
  {   int l =100;
      random_number = random_number%l;
  }
  if(random_number==0)
  {
      random_number=100;
  }
  // cout<<random_number<<endl;
 
   while(1)
   {
    cout<<"guess the number between 1 to 100"<<endl;
    cin>>x;
    if(x>100)
    {
        cout<<"Invalid number"<<endl;
        cout<<"please try again"<<endl;
    
        continue;
    }
    if(random_number == x)
    {
        cout<<"congratulations ! you  guess the correct number"<<endl;
        break;
    }else if(random_number>x)
    {
        cout<<"your number is too low"<<endl;
        cout<<"please try again"<<endl;
    }else{
        cout<<"your number is too high"<<endl;
        cout<<"please try again"<<endl;
    }
   }
}