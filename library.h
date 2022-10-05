/**********************************************************************************************/
/***** Name: Kyrellos Saleeb             ********************************************************/
/***** Component: Library    	        ********************************************************/
/**********************************************************************************************/


#ifndef LIBRARY_H
#define LIBRARY_H

/********************************* Includes ****************************/
#include <stdio.h>
#include "STD_TYPES.h"
#include "doublyLinkedList.h"
#include "ERROR_STATE.h"

/********************************* Prototypes ***************************/

/*
	Use this function to create a libraray.
	It takes:
			1- Address of a doubly linkedlist object.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED).

*/
Error_State_t Lib_Create(DList_t *Copy_PdoublyLinkedList);

/*
	Use this function to print options.
	It takes:
			- void.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED).

*/
Error_State_t Lib_PrintOptions(void);

/*
	Use this function to get the option number from the user.
	It takes:
			1- Address of u32 variable to store the user input.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED).

*/
Error_State_t Lib_GetInput(u32 *Copy_OptionNumber);

/*
	Use this function to print the books stored in a library.
	It takes:
			1- Address of a doubly linkedlist object.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED).

*/
Error_State_t Lib_DiplayBooks(DList_t *Copy_PdoublyLinkedList);

/*
	Use this function to add a book to a library.
	It takes:
			1- Address of a doubly linkedlist object.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED).

*/
Error_State_t Lib_AddBook(DList_t *Copy_PdoublyLinkedList);

/*
	Use this function to delete a book from a library.
	It takes:
			1- Address of a doubly linkedlist object.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED).

*/
Error_State_t Lib_DeleteBook(DList_t *Copy_PdoublyLinkedList);

/*
	Use this function to get the number of books in a library.
	It takes:
			1- Address of a doubly linkedlist object.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED).

*/
Error_State_t Lib_GetbooksNumber(DList_t *Copy_PdoublyLinkedList);

/*
	Use this function to clear the whole library.
	It takes:
			1- Address of a doubly linkedlist object.
	It returns:
			- object of type Error_State_t (RT_OK or RT_NOK or RT_NULL_PTR_PASSED).

*/
Error_State_t Lib_ClearLibrary(DList_t *Copy_PdoublyLinkedList);

#endif