#include<iostream>
#include<ctime>                 //Use in the srand() function to generate random number using system time
using namespace std;
int partitionHelper(int *arr,int s,int e)
{
    int i=s-1;
    int pivot=arr[e];
    for(int j=s;j<=e-1;j++)
    {
        if(arr[j]<pivot) //2 8 3 1 7 4 ----> pivot is taken to be 4 ----> last element
        {
            i++;
            swap(arr[i],arr[j]);// to get the number smaller than pivot to one part of the partition
        }
    }
    swap(arr[i+1],arr[e]); //swapping the pivot with the element just next to the smaller part of the array the pivot element
    //eg. 2 8 3 1 7 4 ----> 2 3 1 | 8 7 4 ----> after this swapping is done by the statement swap(arr[i+1],arr[e]) to get ----> 2 3 1 | 4 7 8 
    
    return i+1;         //index of 4 after the previous step
}     

int partition(int *arr,int s,int e)
{
    srand(time(0));     //syntax to  use this function
    int r=s+rand()%(e-s);       //to generate a random index---> srand()helps to generate different random numbers every time it is called as it uses system time.
    swap(arr[r],arr[e]);        //swapping last element with that random index
    return partitionHelper(arr,s,e);       //after unsorting we call the partitionHelper() function
}//we are returning as when we call partitionHelper it will now send the value to this function instead of the main function so we have to return


void quicksort(int *arr,int s,int e)
{
    //base case
    if(s>=e)
    {
        return;
    }

    //recursive case
    int p=partition(arr,s,e);
    quicksort(arr,s,p-1);           //for the first part 2 3 1 | 4 7 8 ----> works on 2, 3 and 1
    quicksort(arr,p+1,e);           //for the second part 2 3 1 | 4 7 8 --> works on 7 and 8
    //-----> last call should be recursive and is called ----> tail recursion ----> no statement should be after this ---> then it is called tail recusion
    //tail recursion is without return -------> IMPORTANT
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
     
    cout<<endl;
    cout<<"The elements after quicksort are :"<<endl;
    quicksort(arr,0,n-1);       //calling quicksort function

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;

}