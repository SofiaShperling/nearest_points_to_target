#include <vector>
#include "Point.h"
#include "Polyline.h"
#include "Edge.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


void Polyline::ReadPolylineFromFile ( std::string filename)
{
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл");
    };

    double x, y, z;
    file >> x >> y >> z;
    Point t_point(x, y, z);
    Target_Point = t_point;
    while (file >> x >> y >> z) {
        Point point(x, y, z);
        vertices.emplace_back(point);
    }

    file.close();

    CreateEdges();
}

void Polyline::CreateEdges() 
{
    edges.clear();
    for (size_t i = 0; i < vertices.size() - 1; ++i) {
        Edge edge(vertices[i],  vertices[i + 1]);
        edges.emplace_back(edge);
    }
    edges.emplace_back(vertices.back(), vertices.front());
}

std::vector<std::pair<int, Point>> Polyline::Find_Nearest_Points_To_Target()
{   
    std::vector<std::pair<int, Point>> nearest_points_with_indexes;
    Point closest_point = edges[0].Find_Closets_Point(Target_Point);
    double closest_dist = edges[0].Find_Closest_Dist(Target_Point);
    double min_dist = closest_dist;
    nearest_points_with_indexes.clear();
    nearest_points_with_indexes.push_back({1, closest_point});

    for (size_t i = 1; i < edges.size(); ++i) 
    {
        Point closest_point = edges[i].Find_Closets_Point(Target_Point);
        double closest_dist = edges[i].Find_Closest_Dist(Target_Point);

        if (min_dist > closest_dist)
        {
            nearest_points_with_indexes.clear();
            nearest_points_with_indexes.push_back({i+1, closest_point});
            min_dist = closest_dist;
        }
        else if (min_dist == closest_dist)
        {
            nearest_points_with_indexes.push_back({i+1, closest_point});
        }
    }
    
    return nearest_points_with_indexes;
}

double Polyline::Find_Distance_To_Target(Edge edge)
{
    double closest_dist = edge.Find_Closest_Dist(Target_Point);
    Point closest_point = edge.Find_Closets_Point(Target_Point);

    return closest_dist;
}