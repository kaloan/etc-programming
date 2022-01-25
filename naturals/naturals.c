#include <stdio.h>
#include <stdlib.h>
#define zero NULL

typedef struct {
	struct Nat* suc;
} Nat;

void printNat(Nat* nat) {
	while (nat) {
		printf("suc ");
		nat = nat->suc;
	}
	printf("zero\n");
}

short eq(Nat* nat1, Nat* nat2) {
	if (!nat1) return !nat2;
	if (!nat2) return 0;
	return eq(nat1->suc, nat2->suc);
}

short leq(Nat* nat1, Nat* nat2) {
	if (!nat1) return 1;
	if (!nat2) return 0;
	return leq(nat1->suc, nat2->suc);
}

Nat* plusOne(Nat* nat) {
	Nat* res = (Nat*)malloc(sizeof(Nat));
	res->suc = nat;
	return res;
}

Nat* add(Nat* nat1, Nat* nat2) {
	if (!nat2) return nat1;
	Nat* res = (Nat*)malloc(sizeof(Nat));
	res->suc = nat1;

	return add(res, nat2->suc);
}

Nat* mult(Nat* nat1, Nat* nat2) {
	if (!nat1 || !nat2) return zero;
	if (nat2->suc == zero) return nat1;

	Nat* res = zero;
	for (Nat* iter = nat2; iter != zero; iter = iter->suc) {
		res = add(nat1, res);
	}

	return res;
}


int main() {
	Nat* one = (Nat*)malloc(sizeof(Nat));
	Nat* two = (Nat*)malloc(sizeof(Nat));
	one->suc = zero;
	two->suc = one;

	printNat(zero);
	printNat(one);
	printNat(two);

    printf("1 = 1 ? %d \n", eq(one, one));
    printf("1 = 1 ? %d \n", eq(two, one));
    printf("1 = 1 ? %d \n", leq(zero, one));
    printf("1 = 1 ? %d \n", leq(two, one));
    
    printf("1 + 1 = ");
    printNat(plusOne(one));
    printf("2 + 2 = ");
    printNat(add(two, two));
	printf("2 * (2 + 1) = ");
    printNat(mult(two, plusOne(two)));

	return 0;
}