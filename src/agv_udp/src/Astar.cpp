#include <Astar.h>

CPoint::~CPoint()
{};
//realize the A* algorithm
bool comp_F(const CPoint* pl, const CPoint* pr)
{
    return pl->F < pr->F;
}
CAstar::CAstar(int map[], int o_edge[][4], int row, int column)
{
    ROW = row;
    COLUMN = column;
    for (int i=0;i<100;i++)
    {
        for (int j=0;j<100;j++)
        {
            if (i<ROW && j<COLUMN)
            {m_map[i][j] = map[i*COLUMN+j];
                //std::cout<<m_map[i][j];
            }
            else
                m_map[i][j] = 0;
        }
        //std::cout<<std::endl;
    }
    for (int i=0;i<10000;i++)
    {
        for (int j=0;j<4;j++)
        {
            if (i < ROW*COLUMN)
                orientation_edge[i][j] = o_edge[i][j];
            else
                orientation_edge[i][j] = 0;
        }
    }
    //std::cerr<<"initial success!"<<std::endl;
 /*   for (int i=0;i<ROW;i++)
    {
       for(int j=0;j<COLUMN;j++)
        {
            std::cout<<orientation_edge[i*COLUMN+j][0]<<orientation_edge[i*COLUMN+j][1]<<orientation_edge[i*COLUMN+j][2]<<orientation_edge[i*COLUMN+j][3]<<" ";
        }
        std::cout<<std::endl;
    }
*/
}

CPoint* CAstar::find_path(CPoint *start, CPoint *end)
{
    //judge the start point is whether in collision set or not
    //add the start to the open list
    if (!m_map[start->X][start->Y])
    {
        open_list.push_back(start);
    }
    else
    {
        std::cerr<<"The Start Point Is Invalid....."<<std::endl;
        return NULL;
    }

    while (open_list.size())//openlist is not empty)
    {
        //get the point with the min F
        CPoint* current_point = get_min_F_point();
        //add this point to the close list, and delete it from the open list
        remove_from_open_list(current_point);
        close_list.push_back(current_point);
        //get the set of its surround points
        std::vector<CPoint*> surround_point = surround_points(current_point);
        //visit the surround points in order
        std::vector<CPoint*>::iterator _iter = surround_point.begin();
        for (_iter; _iter != surround_point.end();++_iter)
        {
            CPoint* point = *_iter;
            //if the surround point is in open list ,update the G value, if the G
            //value is more small, update its parent, if not do nothing
            if (inopen_list(point->X, point->Y))
            {
                //calculate the G value from the current node
                int G = current_point->G + 1;
                if ( G < point->G)
                {
                    point->G = G;
                    point->m_parent_point = current_point;
                    point->calcF();
                }
            }
            else
            {
                //if not in the open list, add it to the open list
                point->m_parent_point = current_point;
                point->G = current_point->G +1;
                //calculate the H value
                point->H =0* (abs(point->X - end->X) + abs(point->Y - end->Y));
                point->calcF();
                open_list.push_back(point);

            }
        }
/*
	for(int i=0;i<open_list.size();i++)
	{
		std::cout<<open_list[i]->X<<" "<<open_list[i]->Y<<'\t';	
	}
	std::cout<<".................."<<std::endl;
*/
        if(inopen_list(end->X, end->Y))
        {

            for (int i=0; i<open_list.size();i++)
            {
                if(open_list[i]->X ==end->X && open_list[i]->Y == end->Y)
                {
                    //std::cerr<<"end point in open list!"<<std::endl;
                    return open_list[i];

                }
			
            }

        }
        //std::cerr<<"ahhaahhaahh"<<std::endl;

    }
    std::cerr<<"              error      "<<std::endl;
    return end;
}

CPoint* CAstar::get_min_F_point()
{
    std::vector<CPoint*> temp_list;
    for (int i=0;i<(int)open_list.size();i++)
    {
        temp_list.push_back(open_list[i]);
    }
    sort(temp_list.begin(), temp_list.end(), comp_F);
    if (temp_list.size())
    {
        return temp_list[0];
    }
}

std::vector<CPoint*> CAstar::surround_points(CPoint* point)
{
    std::vector<CPoint*> temp_surround_list;
    //up: (x-1,y) down:(x+1, y) left:(x,y-1) right:(x, y+1)
    int x = point->X;
    int y = point->Y;
    std::vector<std::vector<int> > points(4, std::vector<int>(2));
    points[0][0] = x-1; points[0][1] = y;
    points[1][0] = x+1; points[1][1] = y;
    points[2][0] = x  ; points[2][1] = y-1;
    points[3][0] = x  ; points[3][1] = y+1;
    for (int i=0;i<4;i++)
    {
        if(can_reach(point, points[i][0], points[i][1], i))
        {
            CPoint* p_insert = new CPoint(points[i][0], points[i][1]);
            temp_surround_list.push_back(p_insert);
        }

    }
    return temp_surround_list;
}
//orientation graph is special
bool CAstar::canreach(int x, int y)
{
    return m_map[x][y] == 0;
}
bool CAstar::out_bound(int x, int y)
{
if( (x<0) || (x>=ROW) || (y<0) || (y>=COLUMN) )
    return true;
else
    return false;
}
bool CAstar::can_reach( CPoint* tempstart, int x, int y, int index)
{
    if (out_bound(x, y))
        return false;
    if(!canreach(x, y) || inclose_list(x, y) ||
            !orientation_edge[(tempstart->X)*COLUMN+tempstart->Y][index])
        return false;
    else
        return true;
}
bool CAstar::inopen_list(int x, int y)
{
    CPoint* p =new CPoint(x, y);
    std::vector<CPoint*>::iterator _iter = open_list.begin();
    for (_iter; _iter !=open_list.end(); ++_iter)
    {
        CPoint* temp = *_iter;
        if (temp->X == p->X && temp->Y == p->Y)
            return true;
    }
    if (p)
    {
        delete p;
        p = NULL;
    }
    return false;
}

bool CAstar::inclose_list(int x, int y)
{
    CPoint* p =new CPoint(x, y);
    std::vector<CPoint*>::iterator _iter = close_list.begin();
    for (_iter; _iter !=close_list.end(); ++_iter)
    {
        CPoint* temp = *_iter;
        if (temp->X == p->X && temp->Y == p->Y)
            return true;
    }
    if (p)
    {
        delete p;
        p = NULL;
    }
    return false;
}

void CAstar::remove_from_open_list(CPoint *point)
{
    std::vector<CPoint*>::iterator _iter = open_list.begin();
    for (_iter; _iter!= open_list.end(); ++_iter)
    {
        open_list.erase(_iter);
        break;
    }
}
