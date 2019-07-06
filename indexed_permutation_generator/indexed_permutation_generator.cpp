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

vector<long> Permutation(long element_count, long permutation_index) {
        vector<long> element_vector, perm;

        long total = Factorial(element_count);
        permutation_index %= static_cast<unsigned int>(total); // avoiding Invalid permutation. Valid values: 0 <= permutation < factorial(elements)

        for(int i = 0; i < element_count; ++i) {
                element_vector.push_back(i);
        }

        for(int i = 1; i < element_count; ++i) {
                total /= (element_count - i + 1);	// Same as total = Factorial(elements - i), but faster.
                perm.push_back(element_vector[static_cast<unsigned long>(permutation_index/total)]);
                element_vector.erase(element_vector.begin() + permutation_index/total);
                permutation_index %= total;
        }
        perm.push_back(element_vector[0]);
        return perm;
}

unsigned long ElementPosition(const vector<long> &set, long element) {
        for(unsigned long i = 0; i < set.size(); ++i) {
                if(set[i] == element) {
                        return i;
                }
        }
        return set.size();
}

unsigned long Index(const vector<long> &permutation) {
        // Valid permutatios have:
        //	1: size() = n
        //	2:Non repeated and scrambled elements 0, 1, 2, 3, ..., n-1
        vector<long> element_vector, perm;
        for(unsigned int i = 0; i < permutation.size(); ++i) {
                element_vector.push_back(static_cast<int>(i));
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

void PrintPermutation(const vector<long> &permutation) {
        for(unsigned long i = 0; i <permutation.size() ; ++i) {
                if(i) {
                        cout << ", ";
                }
                cout << permutation[i];
        }
}

int main(int, char **) {
        vector<long> permutation;
        long elements = 9;

        for(unsigned long i = 0; i < Factorial(elements); ++i) {
                cout << "Permutation " << i << ": ";
                PrintPermutation(Permutation(elements, i));
                cout << " Index: " << Index(Permutation(elements, i)) << endl;
        }

        return 0;
}
