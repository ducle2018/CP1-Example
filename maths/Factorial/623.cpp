///Author: Duc Le
///Topics: Mathematics - Fibonacci number
///Problem: 4 - UVa 623 - 500!
///Language: C++
///Last update & reviewed by

#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
const int mod = 1e9;
struct bigint{
	int d[300];
	void init() {memset(d,0,sizeof(d));}
	void init(int x) {init(); d[0] = 1; d[1] = x;}
	void reset() {while (d[0] > 1 && d[d[0]] == 0) d[0]--; }
	void print() {
		printf("%d",d[d[0]]);
		for (int i=d[0]-1;i>=1;--i) printf("%09d",d[i]);
		printf("\n");
	}	
};

bigint operator*(bigint &a,bigint &b) {
	bigint c; c.init();
	c.d[0] = a.d[0] + b.d[0];	
	long long t;
	for (int i=1;i<=a.d[0];++i)
	    for (int j=1;j<=b.d[0];++j) {
		t = 1ll*a.d[i]*b.d[j]+c.d[i+j-1];
		c.d[i+j-1] = t%mod;
		c.d[i+j] += t/mod;
	    }
	c.reset();
	return c;
}

bigint F[1002], A;

int main() {
	F[0].init(1);
	for (int i=1;i<=1000;++i) A.init(i), F[i] = F[i-1]*A;
	int n; 
	while (cin >> n) {
		cout << n << "!\n";
		F[n].print();
	}
	return 0;	
}
