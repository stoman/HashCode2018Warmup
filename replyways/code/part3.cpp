#pragma once
#include "util.cpp"

typedef pair<ll,ll> Point;

ll offset = 20000;

vector<vector<vector<int>>> grid;
vector<int>& getcell(Input& input, int x, int y) {
  return grid[(x + offset)/input.gridsize][(y + offset)/input.gridsize];
}

bool setupdone = false;
vector<int>& closepoints(Input& input, int a) {
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

vector<vector<vector<int>>> gridtriangles;
bool setupdonetriangles = false;
vector<int>& closetriangles(Input& input, int a) {
  if(!setupdonetriangles) {
    gridtriangles.resize(2*offset/input.gridsize);
    for(int i = 0; i < gridtriangles.size(); i++) {
      gridtriangles[i].resize(2*offset/input.gridsize);
    }
    for(int i = 0; i < input.n; i++) {
      int minx = min(min(input.triangles[3*i].first, input.triangles[3*i+1].first), input.triangles[3*i+2].first);
      int miny = min(min(input.triangles[3*i].second, input.triangles[3*i+1].second), input.triangles[3*i+2].second);
      int maxx = max(max(input.triangles[3*i].first, input.triangles[3*i+1].first), input.triangles[3*i+2].first);
      int maxy = max(max(input.triangles[3*i].second, input.triangles[3*i+1].second), input.triangles[3*i+2].second);
      for(int k = (minx + offset)/input.gridsize-1; k <= (maxx + offset)/input.gridsize+1; k++) {//-1/+1 because this is the length of the lines we consider
        for(int j = (miny + offset)/input.gridsize-1; j <= (maxy + offset)/input.gridsize+1; j++) {
          gridtriangles[k][j].push_back(i);
        }
      }
    }
    setupdonetriangles = true;
  }
  return gridtriangles[(input.points[a].first + offset)/input.gridsize][(input.points[a].second + offset)/input.gridsize];
}
