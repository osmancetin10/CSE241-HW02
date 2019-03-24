#include "composedshape.h"
#include <iostream>
#include <cmath>
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include <fstream>
#include<vector>

/*This C++ file includes all functions codes which will use in program*/


using namespace std;
const double PI = 3.14;

composedshape::composedshape()
{
    //ctor
}

double composedshape::optimalfit(circle circle1,circle circle2){/*this function calculates how much small circle fits into big circle with using circle's equation, and returns residual area*/
	
	auto counter=0;
	int i,k=0;
	double radius1=circle1.getradius(),radius2=circle2.getradius(),cur_x,cur_y=radius1-radius2,point;
	ofstream file;
	file.open("circle_circle.svg");

	file <<	"<svg version=\"1.1\"\n"
		 << "baseProfile=\"full\"\n"
		 << "width=\"" << radius1*2 << "\" height=\"" << radius1*2 << "\"\n"
		 << "xmlns=\"http://www.w3.org/2000/svg\">\n"
		 << "<circle cx=\"" << radius1 << "\" cy=\"" << radius1 << "\" r=\"" << radius1 << "\" fill=\"red\" />\n";

	cur_x=0; cur_y=radius2;

	for(i=1;i<=radius1/radius2;i++){

		k=0;
		for(cur_x=0;k==0;cur_x++){

			point=(cur_x-radius1)*(cur_x-radius1)+(cur_y-radius1)*(cur_y-radius1);
			if(point<=radius1*radius1){
				point=(cur_x+radius2-radius1)*(cur_x+radius2-radius1)+(cur_y-radius2-radius1)*(cur_y-radius2-radius1);
				if(point<=radius1*radius1){
					point=(cur_x+radius2-radius2/sqrt(2)-radius1)*(cur_x+radius2-radius1)+(cur_y+radius2/sqrt(2)-radius1)*(cur_y+radius2/sqrt(2)-radius1);
					if(point<=radius1*radius1){
						
						draw(file,radius2,cur_x,cur_y);
						cur_x+=2*radius2-1;
						counter++;
					}
				}
			}

			if(cur_x>2*radius1){
				cur_x=0;
				cur_y+=2*radius2;
				k++;
			}
		}
	}

	
	file << "</svg>";
	file.close();
	cout << "I can fit at most " << counter << " small shapes into the main container.\n";
	
	return PI*radius1*radius1-counter*PI*radius2*radius2;
}
double composedshape::optimalfit(circle circle1,rectangle rec2){/*this functon calculates how much small rectangles fits into big circle and returns residual area*/

	int i,j,k=0,l=0,counter=0;
	double radius1=circle1.getradius(),height2=rec2.getheight(),width2=rec2.getwidth(),line,cur_x,cur_y,res_len,temp_x,sur,point;

	ofstream file;
	file.open("circle_rec.svg");

	file <<	"<svg version=\"1.1\"\n"
		 << "baseProfile=\"full\"\n"
		 << "width=\"" << radius1*2 << "\" height=\"" << radius1*2 << "\"\n"
		 << "xmlns=\"http://www.w3.org/2000/svg\">\n"
		 << "<circle cx=\"" << radius1 << "\" cy=\"" << radius1 << "\" r=\"" << radius1 << "\" fill=\"red\" />\n";

	res_len=radius1-sqrt(radius1*radius1-height2*height2);
	line=2*radius1-2*res_len;
	cur_x=res_len;
	cur_y=radius1-height2;
	temp_x=res_len;

	for(i=1;i<=radius1/height2;i++){

		for(j=1;j<=line/width2;j++){

			if((cur_x-radius1)*(cur_x-radius1)+(cur_y-radius1)*(cur_y-radius1)<=radius1*radius1){
				
				draw(file,width2,height2,cur_x,cur_y);
				cur_x+=width2;
				counter++;
			}
		}
		k=0;
		cur_y-=height2;
		if(cur_y-height2<0) k++;
		while(k==0){
			temp_x+=1;
			point=(temp_x-radius1)*(temp_x-radius1)+(cur_y-radius1)*(cur_y-radius1);
			if(point<=radius1*radius1){
				sur=temp_x-res_len;
				k++;
			}
		}
		line-=2*sur;
		res_len+=sur;
		cur_x=temp_x;

	}

	res_len=radius1-sqrt(radius1*radius1-height2*height2);
	line=2*radius1-2*res_len;
	cur_x=res_len;
	cur_y=radius1-height2;
	temp_x=res_len;

	for(i=1;i<=(radius1)/height2;i++){

		for(j=1;j<=line/width2;j++){

			draw(file,width2,height2,cur_x,cur_y);
			cur_x+=width2;
			counter++;
		}
		l=0;
		cur_y+=height2;
		if(cur_y+height2>2*radius1) l++;
		while(l==0){
			temp_x+=1;
			point=(temp_x-radius1)*(temp_x-radius1)+(cur_y+height2-radius1)*(cur_y+height2-radius1);
			if(point<=radius1*radius1){
				sur=temp_x-res_len;
				l++;
			}
		}
		line-=2*sur;
		res_len+=sur;
		cur_x=temp_x;

	}

	file << "</svg>";
	file.close();

	cout << "I can fit at most " << counter << " small shapes into the main container.\n";

	return PI*radius1*radius1 - counter*height2*width2;
}

