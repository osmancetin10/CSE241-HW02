                              /************************************************/
                              /*                                              */
                              /*                 Osman Çetin                  */
                              /*                  161044069                   */
                              /*                   CSE-241                    */
                              /*                     HW-2                     */
                              /*                                              */ 
                              /*                                              */
                              /************************************************/

/*This program calculates how much small shape fit into big shape with using mathematical calculations with class techniques. Firstly program asks to user big shape's type(rectangle,cirle,triangle), and type's datas. Secondly asks smallest shape's type and datas. Finally, prepairs output.svg file and calculation results.*/ 




#include <iostream>
#include "circle.h"
#include "triangle.h"/*these are our program's header and library declaration*/
#include "rectangle.h"
#include "composedshape.h"

using namespace std;

int main(){

    decltype(3.75) result;
	circle circle1,circle2;
	rectangle rec1,rec2;
	triangle tri1,tri2;
	composedshape work;

	
	/******************SAMPLE 1*************/
	//Rectangle in Rectangle example
	//Big rectangle's width=300, height=200
	//smallest rectangle's width=20, height=30
	
	rec1.setrectangle(300,200);
	rec2.setrectangle(20,30);
	result=work.optimalfit(rec1,rec2);

	cout << "(rectangle in rectangle)The empty area (red) in container is " << result << ".\n\n";/*this writes result on terminal*/
	
	
	/******************SAMPLE 2*************/
	//Rectangle in Circle example
	//Big circle's radius=250 
	//smallest rectangle's width=20, height=30
	
	circle1.setradius(250);
	rec2.setrectangle(20,30);
	result=work.optimalfit(circle1,rec2);

	cout << "(rectangle in circle)The empty area (red) in container is " << result << ".\n\n";/*this writes result on terminal*/
	
	
	/******************SAMPLE 3*************/
	//Rectangle in triangle example
	//Big triangle's lenght=300 
	//smallest rectangle's width=20, height=30
	
	tri1.setside(300);
	rec2.setrectangle(20,30);
	result=work.optimalfit(tri1,rec2);

	cout << "(rectangle in triangle)The empty area (red) in container is " << result << ".\n\n";/*this writes result on terminal*/
	
	
	/******************SAMPLE 4*************/
	//Circle in triangle example
	//Big triangle's lenght=600 
	//smallest circle's radius=30
	
	tri1.setside(600);
	circle2.setradius(15);
	result=work.optimalfit(tri1,circle2);

	cout << "(circle in triangle)The empty area (red) in container is " << result << ".\n\n";/*this writes result on terminal*/
	
	
	/******************SAMPLE 5*************/
	//Circle in rectangle example
	//Big rectangle's width=300 height=400 
	//smallest circle's radius=30
	
	rec1.setrectangle(300,400);
	circle2.setradius(15);
	result=work.optimalfit(rec1,circle2);

	cout << "(circle in rectangle)The empty area (red) in container is " << result << ".\n\n";/*this writes result on terminal*/
	
	
	/******************SAMPLE 6*************/
	//Circle in Circle example
	//Big circle's radius=600 
	//smallest circle's radius=30
	
	circle1.setradius(600);
	circle2.setradius(15);
	result=work.optimalfit(circle1,circle2);

	cout << "(circle in circle)The empty area (red) in container is " << result << ".\n\n";/*this writes result on terminal*/
	
	
	/******************SAMPLE 7*************/
	//Triangle in triangle example
	//Big triangle's length=350 
	//smallest triangle's length=30
	
	tri1.setside(350);
	tri2.setside(30);
	result=work.optimalfit(tri1,tri2);

	cout << "(triangle in triangle)The empty area (red) in container is " << result << ".\n\n";/*this writes result on terminal*/
	
	
	/******************SAMPLE 8*************/
	//Triangle in circle example
	//Big circle's radius=300 
	//smallest triangle's length=30
	
	circle1.setradius(630);
	tri2.setside(30);
	result=work.optimalfit(circle1,tri2);

	cout << "(triangle in circle)The empty area (red) in container is " << result << ".\n\n";/*this writes result on terminal*/
	
	
	/******************SAMPLE 9*************/
	//Triangle in Rectangle example
	//Big rectangle's width=300,height=250 
	//smallest triangle's length=30
	
	rec1.setrectangle(300,250);
	tri2.setside(30);
	result=work.optimalfit(rec1,tri2);

	cout << "(triangle in rectangle)The empty area (red) in container is " << result << ".\n\n";/*this writes result on terminal*/
	
	
	
	/*************************If you want to open to user access delete comment line**************/ 
	
	/*while(k==0){
		int k=0;
		char type1,type2;
		double width1,height1,width2,height2,radius1,radius2,side1,side2;
				
		cout << "Please enter the main container shape (R, C, T)\n";
		cin >> type1;

		if(type1 == 'R' || type1 == 'r' ){

			cout << "Please enter width:";
			cin >> width1;
			cout << "Please enter height:";
			cin >> height1;
			rec1.setrectangle(width1,height1);
			k++;
		}

		else if(type1 == 'C' || type1 == 'c'){

			cout << "Please enter the radius:";
			cin >> radius1;
			circle1.setradius(radius1);
			k++;
		}

		else if(type1 == 'T' || type1 == 't'){

			cout << "Please enter the lenght of the edge:";
			cin >> side1;
			tri1.setside(side1);
			k++;
		}

		else{
			cout << "False selection. ";
		}
	}

	k=0;

	while(k==0){
		cout << "Please enter the small shape (R, C, T)\n";
		cin >> type2;

		if(type2 == 'R' || type2 == 'r' ){

			cout << "Please enter width:";
			cin >> width2;
			cout << "Please enter height:";
			cin >> height2;
			rec2.setrectangle(width2,height2);
			k++;
		}

		else if(type2 == 'C' || type2 == 'c'){

			cout << "Please enter the radius:";
			cin >> radius2;
			circle2.setradius(radius2);
			k++;
		}

		else if(type2 == 'T' || type2 == 't'){

			cout << "Please enter the edge length:";
			cin >> side2;
			tri2.setside(side2);
			k++;
		}


		else{
			cout << "False selection. ";
		}
	}


	if( type1=='r' && type2=='c'){

		result=work.optimalfit(rec1,circle2);

	}

	else if( type1=='r' && type2=='r'){

		result=work.optimalfit(rec1,rec2);

	}

	else if( type1=='r' && type2=='t' ){

		result=work.optimalfit(rec1,tri2);

	}

	else if( type1=='c' && type2=='c'){

		result=work.optimalfit(circle1,circle2);

	}

	else if(type1=='t' && type2=='t'){

		result=work.optimalfit(tri1,tri2);

	}

	else if( type1=='t' && type2=='r'){

		result=work.optimalfit(tri1,rec2);

	}

	else if( type1=='t' && type2=='c'){

		result=work.optimalfit(tri1,circle2);

	}

	else if( type1=='c' && type2=='r' ){

		result=work.optimalfit(circle1,rec2);

	}

	else if( type1=='c' && type2=='t'){

		result=work.optimalfit(circle1,tri2);

	}

	cout << "The empty area (red) in container is " << result << ".\n";*/

    return 0;
}

