#pragma once
#include "util.cpp"

vector<pair<int, int>> slices;
vector<pair<int, int>> neighbors = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};

int score(pair<int, int> &field, Input &input) {
	//set up slices
	if(slices.size() == 0) {
		for(int i = 1; i <= input.h; i++) {
			for(int j = 1; j <= input.h; j++) {
				if(2*input.l <= i*j && i*j <= input.h) {
					slices.push_back(make_pair(i, j));
				}
			}
		}
	}

	//validate
	if(field.first < 0 || field.first >= input.r) return -1;
	if(field.second < 0 || field.second >= input.c) return -1;

	//try slices
	int max = -1;
	pair<int, int> best;
	for(auto &slice: slices) {
		bool valid = true;
		if(field.first + slice.first - 1 >= input.r) valid = false;
		if(field.second + slice.second - 1 >= input.c) valid = false;
		int sc = 0;
		int tomato = 0;
		for(int i = field.first; i < field.first + slice.first; i++) {
			for(int j = field.second; j < field.second + slice.second; j++) {
				if(input.sliced[i][j]) valid = false;
				if(input.pizza[i][j]) tomato++;
				for(auto &neigh: neighbors) {
					if(0 <= i + neigh.first && i + neigh.first < input.r && 0 <= j + neigh.second && j + neigh.second < input.c) {
						if(input.sliced[i + neigh.first][j + neigh.second]) {
							sc++;
						}
					}
				}
			}
		}
		if(tomato < input.l || slice.first * slice.second - tomato < input.l) valid = false;
		if(valid && sc > max) {
			max = sc;
			input.bestPiece[field.first][field.second] = slice;
		}
	}

	//return
	return max;
}

