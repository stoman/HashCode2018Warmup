#pragma once
#include "util.cpp"

typedef pair<ll,ll> Point;

ll offset = 20000;
vector<vector<vector<int>>> grid;

vector<int>& getcell(Input& input, int x, int y) {
  return grid[(x + offset)/input.gridsize][(y + offset)/input.gridsize];
}

bool setupdone = false;
vector<int> closepoints(Input& input, int a) {
  if(!setupdone) {
    grid.resize(2*offset/input.gridsize);
    for(int i = 0; i < grid.size(); i++) {
      grid[i].resize(2*offset/input.gridsize);
    }
    for(int i = 0; i < input.points.size(); i++) {
      for(int k = -1; k <= 1; k++) {
        for(int j = -1; j <= 1; j++) {
          getcell(input, input.points[i].first + k*input.gridsize, input.points[i].second + j*input.gridsize).push_back(i);
        }
      }
    }
    setupdone = true;
  }

  return getcell(input, input.points[a].first, input.points[a].second);
}
