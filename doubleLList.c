#include <stdio.h>
#include <stdlib.h>
#include "doubleLList.h"

/*
#############################################################################
# Inicialização da struct doubleLList com 4 campos:
#
# data - valor guardado na posição, inteiro
# prev - pointer para o endereço anterior, pointer to struct
# next - pointer para o endereço seguinte, pointer to struct
# header - pointer para o inicio da lista, pointer to struct
#############################################################################
*/

struct doubleLList
{
    ElementType data;
    DPosition prev;
    DPosition next;

};

/*
#############################################################################
# CreateDList - Aloca espaço na memória para o primeiro node da lista e
#               define os parametros iniciais para todos os campos da struct
# Argumentos:
# Não tem argumentos.
# Valor de retorno:
# Retorna um pointer para o node inicial da lista
#############################################################################
*/


DList CreateDList( void )
{
    DList DLL = malloc( sizeof ( struct doubleLList ) );
    assert ( DLL != NULL && "Lista Dupla não criada em memória");

    DLL->next = NULL;
    DLL->prev = NULL;
    DLL->data = 0;

    return DLL;
}

/*
#############################################################################
# MakeEmptyDList - Recebe uma lista e esvazia todos os nodes da mesma
#
# Argumentos:
# DList L - doubly linked list, struct 
# Valor de retorno:
# Não tem retorno.
#############################################################################
*/

void MakeEmptyDList( DList L)
{
    if( L != NULL)
    {
        if(!IsEmptyDList(L))
        {
            DPosition head = DHeader(L);

            while(head->next != NULL && head->next != head)
            {
                DPosition clean = head;
                head = head->next;
                free(clean);
            }
            printf("A Lista está vazia.");
        }
        printf("A Lista está vazia.");
    }
    else
    {
        printf("Lista não Inicializada !!!");
    }
}

/*
#############################################################################
# SizeDList - Recebe uma lista e conta quantos elementos a mesma tem
#
# Argumentos:
# DList L - doubly linked list, struct
# Valor de retorno:
# O numero de elementos da lista, inteiro
#############################################################################
*/

int SizeDList(DList L)
{
    if ( L != NULL )
    {
        if( L->next != NULL )
        {
            DPosition head = DHeader(L);
            ElementType counter = 1;
            while( head->next != NULL && head->next != head )
            {

                head = head->next;
                counter++;
            }
            return counter;
        }
        else
        {
            printf("A Lista está Vazia !!");
            return 0;
        }
    }
    else
    {
        printf("Lista não Inicializada !!!");
        return 0;
    }
}

/*
#############################################################################
# DHeader - Recebe uma lista e devolve o valor da primeira posição (head) 
#
# Argumentos:
# DList L - doubly linked list, struct
# Valor de retorno:
# Retorna o valor da primeira posição da lista, inteiro
#############################################################################
*/

DPosition DHeader(DList L)
{
    if ( L != NULL )
    {
        if ( L->next != NULL)
        {
            DPosition head = L;

            while(head->prev != NULL)
            {
                head = Back(head);
            }
            return head;
        }
        else
        {
            printf("A Lista está vazia !!!");
            return NULL;
        }
    }
    print("Lista não Inicializada !!!");
    return NULL;
}

/*
#############################################################################
# DFooter - Recebe uma lista e devolve o valor da ultima posição (tail)
#
# Argumentos:
# DList L - doubly linked list, struct
# Valor de retorno:
# Retorna o valor da ultima posição da lista
#############################################################################
*/

DPosition DFooter(DList L)
{
     if ( L != NULL )
    {
        if ( L->next != NULL)
        {
            DPosition head = DHeader(L);
            while(head->next != NULL && SizeDList(L) != 1)
            {
                head = head->next;
            }
            return head;
        }
        else
        {
            printf("A Lista está vazia !!!");
            return NULL;
        }
    }
    print("Lista não Inicializada !!!");
    return NULL;
}

/*
#############################################################################
# IsEmptyDList - Verifica se a lista passada como argumento está vazia
#
# Argumentos:
# DList L - doubly linked list, struct
# Valor de retorno:
# Retorna 1(true) se a lista estiver vazia, e 0(false) se não
#############################################################################
*/

