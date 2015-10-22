#include<stdio.h>
#include<stdlib>
#include "HashSeq.h"

struct ListNode
{
	ElementType element;
	Position next;
};

struct HashTbl
{
	int tableSize;
	List * theLists; 
}

HashTable initializeTable(int tableSize){
	HashTable h = malloc(sizeof(struct HashTbl));
	h -> tableSize = tableSize;
	h -> theLists = malloc(h -> tableSize * sizeof(List));

	for(int i = 0; i < h -> tableSize; i++){
		h -> theLists[i] = malloc(sizeof(struct ListNode));
		h -> theLists[i] -> next = NULL;
	}

	return h;
}

Position find(ElementType key, HashTable h){
	Position p;
	List l;

	l = h -> theLists[Hash(key, h -> tableSize)];
	p = l -> next;
	while (p != null && p -> element != key){
		p = p -> next;
	}

	return p;
}

void insert(ElementType key, HashTable h){
	Position pos, newCell;
	List l;

	pos = find(key, h);
	if (pos == NULL){
		newCell = malloc(sizeof(struct ListNode));
		if (newCell == NULL){
			printf("out of space");
		}
		else{
			l = h -> theLists[Hash(key, h -> tableSize)];
			newCell -> next = l -> next;
			newCell -> element = key;
			l -> next = newCell;
		}
	}
}
