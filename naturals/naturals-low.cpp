#include <iostream>
using namespace std;

constexpr auto zero = nullptr;

struct Nat {
	Nat* suc;
};

void printNat(Nat* nat) {
	while (nat) {
		cout << "suc ";
		nat = nat->suc;
	}
	cout << "zero" << "\n";
}

bool eq(Nat* nat1, Nat* nat2) {
	if (!nat1) return !nat2;
	if (!nat2) return false;
	return eq(nat1->suc, nat2->suc);
}

bool leq(Nat* nat1, Nat* nat2) {
	if (!nat1) return true;
	if (!nat2) return false;
	return leq(nat1->suc, nat2->suc);
}

Nat* plusOne(Nat* nat) {
	Nat* res = new Nat();
	res->suc = nat;
	return res;
}

Nat* add(Nat* nat1, Nat* nat2) {
	if (!nat2) return nat1;
	Nat* res = new Nat();
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
	Nat* one = new Nat();
	Nat* two = new Nat();
	one->suc = zero;
	two->suc = one;

	printNat(zero);
	printNat(one);
	printNat(two);

	cout << "1 = 1 ? " << eq(one, one) << "\n";
	cout << "2 = 1 ? " << eq(two, one) << "\n";
	cout << "0 <= 1 ? " << leq(zero, one) << "\n";
	cout << "2 <= 1 ? " << leq(two, one) << "\n";

	cout << "1 + 1 = ";
	printNat(plusOne(one));
	cout << "2 + 2 = "; 
	printNat(add(two, two));
	cout << "2 * (2 + 1) = ";
	printNat(mult(two, plusOne(two)));
	return 0;
}