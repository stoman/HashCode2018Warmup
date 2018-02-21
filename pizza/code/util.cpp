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
	int r, c, l, h;
	vector<vector<bool>> pizza;
	vector<vector<bool>> sliced;
	vector<vector<pair<int, int>>> bestPiece;
	vector<pair<int, int>> answerColumn;
	vector<pair<int, int>> answerRow;
};

//input handling
void readInput(Input& input, istream& in) {
	in >> input.r >> input.c >> input.l >> input.h;
	char c = ' ';
	input.pizza.resize(input.r);
	for(int i = 0; i < input.r; i++) {
		input.pizza[i].resize(input.c);
		for(int j = 0; j < input.c; j++) {
			while(c != 'T' && c != 'M') in >> c;
			input.pizza[i][j] = c == 'T';
			in >> c;
		}
	}
	input.sliced.resize(input.r);
	for(int i = 0; i < input.r; i++) {
		input.sliced[i].resize(input.c);
		for(int j = 0; j < input.c; j++) {
			input.sliced[i][j] = false;
		}
	}
	input.bestPiece.resize(input.r);
	for(int i = 0; i < input.r; i++) {
		input.bestPiece[i].resize(input.c);
	}
}
