/**********************************************************************************************/
/***** Name: Kyrellos Saleeb             ********************************************************/
/***** Component: Doubly LinkedList    ********************************************************/
/**********************************************************************************************/


/********************************* Includes ****************************/
#include "doublyLinkedList.h"

/*********************** Functions Implementation **********************/

/***********************************************************************/
Error_State_t DList_Init(DList_t *Copy_PdoublyLinkedList)
{
	Error_State_t Local_Error_State = RT_OK;
	if(NULL != Copy_PdoublyLinkedList)
	{
		Copy_PdoublyLinkedList->size = 0;
		Copy_PdoublyLinkedList->head = NULL;
		Copy_PdoublyLinkedList->tail = NULL;
	}
	else
	{
		printf("Sorry: A NULL pointer is passed to function 'DList_Init'...!\n");
		Local_Error_State = RT_NULL_PTR_PASSED;
	}
	
	return Local_Error_State;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t DList_IsEmpty(DList_t *Copy_PdoublyLinkedList, DList_EmptyState_t *Copy_PemptyState_enum)
{
	Error_State_t Local_Error_State = RT_OK;
	
	if((NULL != Copy_PdoublyLinkedList) && (NULL != Copy_PemptyState_enum))
	{
		
		if(0 == (Copy_PdoublyLinkedList->size))
		{
			*Copy_PemptyState_enum = DLIST_EMPTY;
		}
		else
		{
			*Copy_PemptyState_enum = DLIST_NOT_EMPTY;
		}
	}
	else{
		printf("Sorry: A NULL pointer is passed to function 'DList_IsEmpty' ...!\n");
		Local_Error_State = RT_NULL_PTR_PASSED;
	}
	
	return Local_Error_State;
	
}
/***********************************************************************/

/***********************************************************************/
Error_State_t DList_Display(DList_t *Copy_PdoublyLinkedList)
{
	Error_State_t Local_Error_State = RT_OK;
	DList_EmptyState_t Local_EmptyState = DLIST_NOT_EMPTY;
	u32 Local_BookNumber = 0;
	
	Node_t *Local_PTempNode = Copy_PdoublyLinkedList->head;
	
	if(NULL != Copy_PdoublyLinkedList)
	{
		DList_IsEmpty(Copy_PdoublyLinkedList, &Local_EmptyState);
		
		if(Copy_PdoublyLinkedList->size != 0)
		{
			printf("--------------------------------------------\n");
			while(NULL != Local_PTempNode->next)
			{
				Local_BookNumber++;
				printf("Book Number : %d\n", Local_BookNumber);
				printf("Name : %s\n", Local_PTempNode->book.name);
				printf("Author : %s\n", Local_PTempNode->book.author);
				printf("Price : %d\n", Local_PTempNode->book.price);
				Local_PTempNode = Local_PTempNode->next;
				printf("--------------------------------------------\n");
			}
			Local_BookNumber++;
			printf("Book Number : %d\n", Local_BookNumber);
			printf("Name: %s\n", Local_PTempNode->book.name);
			printf("Author: %s\n", Local_PTempNode->book.author);
			printf("Price: %d\n", Local_PTempNode->book.price);
			printf("--------------------------------------------\n");
			
		}
		else
		{
			printf("Sorry: The LinkedList is empty ...!\n");
			Local_Error_State = RT_NOK;
		}
	}
	else{
		printf("Sorry: A NULL pointer is passed to function 'DList_Display' ...!\n");
		Local_Error_State = RT_NULL_PTR_PASSED;
	}
	
	return Local_Error_State;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t DList_AddAtFront(DList_t *Copy_PdoublyLinkedList, const Book_t *Copy_Pbook)
{
	Error_State_t Local_Error_State = RT_OK;
	DList_EmptyState_t Local_EmptyState = DLIST_NOT_EMPTY;
	Node_t *NewNodePtr = NULL;
	
	if((NULL != Copy_PdoublyLinkedList) && (NULL != Copy_Pbook))
	{
		NewNodePtr = (Node_t *)malloc(sizeof(Node_t));
		if(NULL != NewNodePtr)
		{
			NewNodePtr->book = *Copy_Pbook;
			NewNodePtr->prev = NULL;
			NewNodePtr->next = Copy_PdoublyLinkedList->head;
			
			DList_IsEmpty(Copy_PdoublyLinkedList, &Local_EmptyState);
			if(Copy_PdoublyLinkedList->size != 0)
			{
				//not empty
				
				Copy_PdoublyLinkedList->head->prev = NewNodePtr;
				Copy_PdoublyLinkedList->head = NewNodePtr;
			}
			else
			{
				//empty
				Copy_PdoublyLinkedList->head = NewNodePtr;
				Copy_PdoublyLinkedList->tail = NewNodePtr;
			}
			Copy_PdoublyLinkedList->size++;
		}
		else{
			printf("Sorry: Failed to allocate a new node ...!\n");
			Local_Error_State = RT_NOK;
		}
		
	}
	else{
		printf("Sorry: A NULL pointer is passed to function 'DList_AddAtFront' ...!\n");
		Local_Error_State = RT_NULL_PTR_PASSED;
	}
	
	return Local_Error_State;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t DList_DeleteAtFront(DList_t *Copy_PdoublyLinkedList, Book_t *Copy_Pbook)
{
	Error_State_t Local_Error_State = RT_OK;
	DList_EmptyState_t Local_EmptyState = DLIST_NOT_EMPTY;
	
	if((NULL != Copy_PdoublyLinkedList) && (NULL != Copy_Pbook))
	{
		DList_IsEmpty(Copy_PdoublyLinkedList, &Local_EmptyState);
		if(DLIST_NOT_EMPTY == Local_EmptyState)
		{
			*Copy_Pbook = Copy_PdoublyLinkedList->head->book;
			if(1 == Copy_PdoublyLinkedList->size)
			{
				free(Copy_PdoublyLinkedList->head);
				Copy_PdoublyLinkedList->head = NULL;
				Copy_PdoublyLinkedList->tail = NULL;
			}
			else{
				Copy_PdoublyLinkedList->head = Copy_PdoublyLinkedList->head->next;
				free(Copy_PdoublyLinkedList->head->prev);
				Copy_PdoublyLinkedList->head->prev = NULL;
			}
			Copy_PdoublyLinkedList->size--;
		}
		else{
			printf("Sorry: The LinkedList is empty ...!\n");
			Local_Error_State = RT_NOK;
		}
	}
	else
	{
		printf("Sorry: A NULL pointer is passed to function 'DList_DeleteAtFront' ...!\n");
		Local_Error_State = RT_NULL_PTR_PASSED;
	}
	
	
	
	return Local_Error_State;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t DList_AddAtEnd(DList_t *Copy_PdoublyLinkedList, const Book_t *Copy_Pbook)
{
	Error_State_t Local_Error_State = RT_OK;
	DList_EmptyState_t Local_EmptyState = DLIST_NOT_EMPTY;
	Node_t *NewNodePtr = NULL;
	
	if((NULL != Copy_PdoublyLinkedList) && (NULL != Copy_Pbook))
	{
		NewNodePtr = (Node_t *)malloc(sizeof(Node_t));
		if(NULL != NewNodePtr)
		{
			NewNodePtr->book = *Copy_Pbook;
			NewNodePtr->next = NULL;
			NewNodePtr->prev = Copy_PdoublyLinkedList->tail;
			
			DList_IsEmpty(Copy_PdoublyLinkedList, &Local_EmptyState);
			if(DLIST_NOT_EMPTY == Local_EmptyState)
			{
				Copy_PdoublyLinkedList->tail->next = NewNodePtr;
				Copy_PdoublyLinkedList->tail = NewNodePtr;
				
			}
			else
			{
				Copy_PdoublyLinkedList->head = NewNodePtr;
				Copy_PdoublyLinkedList->tail = NewNodePtr;
			}
			Copy_PdoublyLinkedList->size++;
		}
		else
		{
			printf("Sorry: Failed to allocate a new node ...!\n");
			Local_Error_State = RT_NOK;
		}
		
	}
	else
	{
		printf("Sorry: A NULL pointer is passed to function 'DList_AddAtEnd' ...!\n");
		Local_Error_State = RT_NULL_PTR_PASSED;
	}
	
	return Local_Error_State;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t DList_DeleteAtEnd(DList_t *Copy_PdoublyLinkedList, Book_t *Copy_Pbook)
{
	Error_State_t Local_Error_State = RT_OK;
	DList_EmptyState_t Local_EmptyState = DLIST_NOT_EMPTY;
	if((NULL != Copy_PdoublyLinkedList) && (NULL != Copy_Pbook))
	{
		if(DLIST_NOT_EMPTY == Local_EmptyState)
		{
			//not empty
			*Copy_Pbook = Copy_PdoublyLinkedList->tail->book;
			if(1 == Copy_PdoublyLinkedList->size)
			{
				free(Copy_PdoublyLinkedList->head);
				Copy_PdoublyLinkedList->head = NULL;
				Copy_PdoublyLinkedList->tail = NULL;
			}
			else{
				Copy_PdoublyLinkedList->tail = Copy_PdoublyLinkedList->tail->prev;
				free(Copy_PdoublyLinkedList->tail->next);
				Copy_PdoublyLinkedList->tail->next = NULL;
			}
			Copy_PdoublyLinkedList->size--;
		}
		else
		{
			//empty
			printf("Sorry: The LinkedList is empty ...!\n");
			Local_Error_State = RT_NOK;
		}
	}
	else{
		printf("Sorry: A NULL pointer is passed to function 'DList_DeleteAtEnd' ...!\n");
		Local_Error_State = RT_NULL_PTR_PASSED;
	}
	
	return Local_Error_State;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t DList_ListSize(DList_t *Copy_PdoublyLinkedList, u32 *Copy_PNumberOfBooks)
{
	Error_State_t Local_Error_State = RT_OK;
	
	if((NULL != Copy_PdoublyLinkedList) && (NULL != Copy_PNumberOfBooks))
	{
		*Copy_PNumberOfBooks = Copy_PdoublyLinkedList->size;
	}
	else
	{
		printf("Sorry: A NULL pointer is passed to function 'DList_BooksNumber' ...!\n");
		Local_Error_State = RT_NULL_PTR_PASSED;
	}
	
	return Local_Error_State;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t DList_AddAtIndex(DList_t *Copy_PdoublyLinkedList, const Book_t *Copy_Pbook, u32 Copy_Index)
{
	Error_State_t Local_Error_State = RT_OK;
	Node_t * NewNodePtr = NULL;
	Node_t * TempPtr = NULL;
	u32 Local_Counter = 0;
	
	if((NULL != Copy_PdoublyLinkedList) && (NULL != Copy_Pbook))
	{
		if(Copy_Index <= Copy_PdoublyLinkedList->size)
		{
			NewNodePtr = (Node_t *)malloc(sizeof(Node_t));
			if(NULL != NewNodePtr)
			{
				NewNodePtr->book = *Copy_Pbook;
				if(0 == Copy_Index)
				{
					DList_AddAtFront(Copy_PdoublyLinkedList, Copy_Pbook);
				}
				else if ((Copy_PdoublyLinkedList->size) == Copy_Index)
				{
					DList_AddAtEnd(Copy_PdoublyLinkedList, Copy_Pbook);
				}
				else
				{
					TempPtr = Copy_PdoublyLinkedList->head;
					for(Local_Counter = 0; Local_Counter < Copy_Index; Local_Counter++)
					{
						TempPtr = TempPtr->next;
					}
					NewNodePtr->next = TempPtr;
					NewNodePtr->prev = TempPtr->prev;
					TempPtr->prev->next = NewNodePtr;
					TempPtr->prev = NewNodePtr;
					Copy_PdoublyLinkedList->size++;
				}
				
				
			}
			else{
				printf("Sorry: Failed to allocate a new node ...!\n");
				Local_Error_State = RT_NOK;
			}
			
		}
		else
		{
			printf("Sorry: The index is out of range ...!\n");
			Local_Error_State = RT_NOK;
		}
	}
	else{
		printf("Sorry: A NULL pointer is passed to function 'DList_AddAtIndex' ...!\n");
		Local_Error_State = RT_NULL_PTR_PASSED;
	}
	return Local_Error_State;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t DList_DeleteAtIndex(DList_t *Copy_PdoublyLinkedList, Book_t *Copy_Pbook, u32 Copy_Index)
{
	Error_State_t Local_Error_State = RT_OK;
	Node_t * TempPtr = NULL;
	u32 Local_Counter = 0;
	
	if((NULL != Copy_PdoublyLinkedList) && (NULL != Copy_Pbook))
	{
		if(Copy_Index < Copy_PdoublyLinkedList->size)
		{
				if(0 == Copy_Index)
				{
					DList_DeleteAtFront(Copy_PdoublyLinkedList, Copy_Pbook);
				}
				else if ((Copy_PdoublyLinkedList->size - 1) == Copy_Index)
				{
					DList_DeleteAtEnd(Copy_PdoublyLinkedList, Copy_Pbook);
				}
				else
				{
					TempPtr = Copy_PdoublyLinkedList->head;
					for(Local_Counter = 0; Local_Counter < Copy_Index; Local_Counter++)
					{
						TempPtr = TempPtr->next;
					}
					*Copy_Pbook = TempPtr->book;
					TempPtr->prev->next = TempPtr->next;
					TempPtr->next->prev = TempPtr->prev;
					free(TempPtr);
					Copy_PdoublyLinkedList->size--;
				}	
			
		}
		else
		{
			printf("Sorry: The index is out of range ...!\n");
			Local_Error_State = RT_NOK;
		}
	}
	else{
		printf("Sorry: A NULL pointer is passed 'DList_DeleteAtIndex' ...!\n");
		Local_Error_State = RT_NULL_PTR_PASSED;
	}
	return Local_Error_State;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t DList_DeallocateList(DList_t *Copy_PdoublyLinkedList)
{
	Error_State_t Local_Error_State = RT_OK;
	DList_EmptyState_t Local_EmptyState = DLIST_NOT_EMPTY;
	Node_t * TempPtr = NULL;
	if(NULL != Copy_PdoublyLinkedList)
	{
		DList_IsEmpty(Copy_PdoublyLinkedList, &Local_EmptyState);
		if(DLIST_NOT_EMPTY == Local_EmptyState)
		{
			TempPtr = Copy_PdoublyLinkedList->head;
			while(NULL != TempPtr->next)
			{
				TempPtr = TempPtr->next;
				free(TempPtr->prev);
			}
			free(TempPtr);
			Copy_PdoublyLinkedList->size = 0;
			Copy_PdoublyLinkedList->head = NULL;
			Copy_PdoublyLinkedList->tail = NULL;
		}
		else
		{
			//do nothing it's already empty.
		}
	}
	else{
		printf("Sorry: A NULL pointer is passed 'DList_DeallocateList' ...!\n");
		Local_Error_State = RT_NULL_PTR_PASSED;
	}
	
	return Local_Error_State;
}
/***********************************************************************/