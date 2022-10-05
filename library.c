/**********************************************************************************************/
/***** Name: Kyrellos Saleeb             ********************************************************/
/***** Component: Library    	        ********************************************************/
/**********************************************************************************************/


/******************************* Includes *******************************/
#include "library.h"

/*********************** Functions Implementation **********************/

/***********************************************************************/
Error_State_t Lib_Create(DList_t *Copy_PdoublyLinkedList)
{
	Error_State_t Local_ErrorState = RT_OK;
	if(NULL != Copy_PdoublyLinkedList)
	{
		DList_Init(Copy_PdoublyLinkedList);
	}
	else{
		printf("Sorry: A NULL pointer is passed to function 'Lib_Create' ...!\n");
		Local_ErrorState = RT_NULL_PTR_PASSED;
	}
	
	return Local_ErrorState;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t Lib_PrintOptions(void){
	
	Error_State_t Local_ErrorState = RT_OK;
	
		printf("--------------------------------------------- \n");
		printf("Choose one of the following options: \n");
		printf("To view all books 		 				Enter '1' \n");
		printf("To add a New book						Enter '2' \n");
		printf("To Delete a book 						Enter '3' \n");
		printf("To view No. of available books  		Enter '4' \n");
		printf("To Exist the Library App 	 			Enter '5' \n");
		printf("--------------------------------------------- \n");

	return Local_ErrorState;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t Lib_GetInput(u32 *Copy_OptionNumber){
	
	Error_State_t Local_ErrorState = RT_OK;
	if(NULL != Copy_OptionNumber)
	{
		printf("---> Your Choice is : ");
		scanf("%d", Copy_OptionNumber);
		fflush(stdin);
	}
	else
	{
		printf("Sorry: A NULL pointer is passed to function 'Lib_PrintOptions' ...!\n");
		Local_ErrorState = RT_NULL_PTR_PASSED;
	}
	
	return Local_ErrorState;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t Lib_DiplayBooks(DList_t *Copy_PdoublyLinkedList){
	
	Error_State_t Local_ErrorState = RT_OK;
	DList_EmptyState_t Local_EmptyState = DLIST_NOT_EMPTY;
	if(NULL != Copy_PdoublyLinkedList)
	{
		DList_IsEmpty(Copy_PdoublyLinkedList, &Local_EmptyState);
		if(DLIST_EMPTY == Local_EmptyState)
		{
			printf("The library is empty. No books to view !\n");
		}
		else
		{
			DList_Display(Copy_PdoublyLinkedList);
		}	
	}
	else
	{
		printf("Sorry: A NULL pointer is passed to function 'Lib_DiplayBooks' ...!\n");
		Local_ErrorState = RT_NULL_PTR_PASSED;
	}
	return Local_ErrorState;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t Lib_AddBook(DList_t *Copy_PdoublyLinkedList)
{
	Error_State_t Local_ErrorState = RT_OK;
	Error_State_t Local_FuncReturn = RT_OK;
	
	if(NULL != Copy_PdoublyLinkedList)
	{
		Book_t Local_NewBook;
		printf("Enter the name of the book : ");
		gets(Local_NewBook.name);
		printf("Enter the name of the author : ");
		gets(Local_NewBook.author);
		printf("Enter the book price : ");
		scanf("%d", &Local_NewBook.price);
		printf("--------------------------------------------- \n");
		
		Local_FuncReturn = DList_AddAtEnd(Copy_PdoublyLinkedList, &Local_NewBook);
		if(Local_FuncReturn == RT_OK)
		{
			printf("Book added Successfully ...\n");
		}
		else
		{
			printf("Error: Book is not added ...\n");
		}
	}
	else{
		printf("Sorry: A NULL pointer is passed to function 'Lib_AddBook' ...!\n");
		Local_ErrorState = RT_NULL_PTR_PASSED;
	}
	
	
	return Local_ErrorState;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t Lib_DeleteBook(DList_t *Copy_PdoublyLinkedList)
{			
	Error_State_t Local_ErrorState = RT_OK;
	DList_EmptyState_t Local_EmptyState = DLIST_NOT_EMPTY;
	Book_t Local_DeletedBook ;
	
	Error_State_t Local_FuncReturn = RT_OK;
	u32 Local_BookNumber = 0;
	u32 Local_ListSize = 0;
			
	if(NULL != Copy_PdoublyLinkedList){
		DList_IsEmpty(Copy_PdoublyLinkedList, &Local_EmptyState);
		if(DLIST_EMPTY == Local_EmptyState)
		{
			printf("Sorry the library is empty and there is no books to be deleted.\n");
		}
		else{
			DList_ListSize(Copy_PdoublyLinkedList, &Local_ListSize);
			printf("Enter the Number of the book you want to delete (from 1 to %d): ", Local_ListSize);
			scanf("%d", &Local_BookNumber);
			if((Local_BookNumber < 1 ) || (Local_BookNumber > Local_ListSize) ){
				printf("Sorry: Wrong Book Number ...!\n");
				Local_ErrorState = RT_NOK;
			}
			else
			{
				printf("--------------------------------------------- \n");
				Local_FuncReturn = DList_DeleteAtIndex(Copy_PdoublyLinkedList, &Local_DeletedBook, Local_BookNumber-1);
				if(Local_FuncReturn == RT_OK)
				{
					printf("Book deleted Successfully ...\n");
				}
				else
				{
					printf("Error: Book is not deleted ...\n");
					Local_ErrorState = RT_NOK;
				}
			}
		}
	}
	else{
		printf("Sorry: A NULL pointer is passed to function 'Lib_DeleteBook' ...!\n");
		Local_ErrorState = RT_NULL_PTR_PASSED;
	}
	
	return Local_ErrorState;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t Lib_GetbooksNumber(DList_t *Copy_PdoublyLinkedList)
{
	Error_State_t Local_ErrorState = RT_OK;
	DList_EmptyState_t Local_EmptyState = DLIST_NOT_EMPTY;
	u32 Local_ListSize = 0;
	if(NULL != Copy_PdoublyLinkedList)
	{
		DList_IsEmpty(Copy_PdoublyLinkedList, &Local_EmptyState);
		if(DLIST_EMPTY == Local_EmptyState)
		{
			printf("The Library is empty. No available books to view !\n");
		}
		else{
			DList_ListSize(Copy_PdoublyLinkedList, &Local_ListSize);
			printf("The Number of available Books is %d\n", Local_ListSize);
		}
	}
	else
	{
		printf("Sorry: A NULL pointer is passed to function 'Lib_GetbooksNumber' ...!\n");
		Local_ErrorState = RT_NULL_PTR_PASSED;
	}
	
	
	return Local_ErrorState;
}
/***********************************************************************/

/***********************************************************************/
Error_State_t Lib_ClearLibrary(DList_t *Copy_PdoublyLinkedList)
{
	Error_State_t Local_ErrorState = RT_OK;
	Error_State_t Local_FuncReturn = RT_OK;
	if(NULL != Copy_PdoublyLinkedList)
	{
		Local_FuncReturn = DList_DeallocateList(Copy_PdoublyLinkedList);
		
		if((RT_NOK == Local_FuncReturn) || (RT_NULL_PTR_PASSED == Local_FuncReturn))
		{
			printf("List is not cleared ...\n");
			Local_ErrorState = RT_NOK;
		}
		else{
			//Do nothing.
		}
	}
	else
	{
		printf("Sorry: A NULL pointer is passed to function 'Lib_ClearLibrary' ...!\n");
		Local_ErrorState = RT_NULL_PTR_PASSED;
	}
	return Local_ErrorState;
}
/***********************************************************************/