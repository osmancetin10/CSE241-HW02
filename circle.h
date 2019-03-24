#ifndef CIRCLE_H
#define CIRCLE_H


class circle
{
    public:
        circle();
        circle(double x){
            setradius(x);
        }

        inline void setradius(double x){
            radius=x;
            coor_x=radius; coor_y=radius;
        }

        inline double getradius(){ return radius;}
        inline double getcoor_x(){ return radius;}
        inline double getcoor_y(){ return coor_y;}


    private:
        double radius,coor_x,coor_y;
};

#endif // CIRCLE_H
