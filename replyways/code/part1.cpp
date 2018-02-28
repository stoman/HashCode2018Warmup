#pragma once
#include "util.cpp"
#include <cmath>

const ll inf = 1e14;

ll sq(ll x) {
    return x*x;
}

double dist(pair<ll,ll> a, pair<ll,ll> b) {
    return sqrt(sq(a.first-b.first) + sq(a.second-b.second)); 
}

void astar(Input& input) {
    
    int m = input.points.size();
    vector<int> visited(m, 0), p(m,-1);
    vector<double> d(m,(double)inf);
    set< pair<double,int> > h;

    //debug(m); 
    //debug("Points:");
    //for (int i = 0; i < m; i++)
    //{    
    //    debug(input.points[i].first); 
    //    debug(input.points[i].second);
    //    debug("\n");
    //}
    d[0] = 0ll;
    h.insert({dist(input.points[0], input.points[1]), 0});
    
    while (h.size())    {
        int cur = h.begin()->second;
        
        //debug("Current point: ");
        //debug(cur);
        //debug("Estimated distance to goal: ");
        debug(h.begin()->first - d[cur]);
        
        h.erase(h.begin());
        
        if (cur == 1)
            break;

        auto nbh = neighbors(input, cur);
        for (int i = 0; i < nbh.size(); i++)    {
            int k = nbh[i];
            if (visited[k])
                continue;
            
            double tscore = d[cur] + dist(input.points[cur], input.points[k]);
            if (tscore >= d[k])
                continue;
                
            p[k] = cur;
            h.erase({d[k]+dist(input.points[k], input.points[1]), k});
            d[k] = tscore;
            h.insert({d[k]+dist(input.points[k], input.points[1]), k});            
        }
    }
    
    for (int i = 1; i != -1; i = p[i])
        input.path.push_back(input.points[i]);
}