double composedshape::optimalfit(circle circle1,triangle tri2){/*this function calculates how much small triangles fits into big circle and returns residual area*/

	int i,j,k=0,counter=0;
	double radius1=circle1.getradius(),side2=tri2.getside(),line=2*radius1,res_len,sur,point,height2=side2*sqrt(3)/2,coor1_x=0,coor1_y=radius1,coor2_x=side2,coor3_x=side2/2,coor3_y=radius1-height2,temp1_x=0;

	ofstream file;
	file.open("circle_tri.svg");

	file <<	"<svg version=\"1.1\"\n"
		 << "baseProfile=\"full\"\n"
		 << "width=\"" << radius1*2 << "\" height=\"" << radius1*2 << "\"\n"
		 << "xmlns=\"http://www.w3.org/2000/svg\">\n"
		 << "<circle cx=\"" << radius1 << "\" cy=\"" << radius1 << "\" r=\"" << radius1 << "\" fill=\"red\" />\n";

	for(i=1;i<=radius1/height2;i++){

		for(j=1;j<=line/side2;j++){

			draw(file,coor1_x,coor1_y,coor2_x,coor3_x,coor3_y);

			if((coor3_x+side2-radius1)*(coor3_x+side2-radius1)+(coor3_y-radius1)*(coor3_y-radius1)<=radius1*radius1){
				
				draw(file,coor3_x,coor3_y,coor2_x,coor3_x+side2,coor3_y);				
				counter++;
			}

			coor1_x+=side2;
			coor2_x+=side2;
			coor3_x+=side2;
			counter++;

		}
		k=0;
		coor1_y-=height2;
		coor3_y-=height2;

		if(coor1_y-height2<0) k++;
		while(k==0){
			temp1_x+=1;
			point=(temp1_x-radius1)*(temp1_x-radius1)+(coor1_y-radius1)*(coor1_y-radius1);
			if(point<=radius1*radius1){
				point=(temp1_x+side2/2-radius1)*(temp1_x+side2/2-radius1)+(coor3_y-radius1)*(coor3_y-radius1);
				if(point<=radius1*radius1){
					sur=temp1_x-res_len;
					k++;
				}
			}
		}
		line-=2*sur;
		res_len+=sur;
		coor1_x=temp1_x;
		coor2_x=temp1_x+side2;
		coor3_x=temp1_x+side2/2;

	}

	coor1_x=0,coor1_y=radius1,coor2_x=side2,coor3_x=side2/2,coor3_y=radius1+height2,line=2*radius1,temp1_x=0,res_len=0;

	for(i=1;i<=radius1/height2;i++){

		for(j=1;j<=line/side2;j++){

			draw(file,coor1_x,coor1_y,coor2_x,coor3_x,coor3_y);

			if((coor3_x+side2-radius1)*(coor3_x+side2-radius1)+(coor3_y-radius1)*(coor3_y-radius1)<=radius1*radius1){
				
				draw(file,coor3_x,coor3_y,coor2_x,coor3_x+side2,coor3_y);
				counter++;
			}

			coor1_x+=side2;
			coor2_x+=side2;
			coor3_x+=side2;
			counter++;

		}
		k=0;
		coor1_y+=height2;
		coor3_y+=height2;

		if(coor1_y+height2>2*radius1) k++;
		while(k==0){
			temp1_x+=1;
			point=(temp1_x-radius1)*(temp1_x-radius1)+(coor1_y-radius1)*(coor1_y-radius1);
			if(point<=radius1*radius1){
				point=(temp1_x+side2/2-radius1)*(temp1_x+side2/2-radius1)+(coor3_y-radius1)*(coor3_y-radius1);
				if(point<=radius1*radius1){
					sur=temp1_x-res_len;
					k++;
				}
			}
		}
		line-=2*sur;
		res_len+=sur;
		coor1_x=temp1_x;
		coor2_x=temp1_x+side2;
		coor3_x=temp1_x+side2/2;

	}

	file << "</svg>";
	file.close();

	cout << "I can fit at most " << counter << " small shapes into the main container.\n";
	return PI*radius1*radius1 - counter*side2*side2*sqrt(3)/4;
}

