
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"avl.h"

int main()
{
    AVL t;
    
    init_AVL(&t);
    char name1[20]="January";
    char name2[20]="February";
    char name3[20]="March";
    char name4[20] = "April";
    char name5[20] = "May";
    char name6[20] = "June";
    char name7[20] = "July";
    char name8[20] = "August";
    char name9[20] = "Septeber";
    char name10[20] = "October"; 
    char name11[20] = "November";
    char name12[20] = "December";

    int o;
    while(1)
    {
        printf("\n\n");
        printf("1.INSERT NODE");
        printf("\n2.DELETE NODE");
        printf("\n3.INORDER TRAVERSAL");
        printf("\n4.HEIGHT OF TREE");
        printf("\n5.ROOT OF TREE");
        printf("\n6.DELETE TREE");
        printf("\n7.EXIT");
        printf("\n\nEnter operation number ");
        scanf("%d",&o);
	char month[20];
	int del;
        switch (o)
        {
        case 1:
           
            printf("Enter month name ");
            scanf("%s",month);
            if(strcmp(month,name1)==0)
            {
                insert_Node(&t,1,name1);
            }
            else if(strcmp(month,name2)==0)
            {
                insert_Node(&t,2,name2);
            }
            else if(strcmp(month,name3)==0)
            {
                insert_Node(&t,3,name3);
            }
            else if(strcmp(month,name3)==0)
            {
                insert_Node(&t,3,name3);
            }
            else if(strcmp(month,name4)==0)
            {
                insert_Node(&t,4,name4);
            }
            else if(strcmp(month,name5)==0)
            {
                insert_Node(&t,5,name5);
            }
            else if(strcmp(month,name6)==0)
            {
                insert_Node(&t,6,name6);
            }
            else if(strcmp(month,name7)==0)
            {
                insert_Node(&t,7,name7);
            }
            else if(strcmp(month,name8)==0)
            {
                insert_Node(&t,8,name8);
            }
            else if(strcmp(month,name9)==0)
            {
                insert_Node(&t,9,name9);
            }
            else if(strcmp(month,name10)==0)
            {
                insert_Node(&t,10,name10);
            }
            else if(strcmp(month,name11)==0)
            {
                insert_Node(&t,11,name11);
            }
            else if(strcmp(month,name12)==0)
            {
                insert_Node(&t,12,name12);
            }
            else
            {
                printf("Invalid month");
            }
            break;
        
        case 2:
            printf("Enter month number ");
            scanf("%d",&del);
            delete_node(&t,del);
            break;
        
        case 3:
            inorder(t);
            break;

        case 4:
            printf("Height is %d",height(t));
            break;
        
        case 5:
            printf("Root is month %s and month number %d with balance factor %d",t->month,t->data,t->balance_factor);
            break;

        case 6:
            delete_tree(&t);
            break;
        
        case 7:
            exit(1);
            
        default:
            printf("Invalid choice"); 
            break;
        }
    }

    return 0;
}
