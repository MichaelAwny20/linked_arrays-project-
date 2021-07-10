#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int counter=0;
struct student
{
    char name[20];
    int id;
    int day;
    int month;
    int year;
    int score;

};
struct node{
    struct student S;                        //Data of the node
    struct node *next;           //Address of the next node
};
struct student create_stud_data()
{
struct student S1;
printf("enter name of student: \n");
scanf("%s",S1.name);
printf("enter ID of student: \n");
scanf("%d", &S1.id);
printf("enter Day of student: \n");
scanf("%d", &S1.day);
printf("enter month of student: \n");
scanf("%d", &S1.month);
printf("enter year of student: \n");
scanf("%d",&S1.year);
printf("enter score of student: \n");
scanf("%d",&S1.score);
return S1;
}
void insert_at_begining(struct node**head_ref,struct student stud)
{
    struct node* newnode = (struct node *)malloc(sizeof(struct node));
    newnode->S=stud;
    newnode->next=*head_ref;
    *head_ref=newnode;
    counter++;
}
void insert_at_end(struct node**tail_ref,struct student stud)
{
    struct node* newnode = (struct node *)malloc(sizeof(struct node));
    newnode->S=stud;
    newnode->next=NULL;
    *tail_ref=newnode;
    counter++;
}
void insert_at_middle(struct node**head_ref,struct student stud)
{
    struct node*slow=*head_ref;
    struct node*fast=*head_ref;
    if(fast==NULL || fast->next==NULL)
    {
        insert_at_begining(head_ref,stud);
        return;
    }

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    struct node* newnode = (struct node *)malloc(sizeof(struct node));
    newnode->S=stud;
    newnode->next=slow->next;
    slow->next=newnode;
    counter++;
}
void create_list(struct node**head_ref,struct node**tail_ref,int N)
{
    int i;
    struct student v=create_stud_data();
    for(i=0;i<N;i++)
    {
        insert_at_begining(head_ref,v);
        if(counter==1)
            *tail_ref=*head_ref;
    }

}

int main()
{
    int numofelem;
    printf("please enter number of elements \n");
    scanf("%d",&numofelem);
    struct node *head,*tail;
    create_list(&head,&tail,numofelem);
    struct student entered=create_stud_data();

    int start=clock();
    insert_at_end(&tail,entered);
    int finish=clock();
    printf("time elapsed to insert at beginning = %.12lf",(long double)(finish-start)/CLOCKS_PER_SEC);
    return 0;
}