int IsEmptyDList(DList L)
{
    if(L != NULL)
    {
        if ( L->next == NULL && L->prev == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        printf("Lista não Inicializada !!!");
        return true;
    }
}

/*
#############################################################################
# InsertDList - Insere um elemento X na lista, aseguir á posição P
#
# Argumentos:
# ElementType X - valor a inserir na lista, inteiro
# DPosition P - posição na lista, pointer to struct
# Valor de retorno:
# Nao retorna nada.
#############################################################################
*/

//Insere na lista aseguir á posição P
void InsertDList(ElementType X, DPosition P)
{
    if( P != NULL)
    {
        
        DPosition temp = P;
        
        if(temp->next == NULL && temp->prev == NULL)
        {
            temp->data = X;
            temp->next = temp;
            return;
        }
        else if( temp->next == temp )
        {
            DList newNode = malloc ( sizeof ( struct doubleLList ) );

            newNode->data = X;
            newNode->prev = temp;
            temp->next = newNode;
            return;
        }
        else if ( temp->next == NULL && temp->prev != NULL) 
        {
            DList newNode = malloc ( sizeof ( struct doubleLList ) );

            newNode->data = X;
            newNode->prev = temp;
            temp->next = newNode;
            return;
        }
        else
        {
            DList newNode = malloc ( sizeof ( struct doubleLList ) );
            DPosition nextPtr = Advance(temp);

            nextPtr->prev = newNode;
            temp->next = newNode;

            newNode->next = nextPtr;
            newNode->prev = temp;

            newNode->data = X;
            return;
        }
    }
    else
    {
        printf("Não existe lista !!!");
    }
}

/*
#############################################################################
# InsertDListIth - Insere o valor X na i-ésima posição da lista
#
# Argumentos:
# ElementType X - valor a inserir na lista, inteiro
# int i - posição na qual vamos inserir o novo valor
# DList L - doubly linked list, struct
# Valor de retorno:
# Nao retorna nada
#############################################################################
*/

void InsertDListIth(ElementType X, int i, DList L)
{
    if( L != NULL)
    {
        if( i <= SizeDList(L)  && i > 0 )
        {   
            DPosition head = DHeader(L);
            if(i == 1 && head->next == NULL && head->prev == NULL)
            {
                head->data = X;
                head->next = head;
                return;
            }
            else if( i == 1 && head->next == head )
            {
                DList newNode = malloc ( sizeof ( struct doubleLList ) );

                newNode->next = head;
                newNode->data = X;
                head->prev = newNode;
                head->next = NULL;
                return; 
            }
            else if( i == 1 && SizeDList(L) > 1 )
            {
                DList newNode = malloc ( sizeof ( struct doubleLList ) );
                head->prev = newNode;
                newNode->next = head;
                newNode->data = X;
                return;
            }
            else 
            {
                for(int counter = 1; counter = i; counter++)
                {
                    head = Advance(head);
                }
                    DList newNode = malloc ( sizeof ( struct doubleLList ) );
                    DPosition prevPtr = Back(head);
                    
                    prevPtr->next = newNode;
                    head->prev = newNode;
                    newNode->next = head;
                    newNode->prev = prevPtr;
                    newNode->data = X;
                    return;
            }
            return;
            }
        }
        else
        {
            printf("Posição não existente na lista !!!");
        }
    }
    else
    {
        printf("Lista não existe !!!!");
    }
}

/*
#############################################################################
# addDList - Insere um valor X no fim da Lista
#
# Argumentos:
# ElementType X - valor a inserir na lista , inteiro
# DList L - doubly linked list, struct 
# Valor de retorno:
# Nao retorna nada.
#############################################################################
*/

void addDList(ElementType X, DList L)
{
    if( L != NULL )
    {   
        DPosition temp = DHeader(L);
        if (temp->next == NULL && temp->prev == NULL)
        {
            temp->data = X;
            temp->next = temp;
            return;
        }
        else if(temp->next = temp)
        {
            DList newNode = malloc ( sizeof ( struct doubleLList ) );

            temp->next = newNode;

            newNode->prev = temp;
            newNode->data = X;
            return;
        }
        else
        {
            temp = DFooter(L);
            DList newNode = malloc ( sizeof ( struct doubleLList ) );

            temp->next = newNode;
            newNode->prev = temp;

            newNode->data = X;
            return;
        }
    }
    else 
    {
        printf("Lista Não Inicializada !!!");
    }
}

/*
#############################################################################
# FindDList - Verifica se o valor e existe na lista L
#
# Argumentos:
# ElementType e - valor que estamos á procura, inteiro
# DList L - doubly linked list, struct
# Valor de retorno:
# Retorna um pointer para a posição na lista do valor e, se existir na lista,
# se não existir retorna NULL
#############################################################################
*/

DPosition FindDList(ElementType e, DList L)
{
   if( L != NULL)
   {
        DPosition head = DHeader(L);
        for(ElementType counter = 1; counter <= SizeDList(L); counter++)
        {
            if ( head->data = e )
            {
                return head;
            }
            else
            {
                head = Advance(head);
            }
        }
        
        printf("O Elemento %d, não existe na lista. \n", e);
        return NULL;
        
   }
    printf("Lista Não Inicializada !!!");
    return NULL;
}

/*
#############################################################################
# DeleteElement - Elimina o elemento e da lista L
#
# Argumentos:
# ElementType e - valor que queremos eliminar da lista
# DList L - doubly linked list, struct
# Valor de retorno:
# Nao retorna nada.
#############################################################################
*/

