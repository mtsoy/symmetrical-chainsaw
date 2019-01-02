#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void print_int(void *a)
{
	printf("%d", *((int*)a));
}

int hash_int(void *key)
{
	return *((int*)key);
}

int cmp_int(void *a, void *b)
{
	return *((int*) a) == *((int*) b);
}

int main()
{
	
	pList lst = ListCreate(cmp_int);
	
	int a1 = 2;
	ListAddToBack(lst, &a1);
	
	int a2 = 3;
	ListAddToBack(lst, &a2);
	
	int a3 = 1;
	ListAddToFront(lst, &a3);
		
	int a4 = 4;
	pListElement tmp = ListFind(lst, &a4);
	if(tmp)
		printf("Found\n");
	
	PRINTLIST(lst, print_int);
	
	ListClear(lst);
	
	PRINTLIST(lst, print_int);
	
	ListDelete(&lst);
	
	lst = ListCreate(cmp_int);
	
	int *pa1 = (int*)malloc(sizeof(int));
	*pa1 = 1;
	ListAddToBack(lst, pa1);
	
	ListReleaseAndClear(lst);
	
	ListDelete(&lst);
	
	return 0;
}
