#include "Tab_hash.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <math.h>

int Tab_hash::pot2(int m) {
	int i = 1;
	while (m > i) i = i << 1;
	return i;
}

int Tab_hash::calc_m(int p, int n) {
	double base = 0.619223;
	double prob = (double)p / 1000;
	double x = (log2(prob) / log2(base));
	int m = x * (double)n;
	return pot2(m);
}

int Tab_hash::calc_k(int m, int n) {
	double d1 = 9.0/13.0;
	double d2 = (double)m / (double)n;
	double kopt = d1*d2;
	int k = kopt + 1;
	return k;
}

Tab_hash::Tab_hash (int p, set<string> w) {
	m = calc_m(p, w.size());
	int k = calc_k(m, w.size());
	set<string>::iterator it = w.begin();
	unsigned int u = 256;
	vector<vector< vector<unsigned int> > > ax (k, vector<vector<unsigned int> > ((*it).size(), vector<unsigned int> (u)));
	Tab = ax;
	
	srand(time(NULL));
	
	for (int f = 0; f < k; ++f) {
		
		for (int i = 0; i < Tab[f].size(); ++i) {
			for (int j = 0; j < Tab[f][0].size(); ++j) {
				Tab[f][i][j] = rand()%m;
			}
		}
		
		it = w.begin();
		while(it != w.end()) {
			unsigned int hsh;
			for(int i = 0; i < (*it).size(); ++i) {
				char aux = (*it)[i];
				if (i == 0) {
					hsh = Tab[f][i][(int)aux];
				}
				else {
					hsh = hsh ^ Tab[f][i][(int)aux];
				}
			}
			list<unsigned int>::iterator it2 =  thff[*it].end();
			thff[*it].insert(it2, hsh);
			++it;
		}
	}
}

map<string, list<unsigned int> > Tab_hash::tabHashFuncFam() {
	return thff;
}

list<unsigned int> Tab_hash::tabHashFuncFamKey(string key) {
	list<unsigned int> h;
	for (int f = 0; f < Tab.size(); ++f) {
		unsigned int hsh;
		for(int i = 0; i < key.size(); ++i) {
			char aux = key[i];
			if (i == 0) {
				hsh = Tab[f][i][(int)aux];
			}
			else {
				hsh = hsh ^ Tab[f][i][(int)aux];
			}
		}
		list<unsigned int>::iterator it =  h.end();
		h.insert(it, hsh);
	}
	return h;
}

int Tab_hash::get_m() {
	return m;
}
