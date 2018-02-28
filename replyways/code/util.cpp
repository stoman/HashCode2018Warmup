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
	int n, gridsize;
	vector<pair<ll, ll>> triangles;// size: 3n, triangle: 3i, 3i+1, 3i+2
	vector<pair<ll, ll>> points;// size: 24n + 2, 0: s, 1: f
	vector<pair<ll, ll>> path;
};

//input handling
void readInput(Input& input, istream& in) {
	input.points.resize(2);
	for(int i = 0; i < input.points.size(); i++) {
		int x, y;
		in >> x >> y;
		input.points[i] = make_pair(x, y);
	}
	in >> input.n;
	input.points.resize(24*input.n + 2);
	input.triangles.resize(3*input.n);
	for(int i = 0; i < 3*input.n; i++) {
		int x, y;
		in >> x >> y;
		input.points[8*i+2] = make_pair(x, y-1);
		input.points[8*i+3] = make_pair(x, y+1);
		input.points[8*i+4] = make_pair(x-1, y-1);
		input.points[8*i+5] = make_pair(x-1, y);
		input.points[8*i+6] = make_pair(x-1, y+1);
		input.points[8*i+7] = make_pair(x+1, y-1);
		input.points[8*i+8] = make_pair(x+1, y);
		input.points[8*i+9] = make_pair(x+1, y+1);
		input.triangles[i] = make_pair(x, y);
	}
}

vector<int> neighbors(Input& input, int a);
