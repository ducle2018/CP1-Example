///Author: Duc Le
///Topics: Mathematics - Fibonacci number
///Problem: 5 - UVa 10183 - How many Fibs?
///Language: C++
///Last update & reviewed by

#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
const int mod = 1e9;
struct bigint{
	int d[150];
	void init() {memset(d,0,sizeof(d));}
	void init(int x) {init(); d[0] = 1; d[1] = x;}
	void init(string &s) {
		init();		
		int n = s.length(), t;
		for (int i=0;i<n;++i) {
			if (i%9 == 0) d[0]++, t = 1;
			d[d[0]] += t*(s[n-i-1]-'0');
			t *= 10;
		}
	}
	void reset() {while (d[0] > 1 && d[d[0]] == 0) d[0]--; }
	void print() {
		printf("%d",d[d[0]]);
		for (int i=d[0]-1;i>=1;--i) printf("%09d",d[i]);
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

int compare(bigint &a,bigint &b) {
	a.reset(); b.reset();
	if (a.d[0] != b.d[0])
		if (a.d[0] < b.d[0]) return -1;
		else return 1;
	for (int i=a.d[0];i>=1;--i)
		if (a.d[i] != b.d[i])
			if (a.d[i] < b.d[i]) return -1;
			else return 1;
	return 0;
}

string s;
bigint F[701], A, B, C;;

int main() {
	ios_base::sync_with_stdio(false);
	F[0].init(1); F[1].init(1);
	for (int i=2;i<=700;++i) F[i] = F[i-1] + F[i-2];
	// a, b <= 10^100, F[700] has about 100++ digits	
	while (cin >> s) {
		int ans = 0;
		A.init(s); 
		cin >> s; B.init(s);
		if (s == "0") break;
		if (compare(A,B) == 1) 
			C = A, A = B, B = C; // swap A,B
		for (int i=1;i<700;++i)
			if (compare(A,F[i]) < 1)
				if (compare(F[i],B) < 1) ans++; 
		cout << ans << '\n';
	}

	return 0;	
}
