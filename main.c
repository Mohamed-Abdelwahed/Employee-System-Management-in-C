#include <stdio.h>
#include <stdlib.h>
#include "singly_linkedList.h"

void main()
{

   system("cls");
   sll_t *empList = create_list();
   append_node(empList, 1, "ahmed mohamed", 23, 25, "manager");
   append_node(empList, 2, "wael salem", 30, 98, "hr");
   append_node(empList, 3, "saeed mohamed", 25, 67, "hr");

   /*============================================================================*/
   char choice;
   char emp_name[50];
   char emp_title[50];
   int Id;
   double salary;
   int age;

   while (1)
   {
      printf("\n\nplease select one of the following options :\n\n1-Add new employee data (press 1 to select this option)\n2-Delete the data of an employee (press 2 to select this option )\n3-Modify the data of an employee (press 3 to select this option)\n4-View the data of an employee (press 4 to select this option)\n5-View all the employee's data (press 5 t select this option)\n6-exit (press 6 to select this option)\n\nplease enter your choice:");
      fflush(stdin);
      scanf("%c", &choice);
      printf("\n\n");
      switch (choice)
      {
      case '1':
         printf("\n==================================================\n");
         printf("\nEnter Employee name :  ");
         fflush(stdin);
         gets(emp_name);
         printf("\nEnter Employee Age :  ");
         scanf("%d", &age);
         printf("\nEnter Employee Salary :  ");
         scanf(" %lf", &salary);
         printf("\nEnter Employee title :  ");
         fflush(stdin);
         gets(emp_title);
         printf("\nEnter Employee Id :  ");
         scanf("%d", &Id);

         append_node(empList, Id, emp_name, age, salary, emp_title);
         break;
      case '2':
         printf("Enter Employee Id to Delete : ");
         scanf("%d", &Id);
         delete_node_by_value(empList, Id);
         break;
      case '3':
          printf("Enter Employee Id You want to Edit his data: ");
            printf("\n==================================================\n");
          scanf("%d", &Id);
         node_t *eidte_id = NULL;
         modify_node(empList, Id, &eidte_id);
      break;
      case '4':
         printf("Enter Employee Id You want to show his data: ");
         printf("\n==================================================\n");
         scanf("%d", &Id);
         node_t *searchPointer = NULL;
         search_node(empList, Id, &searchPointer);
         break;
      case '5':
         display_list(empList);
         break;
      case '6':
         exit(0);
      default:
         printf("wrong choice\n\n");
      }
   }

   
}