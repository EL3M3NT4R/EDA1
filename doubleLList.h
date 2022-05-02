//
//  doubleLList.h
//  ListasDuplas
//
//  Created by Ligia Ferreira on 29/03/2022.
//

#ifndef doubleLList_h
#define doubleLList_h

#include <stdio.h>
#include <assert.h>


#define true 1
#define false 0

typedef int ElementType;

//Defenir Estrutura
struct doubleLList;
// Defenir PTrtoDLL como tipo pointer to struct
typedef struct doubleLList *PtrToDLL;
typedef PtrToDLL DList;
typedef PtrToDLL DPosition;



DList CreateDList( void );
void MakeEmptyDList( DList L);
int SizeDList(DList L);
DPosition DHeader(DList L);
DPosition DFooter(DList L);
int IsEmptyDList(DList L);
void InsertDList(ElementType X, DPosition P);
void InsertDListIth(ElementType X, int i, DList L);
void addDList(ElementType X, DList L);
DPosition FindDList(ElementType e, DList L);
void DeleteElement(ElementType e, DList L);
ElementType RemoveElementAt(int i, DList L);
DPosition Advance(DPosition P);
DPosition Back(DPosition P);
ElementType Retrieve(DPosition P);
void PrintDList(DList L);

#endif /* doubleLList_h */
