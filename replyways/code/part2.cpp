#pragma once
#include "util.cpp"

typedef pair<ll,ll> Point;


bool ccw(Point &p1, Point &p2, Point &p3)
{
	return (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second) <= 0;
}

bool linesIntersect(Point &p1, Point &p2, Point &q1, Point &q2)
{
	return (ccw(p1,p2,q1) != ccw(p1,p2,q2) && ccw(q1,q2,p1) != ccw(q1,q2,p2));
}

vector<int> neighbors(Input& input, int a) 
{
	vector<int> validPoints;
	Point &x = input.points[a];
	for (int k = 0; k < input.points.size(); k++)
	{
		if (k == a)
		{
			continue;
		}
		Point &y = input.points[k];
		bool valid = true;
		for (int i = 0; i < input.n; ++i)
		{
			Point &a = input.points[3*i+2];
			Point &b = input.points[3*i+3];
			Point &c = input.points[3*i+4];
			
			// check lines ab, bc, ca
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
	ss << "Point " << a << " has " << validPoints.size() << " neighbors" << endl;
	debug(ss.str());
	return validPoints;	
}