#include <iostream>
#ifndef POINT_H
#define POINT_H


/**
* @class Point
* @brief Класс для представления точки в трёхмерном пространстве.
*
* Класс Point используется для хранения координат точки в трёхмерном пространстве.
*/
class Point 
{
public:
    double x; ///< Координата X точки
    double y; ///< Координата Y точки
    double z; ///< Координата Z точки

    /**
    * @brief Конструктор.
    *
    * Инициализирует точку с заданными координатами.
    * 
    * @param _x Координата X.
    * @param _y Координата Y.
    * @param _z Координата Z.
    * 
    * По умолчанию инициализирует точку с координатами (0, 0, 0).
    */
    Point(double x_n = 0.0, double y_n = 0.0, double z_n = 0.0);

    /**
    * @brief Выводит координаты точки.
    *
    * Печатает координаты точки в стандартный вывод в формате x = ..., y = ..., z = ...
    */
    void print() 
    {
        std::cout << "x: " << x << "\ty: " << y <<  "\tz: " << z << std::endl;
    };

};

#endif