#include<stdio.h>
#include"add.h"
#include"sub.h"

int main(void){
	int a = 1, b = 2;
	printf("b - a = %d\n", sub(b, a));
	printf("b + a = %d\n", add(b, a));
	return 0;
}
