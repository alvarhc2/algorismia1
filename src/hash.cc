#include <iostream>
#include <set>
#include <list>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <vector>
#include <tr1/functional>
#include <math.h>

using namespace std;

bool es_primer(int n) {
	if (n <= 3) return(n == 2 or n == 3);
	else if (n % 2 == 0 or n % 3 == 0) return false;
	else {
		for (int i = 5; i * i <= n; i = i + 6) {
			if (n % i == 0 or n % (i + 2) == 0) return false;
		}
		return true;
	}
}

int prim(int n) {
  if(es_primer(n)) return n;
  else {
	  int i = n + 1;
	  while(not es_primer(i)) {
		  ++i;
	  }
	  return i;
  }
}

int calc_m(int p, int n) {
	double base = 0.619223;
	double prob = (double)p / 1000;
	double x = (log2(prob) / log2(base));
	int m = x * (double)n;
	return prim(m);
}

int calc_k(int m, int n) {
	double d1 = 9.0/13.0;
	double d2 = (double)m / (double)n;
	double kopt = d1*d2;
	int k = kopt + 1;
	return k;
}

map<string, list<unsigned int> > hashFuncFam (int p, set<string> w) {
	int m = calc_m(p, w.size());
	int k = calc_k(m, w.size());
	map<string, list<unsigned int> > hff;
	vector<pair<int,int> > funcs(k);
	srand(time(NULL));
	for(int i = 0; i < k; ++i) {
		pair <int,int> hash;
		int a = 1+rand()%(m-1);
		int b = rand()%m;
		hash = make_pair(a,b);
		funcs[i] = hash;
	}
	
	std::tr1::hash<string> str_hash;
	set<string>::iterator it;
	vector<unsigned int> h (w.size());
	it = w.begin();
	int pos = 0;
	while(it != w.end()) {
		unsigned int a = str_hash(*it);
		h[pos] = a;
		++pos;
		++it;
	}
	
	for(int i = 0; i < k; ++i) {
		int a = funcs[i].first;
		int b = funcs[i].second;
		map<string, list<unsigned int> >::iterator itm;
		it = w.begin();
		int pvec = 0;
		while(it != w.end()) {
			list<unsigned int>::iterator it2 = hff[*it].end();
			unsigned int aux = (a * h[pvec] + b)%m;
			hff[*it].insert(it2, aux);
			++pvec;
			++it;
		}
	}
	
	return hff;
}

/*int main() {
	set<string> ss;
	ss.insert("hola");
	ss.insert("adeu");
	ss.insert("heys");
	map<string, list<unsigned int> > m = hashFuncFam(7, ss);
	
	map<string, list<unsigned int> >::iterator itm = m.begin();
	while(itm != m.end()) {
		cout << (*itm).first << " ";
		list<unsigned int>::iterator it = m[(*itm).first].begin();
		while(it != m[(*itm).first].end()) {
			cout << *it << " ";
			++it;
		}
		cout << endl;
		++itm;
	}
}*/


