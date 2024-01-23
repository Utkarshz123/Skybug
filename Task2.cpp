#include <iostream>
using namespace std;
int main() {
    
    float m,n;
    char op;
    cout<<"Enter the first number";
    cin>>m;
    cout<<"Enter the second number";
    cin>>n;
    cout<<"Enter the operation";
    cin>>op;
    switch(op){
        case '+':   cout<<"The sum is"<<(m+n)<<endl;
        break;
        case '-':   cout<<"The subtraction is"<<(m-n)<<endl;
        break;
        case '*':   cout<<"The multiplication is"<<(m*n)<<endl;
        break;
        case '/':   cout<<"The division is"<<(m/n)<<endl;
        break;
        
    
       
        
    }
    
   

    return 0;
}
