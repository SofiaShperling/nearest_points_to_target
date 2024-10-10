#include <iostream>
#include "Polyline.h"



int main()
{   

    Polyline polygon;
    polygon.ReadPolylineFromFile("test_data/polyline2.txt");
    std::vector<std::pair<int, Point>> nearest_points = polygon.Find_Nearest_Points_To_Target();

    for (auto it = nearest_points.begin(); it != nearest_points.end(); ++it) {
        const auto& current = *it;

        std::cout << "segment " << current.first << " point " << current.second.x << " " 
                << current.second.y << " " << current.second.z << std::endl;

        if (it != nearest_points.end() - 1){
            const auto& next = *(it + 1);
            if (current.second.x == next.second.x &&
                current.second.y == next.second.y &&
                current.second.z == next.second.z) {
                std::cout << "or" << std::endl;
            }
        }
    }

}