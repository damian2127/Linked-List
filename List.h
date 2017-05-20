#ifndef _LIST_INCLUDE_
#define _LIST_INCLUDE_
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

typedef struct tagListItem
{
	int xKey;
	tagListItem* pNext;
} ListItem;

typedef ListItem* List;

void LInitList(List* pList);  //inicjalizacja listy
void LAddFront(List pList, int x); //dodaje element na poczatku listy 
void LPrintList(List pList); //wypisuje zawartosc listy 
void LDeleteFront(List pList ); //usuwanie z poczatku
void LFreeList(List* pList); //czysci cala liste
int LisEmpty(List pList); // sprawdza czy lista jest pusta i zainicjowana
int LFront(List pList); //zwraca pierwszy element listy
ListItem* LFind(List pList, int x, ListItem** ppNext); // zwraca element poprzedni
void LAdd(List pList, ListItem* pElem, int x); // dodawanie przed wskazanym elementem
void LDelete(List pList, ListItem* ppNext, ListItem* pPrev ); //usuwanie wskazanego elementu
void LSortList(List pList); //sortowanie listy przez przewiazywanie elementow

#endif