/*				gcc main.c library.c doublyLinkedList.c -o Project.exe																				*/


/**********************************************************************************************/
/***** Name: Kyrellos Saleeb             ********************************************************/
/***** Component: APP          	        ********************************************************/
/**********************************************************************************************/

/******************************* Includes *******************************/
#include "main.h"

/******************************** Logic *********************************/
void main(void)
{
	printf("\n--------------- WELCOME TO THE LIBRARY APP ---------------\n\n");
	
	DList_t Local_Dlist1;
	u32 Local_Input;
	
	Lib_Create(&Local_Dlist1);
	
	while(1)
	{
		Lib_PrintOptions();
		Lib_GetInput(&Local_Input);
		
		if(5 == Local_Input)
		{
			break;
		}
		else
		{
			switch(Local_Input)
			{
				case 1:
					Lib_DiplayBooks(&Local_Dlist1);
					break;
				case 2:
					Lib_AddBook(&Local_Dlist1);
					break;
				case 3:
					Lib_DeleteBook(&Local_Dlist1);
					break;
				case 4:
					Lib_GetbooksNumber(&Local_Dlist1);
					break;
					
				default : printf("Sorry: Wrong Option ...! \n");
			}
		}
		
	}
	
	Lib_ClearLibrary(&Local_Dlist1);
	
}

