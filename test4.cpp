#include<iostream>
#include <cmath> 
using namespace std;

long long zhengshu(long long num)
{
    long long a=0;
    if(num>=0)
    {  
        while(num>0)
        {
            a=10*a+num%10;
            num/=10;
        } 
    return a;
    }
    if(num<0)
    {        
        num*=-1;
        while(num>0)
        {
            a=10*a+num%10;
            num/=10;
        }
    }
    return a*(-1);
} 

double xiaoshu( double num )
{
    double integerPart = trunc( num );
    int decimalPart = fabs( num - integerPart );

    long long b=0;
    double c=0.0;
    int count =0;
    int d=0;    
    if( decimalPart >=0)
    {  
        while( decimalPart >0)
        {
            b=10*b+decimalPart%10;
            decimalPart /=10;
        } 

        while( integerPart < 1)
        {
            integerPart *=10;
            c=10*c+integerPart/10;
            integerPart = trunc( integerPart );
            count++;
        }

        for (int i=0;i<count;i++){
            d=c/10;
            }
        return b+d;

    }
    if( decimalPart <0)
    {  
        decimalPart *= -1;
        while( decimalPart >0)
        {
            b=10*b+decimalPart%10;
            decimalPart /=10;
        } 

        while( integerPart < 1)
        {
            integerPart *=10;
            c=10*c+integerPart/10;
            integerPart = trunc( integerPart );
            count++;
        }

        for (int i=0;i<count;i++){
            d=c/10;
            }
        return b*(-1)+d;

    }
 
}

int fenshu(int num){
    cout << "false" << endl;
}

int baifenshu (int num){
    cout << "error" << endl;
}

int main()
{
    cout << "xuanzeleixing：" << endl;
    cout << "zhengshu:1" << endl;
    cout << "fudianshu:2" << endl;
    cout << "fenshu:3" << endl;
    cout << "baifenshu:4" << endl;  

    int choice=0;
    cin >> choice;

    int num;
    cout << "shuruneirong" << endl;
    cin >> num;

    switch  (choice) 
    {
        case 1:{
            zhengshu(num);
            break;
        }
        case 2:{
            xiaoshu(num);
            break;
        }
        case 3:{
            fenshu(num);
            break; 
        }
        case 4:{
            baifenshu(num);
            break;
        }
    }
        return 0;
    }
 
 