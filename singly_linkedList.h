#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef int data_t;

typedef struct tag_node
{
    char name[40];
    int age;
    double salary;
    char title[50];
    int data;
    struct tag_node* next; 
}node_t;


typedef struct tag_singly_linkedList
{
   node_t * head;
   int size;
}sll_t;

typedef enum{
    LL_OK,
    LL_NOT_OK,
    LL_NODE_NOT_CREATED,
    LL_NODE_NOT_FOUND,
    LL_EMPTY,

}EN_LL_state_t;

/**
 * ----------------------------------------------------------------
 * CREATE Linked LIST
 * ----------------------------------------------------------------
*/
 
 sll_t * create_list();


/**
 * ----------------------------------------------------------------
 * APPEND NODE TO LNKED LIST 
 * ----------------------------------------------------------------
*/

EN_LL_state_t append_node(sll_t *list, data_t val , char* name , int age , double salary , char* title);

/**
 * ----------------------------------------------------------------
 * CRATE NEW NODES
 * ----------------------------------------------------------------
*/
node_t * create_node(data_t val , char* name , int age , double salary , char* title);
// void create_node(node_t **head_ptr);

/**
 * ----------------------------------------------------------------
 * display linked list data
 * ----------------------------------------------------------------
*/

EN_LL_state_t display_list(sll_t* list);


/**
 * ----------------------------------------------------------------
 * free the list
 * ----------------------------------------------------------------
*/
EN_LL_state_t free_list(sll_t * list);

/**
 * ----------------------------------------------------------------
 * search in the list the list for ceartin node
 * ----------------------------------------------------------------
*/
EN_LL_state_t search_node(sll_t* list , data_t val , node_t ** retNode);

/**
 * ----------------------------------------------------------------
 * search in the list the list for ceartin node (another way)
 * ----------------------------------------------------------------
*/
node_t * search_node2(sll_t* list , data_t val);

/**
 * ----------------------------------------------------------------
 * delete ceratin node by value
 * ----------------------------------------------------------------
*/
EN_LL_state_t delete_node_by_value(sll_t * list , data_t val);
/**
 * ----------------------------------------------------------------
 * insert new node at certain position 
 * ----------------------------------------------------------------
*/
EN_LL_state_t insert_node_at_position(sll_t * list , data_t val , int pos);
/**
 * ----------------------------------------------------------------
 * delete node at ceratin position
 * ----------------------------------------------------------------
*/
EN_LL_state_t delete_node_by_position(sll_t * list, int pos);
/**
 * ----------------------------------------------------------------
 * Reverse linked list
 * ----------------------------------------------------------------
*/
EN_LL_state_t ll_reverse(sll_t * list);
/**
 * ----------------------------------------------------------------
 * Edite Employee
 * ----------------------------------------------------------------
*/
EN_LL_state_t modify_node(sll_t* list , data_t val , node_t ** retNode);








#endif