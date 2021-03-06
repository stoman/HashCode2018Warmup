#pragma once
#include "util.cpp"

void update_range(int sx, int sy, int fx, int fy, Input &input) {
	for (int i = sx; i < fx; i++)
    {
        for (int j = sy; j < fy; j++) 
        {
            pair<int,int> current_field = {i, j};
            
            int current_score = score(current_field, input);
            
            current_field = {i, j};
            update(current_field, current_score, input);
        }
    }
}

void run(Input &input) {
	//score all fields
    update_range(0, 0, input.r, input.c, input);

	//while there is a next field
	//	update data structure (update input->sliced, call scoring and send to part1)
    for (auto field = nextField(); field.first != -1; field = nextField())  {
        
        int sx = field.first;
        int sy = field.second;
        int slice_x = input.bestPiece[sx][sy].first;
        int slice_y = input.bestPiece[sx][sy].second;
        
           input.answerRow.push_back({sx, sx+slice_x-1});
        input.answerColumn.push_back({sy, sy+slice_y-1});

        if (input.answerColumn.size() % 100 == 0)
            debug(input.answerColumn.size());
        
        for (int i = sx; i < sx + slice_x; i++)
            for (int j = sy; j < sy + slice_y; j++)
                input.sliced[i][j] = true;
        
        update_range(sx-13, sy-13, sx+slice_x, sy+slice_y, input);
    }
}