void DeleteElement(ElementType e, DList L)
{
    if ( L != NULL )
    {
        DPosition head = DHeader(L);
        if( head->next != head)
        {
            DPosition findPosPtr = FindDList(e, L);
            
            else if(findPosPtr->next == NULL)
            {
                DPosition prevPtr = findPosPtr->prev;
                prevPtr->next = NULL;
                free(findPosPtr);
            }
            else if(findPosPtr->prev == NULL)
            {
                DPosition nextPtr = findPosPtr->next;
                prevPtr->prev = NULL;
                free(findPosPtr);
            }
            else
            {
                DPosition prevPtr = findPosPtr->prev;
                DPosition nextPtr = findPosPtr->next;

                prevPtr->next = nextPtr;
                nextPtr->prev = prevPtr;
                
                free(findPosPtr);
            }
            else
            {
                printf(" O elemento %d não existe na Lista", e);
            }
        }
        else 
        {
            printf("A Lista está vazia !!!");
        }
    }
    else
    {
        printf("Lista Não Inicializada !!!!");
    }
}

/*
############################################################################
# DeleteElementAt - Elimina o i-ésimo elemento da lista L
#
# Argumentos:
# int i - posição do elemento que queremos eliminar, inteiro
# DList L - doubly linked list, struct
# Valor de retorno:
# Nao retorna nada.
#############################################################################
*/

ElementType RemoveElementAt(int i, DList L)
{
    if( L != NULL )
    {
        if( i <= SizeDList(L) && i > 0 )
        {
            DPosition head = DHeader(L);
            if ( i == 1 && head->next == NULL && head->prev == NULL)
            {
                printf("A Lista está vazia!!");
                return 0;
            }
            else if ( i == 1 && head->next = head)
            {   
                ElementType del = head->data;
                DeleteElement(head->data, L);
                return del;
            }
            else 
            {
                for(int counter = 1; counter <= SizeDList(L); counter++)
                {
                    if( counter == i )
                    {
                        ElementType del = head->data;
                        DeleteElement(head->data, L);
                        return del;
                    }
                    else
                    {
                        head = Advance(head);
                    }
                }
            }
        }
        else
        {
            printf("A posição %d não existe na lista!", i);
            return 0;
        }
    }
    else
    {
        printf("Lista não inicializada!!!");
        return -1;
    }
}

/*
#############################################################################
# Advance - Recebe uma posição da lista e retorna a seguinte
#
# Argumentos:
# DPosition P - pointer para a posição actual na lista, pointer to struct
# Valor de retorno:
# Retorna um pointer para o endereço da posição seguinte.
#############################################################################
*/

DPosition Advance(DPosition P)
{
    if( P != NULL)
    {
        if (P->next = P || P->next == NULL)
        {
            printf("A Lista não tem mais valores !!");
            return NULL;
        }
        else
        {
            return P->next
        }
    }
    else
    {
        printf("Posição Não existente !!!");
        return NULL
    } 
}

/*
#############################################################################
# Back - Recebe uma posição da lista e retorna a seguinte
#
# Argumentos:
# DPosition P - pointer para a posição actual na lista, pointer to struct
# Valor de retorno:
# Retorna um pointer para o endereço da posição anterior.
#############################################################################
*/

DPosition Back(DPosition P)
{   
      if( P != NULL)
    {
        if(P->prev == NULL)
        {
            printf("Primeira posição da Lista!!!");
            return NULL;
        }
        else
        {
            return P->prev;
        }
    }
    else
    {
        printf("Posição Não existente !!!");
        return NULL
    } 
}

/*
#############################################################################
# Retrieve - Recebe uma posição da lista e retorna o valor guardado na mesma
#
# Argumentos:
# DPosition P - pointer para a posição actual na lista, pointer to struct
# Valor de retorno:
# Retorna o valor guardado na posição P, inteiro
#############################################################################
*/

ElementType Retrieve(DPosition P)
{
      if( P != NULL)
    {   
        if ( P->next == P )
        {
            printf(" A Lista está vazia !!!");
            return 0;
        }
        else 
        {
            return P->data;
        }
    }
    else
    {
        printf("Lista não Inicializada !!!");
        return -1;
    } 
}

/*
#############################################################################
# PrintDList - Dá print a todos os valores da lista
#
# Argumentos:
# DList L - doubly linked list, struct
# Valor de retorno:
# Nao retorna nada.
#############################################################################
*/

void PrintDList(DList L)
{
    if ( L != NULL )
    {
        DPosition head = DHeader(L);
        if (head->next != NULL && head->prev != NULL)
        {
           if(head->next = head)
           {
               printf("Lista = { %d }\n", head->data);
           }
           printf("Lista = { ");
           while(head->next != NULL)
           {
               printf("%d, ", head->data);
               head = Advance(head);
           }
           printf("%d }", head->data);
        }
        else
        {
            printf("A Lista está vazia !!!!");
        }
    }
    printf("Lista Não Inicializada !!!!");
}


