/**********************************************************************************************/
/***** Name: Kyrellos Saleeb             ********************************************************/
/***** Component: Doubly LinkedList    ********************************************************/
/**********************************************************************************************/

#ifndef DOUBLYlINKEDlIST_H
#define	DOUBLYlINKEDlIST_H

/********************************* Includes ****************************/
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "ERROR_STATE.h"

/********************************* Declarations ************************/
typedef struct Book{
	u8 name[50];
	u8 author[50];
	u32 price;
}Book_t;

typedef struct Node{
	Book_t book;
	struct Node *next;
	struct Node *prev;
}Node_t;

typedef struct List{
	u32 size;
	Node_t *head;
	Node_t *tail;
}DList_t;

typedef enum{
	DLIST_NOT_EMPTY,
	DLIST_EMPTY
}DList_EmptyState_t;

/********************************* Prototypes ***************************/

/*
	Use This function to initialize the list.
	It takes:
			1- Address of a doubly linkedlist object.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED). 

*/
Error_State_t DList_Init(DList_t *Copy_PdoublyLinkedList);

/*
	Use this function to check if the list is empty.
	It takes:
			1- Address of a doubly linkedlist object.
			2- Address of a DList_EmptyState_t object to store the list state:
														- DLIST_NOT_EMPTY or
														- DLIST_EMPTY
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED). 

*/
Error_State_t DList_IsEmpty(DList_t *Copy_PdoublyLinkedList, DList_EmptyState_t *Copy_PemptyState_enum);

/*
	Use this function to display the list members.
	It takes:
			1- Address of a doubly linkedlist object.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED). 

*/
Error_State_t DList_Display(DList_t *Copy_PdoublyLinkedList);

/*
	Use this function to add a book at the front of a list.
	It takes:
			1- Address of a doubly linkedlist object.
			2- Address of a Book_t object to store.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED). 

*/
Error_State_t DList_AddAtFront(DList_t *Copy_PdoublyLinkedList, const Book_t *Copy_Pbook);

/*
	Use this function to delete a book from the front of a list.
	It takes:
			1- Address of a doubly linkedlist object.
			2- Address of a Book_t object to store the deleted book.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED). 

*/
Error_State_t DList_DeleteAtFront(DList_t *Copy_PdoublyLinkedList, Book_t *Copy_Pbook);

/*
	Use this function to add a book at the end of a list.
	It takes:
			1- Address of a doubly linkedlist object.
			2- Address of a Book_t object to store.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED). 

*/
Error_State_t DList_AddAtEnd(DList_t *Copy_PdoublyLinkedList, const Book_t *Copy_Pbook);

/*
	Use this function to add a book at the end of a list.
	It takes:
			1- Address of a doubly linkedlist object.
			2- Address of a Book_t object to store.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED). 

*/
Error_State_t DList_DeleteAtEnd(DList_t *Copy_PdoublyLinkedList, Book_t *Copy_Pbook);

/*
	Use this function to get the number of members in the list.
	It takes:
			1- Address of a doubly linkedlist object.
			2- Address of a u32 variable to store the number of members.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED). 

*/
Error_State_t DList_ListSize(DList_t *Copy_PdoublyLinkedList, u32 *Copy_PNumberOfBooks);

/*
	Use this function to add a book at a specific index.
	It takes:
			1- Address of a doubly linkedlist object.
			2- Address of a Book_t object to store.
			3- the index to push at.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED). 

*/
Error_State_t DList_AddAtIndex(DList_t *Copy_PdoublyLinkedList, const Book_t *Copy_PBook, u32 Copy_Index);

/*
	Use this function to delete a book at a specific index.
	It takes:
			1- Address of a doubly linkedlist object.
			2- Address of a Book_t object to store the deleted book.
			3- Index of the book.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED). 

*/
Error_State_t DList_DeleteAtIndex(DList_t *Copy_PdoublyLinkedList, Book_t *Copy_PBook, u32 Copy_Index);

/*
	Use this function to Deallocate the whole Doubly LinkedList from the heap.
	It takes:
			1- Address of a doubly linkedlist object.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED).

*/
Error_State_t DList_DeallocateList(DList_t *Copy_PdoublyLinkedList);

#endif