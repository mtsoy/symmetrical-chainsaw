#include "list.h"
#include <stdlib.h>

#ifdef DEBUG
#include <stdio.h>
#endif

pList ListCreate(int(*cmp)(void*, void*))
{
	pList tmp = (pList) malloc(sizeof(List));
	tmp->first = tmp->last = NULL;
	tmp->cmp = cmp;
	
	return tmp;
}
void ListDelete(pList *lst)
{
	ListClear(*lst);
	
	free(*lst);
	*lst = NULL;
}

void ListClear(pList lst)
{
	pListElement current = lst->first;
	pListElement tmp;
	
	while(current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	
	lst->first = lst->last = NULL;
}

void ListReleaseAndClear(pList lst)
{
	pListElement current = lst->first;
	pListElement tmp;
	
	while(current)
	{
		free(current->value);
		
		current = current->next;
	}
	
	ListClear(lst);
}

void ListAddToFront(pList lst, void *value)
{
	pListElement tmp = (pListElement) malloc(sizeof(ListElement));
	tmp->prev = NULL;
	tmp->value = value;
	
	tmp->next = lst->first;
	if(lst->first)
		lst->first->prev = tmp;
	
	// if empty
	if(!lst->first)
		lst->last = tmp;
	
	lst->first = tmp;
}

void ListAddToBack(pList lst, void *value)
{
	pListElement tmp = (pListElement) malloc(sizeof(ListElement));
	tmp->next = NULL;
	tmp->value = value;
	
	tmp->prev = lst->last;
	if(lst->last)
		lst->last->next = tmp;
	
	
	// if empty
	if(!lst->first)
		lst->first = tmp;
	
	lst->last = tmp;
}

pListElement ListFind(pList lst, void *value)
{
	pListElement current = lst->first;
	while(current)
	{
		if(lst->cmp(current->value, value))
			return current;
		
		current = current->next;
	}
	
	return NULL;
}

void ListRemove(pList lst, pListElement e)
{
	if(e == NULL)
		return;
	
	if(e->prev)
		e->prev->next = e->next;
	else
		lst->first = lst->first->next;
	
	if(e->next)
		e->next->prev = e->prev;
	else
		lst->last = lst->last->prev;
	
	free(e);
}

#ifdef DEBUG

void ListConsolePrint(pList lst, void(*Print)(void*))
{
	if(!lst->first)
	{
		printf("List is empty\n");
		return;
	}
	
	pListElement current = lst->first;
	while(current)
	{
		Print(current->value);
		printf(" ");
		
		current = current->next;
	}
	printf("\n");
}

#endif
