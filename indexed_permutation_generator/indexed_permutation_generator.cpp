#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

unsigned long Factorial(unsigned long n) {
        if(n > 1) {
                return n*Factorial(n-1);
        }
        return 1;
}

vector<unsigned long> Permutation(unsigned long element_count, unsigned long permutation_index) {
        vector<unsigned long> element_vector, perm;

        unsigned long total = Factorial(element_count);
        permutation_index %= static_cast<unsigned int>(total); // avoiding Invalid permutation. Valid values: 0 <= permutation < factorial(elements)

        for(unsigned long i = 0; i < element_count; ++i) {
                element_vector.push_back(i);
        }

        for(unsigned long i = 1; i < element_count; ++i) {
                total /= (element_count - i + 1);	// Same as total = Factorial(elements - i), but faster.
                perm.push_back(element_vector[static_cast<unsigned long>(permutation_index/total)]);
                element_vector.erase(element_vector.begin() + static_cast<long>(permutation_index/total));
                permutation_index %= total;
        }
        perm.push_back(element_vector[0]);
        return perm;
}

unsigned long ElementPosition(const vector<unsigned long> &set, unsigned long element) {
        for(unsigned long i = 0; i < set.size(); ++i) {
                if(set[i] == element) {
                        return i;
                }
        }
        return set.size();
}

unsigned long Index(const vector<unsigned long> &permutation) {
        // Valid permutatios have:
        //	1: size() = n
        //	2:Non repeated and scrambled elements 0, 1, 2, 3, ..., n-1
        vector<unsigned long> element_vector, perm;
        for(unsigned long i = 0; i < permutation.size(); ++i) {
                element_vector.push_back(i);
        }

        unsigned long index = 0;
        unsigned long element_pos;
        for(unsigned int i = 0; i < permutation.size(); ++i) {
                element_pos = ElementPosition(element_vector, permutation[i]);
                index += element_pos * Factorial(permutation.size() - i - 1);
                element_vector.erase(element_vector.begin() + static_cast<long>(element_pos));
        }

        return index;
}

void PrintPermutation(const vector<unsigned long> &permutation) {
        for(unsigned long i = 0; i <permutation.size() ; ++i) {
                if(i) {
                        cout << ", ";
                }
                cout << permutation[i];
        }
}

int main(int, char **) {
        vector<long> permutation;
        unsigned long elements = 9;

        for(unsigned long i = 0; i < Factorial(elements); ++i) {
                cout << "Permutation " << i << ": ";
                PrintPermutation(Permutation(elements, i));
                cout << " Index: " << Index(Permutation(elements, i)) << endl;
        }

        return 0;
}

