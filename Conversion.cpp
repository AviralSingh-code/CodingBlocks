#include <iostream>
#include <cmath>
using namespace std;
static int decimalToBinary(int num)
{
        int count=0;
        int arr[1000];
        int k=0;
        int Final=0;
        while(num)
        {
            int d=num%2;
            arr[k]=d;
            k++;
            count++;
            num=(int)(num/2);
        }
        for(int i=count-1;i>=0;i--)
        {
            Final=(Final*10)+arr[i];
        }
        return(Final);
}
static int decimalToOctal(int num)
{
        int count=0;
        int arr[1000];
        int k=0;
        int Final=0;
        while(num)
        {
            int d=num%8;
            arr[k]=d;
            k++;
            count++;
            num=(int)(num/8);
        }
        for(int i=count-1;i>=0;i--)
        {
            Final=(Final*10)+arr[i];
        }
        return Final;
}
static int HexadecimalToDecimal(string number)
{
        cin>>number;
        int value[1000];
        int counter=0;
        int length=number.length();
        for(int i=0;i<length;i++)
        {
            char f=number.at(i);
            if(f=='A')
            {
                value[counter]=10;
                counter++;
            }
            else if(f=='B')
            {
                value[counter]=11;
                counter++;
            }
            else if(f=='C')
            {
                value[counter]=12;
                counter++;
            }
            else if(f=='D')
            {
                value[counter]=13;
                counter++;
            }
            else if(f=='E')
            {
                value[counter]=14;
                counter++;
            }
            else if(f=='F')
            {
                value[counter]=15;
                counter++;
            }
            else if(f=='0')
            {
                value[counter]=0;
                counter++;
            }
            else if(f=='1')
            {
                value[counter]=1;
                counter++;
            }
            else if(f=='2')
            {
                value[counter]=2;
                counter++;
            }
            else if(f=='3')
            {
                value[counter]=3;
                counter++;
            }
            else if(f=='4')
            {
                value[counter]=4;
                counter++;
            }
            else if(f=='5')
            {
                value[counter]=5;
                counter++;
            }
            else if(f=='6')
            {
                value[counter]=6;
                counter++;
            }
            else if(f=='7')
            {
                value[counter]=7;
                counter++;
            }
            else if(f=='8')
            {
                value[counter]=8;
                counter++;
            }
            else if(f=='9')
            {
                value[counter]=9;
                counter++;
            }   
        }
        int k=0;
        int ans=0;
        for(int i=counter-1;i>=0;i--)
        {
            ans=ans+value[i]*pow(16,k);
            k++;
        }
        return(ans);
}
static int binaryToDecimal(int num)
{
        int k=0;
        int sum=0;
        while(num)
        {
            int d=num%10;
            sum=sum+(d*pow(2,k));
            k++;
            num=num/10;
        }
        return sum;
}
static int octalToDecimal(int num)
{
     int k=0;
        int sum=0;
        while(num)
        {
            int d=num%10;
            sum=sum+(d*pow(8,k));
            k++;
            num=num/10;
        }
        return sum;
}
static string decimalToHexadecimal(int num)
{
        int count=0;
        int arr[1000];
        int k=0;
        string answer="";
        while(num)
        {
            int d=num%16;
            arr[k]=d;
            k++;
            count++;
            num=(int)(num/16);
        }
        for(int i=count-1;i>=0;i--)
        {
            if(arr[i]<=9)
            {
                if(arr[i]==0)
                {
                    answer=answer+'0';
                }
                if(arr[i]==1)
                {
                    answer=answer+'1';
                }
                if(arr[i]==2)
                {
                    answer=answer+'2';
                }
                if(arr[i]==3)
                {
                    answer=answer+'3';
                }
                if(arr[i]==4)
                {
                    answer=answer+'4';
                }
                if(arr[i]==5)
                {
                    answer=answer+'5';
                }
                if(arr[i]==6)
                {
                    answer=answer+'6';
                }
                if(arr[i]==7)
                {
                    answer=answer+'7';
                }
                if(arr[i]==8)
                {
                    answer=answer+'8';
                }
                if(arr[i]==9)
                {
                    answer=answer+'9';
                }
            }
            else 
            {
                int hold=arr[i];
                if(hold==10)
                {
                    answer=answer+'A';
                }
                else if(hold==11)
                {
                    answer=answer+'B';
                }
                else if(hold==12)
                {
                    answer=answer+'C';
                }
                else if(hold==13)
                {
                    answer=answer+'D';
                }
                else if(hold==14)
                {
                    answer=answer+'E';
                }
                else if(hold==15)
                {
                    answer=answer+'F';
                }
            }
        }
        return answer;
}
int main()
{
    int base,fbase,number;
    cin>>base>>fbase;
    if(base==10&&fbase==2)              //Decimal to binary
    { 
        cin>>number;
        int value=decimalToBinary(number);
        cout<<value;
    }
    else if(base==10&&fbase==8)             //Decimal to Octal
    {
        cin>>number;
        int value=decimalToOctal(number);
        cout<<value;
    }
    else if(base==10&&fbase==16)   //Decimal to Hexadecimal
    {
        int number;
        cin>>number;
        string value=decimalToHexadecimal(number);
        cout<<value;
    }
    else if(base==2&&fbase==10)                 //Binary to Decimal
    {
        int number;
        cin>>number;
        int value=binaryToDecimal(number);
        cout<<value;
    }
    else if(base==8&&fbase==10)         //Octal to Decimal
    {
        int number;
        cin>>number;
        int value=octalToDecimal(number);
        cout<<value;
    }
     else if(base==16&&fbase==10)            //Hexadecimal to Decimal
    {
        string n;
        cin>>n;
        int value=HexadecimalToDecimal(n);
        cout<<value;
    }
    else if(base==2&&fbase==16)                 //Binary To Hexadecimal
    {
        int number;
        cin>>number;
        int first=binaryToDecimal(number);
        string second=decimalToHexadecimal(first);
        cout<<second;
    }
    else if(base==2&&fbase==8)                  //Binary To Octal
    {
        int number;
        cin>>number;
        int first=binaryToDecimal(number);
        int second=decimalToOctal(first);
        cout<<second;
    }
    else if(base==16&&fbase==2)                 //Hexadecimal To Binary
    {
        string n;
        cin>>n;
        int first=HexadecimalToDecimal(n);
        int second=decimalToBinary(first);
        cout<<second;
    }
    else if(base==8&&fbase==2)                //Octal To Binary
    {
        int number;
        cin>>number;
        int first=octalToDecimal(number);
        int second=decimalToBinary(first);
        cout<<second;
    }
    else if(base==16&&fbase==8)                 //Hexadecimal To Octal
    {
        string n;
        cin>>n;
        int first=HexadecimalToDecimal(n);
        int second=decimalToOctal(first);
        cout<<second;
    }
    else if(base==8&&fbase==16)                 //Octal To Hexadecimal
    {
        int number;
        cin>>number;
        int first=octalToDecimal(number);
        string second=decimalToHexadecimal(first);
        cout<<second;
    }
}