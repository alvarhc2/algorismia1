#include <iostream>
#include <set>
#include <list>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

int pot2(int m) {
	int i = 1;
	while (m > i) i = i << 1;
	return i;
}

int calc_m(int p, int n) {
	double base = 0.619223;
	double prob = (double)p / 1000;
	double x = (log2(prob) / log2(base));
	int m = x * (double)n;
	return pot2(m);
}

int calc_k(int m, int n) {
	double d1 = 9.0/13.0;
	double d2 = (double)m / (double)n;
	double kopt = d1*d2;
	int k = kopt + 1;
	return k;
}

map<string, list<unsigned int> > tabHashFuncFam (int p, set<string> w) {
	int m = calc_m(p, w.size());
	int k = calc_k(m, w.size());
	map<string, list<unsigned int> > thff;
	set<string>::iterator it = w.begin();
	unsigned int u = 256;
	vector< vector<unsigned int> > Tab ((*it).size(), vector<unsigned int> (u));
	
	srand(time(NULL));
	
	for (int f = 0; f < k; ++f) {
		
		for (int i = 0; i < Tab.size(); ++i) {
			for (int j = 0; j < Tab[0].size(); ++j) {
				Tab[i][j] = rand()%m;
			}
		}
		
		it = w.begin();
		while(it != w.end()) {
			unsigned int hsh;
			for(int i = 0; i < (*it).size(); ++i) {
				char aux = (*it)[i];
				if (i == 0) {
					hsh = Tab[i][(int)aux];
				}
				else {
					hsh = hsh ^ Tab[i][(int)aux];
				}
			}
			list<unsigned int>::iterator it2 =  thff[*it].end();
			thff[*it].insert(it2, hsh);
			++it;
		}
	}
	return thff;
}

/*int main() {
	set<string> ss;
	ss.insert("hola");
	ss.insert("adeu");
	ss.insert("heys");
	map<string, list<unsigned int> > m = tabHashFuncFam(10, ss);
	
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
	
