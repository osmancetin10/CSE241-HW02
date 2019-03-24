#ifndef RECTANGLE_H
#define RECTANGLE_H


class rectangle
{
    public:
        rectangle();
        void setrectangle(double x,double y);

        inline double getwidth(){ return width;}
        inline double getheight(){ return height;}
        inline double getcur_x(){ return cur_x;}
        inline double getcur_y(){ return cur_y;}

    private:
        double height,width,cur_x,cur_y;
};

#endif // RECTANGLE_H
