#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
} *Head;

typedef struct Node Node;

void insert(int x, char p)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    if(p == 'b')
    {
        temp->next = Head;
        Head = temp;
    }
    else if(p == 'e')
    {
        Node *ptr = Head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        temp->next = NULL;
        ptr->next = temp; 
    }
    else
    {
        printf("Please enter the second perameter 'b' or 'e'\n");
        return ;
    }

    printf("%d inserted\n",temp->data);
}

void insertn(int x, int n)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    Node *ptr = Head;
    for(int i=1; i<n-1; i++)
    {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp; 

    printf("%d inserted\n",temp->data);
}

void delete(char p)
{
    Node *temp;
    temp = Head;
    if(p == 'b')
    {
        Head = Head->next;
    }
    else if(p=='e')
    {
        Node *ptr;
        while(temp->next != NULL)
        {
            ptr = temp;
            temp =temp->next;
        }
        ptr->next = NULL;
    }
    else
    {
        printf("Please pass 'b' or 'e'\n" );
        return ;
    }
    printf("%d Deleted\n", temp->data);
    free(temp);
}

void deleten(int n)
{
    Node *temp, *ptr;
    temp = Head;
    for (int i = 1; i < n; i++)
    {
        ptr = temp;
        temp = temp->next;
    }
    ptr->next = temp->next;
    printf("%d Deleted\n", temp->data);
    free(temp);
}

void show()
{   
    Node *ptr = Head;
    printf("List is: ");
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    Head = NULL;
    insert(1,'b');
    show();
    insert(2,'e');
    show();
    insert(6,'e');
    show();
    insert(8,'b');
    show();
    insertn(3, 2);
    show();
    insertn(4, 3);
    show();
    delete('b');
    show();
    delete('e');
    show();
    deleten(2);
    show();
    delete('a');

    return 0;
}