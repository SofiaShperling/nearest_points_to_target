#include <iostream>
#include "Vector.h"

Vector::Vector(double x_n, double y_n, double z_n)
    {
        x = x_n;
        y = y_n;
        z = z_n;
    }

Vector::Vector()
{

}

double Vector::scal_prod_vec(Vector vec2) 
{
return x * vec2.x + y * vec2.y + z * vec2.z;
}
