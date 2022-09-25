#include "Library.h"

ErrorState_t Create_List(List_t **PointerToPointer)
{
	ErrorState_t FunctionState = RET_NOK;
	List_t *ListPtr = (List_t *)malloc(sizeof(List_t));
	
	if(NULL == ListPtr)
	{
		printf("Error: malloc failed to allocate the list ....\n");
		FunctionState = RET_NULL_PTR;
	}
	
	else{
		ListPtr->Size = 0;
		ListPtr->Head = NULL;
		ListPtr->Tail = NULL;
		*PointerToPointer = ListPtr;
		FunctionState = RET_OK;
	}
	
	return FunctionState;
}



ErrorState_t List_Empty(List_t *List, ListState_t *ListStatus)
{
	ErrorState_t FunctionState = RET_NOK;
	if((NULL != List) && (NULL != ListStatus))
	{
		if(0 == List->Size)
		{
			*ListStatus = LIST_EMPTY;
		}
		else{
			*ListStatus = LIST_NEMPTY;
		}
		FunctionState = RET_OK;
	}
	
	else{
		printf("Error: List pointer or ListStatus pointer or both have NULL Address ...\n");
		FunctionState = RET_NULL_PTR;
	}
	
	return FunctionState;
}


ErrorState_t AddToFront(List_t *List, u8 Copy_u8Name_Of_Book[], u8 Copy_u8Name_Of_Author[],u16 Copy_u16Price_Of_Book)
{
	ErrorState_t FunctionState = RET_NOK;
	ListState_t L_State = LIST_NEMPTY;
	
	if(NULL != List)
	{
		Node_t *NodePtr = (Node_t *)malloc(sizeof(Node_t));
		if(NULL != NodePtr)
		{
			strcpy(NodePtr->Name_Of_Book, Copy_u8Name_Of_Book);
			strcpy(NodePtr->Name_Of_Author, Copy_u8Name_Of_Author);
			NodePtr->Price_Of_Book = Copy_u16Price_Of_Book;
			
			NodePtr->Previous = NULL;
			
			List_Empty(List, &L_State);
			if(L_State == LIST_EMPTY)
			{
				List->Head = NodePtr;
				List->Tail = NodePtr;
				NodePtr->Next = NULL;
				NodePtr->Previous = NULL;
			}
			else{
				NodePtr->Next = List->Head;
				List->Head->Previous = NodePtr;
				List->Head = NodePtr;
			}
			List->Size++;
			FunctionState = RET_OK;
		}
		else{
			printf("Error: malloc failed to create the node ...\n");
		}
	}
	
	else{
		printf("Error: List pointer has a NULL address ...\n");
		FunctionState = RET_NULL_PTR;
	}
	
	return FunctionState;
}




ErrorState_t AddToBack(List_t *List, u8 Copy_u8Name_Of_Book[], u8 Copy_u8Name_Of_Author[],u16 Copy_u16Price_Of_Book)
{
	ErrorState_t FunctionState = RET_NOK;
	ListState_t L_State = LIST_NEMPTY;
	if(NULL != List)
	{
		Node_t *NodePtr = (Node_t *)malloc(sizeof(Node_t));
		if(NULL != NodePtr)
		{
			strcpy(NodePtr->Name_Of_Book, Copy_u8Name_Of_Book);
			strcpy(NodePtr->Name_Of_Author, Copy_u8Name_Of_Author);
			NodePtr->Price_Of_Book = Copy_u16Price_Of_Book;
			
			NodePtr->Next = NULL;
			
			List_Empty(List, &L_State);
			if(L_State == LIST_EMPTY)
			{
				List->Head = NodePtr;
				List->Tail = NodePtr;
				NodePtr->Previous = NULL;
				NodePtr->Next = NULL;
			}
			else{
				NodePtr->Previous = List->Tail;
				List->Tail->Next = NodePtr;
				List->Tail = NodePtr;
			}
			List->Size++;
			FunctionState = RET_OK;
		}
		else{
			printf("Error: malloc failed to create the node ...\n");
		}
		
	}
	else{
		printf("Error: List pointer has a NULL address ...\n");
		FunctionState = RET_NULL_PTR;
	}
	return FunctionState;
}



