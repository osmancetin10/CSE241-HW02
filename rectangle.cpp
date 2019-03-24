#include "rectangle.h"

rectangle::rectangle(){
    setrectangle(0,0);
}

void rectangle::setrectangle(double x,double y){

    width=x; height=y;
    cur_x=0; cur_y=0;
}
