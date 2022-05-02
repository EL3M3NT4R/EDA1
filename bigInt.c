#include <stdio.h>
#include <stdlib.h>
#include "bigInt.h"
#include "doubleLList.h"

/*
#############################################################################
# Inicialização da struct bigInt com 2 campos:
#
# data - valor guardado na posição, inteiro
# sinal - sinal do Big Int armazenado, inteiro
#############################################################################
*/


typedef struct bigInt
{
    int sinal;
    DList data;

};

/*
#############################################################################
# big_new - Lẽ um array de characteres, e armazena-os numa estrutura do tipo DLList
#
# Argumentos:
# char * num - Array de characteres, char
# Valor de retorno:
# Retorna a estrutura com o nosso Big Int armazenado
#############################################################################
*/

BigInt big_new(char *num)
{
    BigInt big = malloc ( sizeof ( struct bigInt ) );
    big->sinal = 0;
    big->data = CreateDList();
    
    if ( num[0] == 45)
    {
        big->sinal = -1;
    }
    else 
    {
        big->sinal = 1;
    }
    
    assert(big->sinal != 0 && "Sinal não atribuido");

    DPosition big_Element = big->data; 
    char * copyNum;
    for( copyNum = num; *copyNum != '\0'; copyNum++)
    {
        int x = (int) *copyNum;
        if ( x == 45 )
        {
            continue;
        }
        else if( x < 58 && x > 47) 
        {
            x -= 48;
            addDList(x, big_Element);
        }
        else 
        {
            assert( 0 && "Character Inválido !!!");
        }
    }
    return big;
}

/*
#############################################################################
# sum_b - Faz a soma entre dois BIG INT armazenados na lista
#
# Argumentos:
# BigInt a - doubly linked list, struct
# BigInt b - doubly linked list, struct
# Valor de retorno:
# Retorna a soma entre as duas listas, struct
#############################################################################
*/

BigInt sum_b(BigInt a, BigInt b)
{
    BigInt sum = malloc(sizeof( struct bigInt ) );
    DPosition lastA = DFooter(a->data);
    DPosition lastB = DFooter(b->data);
    ElementType carry = 0;

    if( SizeDList(a) > SizeDList(b) ){
        for(int counter = 0; counter < SizeDList(b->data); counter++)
        {
            ElementType soma = Retrieve(lastA) + Retrieve(lastB);
                    
            soma += carry;
            
            if ( soma > 9 )
            {
                soma %= 10;
                carry = 1;
            }
            else 
            {
                carry = 0;
            }
            
            InsertDListIth(soma, 1, sum);
            lastA = Back(lastA);
            lastB = Back(lastB);
        }
        
        InsertDListIth( Retrieve(lastA) + carry, 1, sum);
        lastA = Back(lastA);
        
        
        while ( lastA != DFooter(a) )
            {
                InsertDListIth(Retrieve(a), 1, sum);
                lastA = Back(lastA);
            }  

        return sum;  
    }
    else if( SizeDList(a) < SizeDList(b) ){
        for(int counter = 0; counter < SizeDList(a->data); counter++)
        {
            ElementType soma = Retrieve(lastA) + Retrieve(lastB);
                    
            soma += carry;
            
            if ( soma > 9 )
            {
                soma %= 10;
                carry = 1;
            }
            else 
            {
                carry = 0;
            }
            
            InsertDListIth(soma, 1, sum);
            lastA = Back(lastA);
            lastB = Back(lastB);
        }
        
        InsertDListIth( Retrieve(lastB) + carry, 1, sum);
        lastB = Back(lastB);
        
        
        while ( lastB != DFooter(a) )
            {
                InsertDListIth(Retrieve(a), 1, sum);
                lastB = Back(lastB);
            }  
            
        return sum;  
    }
    
}

/*
#############################################################################
# sub_b - Faz a subtracção entre dois BIG INT armazenados na lista
#
# Argumentos:
# BigInt a - doubly linked list, struct
# BigInt b - doubly linked list, struct
# Valor de retorno:
# Retorna a subtracção entre as duas listas, struct
#############################################################################
*/

BigInt sub_b(BigInt a, BigInt b)
{

}

/*
#############################################################################
# mult_b - Faz a multiplicação entre dois BIG INT armazenados na lista
#
# Argumentos:
# BigInt a - doubly linked list, struct
# BigInt b - doubly linked list, struct
# Valor de retorno:
# Retorna a multiplicação entre as duas listas, struct
#############################################################################
*/

BigInt mult_b(BigInt a, BigInt b)
{

}

/*
#############################################################################
# div_b - Faz a divisão entre dois BIG INT armazenados na lista
#
# Argumentos:
# BigInt a - doubly linked list, struct
# BigInt b - doubly linked list, struct
# Valor de retorno:
# Retorna a divisão entre as duas listas, struct
#############################################################################
*/

BigInt div_b(BigInt a, BigInt b)
{

}

/*
#############################################################################
# mod_b - Faz o módulo entre dois BIG INT armazenados na lista
#
# Argumentos:
# BigInt a - doubly linked list, struct
# BigInt b - doubly linked list, struct
# Valor de retorno:
# Retorna o resto da divisão entre as duas listas, struct
#############################################################################
*/

BigInt mod_b(BigInt a, BigInt b)
{

}

/*
#############################################################################
# print_b - Imprime todos os elementos da lista
# Argumentos:
# BigInt a - doubly linked list, struct
# Valor de retorno:
# Não retorna nada.
#############################################################################
*/

void print_b(BigInt a)
{
    DList DLL = a->data;
    if ( a->sinal == -1)
    {
        printf("-");
    }
    PrintDList(DLL);
}


