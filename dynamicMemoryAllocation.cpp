#include<iostream>
#include<algorithm>
using namespace std;            /*Static memory allocation uses STACK memory*/
int* function(int n)        //function to return address int* is the return type 
{
    int *array=new int[1000];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];      //same as *(array+i)
    }
    return array;       //returning address
}
int main()
{
    int *aptr = new int;        //procedure to create a bucket in the HEAP memory in dynamic memory allocation
    *aptr=50;
    cout<<*aptr;

    delete aptr;        //to delete the value at the pointer
    aptr=NULL;      //to point the pointer to null


    int *arrptr = new int[50];
    for(int i=0;i<5;i++)
    {
        cin>>*(arrptr+i);       //way to take the values in the array
    }

    for(int i=0;i<5;i++)
    {
        cout<<*(arrptr+i)<<" ";
    }

    delete []arrptr;        //way to delete the value at the pointer in an array
    arrptr=NULL;        //to point the pointer to null
    


    int n;
    cin>>n;
    int *app=function(n);       //atoring the returned value we need a pointer
    for(int i=0;i<n;i++)
    {
        cout<<app[i]<<" ";
    }

    delete []app;       //deleting the pointer and setting it to null
    app=NULL;





    //creating 2D array
    int rows,columns;
    cin>>rows>>columns;
    int **arr=new int*[rows];       //as the row array is storing address of each of the column array therefore its data type is int*
    for(int i=0;i<rows;i++)
    {
        arr[i]=new int[columns];        //assigning the column array to each element of the column array
    }


    //deleting the 2D array

    for(int i=0;i<rows;i++)     //deletong the column arrays
    {
        delete []arr[i];        //delets all the array connected to the each row of the arr array 
    }



    //now deleting arr array

    delete []arr;
    arr=NULL;
}