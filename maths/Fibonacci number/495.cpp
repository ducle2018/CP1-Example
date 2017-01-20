///Author: Duc Le
///Topics: Mathematics - Fibonacci number
///Problem: 1 - UVa 495 - Fibonacci Freeze
///Language: C++
///Last update & reviewed by

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int mod = 1e9;
struct bigint{
	int d[150];
	void init() {memset(d,0,sizeof(d));}
	void init(int x) {init(); d[0] = 1; d[1] = x;}
	void reset() {while (d[0] > 1 && d[d[0]] == 0) d[0]--; }
	void print() {
		printf("%d",d[d[0]]);
		for (int i=d[0]-1;i>=1;--i) printf("%09d",d[i]);
		printf("\n");
	}	
};

bigint operator+(bigint &a,bigint &b) {
	bigint c; c.init();
	c.d[0] = max(a.d[0],b.d[0]);
	int t = 0;
	for (int i=1;i<=c.d[0];++i) {
		t += a.d[i] + b.d[i];
		c.d[i] = t%mod;
		t /= mod;
	}
	if (t > 0) c.d[++c.d[0]] = t;
	c.reset();
	return c;
}

bigint F[5001];

int main() {
	F[0].init(0); F[1].init(1);
	for (int i=2;i<=5000;++i) F[i] = F[i-1] + F[i-2];
	int n;	
	while (cin  >> n) {
		printf("The Fibonacci number for %d is ",n);
		F[n].print();		
	}
	return 0;	
}
