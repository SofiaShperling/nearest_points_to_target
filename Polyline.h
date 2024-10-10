#include <vector>
#include "Point.h"
#include "Edge.h"
#ifndef POLYLINE_H
#define POLYLINE_H

/**
* @class Polyline
* @brief Класс для многоугольника в трёхмерном пространстве.
*
* Класс Edge используется для хранение вершин и рёбер многоугольника. Так же в этом классе хранится информация
* о целевой точке многоугольника.
*/
class Polyline
{
public:
    Point Target_Point; ///< Целевая точка
    std::vector<Point> vertices;  ///< Список вершин многоугольника
    std::vector<Edge> edges;  ///< Список рёбер 

    /**
    * @brief Функция считывания данных о многоугольнике.
    *
    * Считывает координаты вершин многоугольника, а так же координаты целевой точки.
    * Заполняет набор вершин и ребер многоугольника.
    * 
    * Данные в файле ожидается видеть в следующем виде. Сначала идет строка координат целевой точки. 
    * Потом на каждой строке записаны координаты вершины многоугольника. Координаты по оси x, y и z 
    * для каждой точки разделены пробелом.
    * 
    * @param _filename Имя файла.
    * 
    */
    void ReadPolylineFromFile ( std::string filename);

    /**
    * @brief Выводит координаты целевой точки.
    *
    * Печатает координаты целевой точки в формате: 
    * Target point x = ..., y = ..., z = ...
    */
    void print_target_point()
    {
        std::cout << "Target point \t";
        Target_Point.print();
    }

    /**
    * @brief Выводит вершины многоугольника.
    *
    * Печатает координаты вершин многоугольника в формате:
    * Vertice 0 x = ..., y = ..., z = ...
    * Vertice 1 x = ..., y = ..., z = ... и т.д.
    * 
    */
    void print_vertices()
    {

        for (size_t i = 0; i < vertices.size(); ++i) {
            std::cout << "Vertice "<< i <<" \t";
            vertices[i].print();
        }
    }

    /**
    * @brief Заполняет вектор ребер.
    *
    * Заполняет вектор ребер многоугольника используя векор вершин многоугольника.
    * 
    */
    void CreateEdges();

    /**
    * @brief Выводит ребра многоугольника.
    *
    * Печатает ребра многоугольника в формате:
    * Edge 0 Start x = ..., y = ..., z = ...
    * End x = ..., y = ..., z = ...
    * Edge 1 Start x = ..., y = ..., z = ...
    * End x = ..., y = ..., z = ... и т.д.
    * 
    */
    void print_edges()
    {

        for (size_t i = 0; i < edges.size(); ++i) {
            std::cout << "Edge "<< i <<" \t" << std::endl;
            edges[i].print();
        }
    }

    /**
    * @brief Находит расстояние от заданного ребра до целевой точки.
    *
    * 
    * @param _edge Интересующее ребро.
    * @return Расстояние.
    */
    double Find_Distance_To_Target(Edge edge);

    /**
    * @brief Находит набор ближайших точек многоугольника до целевой точки.
    *
    * @return Набор пар, где первый элемент пары -- индекс отрезка, на котором расположена точка, а второй -- точка.
    */
    std::vector<std::pair<int, Point>> Find_Nearest_Points_To_Target();

};

#endif