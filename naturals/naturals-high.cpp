#include <iostream>
#include <stack>

using namespace std;

using Nat = stack<bool>;
const Nat zero;

void printNat(Nat nat) {
	while (!nat.empty()) {
		cout << "suc ";
		nat.pop();
	}
	cout << "zero" << "\n";
}

bool eq(Nat nat1, Nat nat2) {
	if (nat1.empty()) return nat2.empty();
	if (nat2.empty()) return false;
	nat1.pop();
	nat2.pop();
	return eq(nat1, nat2);
}

bool leq(Nat nat1, Nat nat2) {
	if (nat1.empty()) return true;
	if (nat2.empty()) return false;
	nat1.pop();
	nat2.pop();
	return leq(nat1, nat2);
}

Nat plusOne(Nat nat) {
    nat.push(true);
    return nat;
}

Nat add(Nat nat1, Nat nat2) {
	if (nat2.empty()) return nat1;
	nat1.push(true);
	nat2.pop();
	return add(nat1, nat2);
}

Nat mult(const Nat& nat1, Nat nat2) {
	if (nat1.empty() || nat2.empty()) return zero;
    nat2.pop();
	return add(nat1, mult(nat1, nat2));
}


int main() {
	Nat one = Nat({true});
	Nat two = Nat({true, true});

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