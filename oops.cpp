#include<iostream>
#include<cstring>
using namespace std; 

//creating a user defined data type
class helicopter {
    private:                //to demonstrate the private access specifier
    int price;

    public:     //access specifier of the setPrice and getPrice
    void setPrice(int p)            //setter function
    {
        price=p;
    }

    int getPrice()
    {
        return price;
    }


    //destructor 
    ~helicopter()
    {
        cout<<"Destructed Helicopter "<<endl;
    }
}; 

class car {         //creating class
     public:
      //char name[100]; we can do it like this
      char *name;       //creating pointer for name
      int model;
      int seats;
      int price;
      const int tyres;      //to set constant
      static int count;     //to create static member variable whose copies are not created at the time of object formation
        //:tyres(4) is used to set constant values
      car():tyres(4)             //default constructor. It is called by default at the time of object creation
      {
          cout<<"Hello! I am the default constructor.."<<endl;
          name=NULL;        //pointing the pointer to null as the default constructor first creates object then assigns value to it. 
          count++;      //to use static member variable 
      }


      car(char *n , int m,int seats,int p):tyres(4),model(m)      //parametrized constructor with initialization list
      {
          name = new char[strlen(n)+1];     //defining name dynamically as null is always present at the end of each string therefore {strlen(n)+1}   
          strcpy(name , n);
          //model=m;
          this->seats=seats;//way to use this keyword when the name is same this keyword points to the object that is being created.
          price=p;
          count++;      //to use static member variable
      }



      void print()          //member method of the class
      {
        cout<<name<<endl;
        cout<<model<<endl;
        cout<<seats<<endl;
        cout<<price<<endl;
      }

      void update(char *n)
      {
          if(name!=NULL)
          {     //We use the method to delete the array as name is a char array assigned dynamically
              delete []name;        //to delete whatever is present in name
              name=NULL;        //to point the name pointer to null
          }

          name = new char[strlen(n)+1];     //+1 is for the null at the end of the string
          strcpy(name,n);

      }




/*copy constructor in called to copy data of one car into other object,
 x is passed by reference as when car d=c is written it calls 
copy constructor and when car x=c(in the arguments of the function) 
 is written then it again calls the copy function giving us an error so it is 
important to pass x by reference*/    
      car(car &x)                                           
      {
          //name=x.name;    for shallow copy
          name = new char[strlen(x.name)+1];        //creating a new memory location for deep copy
          strcpy(name,x.name);
          model=x.model;
          seats=x.seats;
          price=x.price;
          count++;      //to use static member variable
      }



      //copy assignment constructor
      //= sign is the operator that we need to define
    //   void operator=(char l)       //same cincept of deep and shallow copy is followed in copy assignment constructor 
    //   {
    //        //name=x.name;    for shallow copy
    //       name = new char[strlen(l.name)+1];        //creating a new memory location for deep copy
    //       strcpy(name,l.name);
    //       model=l.model;
    //       seats=l.seats;
    //       price=l.price;
     // }


      //destructor
      ~car()
      {
          cout<<"Destructed "<<name<<endl;      //just to show when it is called
          //we can use count-- to show the destruction of the cars
      }
};

int car::count=0;       //way yo initialize the static member variable

int main()
{
    car A;      //creation of object
    //A.name="BMW";     This is the wrong method as we cannot assign string to a character array
    strcpy(A.name , "BMW");         //important method to put string in char array
    A.seats=5;
    A.model=2021;
    A.price=6700000;

    cout<<A.name<<endl;
    cout<<A.model<<endl;
    cout<<A.seats<<endl;
    cout<<A.price<<endl;

    cout<<endl<<endl;


    //Car B is created to demonstrate parametrized constructor

    car B("Audi",2018,4,5700000);       //pass as a parameter
    cout<<B.name<<endl;
    cout<<B.model<<endl;
    cout<<B.seats<<endl;
    cout<<B.price<<endl;


    cout<<endl<<endl;

    //Car C is created to demonstrate member method

    car C("Ferrari",2019,2,57000000);       //pass as a parameter

   C.print();      //  method to use the member method



    //Car D is created to demonstrate member methods

    car D;
    d.update("Lamborghini");

    d.update("Qwerty");//second time if the name is updated then it is important to point name to null and then asign value so that it doesn't hold the previous value


    //Helicopter E is created to demonstration getter and setter 

    helicopter E;
    E.setPrice(20000);      //setter function

    cout<<"Price of Helicopter = "<<E.getPrice()<<endl;            //getter function



    //Car E for copy constructor

    car E=C;        //copying data of C into E
    E.print();


    //shallow and deep copy

    E.name[0]='M';      //change in E causes change in C also as the name is a pointer and the same pointer is copied in the name pointer of E
    cout<<endl;
    E.print();
    cout<<endl;
    C.print();


    //car R for deep copy
     car R=C;
     R.name[0]='M';
     cout<<R.name<<endl;
     cout<<C.name<<endl;


     //copy assignment constructor

     car G;
     G=R;//important assignment in a different line so we need to define the assignment operator as assignment operator is for the primitive data type only and not for user defined

     cout<<car::count<<endl;        //to print the number of cars formed

    return 0;
}