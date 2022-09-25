#ifndef LIBRARY_H
#define LIBRARY_H

#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include<time.h>


#include "STD_TYPES.h"
#include "ERROR_STATE.h"

#define BOOK_NAME_SIZE 		50
#define AUTHOR_NAME_SIZE 	50

typedef struct Node{
	u8 Name_Of_Book[BOOK_NAME_SIZE];
	u8 Name_Of_Author[AUTHOR_NAME_SIZE];
	u16 Price_Of_Book;
	struct Node *Next;
	struct Node *Previous;
}Node_t;

typedef struct List{
	u32 Size;
	Node_t *Head;
	Node_t *Tail;
}List_t;


typedef enum{
	LIST_EMPTY,
	LIST_NEMPTY
}ListState_t;



ErrorState_t Create_List(List_t **PointerToPointer);

ErrorState_t List_Empty(List_t *List, ListState_t *ListStatus);

ErrorState_t AddToFront(List_t *List, u8 Copy_u8Name_Of_Book[], u8 Copy_u8Name_Of_Author[],u16 Copy_u16Price_Of_Book);

ErrorState_t AddToBack(List_t *List, u8 Copy_u8Name_Of_Book[], u8 Copy_u8Name_Of_Author[],u16 Copy_u16Price_Of_Book);

ErrorState_t RemoveFromFront(List_t *List);

ErrorState_t RemoveFromBack(List_t *List);

ErrorState_t RemoveByIndex(List_t *List,u8 Copy_u8Idx);

ErrorState_t Display(List_t *List);

ErrorState_t DisplayByIdx(List_t *List,u8 Copy_u8Book_Idx);

void closing(void);

void Opening(List_t *List);

#endif

