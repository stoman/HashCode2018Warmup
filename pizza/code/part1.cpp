#pragma once
#include "util.cpp"

const int maxScore = 1000;
int bestScore = -1;
vector<set<pair<int,int>>> scores(maxScore);
map<pair<int,int>, int> fieldToScore;



pair<int, int> nextField() {
	if (bestScore == -1)
		return make_pair(-1,-1);
	return *scores[bestScore].begin();
}



void update(pair<int, int> &field, int newScore, Input &input) {
	int r = field.first;
	int c = field.second;
	if (r < 0 || r >= input.r || c < 0 || c >= input.c)
		return;

	// erase old score if it exists
	if (fieldToScore.count(field))
	{
		int oldScore = fieldToScore[field];
		scores[oldScore].erase(field);
	}

	// update new score
	if (newScore != -1)
	{
		scores[newScore].insert(field);
		fieldToScore[field] = newScore;
	}

	// increase best score
	if (newScore > bestScore)
		bestScore = newScore;
	
	// decrease best score
	while (bestScore >= 0 && scores[bestScore].size() == 0)
		bestScore--;
}
