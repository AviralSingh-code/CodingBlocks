#include<iostream>
#include<set>
using namespace std;

template<typename T>    //for the data type of the pair

pair<T , bool> searchElement(set <T> &s , int index)
{
    pair <T , bool> result;
    if(index < s.size())        //to check the validity of the index
    {
        //* opertator is to dereffer to the element at that location
        result.first = *(next(s.begin(),index));   //next returns the iterator to the element after moving certain distance
        result.second = true;   //as we have found the element so the bool value is set to true
    }
    else
    {
        result.second = false;
    }

    return result;
}


int main()
{
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    s.insert(60);
    s.insert(70);

    cout<<"Enter the index of the element"<<endl;
    int index;
    cin>>index;

    cout<<endl;

    pair <int , bool> result = searchElement(s,index);

    if(result.second == true) //i.e. we have found the element 
    {
        cout<<"The element at that location is : ";
        cout<<result.first<<endl;
    }
    else
    {
        cout<<"Invalid Index";
    }

    return 0;

}