#include <stdio.h>
#include <stdlib.h>
#include "singly_linkedList.h"


/**
 * ----------------------------------------------------------------
 * CREATE Linked LIST
 * ----------------------------------------------------------------
 */

sll_t *create_list()
{
    sll_t *list = malloc(1 * sizeof(sll_t));
    if (list == NULL)
    {
        return 0;
    }

    list->head = NULL;
    list->size = 0;

    return list;
}

/**
 * ----------------------------------------------------------------
 * APPEND NODE TO LNKED LIST
 * ----------------------------------------------------------------
 */

EN_LL_state_t append_node(sll_t *list, data_t val , char* name , int age , double salary , char* title){
     if (list == NULL)
    {
        return LL_NOT_OK;
    }
    

    node_t * newNode = create_node(val , name , age , salary , title);
    if (newNode == NULL)
    {
        return LL_NODE_NOT_CREATED;
    }

    //check if the list is empty]]
    if (list->head == NULL)
    {
        list->head = newNode;
        list->size++;
        return LL_OK;
    }
    
    node_t* current = list->head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    list->size++;
    return LL_OK;
    
    
}

/**
 * ----------------------------------------------------------------
 * CRATE NEW NODES
 * ----------------------------------------------------------------
 */

node_t *create_node(data_t val , char* name , int age , double salary , char* title )
{
    node_t *newNode = (node_t *)malloc(1 * sizeof(node_t));
    if (newNode == NULL)
    {
        return NULL;
    }
    newNode->data = val;
    strcpy(newNode->name ,name);
    newNode->age = age;
    newNode->salary = salary;
    strcpy(newNode->title ,title);
    newNode->next = NULL;
    return newNode;
}

/**
 * ----------------------------------------------------------------
 * display linked list data
 * ----------------------------------------------------------------
 */

EN_LL_state_t display_list(sll_t *list)
{
    if (list == NULL)
    {
        return LL_NOT_OK;
    }
    if (list->head == NULL)
    {
        return LL_EMPTY;
    }
    node_t *current = list->head;
    int counter = 1;
    while (current != NULL)
    {
        printf("\n\ndata of employee number %d is : \n" , counter);
        printf("==================================================");
        printf("\nId : %d ", current->data);
        printf("\nName %s ", current->name);
        printf("\nage : %d ", current->age);
        printf("\nslary : %.3f ", current->salary);
        printf("\ntitle : %s \n", current->title);
        counter++;
        current = current->next;
    }
    // printf("\n");
    return LL_OK;
}

/**
 * ----------------------------------------------------------------
 * free the list
 * ----------------------------------------------------------------
 */
EN_LL_state_t free_list(sll_t *list)
{
    if (list == NULL)
    {
        return LL_NOT_OK;
    }
    if (list->head == NULL)
    {
        return LL_EMPTY;
    }

    node_t *current = list->head;

    while (current != NULL)
    {
        list->head = list->head->next;
        free(current);
        current = list->head;
    }
    
    free(list);

    return LL_OK;
}

/**
 * ----------------------------------------------------------------
 * search in the list the list for ceartin node
 * ----------------------------------------------------------------
*/
EN_LL_state_t search_node(sll_t* list , data_t val , node_t ** retNode){
    if(list == NULL || retNode == NULL){
        printf("\nEmployee Not found Please enter correct Id : \n");
        return LL_NOT_OK;
    }

    if(list->head == NULL){
        return LL_EMPTY;
    }

    node_t * current = list->head;
    while(current != NULL){
        if(current->data == val){
            *retNode = current;
            printf("\ndata Employee You entered is : \n");
            printf("==================================================");
            printf("\nId : %d ", current->data);
            printf("\nName %s ", current->name);
            printf("\nage : %d ", current->age);
            printf("\nslary : %.3f ", current->salary);
            printf("\ntitle : %s \n", current->title);
            return LL_OK;
        }

        current = current->next;
    }
    return LL_NODE_NOT_FOUND;
}

/**
 * ----------------------------------------------------------------
 * search in the list the list for ceartin node (another way)
 * ----------------------------------------------------------------
*/
node_t * search_node2(sll_t* list , data_t val){

}


/**
 * ----------------------------------------------------------------
 * delete certain node by value
 * ----------------------------------------------------------------
*/
EN_LL_state_t delete_node_by_value(sll_t * list , data_t val){
            if (list == NULL)
            {
                return LL_OK;
            }
            
            if(list->head == NULL){
                return LL_EMPTY;
            }

            node_t * current = list->head , * prev = current;
            if(current->data == val){
                /*mean the value to be deleted at head*/
                list->head = list->head->next;
                free(current);
                list->size--;
                return LL_OK;
            }

            while (current != NULL)
            {
                if(current->data == val){
                    prev->next = current->next;
                    free(current);
                    list->size--;
                    return LL_OK;
                }

                prev = current;
                current = current->next;
            }

            printf("deleted faild : value not found\n");
            return LL_NODE_NOT_FOUND;
            


}
/**
 * ----------------------------------------------------------------
 * insert new node at certain position 
 * ----------------------------------------------------------------
*/
EN_LL_state_t insert_node_at_position(sll_t * list , data_t val , int pos){

}
/**
 * ----------------------------------------------------------------
 * delete node at ceratin position
 * ----------------------------------------------------------------
*/
EN_LL_state_t delete_node_by_position(sll_t * list, int pos){


}
/**
 * ----------------------------------------------------------------
 * Reverse linked list
 * ----------------------------------------------------------------
*/
EN_LL_state_t ll_reverse(sll_t * list){

}
/**
 * ----------------------------------------------------------------
 * Modify the data of the node 
 * ----------------------------------------------------------------
*/

EN_LL_state_t modify_node(sll_t* list , data_t val , node_t ** retNode){
    if(list == NULL || retNode == NULL){
        printf("\nEmployee Not found Please enter correct Id : \n");
        return LL_NOT_OK;
    }

    if(list->head == NULL){
        return LL_EMPTY;
    }

    node_t * current = list->head;
    while(current != NULL){
        if(current->data == val){
            *retNode = current;
            printf("\nEnter new Data to employee : \n");
            printf("==================================================\n");
            printf("Enter new Id to employee : ");
            scanf("%d" , &(current->data));
            printf("Enter new age to employee : ");
            scanf("%d" , &(current->age));
            printf("Enter new name to employee : ");
            fflush(stdin);
            gets(current->name);
            printf("Enter new slary to employee : ");
            scanf("%lf" , &(current->salary));
            printf("Enter new title to employee : ");
            fflush(stdin);
            gets(current->title);

            return LL_OK;
        }

        current = current->next;
    }
    return LL_NODE_NOT_FOUND;
}




