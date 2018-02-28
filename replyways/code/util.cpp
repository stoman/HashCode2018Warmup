#pragma once

typedef long long ll;

#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <time.h>
#include <utility>
#include <vector>
#include <set>
#include <sstream>

using namespace std;


template<typename T>
void debug (T x)
{
	cerr << ">>> " << x << endl;
}

//util classes
struct Input {
	int n;
	vector<pair<ll, ll>> points;// size: 3n + 2, 0: s, 1: f, triangle: 3i+2, 3i+3, 3i+4
	vector<pair<ll, ll>> path;
};

//input handling
void readInput(Input& input, istream& in) {
	in >> input.n;
	input.points.resize(3*input.n + 2);
	for(int i = 0; i < input.points.size(); i++) {
		int x, y;
		in >> x >> y;
		input.points[i] = make_pair(x, y);
	}
}

vector<int> neighbors(Input& input, int a);
