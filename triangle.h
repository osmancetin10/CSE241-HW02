#ifndef TRIANGLE_H
#define TRIANGLE_H

class triangle
{
    public:
        triangle();
        triangle(double x){
            setside(x);
        }

        void setside(double x);

        inline double getside(){ return side;}
        inline double getheight(){ return height;}
        inline double getcoor1_x(){ return coor1_x;}
        inline double getcoor1_y(){ return coor1_y;}
        inline double getcoor2_x(){ return coor2_x;}
        inline double getcoor3_x(){ return coor3_x;}
        inline double getcoor3_y(){ return coor3_y;}

    private:
        double side,height,coor1_x,coor1_y,coor2_x,coor3_x,coor3_y;
};

#endif // TRIANGLE_H