double composedshape::optimalfit(rectangle rec1,circle circle2){/*this function calculates how much small circle fits into big rectangle, and returns residual area*/

	int i,j;
	double width1=rec1.getwidth(),height1=rec1.getheight(),radius2=circle2.getradius(),cur_x=radius2,cur_y=radius2;

	ofstream file;/*this open svg file*/
	file.open("rec_circle.svg");

	file <<	"<svg version=\"1.1\"\n"/*this draws biggest shape*/
		 << "baseProfile=\"full\"\n"
		 << "width=\"" << width1 << "\" height=\"" << height1 << "\"\n"
		 << "xmlns=\"http://www.w3.org/2000/svg\">\n"
		 << "<rect width=\"100%\" height=\"100%\" fill=\"red\" />\n";

	for(j=1;j<=(height1/(radius2*2));j++){/*this loop draws smallest shape*/

		for(i=1;i<=(width1/(radius2*2));i++){
			 
			 draw(file,radius2,cur_x,cur_y);
			 //file << "<circle cx=\"" << cur_x << "\" cy=\"" << cur_y <<"\" r=\"" << radius2 << "\" fill=\"green\" />\n";
			 cur_x += (radius2*2);
		}
		cur_x = radius2;
		cur_y += radius2*2;
	}

	file << "</svg>";
	file.close();
	i--; j--;

	cout << "I can fit at most " << i*j << " small shapes into the main container.\n";

	return (width1*height1) - (i*j*(PI*radius2*radius2));/*and returns resudial area*/

}
double composedshape::optimalfit(rectangle rec1,rectangle rec2){/*this function calculates how much small rectangle fits into big rectangle, and returns residual area*/

	int i,j,k,l,counter=0;
	double width1=rec1.getwidth(),height1=rec1.getheight(),width2=rec2.getwidth(),height2=rec2.getheight(),cur_x=0,cur_y=0;

	ofstream file;
	file.open("rec_rec.svg");

	file <<	"<svg version=\"1.1\"\n"
		 << "baseProfile=\"full\"\n"
		 << "width=\"" << width1 << "\" height=\"" << height1 << "\"\n"
		 << "xmlns=\"http://www.w3.org/2000/svg\">\n"
		 << "<rect width=\"100%\" height=\"100%\" fill=\"red\" />\n";

	for(i=1;i<=height1/height2;i++){

		for(j=1;j<=width1/width2;j++){
			
			draw(file,width2,height2,cur_x,cur_y);
			cur_x+=width2;
			counter++;
		}
		cur_x=0;
		cur_y+=height2;
	}
	j--;
	cur_y=0;
	cur_x=j*width2;
	for(k=1;k<=height1/width2;k++){/*if fits into deflectingly, it fits and draws*/

		for(l=1;l<=(width1-(j*width2))/height2;l++){
			
			draw(file,width2,height2,cur_x,cur_y);
			cur_x+=height2;
			counter++;
		}
		cur_x=j*width2;
		cur_y+=width2;
	}

	file << "</svg>";
	file.close();

	cout << "I can fit at most " << counter << " small shapes into the main container.\n";
	return (height1*width1)-counter*width2*height2;

}
double composedshape::optimalfit(rectangle rec1,triangle tri2){/*this function calculates how much small triangle fits into big rectangle, and returns residual area*/

	int i,j,counter=0;
	double width1=rec1.getwidth(),height1=rec1.getheight(),side2=tri2.getside(),coor1_x=0,coor1_y=0,coor2_x=side2,coor3_x=side2/2,coor3_y,height_tri=(side2*sqrt(3))/2;
	coor3_y=height_tri;

	ofstream file;
	file.open("rec_tri.svg");

	file <<	"<svg version=\"1.1\"\n"
		 << "baseProfile=\"full\"\n"
		 << "width=\"" << width1 << "\" height=\"" << height1 << "\"\n"
		 << "xmlns=\"http://www.w3.org/2000/svg\">\n"
		 << "<rect width=\"100%\" height=\"100%\" fill=\"red\" />\n";

	 for(i=1;i<=height1/height_tri;i++){


 		for(j=1;j<=width1/side2;j++){

 			draw(file,coor1_x,coor1_y,coor2_x,coor3_x,coor3_y);			
 			coor1_x+=side2;
 			coor2_x+=side2;
 			coor3_x+=side2;
 			counter++;
		}

		coor1_x=0; coor1_y+=height_tri; coor2_x=side2; coor3_x=side2/2; coor3_y+=height_tri;



	}

	coor1_x=side2/2,coor1_y=height_tri,coor2_x=side2/2+side2,coor3_x=side2,coor3_y=0;

	for(i=1;i<=height1/height_tri;i++){/*this loop adds triangle 180 degree deflectingly*/

		for(j=1;j<=width1/side2-1;j++){

			draw(file,coor1_x,coor1_y,coor2_x,coor3_x,coor3_y);
			coor1_x+=side2;
 			coor2_x+=side2;
 			coor3_x+=side2;
 			counter++;
		}

		coor1_x=side2/2; coor1_y+=height_tri; coor2_x=side2/2+side2; coor3_x=side2; coor3_y+=height_tri;
	}

	file << "</svg>";
	file.close();

	cout << "I can fit at most " << counter << " small shapes into the main container.\n";
	return (height1*width1)-counter*(side2*side2)*sqrt(3)/4;

}
double composedshape::optimalfit(triangle tri1,circle circle2){/*this functon calculates how much small circles fits into big triangle and returns residual area*/

	int i,j,counter=0;
	double side1=tri1.getside(),radius2=circle2.getradius(),height=side1*sqrt(3)/2,cur_x,cur_y=radius2,temp_x=radius2*sqrt(3),line=side1-2*radius2*sqrt(3);

	ofstream file;
	file.open("tri_circle.svg");

	file <<	"<svg version=\"1.1\"\n"
		 << "baseProfile=\"full\"\n"
		 << "xmlns=\"http://www.w3.org/2000/svg\">\n"
		 << "<polygon points=\"0,0 " << side1 << ",0 " << side1/2 << "," << height << "\" fill=\"red\"/>\n";

	for(i=1;i<=height/(2*radius2);i++){

		cur_x=temp_x;
		for(j=1;j<=line/(2*radius2)+1;j++){

			draw(file,radius2,cur_x,cur_y);
			cur_x+=2*radius2;
			counter++;
		}

		cur_y+=2*radius2;
		line-=((4*radius2)/sqrt(3));
		temp_x+=2*radius2/sqrt(3);
	}

	file << "</svg>";
	file.close();

	cout << "I can fit at most " << counter << " small shapes into the main container.\n";

	return (side1*side1)*sqrt(3)/4 - counter*PI*radius2*radius2;

}
double composedshape::optimalfit(triangle tri1,rectangle rec2){/*this function calculates how much small triangles fits into big triangle and returns residual area*/
	int i,j,counter=0;
	double side1=tri1.getside(),width2=rec2.getwidth(),height2=rec2.getheight(),height=side1*sqrt(3)/2,line=side1-(2*(height2/sqrt(3))),cur_x,cur_y=0,temp_x=height2/sqrt(3);

	ofstream file;
	file.open("tri_rec.svg");

	file <<	"<svg version=\"1.1\"\n"
		 << "baseProfile=\"full\"\n"
		 << "xmlns=\"http://www.w3.org/2000/svg\">\n"
		 << "<polygon points=\"0,0 " << side1 << ",0 " << side1/2 << "," << height << "\" fill=\"red\"/>\n";

	for(i=1;i<=height/height2;i++){

		cur_x=temp_x;
		for(j=1;j<=line/width2;j++){

			draw(file,width2,height2,cur_x,cur_y);
			cur_x+=width2;
			counter++;

		}
		temp_x+=height2/sqrt(3);
		line-=(2*height2/sqrt(3));
		cur_y+=height2;

	}

	file << "</svg>";
	file.close();

	cout << "I can fit at most " << counter << " small shapes into the main container.\n";

	return (side1*side1)*sqrt(3)/4 - counter*width2*height2;
}
double composedshape::optimalfit(triangle tri1,triangle tri2){/*this function calculates how much small triangles fits into big triangle and returns residual area*/

	int i,j,counter=0;
	double side1=tri1.getside(),side2=tri2.getside(),line=side1,height1=side1*sqrt(3)/2, height2=side2*sqrt(3)/2,coor1_x=0,coor1_y=0,coor2_x=side2,coor3_x=side2/2,coor3_y=height2,temp1_x=0;

	ofstream file;
	file.open("tri_tri.svg");

	file <<	"<svg version=\"1.1\"\n"
		 << "baseProfile=\"full\"\n"
		 << "xmlns=\"http://www.w3.org/2000/svg\">\n"
		 << "<polygon points=\"0,0 " << side1 << ",0 " << side1/2 << "," << height1 << "\" fill=\"red\"/>\n";

	for(i=1;i<=height1/height2;i++){

		coor1_x=temp1_x;
		coor2_x=temp1_x+side2;
		coor3_x=temp1_x+side2/2;
		for(j=1;j<=line/side2;j++){

			draw(file,coor1_x,coor1_y,coor2_x,coor3_x,coor3_y);
			coor1_x+=side2;
			coor2_x+=side2;
			coor3_x+=side2;
			counter++;
		}

		coor1_y+=height2;
		coor3_y+=height2;
		temp1_x+=side2/2;
		line-=side2;

	}

	line=side1-side2;
	temp1_x=side2/2;
	coor1_y=height2;
	coor3_y=0;

	for(i=1;i<=height1/height2;i++){

		coor1_x=temp1_x;
		coor2_x=temp1_x+side2;
		coor3_x=temp1_x+side2/2;
		for(j=1;j<=line/side2;j++){

			draw(file,coor1_x,coor1_y,coor2_x,coor3_x,coor3_y);
			coor1_x+=side2;
			coor2_x+=side2;
			coor3_x+=side2;
			counter++;
		}

		coor1_y+=height2;
		coor3_y+=height2;
		temp1_x+=side2/2;
		line-=side2;

	}

	file << "</svg>";
	file.close();

	cout << "I can fit at most " << counter << " small shapes into the main container.\n";

	return (side1*side1)*sqrt(3)/4 - counter*(side2*side2)*sqrt(3)/4;
}

void composedshape::draw(ofstream& file,double radius,double x,double y){/*this draws circle*/

	file<< "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"" << radius << "\" fill=\"green\" />\n";
}

void composedshape::draw(ofstream &file,double width,double height,double x,double y){/*draws rectangle*/

	file << "<rect x=\"" << x << "\" y=\"" << y <<"\"" << " width=\"" << width << "\" height=\"" << height << "\" fill=\"blue\" style=\"stroke:green\"/>\n";
}

void composedshape::draw(ofstream &file,double coor1_x,double coor1_y,double coor2_x,double coor3_x,double coor3_y){/*draws triangle*/

	file << "<polygon points=\"" << coor1_x << "," << coor1_y << " " << coor2_x << "," << coor1_y << " " << coor3_x << "," << coor3_y << "\" fill=\"purple\"/>\n";
}
