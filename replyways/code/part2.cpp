#pragma once
#include "util.cpp"
#include "part3.cpp"

typedef pair<ll,ll> Point;


int ccw(Point &p1, Point &p2, Point &p3)
{
	ll z = (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
	if (z < 0)
		return -1;
	if (z > 0)
		return 1;
	return 0;
}

bool linesIntersect(Point &p1, Point &p2, Point &q1, Point &q2)
{
	return (ccw(p1,p2,q1) != ccw(p1,p2,q2) && ccw(q1,q2,p1) != ccw(q1,q2,p2));
}

vector<int> neighbors(Input& input, int a) 
{
	vector<int>& triangles = closetriangles(input, a);
	vector<int> validPoints;
	Point &x = input.points[a];
	for (int k : closepoints(input, a))
	{
		if (k == a)
		{
			continue;
		}
		Point &y = input.points[k];
		bool valid = true;
		for (int i: triangles)
		{
			Point &a = input.triangles[3*i];
			Point &b = input.triangles[3*i+1];
			Point &c = input.triangles[3*i+2];
			
			if (linesIntersect(a, b, x, y) || linesIntersect(b, c, x, y) || linesIntersect(a, c, x, y))
			{
				valid = false;
				break;
			}
		}
		if (valid)
		{
			validPoints.push_back(k);
		}
	}
	stringstream ss;
	ss << "Point " << a << " has " << validPoints.size() << " neighbors";
	debug(ss.str());
	return validPoints;	
}
