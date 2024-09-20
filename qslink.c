#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
}*temp;
struct node*front=NULL;
struct node*rear=NULL;

void enqueue(int);
void dequeue();
void peek();
void display();

int main()
{
    int choice,value;
    while(1)
    {
        printf("Enter choice:\n");
        printf("1.Enqueue \n 2.Dequeue \n 3.Peek \n 4.Display \n 5.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
             printf("Enter element:");
             scanf("%d",&value);
             enqueue(value);
             break;
            
            case 2:
             dequeue();
             break;

            case 3:
             peek();
             break;

            case 4:
             display();
             break;

            case 5:
             exit(0);
             break;
             default: printf("Invalid Choice!");
             break;

        }
    }
}
void enqueue(int value)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode==NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data=value;
    newnode->next=NULL;
    if(front==NULL)
    {
        front=rear=newnode;
    }
    else
    rear->next=newnode;
    rear=newnode;
}
    void dequeue()
    {
        if(front==NULL)
        printf("It is Empty");
        else{
            temp=front;
            front=front->next;
            printf("Deleted Element:%d",temp->data);
            free(temp);
        }
    }
    

void peek()
{
    if(front==NULL)
    printf("It is empty");
    else
    printf("front:%d",front->data);
}
void display()
{
    if(front==NULL)
    printf("Queue");
    else{
        temp=front;
        while (temp->next!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }
        
    }
    printf("%d\n",temp->data);
}