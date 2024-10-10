#include "Edge.h"
#include "Vector.h"
#include <cmath>

Edge::Edge(Point start_n, Point end_n)
    {
        start = start_n;
        end = end_n;

        OPVector();
    }

void Edge::OPVector()
    {
        Vector vector(end.x - start.x, end.y - start.y, end.z - start.z);
        op_vector = vector;
    }

double Edge::Found_D(Point M)
    {
        double D = -(op_vector.x*M.x + op_vector.y*M.y + op_vector.z*M.z);

        return D;
    }

double Edge::Found_t(Point M)
    {
        double D = Edge::Found_D(M);
        double t = -(op_vector.x*start.x + op_vector.y*start.y + op_vector.z*start.z + D)/(pow(op_vector.x, 2) + pow(op_vector.y, 2) + pow(op_vector.z, 2));

        return t;
    }

Point Edge::Find_Projection(Point M)
{

    double t = Found_t(M);
    Point projection(start.x + op_vector.x*t, start.y + op_vector.y*t, start.z + op_vector.z*t );

    return projection;
}

Point Edge::Find_Closets_Point(Point M)
{    
    Vector AM(M.x - start.x, M.y - start.y, M.z - start.z);
    
    double t = AM.scal_prod_vec(op_vector) / op_vector.scal_prod_vec(op_vector);

    // Ограничиваем t, чтобы точка была на отрезке
    t = std::max(0.0, std::min(1.0, t));

    // Вычисляем ближайшую точку на отрезке
    Point closest_point(start.x + t*op_vector.x, start.y + t*op_vector.y, start.z + t*op_vector.z);

    return closest_point;
}


double Edge::Find_Segment_len(Point A, Point B)
{
    double len_sqr = pow(A.x - B.x, 2) + pow(A.y - B.y, 2) + pow(A.z - B.z, 2);
    return sqrt(len_sqr);
}

double Edge::Find_Closest_Dist(Point M)
{   
    Point closest_point = Find_Closets_Point(M);
    double closest_dist = Find_Segment_len(M, closest_point);

    return closest_dist;
}

bool Edge::Is_Point_On_Edge(Point point)
{   
    bool withinX = (point.x >= std::min(start.x, end.x) && point.x <= std::max(start.x, end.x));
    bool withinY = (point.y >= std::min(start.y, end.y) && point.y <= std::max(start.y, end.y));
    bool withinZ = (point.z >= std::min(start.z, end.z) && point.z <= std::max(start.z, end.z));

    return withinX && withinY && withinZ;
}
