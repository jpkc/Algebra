#include <iostream>

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

M2x2 F(int n) {
	 M2x2 fm, pm;

	 pm.a = 1; pm.b = 1; pm.c = 1; pm.d = 0; //fibomatrix
	 fm.a = 1; fm.b = 0; fm.c = 0; fm.d = 1; //identity

	 for(int i = n; i > 0; i >>= 1) { //breaking n in powers of 2
		  if(i % 2) {
				fm = MMult(fm, pm);
		  }
		  pm = MMult(pm, pm);
	 }
	 return fm;
}

int IsLikeFibonacci(long long a, long long b, int n) {
	 long long f;
	 M2x2 matrix;


	 switch (n) {
		  case 0:
				f = a;
				break;
		  case 1:
				f = b;
				break;
		  case 2:
				f = a + b;
				break;
		  default:
				matrix = F(n);
				f = matrix.c*b + matrix.d*a;
				break;
	 }
	 return f;
}

int main (int, char **) {
	 int n;
	 long long a, b;

	 cout << "O(Log(n)) Fibonnacci like calculator. Please type F0 F1 and n for desired FN:" << endl;

	  cin >> a >> b >> n;
	  cout << "f" << n << ": " << IsLikeFibonacci(a, b, n) << endl;
}
