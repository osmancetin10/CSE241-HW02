#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H


#include <iostream>
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include <fstream>

using namespace std;

class composedshape
{
    public:
        composedshape();

        double optimalfit(circle circle1,circle circle2);
        double optimalfit(circle circle1,rectangle rec2);
        double optimalfit(circle circle1,triangle tri2);
        double optimalfit(rectangle rec1,circle circle2);
        double optimalfit(rectangle rec1,rectangle rec2);
        double optimalfit(rectangle rec1,triangle tri2);
        double optimalfit(triangle tri1,circle circle2);
        double optimalfit(triangle tri1,rectangle rec2);
        double optimalfit(triangle tri1,triangle tri2);
		void draw(ofstream &file,double radius,double x,double y);
		void draw(ofstream &file,double width,double height,double x,double y);
		void draw(ofstream &file,double coor1_x,double coor1_y,double coor2_x,double coor3_x,double coor3_y);
		

    private:
};

#endif // COMPOSEDSHAPE_H
