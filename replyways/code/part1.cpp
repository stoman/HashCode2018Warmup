#pragma once
#include "util.cpp"

const ll inf = 1e18;

ll sqdist(pair<ll,ll> a, pair<ll,ll> b) {
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second); 
}

void astar(Input& input) {
    
    int m = 3*input.n + 2;
    vector<int> visited(m, 0), p(m,-1);
    vector<ll> d(m,inf);
    set< pair<ll,int> > h;
 
    d[0] = 0ll;
    h.insert({sqdist(input.points[0], input.points[1]), 0});
    
    while (h.size())    {
        int cur = h.begin()->second;
        
        debug("Current point: ");
        debug(cur);
        debug("Estimated distance to goal: ");
        debug((int)h.begin().first);
        
        h.remove(h.begin());
        
        if (cur == 1)
            break;
        
        auto nbh = neighbors(input, cur);
        for (int i = 0; i < nbh.size(); i++)    {
            int k = nbh[i];
            if (visited[k])
                continue;
            
            ll tscore = d[cur] + sqdist(input.points[cur], input.points[k]);
            if (tscore >= d[k])
                continue;
                
            p[k] = cur;
            h.remove({d[k]+sqdist(input.points[k], input.points[1]), k});
            d[k] = tscore;
            h.insert({d[k]+sqdist(input.points[k], input.points[1]), k});            
        }
    }
    
    for (int i = 1; p[i] != -1; i = p[i])
        input.path.push_back(input.points[i]);
}