ErrorState_t RemoveFromFront(List_t *List)
{
	ErrorState_t FunctionState = RET_NOK;
	ListState_t L_State = LIST_NEMPTY;
	Node_t *Ptr = NULL;
	if(NULL != List)
	{
		List_Empty(List, &L_State);
		if(L_State == LIST_EMPTY)
		{
			printf("Sorry: the list is empty and there is no data to remove ...\n");
		}
		else{
			if(List->Size == 1)
			{
				free(List->Head);
				List->Head = NULL;
				List->Tail = NULL;
			}
			else{
				Ptr = List->Head;
				List->Head = List->Head->Next;
				free(Ptr);
				List->Head->Previous = NULL;
			}
			List->Size--;
			FunctionState = RET_OK;
		}
	}
	else{
		printf("Error: List pointer has NULL Address ...\n");
		FunctionState = RET_NULL_PTR;
	}
	return FunctionState;
}


ErrorState_t RemoveFromBack(List_t *List)
{
	ErrorState_t FunctionState = RET_NOK;
	ListState_t L_State = LIST_NEMPTY;
	Node_t *Ptr = NULL;
	if(NULL != List)
	{
		List_Empty(List, &L_State);
		if(L_State == LIST_EMPTY)
		{
			printf("Sorry: the list is empty and no data to remove ....\n");
		}
		else{
			Ptr = List->Tail;
			if(List->Size == 1)
			{
				free(List->Tail);
				List->Tail = NULL;
				List->Head = NULL;
			}
			else{
				List->Tail = List->Tail->Previous;
				free(Ptr);
				List->Tail->Next = NULL;
			}
			List->Size--;
			FunctionState = RET_OK;
		}
	}
	else{
		printf("Error: List pointer has NULL Address ...\n");
		FunctionState = RET_NULL_PTR;
	}
	return FunctionState;
}

ErrorState_t RemoveByIndex(List_t *List,u8 Copy_u8Idx)
{
	ErrorState_t FunctionState = RET_NOK;
	ListState_t L_State = LIST_NEMPTY;
	if(List != NULL)
	{
		List_Empty(List, &L_State);
		if(L_State == LIST_EMPTY)
		{
			printf("Sorry: the list is empty and no data to remove ....\n");
		}
		else{
			u8 Local_u8Counter;
			
			Node_t* Temp=List->Head;
			
			if(Copy_u8Idx == 1){
				RemoveFromFront(List);
			}
			
			else if(Copy_u8Idx == (List->Size))
			{
				RemoveFromBack(List);
			}
			
			else if((Copy_u8Idx>1)&&(Copy_u8Idx<(List->Size)))
			{
				for(Local_u8Counter=1; Local_u8Counter<=Copy_u8Idx; Local_u8Counter++){
					Temp = Temp->Next;
				}
				Temp->Next->Previous = Temp->Previous;
				Temp->Previous->Next = Temp->Next;
				free(Temp);
				List->Size--;
				FunctionState = RET_OK;
			}
			else
			{
				printf("Sorry: the list is empty and there is no data to remove ...\n");
				FunctionState = RET_OUT_OF_RANGE;
			}
		}
	}
	else{
		printf("Error: List pointer has a NULL Address ...\n");
		FunctionState = RET_NULL_PTR;
	}
	return FunctionState;
}


ErrorState_t Display(List_t *List)
{
	
	ErrorState_t FunctionState = RET_OK;
	ListState_t StateObject = LIST_NEMPTY;
	if(List != NULL)
	{
		if(List->Size==0)
		{
			printf("Sorry: The library is empty and no books to be displayed!\n");
		}
		else
		{
			u8 Local_u8Counter=0;
			Node_t *Temp = List->Head;
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LIBRARY BOOKS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
			for(Local_u8Counter=1; Local_u8Counter<=(List->Size); Local_u8Counter++)
			{
				printf("The Book Number is: %d:\nThe Book Name is: %s\nThe Book Author is: %s\nThe Book Price is: %i$\n",Local_u8Counter, Temp->Name_Of_Book, Temp->Name_Of_Author, Temp->Price_Of_Book);
				Temp=Temp->Next;	
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	
			}
		}
	}
	else{
		printf("Error: in function Display has a NULL Address ...\n");
		FunctionState = RET_NULL_PTR;
	}
	return FunctionState;
}

