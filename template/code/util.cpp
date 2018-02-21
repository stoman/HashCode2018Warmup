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
struct SomeClass {
	int n;
	SomeClass(int n): n(n) {};
};

struct Input {
};

//input handling
void readInput(Input& input, istream& in) {
	//TODO read input
}
