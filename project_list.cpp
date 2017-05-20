#include "List.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	List myList; LInitList( &myList );
	ListItem* NEXT = NULL;
	/*
	LAddFront( myList, 7 );
	LAddFront( myList, 5 );
	LAddFront( myList, 3 );
	LAddFront( myList, 40 );
	LAddFront( myList, 908 );
	LAddFront( myList, 50 );
	LAddFront( myList, 1 );
	LPrintList( myList );

	LDelete( myList, NEXT, LFind( myList, 50, &NEXT ) );
	LPrintList( myList );*/

	LAdd( myList, NEXT, 1 );
	LAdd( myList, NEXT, 3 );
	LAdd( myList, NEXT, 5 );
	LPrintList( myList );
	
	/*LDeleteFront( myList );
	LDeleteFront( myList );
	LPrintList( myList );
	*/
	free( myList );
	
	return 0;
}