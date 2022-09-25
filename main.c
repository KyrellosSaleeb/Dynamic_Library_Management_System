#include "main.h"

//gcc main.c Library.c -o pro.exe

void main(void){
	
	List_t* Book = NULL;
	Create_List(&Book);
	while(1){
		Opening(Book);
	}
	
}