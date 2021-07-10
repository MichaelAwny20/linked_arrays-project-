#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int counter=0;//filled elements in linked list
int n;//number of elements of the dynamic array
struct student //structure of student information
{
    char name[30];//name of student
    int id;
    int day;
    int month;
    int year;
    int score;// score of the last year

};
struct student *ptr; //pointer to first element in the dynamic array
struct node //structure for each node in the linked list
{
    struct student S;             //Data of the node (student)
    struct node *next;           //pointer the next node
};
struct student create_stud_data() // a function to fill data of a variable from type student and return a student
{
struct student S1;
printf("enter name of student: \n");
char cl;
scanf("%c",&cl);
fgets(S1.name,30,stdin);
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
return S1; //returning the student
}
void insert_at_begining(struct node**head_ref,struct student stud) // a function to insert at the beginning
{

    struct node* newnode = (struct node *)malloc(sizeof(struct node)); //allocating memory for a new node to be inserted
    newnode->S=stud; //filling data of the new node
    newnode->next=*head_ref; //set next to head
    *head_ref=newnode; //head points to the new node
    counter++; //increase number of elements of the linked list by 1
}
void insert_at_end(struct node**tail_ref,struct student stud) //function to insert a student at end
{
    struct node* newnode = (struct node *)malloc(sizeof(struct node)); //allocating memory for a new node to be inserted
    newnode->S=stud; //filling data of the new node
    newnode->next=NULL;//set next to NULL
    (*tail_ref)->next=newnode; //next of the tail will be the new node
    *tail_ref=newnode;//make the new node as a tail
    counter++; //increase number of elements of the linked list by 1
}
void insert_at_middle(struct node**head_ref,struct student stud)
{    //make two pointer to nodes one of them walk one step and the other walk two steps so when fast reaches the last element of the list
     //slow will be at the middle node
    struct node*slow=*head_ref;
    struct node*fast=(*head_ref)->next;
    if(fast==NULL )
    {
        insert_at_begining(head_ref,stud);
        return;
    }

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    struct node* newnode = (struct node *)malloc(sizeof(struct node)); //allocating memory for a new node to be inserted
    newnode->S=stud; //filling data of the new node
    newnode->next=slow->next; //put the new node in between of slow and next to it to be at the middle
    slow->next=newnode;
    counter++;//increase number of elements of the linked list by 1
}
void create_list(struct node**head_ref,struct node**tail_ref,int N) //creating list with N elements knowing head and tail
{
    int i; //a counter for the loop

    for(i=0;i<N;i++)
    {
        printf("Filling data of student %d \n",i+1);
        struct student v=create_stud_data(); //create new student
        if(counter==0) //at first element head and tail will be pointing to it
        {
        insert_at_begining(head_ref,v); //inserting the first element at beginning
            *tail_ref=*head_ref;
        }
        else{insert_at_end(tail_ref,v);}
    }

}
void display_LL(struct node**head_ref) //function to display the linked list
{
    struct node*temp=*head_ref; //temp pointer pointing to first node
    int i=1;
    while(temp!=NULL) //to display all nodes until the end
    {
        printf("%d)name: %s ------ iD: %d ------Birthday: %d/%d/%d ------ score: %d \n",i,temp->S.name,temp->S.id,temp->S.day,temp->S.month,temp->S.year,temp->S.score);
        temp=temp->next; // to go to the next element after displaying this element
        i++;

    }
    printf(" NULL \n ************************** \n"); //print Null which is the end of list
}
void create_dynamic_array (struct student **ptr_ref ) //creating a list using number of elements and pointer to first element position
{
    int i=0; //a counter for the loop

     *ptr_ref = (struct student*)malloc(n*sizeof(struct student)); //allocating memory for the dynamic array but without initializing
     for(int i=0;i<n;i++) //filling data of each element in dynamic array
     {
         printf("Filling data of student %d \n",i+1);
         struct student v=create_stud_data();
         *((*ptr_ref)+i)= v;
     }
     return; //returning after finishing

}
void insert_at_begining_DA(struct student **ptr_ref,struct student s) //function to insert at the begin of the array
{

    *ptr_ref= (struct student*)realloc((*ptr_ref),(n+1)*sizeof(struct student)); //reallocating memory with new size
    if(*ptr_ref==NULL) //check if the realloc function works well
       {
            printf("fail");
            return;
       }
   for (int i=0;i<n;i++)//shifting all elements one step to put the new element at the beginning
     {
        *((*ptr_ref)+n-i)=*((*ptr_ref)+n-i-1);
     }
    *(*ptr_ref)=s; //put new student at the first position
    n++; //increase number of elements of the dynamic array by 1
}
void insert_at_middle_DA(struct student **ptr_ref,struct student s) //function to insert at middle of the array
{
    *ptr_ref= (struct student*)realloc((*ptr_ref),(n+1)*sizeof(struct student)); //reallocating memory with new size =old size +1
   for (int i=0;i<=n/2;i++) //shifting the last half elements one step
     {
        *(*ptr_ref+n-i)=*(*ptr_ref+n-i-1);
     }
    *(*ptr_ref+(n/2))=s; //put new student at the middle position
    n++;  //increase number of elements of the dynamic array by 1
}
void insert_at_end_DA(struct student **ptr_ref,struct student s) //function to insert at end of the array
{
     *ptr_ref= (struct student*)realloc((*ptr_ref),(n+1)*sizeof(struct student)); //reallocating memory with new size =old size +1
    *(*ptr_ref+n)=s; //put new student at the last position
    n++; //increase number of elements of the dynamic array by 1
}
void display_da (struct student*ptr) //function to display elements of the array
{
    int i; //counter for the loop
    for(i=0;i<n;i++) //moving around all elements of the array using for loop
    {
        printf("%d) name :%s id :%d birthday : %d/%d/%d score %d \n ",i+1,(*(ptr+i)).name,(*(ptr+i)).id,(*(ptr+i)).day,(*(ptr+i)).month,(*(ptr+i)).year,(*(ptr+i)).score);

    }
    printf("\n ********************************************** \n");
}
int main()
{
    //Name : Michael Awny ibrahim grece
    //SEC :3
    //BN: 27
    printf("-----------Welcome to this student system presented by : \n Michael Awny Ibrahim \n Sec:3 \n BN:27 \n under supervising of Dr: Omar Nasr ------------\n");
    printf("size of struct student in memory = %d bytes \n",sizeof(struct student)); //size of the student in memory
    printf("size of struct node in memory = %d bytes \n",sizeof(struct node)); //size of the node in memory
    struct student temp ; //temporarily variable of type student to store data of each student
    int choice; //choosing a type to work
    printf("please enter your choice of work : 1)linked list 2)dynamic array \n note that you should run the program again to work on another choice \n");
    scanf("%d",&choice);
    switch(choice)
    { case 1:       {
                    int numofelem; //variable of number of elements to put in linked list
                    printf("please enter number of elements \n");
                    scanf("%d",&numofelem); //user enters number of elements
                    struct node *head,*tail;
                    head=NULL; //initialize head and tail pointers to NULL
                        tail=NULL;
                         create_list(&head,&tail,numofelem); //creating list with the entered number of elements
                        int choice1; //variable for choice of operations
                        while(1){
                        printf("please enter your choice of operation : 1)insert at begining 2)insert at middle 3)insert at end 4)display 5)exit \n");
                        scanf("%d",&choice1);
                        switch(choice1)
                        { case 1 :  insert_at_begining(&head,create_stud_data());

                                     if(counter==1) //a corner case if the entered number of elements =0
                                          {
                                         tail=head;
                                            }
                                            break;
                          case 2:  insert_at_middle(&head,create_stud_data());
                                     break;
                          case 3:   insert_at_end(&tail,create_stud_data());
                                    break;
                          case 4:   display_LL(&head);
                                    break;
                          case 5:   return 0;
                                     break;
                          default: printf("you entered wrong choice ! \n")  ;
                        }

                        }}
                        break;
    case 2:
                 printf("please enter number of elements of the dynamic array \n");
                scanf("%d",&n); //entering number of elements in the array
                create_dynamic_array (&ptr); //creating the array by allocating memory and filling data of students
                int choice2;
                while(1){
                printf("please enter your choice of operation : 1)insert at begining 2)insert at middle 3)insert at end 4)display 5)exit \n");
                scanf("%d",&choice2);

                switch(choice2){    case 1 :  insert_at_begining_DA(&ptr,create_stud_data());
                                              break;
                                    case 2:   insert_at_middle_DA(&ptr,create_stud_data());
                                              break;
                                    case 3:   insert_at_end_DA(&ptr,create_stud_data());
                                              break;
                                   case 4:   display_da(ptr);
                                             break;
                                   case 5:   return 0;
                                             break;
                          default: printf("you entered wrong choice ! \n")  ;
                        }}
                break;
    default: printf("you entered wrong choice ! \n")  ;
    }
    return 0;
}
