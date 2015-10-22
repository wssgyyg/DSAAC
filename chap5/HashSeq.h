#ifndef _HashSeq_H

struct ListNode;
typedef struct ListNode * Position;
struct HashTbl;
typedef struct HashTbl * HashTable;
typedef Position List;

HashTable initializeTable(int tableSize);
void destroyTable(HashTable h);
Position find(ElementType key, HashTable h);
void insert(ElementType key, HashTable h);
ElementType retrive(Position p);

#endif