/*IMPORTANT SITE FOR REFERENCE ---> CPP REFERENCE*/
#include<iostream>
#include<unordered_map> //STL for hashmap
using namespace std;
int main()
{
    unordered_map<string,int>h;     //synatx--> unordered_map<key,value> h;
    h["Apple"]=100;
    h["Banana"]=150;

    //second way  h.insert({key,value});
    h.insert({"Papaya",160});

    //third way pair<string,int>p("abc",500); --> creating pair --> inserting pair in the hashmap --> h.insert(p);
    pair<string,int>p("Mango",80);
    h.insert(p);


    //fourth way
    h.insert(make_pair("Grapes",500));



    //printing the hashmap
    //we will use for each loop --> doesn't know the end limit
    for(pair<string,int>fruit:h)    //fruit cointains two values key and value so the type of fruit is pair --> :h defines that fruit is of hashmap
    {
        cout<<fruit.first<<"-->"<<fruit.second<<endl;
    }
    cout<<endl;


    // 2nd way

    cout<<"Using auto keyword :"<<endl;
    for(auto fruit:h)       //auto defines the compile to take data type on its own what ever is required
    {
        cout<<fruit.first<<"-->"<<fruit.second<<endl;
    }
    cout<<endl;




    //to erase

    h.erase("Mango");   //removes it from the hashmap

    
    cout<<"Printing after erasing Mango :"<<endl;
    for(auto fruit:h)       //auto defines the compile to take data type on its own what ever is required
    {
        cout<<fruit.first<<"-->"<<fruit.second<<endl;
    }
    cout<<endl;



    //other method to print
    cout<<"Printing using iterator :"<<endl;
    for(auto it=h.begin();it!=h.end();it++) //iterator moves from begining of the hashmap to the ned of the hashmap
    {
        cout<<it->first<<"->"<<it->second<<endl;
    }
    cout<<endl;

}