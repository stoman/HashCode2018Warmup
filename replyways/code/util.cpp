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

using namespace std;

void debug(string s)
{
	cerr << ">>> " << s << endl;
}

void debug(int x)
{
	cerr << ">>> " << x << endl; 
}

//util classes
struct Input {
	int n;
	vector<pair<int, int>> points;// size: 3n + 2, 0: s, 1: f, triangle: 3i+2, 3i+3, 3i+4
	vector<pair<int, int>> path;
};

//input handling
void readInput(Input& input, istream& in) {
	//TODO read input
}
