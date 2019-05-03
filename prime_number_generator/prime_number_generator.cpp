#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int , char **) {
	vector<unsigned long int> prime_list;
	ifstream data;
	data.open("prime_list.txt");
	unsigned int n;
	data >> n;
	prime_list.push_back(n);
	while (data.good()) {
		data >> n;
		prime_list.push_back(n);
	}
	data.close();

	if(prime_list.size() < 2) {
		prime_list.clear();
		prime_list.push_back(2);
		prime_list.push_back(3);
		cout << "prime[0] = " << prime_list[0] << "\nprime[1] = " << prime_list[1] << endl;
	}
	for(unsigned int i = 0; i < 200; ++i) {
		for(unsigned long int prime_tmp = prime_list.back() + 2; ;prime_tmp += 2) {
			unsigned int n = 0;
			for(; n < prime_list.size(); ++n) {
				if(prime_tmp % prime_list[n] == 0) {
					break;
				}
			}
			if(n >= prime_list.size()) {
				prime_list.push_back(prime_tmp);
				cout  << "prime[" << prime_list.size() -1 << "] = " << prime_list.back() << endl;
				break;
			}
		}
	}
	ofstream file;
	file.open("prime_list.txt", ios_base::trunc);
	for(unsigned int i = 0; i < prime_list.size(); ++i) {
		file << prime_list[i] << endl;
	}
	file.close();

	return 0;
}
