# Dynamic_Library_Management_System
Dynamic Library Management System using Doubly Linked List From Scratch based on Layerd Architecture Contains many Functions: 
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
