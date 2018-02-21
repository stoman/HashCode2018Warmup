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

using namespace std;

//util classes
struct SomeClass {
	int n;
	SomeClass(int n): n(n) {};
};

struct Input {
	int r, c, l, h;
	vector<vector<bool>> pizza;
	vector<vector<bool>> sliced;
	vector<vector<pair<int, int>>> bestPiece;
};

//input handling
void readInput(Input& input, istream& in) {
	//TODO read input
}
