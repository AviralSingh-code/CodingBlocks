#include<iostream>
#include<queue>
using namespace std;

class stack{
    private:
    queue<int>q1;
    queue<int>q2;

    public:
    void push(int d)
    {
        if(q1.empty()&&q2.empty())
        {
            q1.push(d);
        }
        else if(!q1.empty()&&q2.empty())
        {
            q1.push(d);
        }
    }

    void pop()
    {
        if(!q1.empty()&&q2.empty())     //if the first queue is not empty
        {
            while (q1.size()>1)
            {
                q2.push(q1.front());            //copying elements from q1 to q2 leaving the last element
                q1.pop();
            }
            q1.pop();           //removing the last element from q1
        }

        if(q1.empty()&&!q2.empty())     //if the second queue is not empty
        {
            while (q2.size()>1)
            {
                q1.push(q2.front());            //copying elements from q1 to q2 leaving the last element
                q2.pop();
            }
            q2.pop();           //removing the last element from q1
        }
        else
        {
            cout<<"Underflow"<<endl;        //if no element is present
        }
    }


    int top()
    {
        if(!q1.empty()&&q2.empty())     //if the first queue is not empty
        {
            while (q1.size()>1)
            {
                q2.push(q1.front());            //copying elements from q1 to q2 leaving the last element
                q1.pop();
            }
            int ans=q1.front();
            q2.push(ans);
            q1.pop();
            return ans;
        }

        if(q1.empty()&&!q2.empty())     //if the second queue is not empty
        {
            while (q2.size()>1)
            {
                q1.push(q2.front());            //copying elements from q1 to q2 leaving the last element
                q2.pop();
            }
            int ans=q2.front();
            q1.push(ans);
            q2.pop();
            return ans;
        }
    }

    bool empty()
    {
        return q1.empty()&&q2.empty();
    }

};

int main()
{

}