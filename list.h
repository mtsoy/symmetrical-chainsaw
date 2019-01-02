#ifndef __LIST_H__
#define __LIST_H__

#ifdef DEBUG
	#define PRINTLIST(A, B) ListConsolePrint(A, B)
#else
	#define PRINTLIST(A, B)
#endif

typedef struct _listElement
{
	void *value;
	struct _listElement *next;
	struct _listElement *prev;
} ListElement, *pListElement;

typedef struct _list
{
	pListElement first;
	pListElement last;
	
	int(*cmp)(void*, void*);
} List, *pList;

pList ListCreate(int(*cmp)(void*, void*));
void ListDelete(pList*);

void ListClear(pList);
void ListReleaseAndClear(pList);

void ListAddToFront(pList, void*);
void ListAddToBack(pList, void*);
pListElement ListFind(pList, void*);

void ListRemove(pList, pListElement);

#ifdef DEBUG
void ListConsolePrint(pList, void(*)(void*));
#endif

#endif //__LIST_H__
