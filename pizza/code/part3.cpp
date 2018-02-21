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
            update(current_field, current_score);
        }
    }
}

int run(Input &input) {
	//score all fields
    update_range(0, 0, input.r, input.c, input);

	//while there is a next field
	//	update data structure (update input->sliced, call scoring and send to part1)
    for (auto field = nextField(); field.first != -1; field = nextField())  {
        
        int sx = field.first;
        int sy = field.second;
        int slice_x = input.bestPiece[sx][sy].first;
        int slice_y = input.bestPiece[sx][sy].second;
        
           input.answerRow.push_back({sx, sx+slice_x});
        input.answerColumn.push_back({sy, sy+slice_y});
        
        for (int i = sx; i < sx + slice_x; i++)
            for (int j = sy; j < sy + slice_y; j++)
                input.sliced[i][j] = true;
        
        update_range(sx-15, sy-15, sx+15, sy+15, input);
    }
}

