#ifndef ASTAR_H_
#define ASTAR_H_
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

//define the point class
class CPoint
{
public:
    CPoint (int x, int y):X(x),Y(y),m_parent_point(NULL),G(0),H(0),F(0)
    {};
    ~CPoint();
    void calcF()
    {
        this->F = this->G+this->H;
    };
public:
    int X; int Y; int G; int H; int F; CPoint* m_parent_point;
};


//define the A* class
class CAstar
{
public:
    //static const int STEP = 10;
    //static const int MAP_SIZE = 18;
    int ROW,COLUMN;
    std::vector<CPoint*> open_list;
    std::vector<CPoint*> close_list;
    int m_map[100][100];
    int orientation_edge[10000][4]; 
public:
    CAstar(int map[], int o_edge[][4], int row, int column);
    CPoint* find_path(CPoint* start, CPoint* end);
    bool inclose_list(int x, int y);
    bool inopen_list(int x, int y);
    bool canreach(int x, int y);
    bool can_reach(CPoint* tempstart, int x, int y, int index);
    bool out_bound(int x, int y);
    std::vector<CPoint*> surround_points(CPoint* point);
    CPoint* get_min_F_point();
    void remove_from_open_list(CPoint* point);
};

#endif
