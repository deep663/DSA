#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};


class LinkList 
{
    private:
    Node *Head ;

    public:
    
    LinkList()
    {
        Head= nullptr;
    }

    void insert(int x, char p)
    {
        Node *newNode = new Node(x);
        if(p == 'b') // 'b' for insertion at the begining
        {
            newNode->next = this->Head;
            this->Head = newNode;
        }
        else if(p == 'e') // 'e' fro insertion at the end
        {
            Node *ptr = this->Head;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            newNode->next= ptr->next;
            ptr->next = newNode;
        }
        else
        {
            cout<<"Please pass 'b' or 'e' "<<endl;
            return;
        }
        cout<< newNode->data<<" inserted"<<endl;
    }

    void deletion(char p)
    {
        Node *temp = this->Head;
        if(p == 'b') 
        {
            this->Head = temp->next;
        }
        else if(p == 'e') 
        {
            Node *ptr;
            while (temp->next != nullptr)
            {
                ptr = temp;
                temp = temp->next;
            }
            ptr->next= temp->next;
        }
        else
        {
            cout<<"Please pass 'b' or 'e' "<<endl;
            return;
        }
        cout<< temp->data<<" is deleted"<<endl;
    }

    void printList()
    {
        Node *ptr = this->Head;
        cout<<"List is: ";
        while(ptr != nullptr)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
};

int main()
{
    LinkList l1;
    l1.insert(1,'b');
    l1.insert(2,'e');
    l1.insert(3,'e');
    l1.insert(4,'e');
    l1.insert(5,'b');
    l1.printList();
    l1.deletion('e');
    l1.deletion('b');
    l1.printList();
    
    return 0;
}