ErrorState_t DisplayByIdx(List_t *List,u8 Copy_u8Book_Idx)
{
	
	ErrorState_t FunctionState = RET_OK;
	ListState_t L_State = LIST_NEMPTY;
	if(List != NULL)
	{
		List_Empty(List, &L_State);
		if(L_State == LIST_EMPTY)
		{
			printf("Sorry: the list is empty and no data to display ....\n");
		}
		
		else{
			if ((Copy_u8Book_Idx > 0) && (Copy_u8Book_Idx <= (List->Size)))
			{
				u8 Local_u8Counter=0;
				Node_t *Temp = List->Head;
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LIBRARY BOOKS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
				for(Local_u8Counter=1; Local_u8Counter<=(List->Size); Local_u8Counter++)
				{
					if(Copy_u8Book_Idx ==Local_u8Counter ){
						printf("The Book Number is: %d:\nThe Book Name is: %s\nThe Book Author is: %s\nThe Book Price is: %i$\n",Local_u8Counter, Temp->Name_Of_Book, Temp->Name_Of_Author, Temp->Price_Of_Book);
						Temp=Temp->Next;
						printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
					}
				}

			}
			else
			{
				printf("The book of entered number is not available in the library \n");
				FunctionState = RET_OUT_OF_RANGE;
			}
		}
	}
	else{
		printf("Error: in function DisplayByIdx has a NULL Address ...\n");;
		FunctionState = RET_NULL_PTR;
	}
	return FunctionState;
}

void closing(void)
{
	system("cls");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CLOSING \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\nThis Project Coded by Kyrellos Saleeb:)");
    printf("\n\nExiting in 3 second...........\n\n\n");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CLOSING  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    Sleep(3000);
    exit(0);
}

void Opening(List_t *List)
{	 
	u8 BookName[BOOK_NAME_SIZE], AuthorName[AUTHOR_NAME_SIZE];
	u8 Book_Idx;
	u8 Choice = 0;
	u16 price;

	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\nChoose one of the following options:\n");
	
	printf("1- To Display all books									Press'1'\n");
	printf("2- To add a New book at Tail							Press'2'\n");
	printf("3- To add a New book at Head							Press'3'\n");
	printf("4- To Delete a book from Tail							Press'4'\n");
	printf("5- To Delete a book from Head							Press'5'\n");
	printf("6- To Delete a single book by Index						Press'6'\n");
	printf("7- To Display a single book by Index					Press'7'\n");
	printf("8- To Display Number of available books					Press'8'\n");
	printf("9- To Exit the Library App								Press'9'\n");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\nEnter your choice: ");

	scanf("%d", &Choice);

	switch(Choice){
		case 1:	system("cls");	
				Display(List);									
				break;
		
		case 2:	system("cls");	
				printf("Please enter Name of book: ");
				//gets(BookName);
				fflush(stdin);
				scanf("%s", &BookName);
				printf("Please enter Name of Author: ");
				//gets(AuthorName);
				fflush(stdin);
				scanf("%s", &AuthorName);
				printf("Please enter price of book: ");
				scanf("%d", &price);
				AddToBack(List, &BookName, &AuthorName, price);					
				break;
				
		case 3:	
				system("cls");	
				printf("Please enter Name of book: ");
				//gets(BookName);
				fflush(stdin);
				scanf("%s", &BookName);
				printf("Please enter Name of Author: ");
				//gets(AuthorName);
				fflush(stdin);
				scanf("%s", &AuthorName);
				printf("Please enter price of book: ");
				scanf("%d", &price);
				AddToFront(List, &BookName, &AuthorName, price);				
				break;
				
		case 4:	system("cls");	
				RemoveFromBack(List);							
				break;
		
		case 5:	system("cls");	
				RemoveFromFront(List);							
				break;
		
		case 6:	system("cls");	
				printf("Please enter number of book to be Removed: ");
				scanf("%d", &Book_Idx);
				RemoveByIndex(List, Book_Idx);									
				break;
				
		case 7:	system("cls");	
				printf("Please enter number of book to be displayed: ");
				scanf("%d", &Book_Idx);
				DisplayByIdx(List, Book_Idx);									
				break;
					
		case 8: system("cls");	
				printf("The Number of Books in Library is: %d\n", List->Size);	
				break;
		
		case 9:	system("cls");	
				closing();									
				break;
		
		default:system("cls");	
				printf("Invalid Choice\n");						
				break;
													
	}

}


