#include<iostream>
#include<unordered_map>
using namespace std;

//------------------My implementation--------------------
struct Node{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }


    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }


    Node* get(char ch)
    {
        return links[ch - 'a'];
    }

    bool setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};
class Trie{

    private:

    Node* root;

    public:

    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node* node = root;
        for(int i = 0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node* node = root;
        for(int i = 0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }

        return node->isEnd();
        
    }

    bool startsWith(string word)
    {
        Node* node = root;
        for(int i = 0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }
};
//-------------------------------------------------------


class node{
    public:
    char data;
    bool isterminal;
    unordered_map<char,node*> h;    //every node contains a map that holds the first character of the string given and node* is the pointer of the other elements of the string that are stored in a node


    node(char ch)
    {
        data=ch;
        isterminal=false;
    }
};

class trie{
    node*root;  //pointer to point at the root node 
    public:
    trie()
    {
        root=new node('\0');    //root formed is null
    }


    void insert(char *word)
    {
        node*temp=root;
        for(int i=0;word[i]!='\0';i++)
        {
            char ch=word[i];    //to get the ith char of the word
            if(temp->h.count(ch))   //temp ke hashmap mai agar ch exist karta hai ya nahi --> gives 2 values 1 if it is present and 0 when it is not present 
            {
                temp=temp->h[ch];   //character in the hashmap is a pointer and it points to the next node and so we now point temp to the next location where the h[ch] points
            }
            else
            {
                temp->h[ch]=new node(ch);       //creating the new node for the character
                temp=temp->h[ch];   //moving temp forward
            }
        }
        temp->isterminal=true;  //this makes the last place where the temp points as the terminal
    }



    bool search(char *key)
    {
        node*temp=root;
        for(int i=0;key[i]!='\0';i++)   //to iterate on the key
        {
            char ch=key[i];
            if(temp->h.count(ch))   //to check if hasmap of temp cointains the character value in ch
            {
                temp=temp->h[ch];   //move temp forward
            }
            else
            {
                return false;   //as the character in ch is not present in the hasmap of temp --> then return false directly
            }
        }
        return temp->isterminal;    //if it had iterated across the word then it would have reached over here --> if for eg we had entred codinger and not coding then the terminal if r and not g --> this shows that we had never entered this word coding
    } 



};

int main()
{
    trie t;
    t.insert("Hello");
    t.insert("HelloWorld");
    t.insert("Coder");
    t.insert("Coding");
    t.insert("Hell");

    if(t.search("Hello"))
    {
        cout<<"Word is present"<<endl;
    }
    else
    {
        cout<<"Word is not present";
    }

    return 0;
}