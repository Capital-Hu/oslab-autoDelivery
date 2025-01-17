#ifndef GRAPH_H
#define GRAPH_H

#include "header.h"
#include "macro.h"
#include "util.h"
/*
0道路
1草地
2顾客
3接收点
4饭店
*/

#define G_USER 2
#define G_RECEIV 3
#define G_REST 4
namespace Graph {
    extern std::vector<std::vector<int>> graph;
    extern int dx[4];
    extern int dy[4];
    extern std::vector<int> error_pos;

    struct Point {
        int x, y;
        int step, est;
        bool operator < (const Point& p) const {
            return step + est > p.step + p.est;
        }
    };

    int H(int sx, int sy, int ex, int ey);

    int astar(int sx, int sy, int ex, int ey, const std::vector<std::vector<int>> &graph);

    std::pair<std::pair<int, int>, std::pair<int, int>> get_valid_pos(int who);
};

#endif