#include <stdio.h>
#include <stdlib.h>
int n; //number of elements of dynamic array
struct student //declaration of structure (student)
{
    char name[20];
    int id;
    int day;
    int month;
    int year ;
    int score;
};
struct student *ptr; //pointer to first element in the dynamic array
struct student create_stud_data() //a function that return a student after we in the data of him
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
void create_dynamic_array (struct student **ptr_ref ) //creating a list using number of elements and pointer to first element position
{
    int i=0;

     *ptr_ref = (struct student*)malloc(n*sizeof(struct student));
     for(int i=0;i<n;i++)
     {
         struct student v=create_stud_data();
         *((*ptr_ref)+i)= v;
     }
     return;

}
void insert_at_begining_DA(struct student **ptr_ref,struct student s)
{

    *ptr_ref= (struct student*)realloc((*ptr_ref),(n+1)*sizeof(struct student));
    if(*ptr_ref==NULL)
       {
            printf("fail");
            return;
       }
   for (int i=0;i<n;i++)
     {
        *((*ptr_ref)+n-i)=*((*ptr_ref)+n-i-1);
     }
    *(*ptr_ref)=s;
    n++;
}
void insert_at_middle_DA(struct student **ptr_ref,struct student s)
{
    *ptr_ref= (struct student*)realloc((*ptr_ref),(n+1)*sizeof(struct student));
   for (int i=0;i<=n/2;i++)
     {
        *(*ptr_ref+n-i)=*(*ptr_ref+n-i-1);
     }
    *(*ptr_ref+(n/2))=s;
    n++;
}
void insert_at_end_DA(struct student **ptr_ref,struct student s)
{
     *ptr_ref= (struct student*)realloc((*ptr_ref),(n+1)*sizeof(struct student));
    *(*ptr_ref+n)=s;
    n++;
}
void display_da (struct student*ptr)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%s %d %d/%d/%d %d----->",(*(ptr+i)).name,(*(ptr+i)).id,(*(ptr+i)).day,(*(ptr+i)).month,(*(ptr+i)).year,(*(ptr+i)).score);

    }
    printf("\n ************************** \n");
}
int main()
{
    printf("please enter number of elements of the dynamic array \n");
    scanf("%d",&n);
    create_dynamic_array (&ptr);
    display_da(ptr);
    struct student m=create_stud_data();
    insert_at_begining_DA(&ptr,m);
    display_da(ptr);
     insert_at_middle_DA(&ptr,m);
    display_da(ptr);
    insert_at_end_DA(&ptr,m);
    display_da(ptr);
    return 0;
}
