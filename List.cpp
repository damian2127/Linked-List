#include "List.h"

using namespace std;

//====================================================================================
void LInitList(List* pList) 
{
	ListItem* p = (ListItem*)malloc( sizeof( ListItem ) );

	if( !p )
	{
		cout << "No memory!!!";
	}

	p->xKey = 0;
	p->pNext = NULL;
	*pList = p;  
}
//======================================================================================

int LisEmpty(List pList)
{
	return (!pList) || !( pList->pNext );
}

//================================================================================
ListItem* LFind(List pList, int x, ListItem** ppNext) //zwraca element poprzedni
{
	if( LisEmpty( pList ) )
	{
		cout << "List is empty!" << endl;
	}

	*ppNext = pList->pNext;  //element po glowie
	ListItem* pPrev = pList;  // poprzednik

	while( *ppNext && ( (*ppNext)->xKey != x )) // jesli nie dojechalem do konca listy
	{
		pPrev = *ppNext;
		*ppNext = (*ppNext)->pNext;
	}

	if( !(*ppNext) )  //jesli jest max 1 element w kolejce
	{
		return NULL;
	}

	return pPrev;
}

//===========================================================================
void LAdd(List pList, ListItem* pElem, int x) //pElem to wskaznik na wyszukany element, dodawanie liczby przed wyszukana liczba
{
	if( !(pList) )
	{
		cout << "No initialization of list" << endl;
	}
	else if ( !pElem )
	{
		cout << "No such element" << endl;
	}

	ListItem* p = (ListItem*)malloc( sizeof( ListItem ) );
	p->xKey = x;
	p->pNext = pElem->pNext;
	pElem->pNext = p;
}

//===========================================================================================
void LAddFront(List pList, int x) 
{
	LAdd( pList, pList, x );//dodaje element po glowie
}

//===========================================================================================
void LPrintList(List pList)
{
	if( LisEmpty( pList ) )
	{
		cout << "======List is empty!!!=======\n " << endl;
	}

	ListItem* p = pList->pNext;

	while( p ) // !=NULL
	{
		cout << p->xKey << "  ";
		p = p->pNext;
	}
	printf("\n\n");
}

//===========================================================================================
void  LDeleteFront(List pList)
{
	LDelete( pList, pList->pNext, pList );

}

//============================================================================================
void LFreeList(List* pList)
{
	while( !LisEmpty( *pList ) )
	{
		LDeleteFront( *pList );
	}
	free( *pList );
	*pList = NULL;
}

//==============================================================================================
int LFront( List pList )   // zwraca pierwszy element listy
{
	if( LisEmpty( pList ) )
	{
		cout << "List is empty" << endl;
		return 0;
	}

	return pList->pNext->xKey;
}

//===============================================================================================
void LSortList( List pList )
{
	if ( LisEmpty(pList) || !pList->pNext->pNext ) // jesli pusty lub zawiera 1 element
        return;

    ListItem* current; // sprawdza akualny element
    ListItem* min; //aktualny minimalny element
    ListItem* ftc = pList; // pierwszy do wyszukiwania minimum
   
    while ( ftc->pNext ) // zakonczy jesli jest ostatni elementem
    {
        min = ftc; 
        current = ftc->pNext;

        while ( current->pNext ) // sprawdza nastepne elementy
        {
			if ( (current->pNext->xKey) < (min->pNext->xKey) )
                min = current; // to mam nowe minimum
 
            current = current->pNext; // nastepny do sprawdzenia
        }
 
        if (min != ftc) //jesli minimum nie jest na swoim miejscu nieprzeszukanej czesci to wloz go za ftc
        {
            ListItem* p = min->pNext;
            min->pNext = min->pNext->pNext;
            p->pNext = ftc->pNext;
            ftc->pNext = p;
        }
 
        ftc = ftc->pNext;
    }

}

//==============================================================================================
void LDelete(List pList, ListItem* ppNext, ListItem* pPrev ) //usuniecie wskazanego elementu
{
	if( LisEmpty( pList ) )
	{
		cout << "List is empty" <<endl; 
		return;
	}

	if( !(ppNext)->pNext )
	{
		cout << "No such element" << endl;
	}

	ListItem* p = ppNext;
	pPrev->pNext = ppNext->pNext;

	free( p );
}
//==================================================================================================