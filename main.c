#include "doubleLList.h"
#include "bigInt.h"




int main(){
	//insert code here...
	printf("Hello, world!\n");


	DList DLL = CreateDList();
	addDList(1, DLL);
	addDList(2, DLL);
	addDList(3, DLL);
	PrintDList(DLL);


	/*
    BigInt b = big_new("-1453778288677");
	
    BigInt a = big_new("89838519993662878919168712");
	printf("a=");
	print_b(a);
	printf("b=");
	print_b(b);
	BigInt soma = sum_b( a, b);
	printf("soma =");
	print_b(soma);
    */
   	/*
	BigInt A = big_new("4009");
	BigInt a = big_new("409");
	BigInt B = big_new("3009");
	BigInt b = big_new("409");
	BigInt Aneg = big_new("-4009");
	BigInt aneg = big_new("-409");
	BigInt Bneg = big_new("-3009");
	BigInt bneg = big_new("-409");

	printf("Testando Função soma.\n BigInt iguais: \n");

	BigInt soma = sum_b(A, B);
	printf("4009 + 3009 = 7018 == ");
	print_b(soma);
	printf("\n");
	soma = sum_b(A, Bneg);
	printf("4009 + (-3009) = 1000 == ");
	print_b(soma);
	printf("\n");
	soma = sum_b(Aneg, B);
	printf("(-4009) + 3009 = -1000 == ");
	print_b(soma);
	printf("\n");
	soma = sum_b(Aneg, Bneg);
	printf("(-4009) + (-3009) = -7018 == ");
	print_b(soma);
	printf("\n");



	printf("Testando Função soma.\n Primeiro maior que o segundo: \n");

	soma = sum_b(A, b);
	printf("4009 + 309 = 4318 == ");
	print_b(soma);
	printf("\n");
	soma = sum_b(A, bneg);
	printf("4009 + (-309) = 3700 == ");
	print_b(soma);
	printf("\n");
	soma = sum_b(Aneg, b);
	printf("(-4009) + 309 = -3700 == ");
	print_b(soma);
	printf("\n");
	soma = sum_b(Aneg, bneg);
	printf("(-4009) + (-309) = -4318 == ");
	print_b(soma);
	printf("\n");


	printf("Testando Função soma.\n Segundo maior que o primeiro: \n");


	soma = sum_b(a, B);
	printf("409 + 3009 = 3418 == ");
	print_b(soma);
	printf("\n");
	soma = sum_b(a, Bneg);
	printf("409 + (-3009) = -3700 == ");
	print_b(soma);
	printf("\n");
	soma = sum_b(aneg, B);
	printf("(-409) + 3009 = 3700 == ");
	print_b(soma);
	printf("\n");
	soma = sum_b(aneg, Bneg);
	printf("(-409) + (-3009) = -3418 == ");
	print_b(soma);
	printf("\n");
*/    
	
	
	return 0;

}



