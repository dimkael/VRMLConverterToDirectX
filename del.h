#pragma once

#include <vector>
#include <iterator>
#include <map>
using std::vector;
using std::iterator;
using std::map;


template <typename T>
void del(vector<T>& v) {
	typename vector<T>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		delete[] * it;
		*it = 0;
	}
	/*for (int i = 0; i < v.size(); i++) {
		delete[] v[i];
		v[i] = 0;
	}*/
	v.clear();
}


template <typename T>
void del(vector<T>* v) {
	typename vector<T>::iterator it;
	for (it = v->begin(); it != v->end(); it++) {
		if ((*it)->def == "") {
			delete* it;
			*it = 0;
		}
	}
	v->clear();
	delete v;
}


template <typename T1, typename T2>
void del(map<T1, T2>& v) {
	typename map<T1, T2>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		delete it->second;
		it->second = 0;
	}
	v.clear();
}


template <typename T1, typename T2>
void del(map<T1, T2>* v) {
	/*typename map<T1, T2>::iterator it;
	for (it = v->begin(); it != v->end(); it++) {
		delete it->second;
		it->second = 0;
	}*/
	typename map<T1, T2>::reverse_iterator it;
	for (it = v->rbegin(); it != v->rend(); it++) {
		delete it->second;
		it->second = 0;
	}
	v->clear();
	delete v;
}


template <typename T1, typename T2>
void del(map<T1, vector<T2>>* v) {
	v->clear();
	delete v;
}


template <typename T>
void delNodes(vector<T>* v) {
	typename vector<T>::iterator it;
	for (it = v->begin(); it != v->end(); it++) {
		if ((*it)->def == "") {
			delete* it;
		}
	}
	v->clear();
	delete v;
}