#include <iostream>
#include <vector>

using namespace std;

int Factorial(int n) {
	if(n > 1) {
		return n*Factorial(n-1);
	}
	return 1;
}

vector<int> Permutations(int elements, int permutation) {
	vector<int> element_vector, perm;

	int total = Factorial(elements);
	permutation %= static_cast<unsigned int>(total); // avoiding Invalid permutation. Valid values: 0 <= permutation < factorial(elements)

	for(int i = 0; i < elements; ++i) {
		element_vector.push_back(i);
	}

	for(int i = 1; i < elements; ++i) {
		total /= (elements - i + 1);	// Same as total = Factorial(elements - i), but faster.
		perm.push_back(element_vector[static_cast<unsigned long>(permutation/total)]);
		element_vector.erase(element_vector.begin() + permutation/total);
		permutation %= total;
	}
	perm.push_back(element_vector[0]);
	return perm;
}

void PrintPermutation(const vector<int> &permutation) {
	for(unsigned int i = 0; i <permutation.size() ; ++i) {
		if(i) {
			cout << ", ";
		}
		cout << permutation[i];
	}
}

int main(int, char **) {
	vector<int> permutation;
	int elements = 9;

	for(int i = 0; i <= Factorial(elements); ++i) {
		cout << "Permutation " << i << ": ";
		PrintPermutation(Permutations(elements, i));
		cout << endl;
	}

	return 0;
}

