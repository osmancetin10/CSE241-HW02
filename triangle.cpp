#include "triangle.h"
#include <cmath>


triangle::triangle(){
    setside(0);
}

void triangle::setside(double x){

    side=x;
    height=side*sqrt(3)/2;
    coor1_x=0; coor1_y=0;
    coor2_x=side;
    coor3_x=side/2; coor3_y=height;
}
