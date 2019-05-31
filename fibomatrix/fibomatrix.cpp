#include <iostream>

#define VERBOSE 0

using namespace std;

typedef struct {
	long long a, b, c, d;
} M2x2;


M2x2 MMult(const M2x2 &m1, const M2x2 &m2) {
	M2x2 mult;

	mult.a = m1.a*m2.a + m1.b*m2.c;
	mult.b = m1.a*m2.b + m1.b*m2.d;
	mult.c = m1.c*m2.a + m1.d*m2.c;
	mult.d = m1.c*m2.b + m1.d*m2.d;

	return mult;
}

void PrintM(M2x2 m) {
	cout << m.a << '\t' << m.b << '\n' << m.c << '\t' << m.d << endl;
}

long long F(M2x2 m, int n) {
	long long f;
	M2x2 fm, pm, id;

	id.a = 1; id.b = 0; id.c = 0; id.d = 1;
	fm = id;
	pm = m;

	for(int i = n; i > 0; i >>= 1) {
		if(i % 2) {
			fm = MMult(fm, pm);
		}
		pm = MMult(pm, pm);

		if(VERBOSE) {
			PrintM(fm);
			cout << endl;
			PrintM(pm);
			cout << '\n' << fm.b << '\n'<< endl;
		}
	}
	f = fm.b;
	return f;
}

int IsLikeFibonacci(M2x2 matrix, int n) {
	long long f;
	switch (n) {
		case 0:
			f = matrix.d;
			break;
		case 1:
			f = matrix.c;
			break;
		case 2:
			f = matrix.c + matrix.d;
			break;
		default:
			f = F(matrix, n);
			break;
	}
	return f;
}

int main (int, char **) {
	int n;
	long long a, b;
	M2x2 m;

	a = 0; b = 1; //F0 and f1. Used to feed matrix
	cout << "O(log(n)) Fibbonacci calculator. Type n for desired Fn:" << endl;
	cin >> n;
	m.a = a + b;
	m.b = m.c = b;
	m.d = a;
	cout << "Fn: " << IsLikeFibonacci(m, n) << endl;
}
