#pragma once
#include "util.cpp"

typedef pair<ll,ll> Point;

ll gridsize = 100;
ll offset = 20000;
vector<vector<vector<int>>> grid(2*offset/gridsize, vector<vector<int>>(2*offset/gridsize));

vector<int>& getcell(int x, int y) {
  return grid[(x + offset)/gridsize][(y + offset)/gridsize];
}

bool setupdone = false;
vector<vector<int>> closepoints(Input& input, int a) {
  if(!setupdone) {
    for(int i = 0; i < input.points.size(); i++) {
      getcell(input.points[i].first, input.points[i].second).push_back(i);
    }
    setupdone = true;
  }

  vector<vector<int>> ret;
  for(int i = -1; i <= 1; i++) {
    for(int j = -1; j <= 1; j++) {
      ret.push_back(getcell(input.points[a].first + i*gridsize, input.points[a].second + j*gridsize));
    }
  }
  return ret;
}
