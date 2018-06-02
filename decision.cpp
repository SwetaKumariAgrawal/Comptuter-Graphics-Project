#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <GL/glx.h>
#include<GL/freeglut.h>    
#include <GL/gl.h>
#include <GL/glut.h>
#include<string.h>
#include<fstream>
#include<math.h>
#include<time.h>
int count=0,introc=0;
int survive=0;
void intro();
using namespace std;
void *font = GLUT_BITMAP_TIMES_ROMAN_24;
int gender=-1,pclass=-1,title=-1,pid=1500;//mr=0,mrs=2,miss=1
float age=0.0;
GLint a=0,b=0,c=0,d=0,e=0,f=0,g=500,h=600,x=0,i=0;
GLfloat theta=0.0;
GLfloat window_width,window_height;
void output(int x, int y, char *string)
{
  int len, i;
  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}

 struct timespec tim, tim2;

void ice();
void display1();
void display2();
void display3();
void ship();
void water();
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0,1.0,1.0,1.0);
	display1();
	if(a>650)

	{
		b+=10;
		display2();
	}
	if(b==180)
	{
		tim.tv_sec = 2;
	        tim.tv_nsec = 500000000L;
	        nanosleep(&tim , &tim2);
	}
	if(b>185)
	{

		c+=10;
		display3();

	}

	glFlush();
	glutSwapBuffers();
}
void update(int value)
{
   
	a+=7.0;
        display();
	glutTimerFunc(200,update,0);       
}
void display1()
{
	glPushMatrix();
	glTranslated(a,75,0.0);
	ship();
	glPopMatrix();
	water();
}

void display2()
{

	glClear(GL_COLOR_BUFFER_BIT);
	ice();
	glPushMatrix();
	glTranslated(b,75,0.0);
	ship();
	glPopMatrix();
	water();

}

void display3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	x-=1;
	ice();
	glPushMatrix();
	glTranslated(c,100+x*5,0.0);
	glRotated(-15,0,0,1);
	ship();
	glPopMatrix();
	water();
}

/* DRAW WATER */
void water()
{

	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(1000,0);
		glVertex2f(1000,70);
		glVertex2f(0,70);
	glEnd();
}

/* TO DRAW SHIP */
void ship()
{
        glScaled(5,5,0);
        glTranslated(0,-2,0);
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
		glVertex2f(3.5,5.5);
		glVertex2f(3.5,8.5);
		glVertex2f(19.5,8.5);
		glVertex2f(19.5,5.5);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1,5.5);
		glVertex2f(4,1);
		glVertex2f(19,1);
		glVertex2f(21.5,5.5);
	glEnd();
	glColor3f(0.7,0.4,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(4,5.5);
		glVertex2f(4,8);
		glVertex2f(5,8);
		glVertex2f(5,5.5);
	glEnd();
	glColor3f(0.9,0.9,0.9);
	glBegin(GL_POLYGON);
		glVertex2f(7,7.5);
		glVertex2f(7,8);
		glVertex2f(10,8);
		glVertex2f(10,7.5);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(11.5,7.5);
		glVertex2f(11.5,8);
		glVertex2f(15,8);
		glVertex2f(15,7.5);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(16,7.5);
		glVertex2f(16,8);
		glVertex2f(19,8);
		glVertex2f(19,7.5);
	glEnd();
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
		glVertex2f(4.5,8.5);
		glVertex2f(4.5,10);
		glVertex2f(18.5,10);
		glVertex2f(18.5,8.5);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(5.5,10);
		glVertex2f(5.5,12.9);
		glVertex2f(7,12.9);
		glVertex2f(7,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(5.5,12.9);
		glVertex2f(5.5,13.5);
		glVertex2f(7,13.5);
		glVertex2f(7,12.9);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(8.5,10);
		glVertex2f(8.5,12.9);
		glVertex2f(10,12.9);
		glVertex2f(10,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(8.5,12.9);
		glVertex2f(8.5,13.5);
		glVertex2f(10,13.5);
		glVertex2f(10,12.9);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(11.5,10);
		glVertex2f(11.5,12.9);
		glVertex2f(13,12.9);
		glVertex2f(13,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(11.5,12.9);
		glVertex2f(11.5,13.5);
		glVertex2f(13,13.5);
		glVertex2f(13,12.9);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(14.5,10);
		glVertex2f(14.5,12.9);
		glVertex2f(16,12.9);
		glVertex2f(16,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(14.5,12.9);
		glVertex2f(14.5,13.5);
		glVertex2f(16,13.5);
		glVertex2f(16,12.9);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(1.5,5.5);
		glVertex2f(1.5,6.5);
		glVertex2f(2,6.2);
		glVertex2f(3,6.2);
		glVertex2f(3.5,6.5);
		glVertex2f(3.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(3.5,5.5);
		glVertex2f(3.5,6.5);
		glVertex2f(4,6.2);
		glVertex2f(5,6.2);
		glVertex2f(5.5,6.5);
		glVertex2f(5.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(5.5,5.5);
		glVertex2f(5.5,6.5);
		glVertex2f(6,6.2);
		glVertex2f(7,6.2);
		glVertex2f(7.5,6.5);
		glVertex2f(7.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(7.5,5.5);
		glVertex2f(7.5,6.5);
		glVertex2f(8,6.2);
		glVertex2f(9,6.2);
		glVertex2f(9.5,6.5);
		glVertex2f(9.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(9.5,5.5);
		glVertex2f(9.5,6.5);
		glVertex2f(10,6.2);
		glVertex2f(11,6.2);
		glVertex2f(11.5,6.5);
		glVertex2f(11.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(11.5,5.5);
		glVertex2f(11.5,6.5);
		glVertex2f(12,6.2);
		glVertex2f(13,6.2);
		glVertex2f(13.5,6.5);
		glVertex2f(13.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(13.5,5.5);
		glVertex2f(13.5,6.5);
		glVertex2f(14,6.2);
		glVertex2f(15,6.2);
		glVertex2f(15.5,6.5);
		glVertex2f(15.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(15.5,5.5);
		glVertex2f(15.5,6.5);
		glVertex2f(16,6.2);
		glVertex2f(17,6.2);
		glVertex2f(17.5,6.5);
		glVertex2f(17.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(17.5,5.5);
		glVertex2f(17.5,6.5);
		glVertex2f(18,6.2);
		glVertex2f(19,6.2);
		glVertex2f(19.5,6.5);
		glVertex2f(19.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(19.5,5.5);
		glVertex2f(19.5,6.5);
		glVertex2f(20,6.2);
		glVertex2f(20.5,6.2);
		glVertex2f(21,6.5);
		glVertex2f(21,5.5);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(4.5,3.5);
		glVertex2f(4.5,4.5);
		glVertex2f(5.5,4.5);
		glVertex2f(5.5,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(7,3.5);
		glVertex2f(7,4.5);
		glVertex2f(8,4.5);
		glVertex2f(8,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(9.5,3.5);
		glVertex2f(9.5,4.5);
		glVertex2f(10.5,4.5);
		glVertex2f(10.5,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(12,3.5);
		glVertex2f(12,4.5);
		glVertex2f(13,4.5);
		glVertex2f(13,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(14.5,3.5);
		glVertex2f(14.5,4.5);
		glVertex2f(15.5,4.5);
		glVertex2f(15.5,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(17,3.5);
		glVertex2f(17,4.5);
		glVertex2f(18,4.5);
		glVertex2f(18,3.5);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(5,10);
		glVertex2f(5,11);
		glVertex2f(5.5,10.8);
		glVertex2f(6.5,10.8);
		glVertex2f(7,11);
		glVertex2f(7,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(7,10);
		glVertex2f(7,11);
		glVertex2f(7.5,10.8);
		glVertex2f(8.5,10.8);
		glVertex2f(9,11);
		glVertex2f(9,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(9,10);
		glVertex2f(9,11);
		glVertex2f(9.5,10.8);
		glVertex2f(10.5,10.8);
		glVertex2f(11,11);
		glVertex2f(11,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(11,10);
		glVertex2f(11,11);
		glVertex2f(11.5,10.8);
		glVertex2f(12.5,10.8);
		glVertex2f(13,11);
		glVertex2f(13,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(13,10);
		glVertex2f(13,11);
		glVertex2f(13.5,10.8);
		glVertex2f(14.5,10.8);
		glVertex2f(15,11);
		glVertex2f(15,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(15,10);
		glVertex2f(15,11);
		glVertex2f(15.5,10.8);
		glVertex2f(16.5,10.8);
		glVertex2f(17,11);
		glVertex2f(17,10);
	glEnd();
}

/* TO DRAW ICEBERG */
void ice()
{
	glPushMatrix();
	glTranslated(240,50,0.0);
	glScaled(4,4,0);
	glColor3f(0.0,1.0,1.0);
	if(c>0)
	{
	glPushMatrix();
	glTranslated(0,x,0);
	glPushMatrix();
	glTranslated(7,2,0.0);
	glRotated(-x,0,0,1);
	glTranslated(-7,-2,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(7,2);
	glVertex2f(8,3);
	glVertex2f(11,18);
	glVertex2f(12,19);
	glVertex2f(12,3);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(12,3,0.0);
	glRotated(x,0,0,1);
	glTranslated(-12,-3,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(12,3);
	glVertex2f(12,19);
	glVertex2f(17,18);
	glVertex2f(18,3);
	glVertex2f(19,3);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	}
	else
	{
	glBegin(GL_POLYGON);
	glVertex2f(7,2);
	glVertex2f(8,3);
	glVertex2f(11,18);
	glVertex2f(12,19);
	glVertex2f(12,3);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(12,3);
	glVertex2f(12,19);
	glVertex2f(17,18);
	glVertex2f(18,3);
	glVertex2f(19,3);
	glEnd();
	}
	glPopMatrix();
}
/*void man()
{
 glColor3f(1.0,1.0,0.0);
 glBegin(GL_POLYGON);
 glVertex2f(300,100);
 glVertex2f(300,150);
 glVertex2f(400,150);
 glVertex2f(400,100);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2f(320,155);
 glVertex2f(320,170);
 glVertex2f(380,170);
 glVertex2f(380,155);
 glEnd();
 glBegin(GL_LINES);
 glVertex2f(340,150);
 glVertex2f(340,155);
 glVertex2f(360,150);
 glVertex2f(360,155);
 glVertex2f(350,160);
 glVertex2f(350,165);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2f(345,170);
 glVertex2f(355,170);
 glVertex2f(355,180);
 glVertex2f(345,180);
 glEnd();
}*/
void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glLineWidth(5.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,150.0);
}
void result_load()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	output(80,85,"Your results are loading");
	glFlush();
}
void intro()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	if(introc<=1)
	output(70,85,"\"The TITANIC SURVIVOR\"");
	output(55,60,"presented by Shreya Sabu & Sweta Agrawal");
	output(55,35,"guided by Mrs. MONIKA RANI H.G");
	glFlush();
}
void display22(void)
{
  	glClearColor(1.0,1.0,1.0,1.0);
  	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,40);
	glVertex2f(300,40);
	glVertex2f(300,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0,50);
	glVertex2f(0,90);
	glVertex2f(300,90);
	glVertex2f(300,50);
	glEnd();
	glBegin(GL_POLYGON);
        glVertex2f(0,100);
        glVertex2f(0,140);
	glVertex2f(300,140);
	glVertex2f(300,100);
	glEnd();
	//age
	glColor3f(0.52,0.39,0.39);
	glBegin(GL_POLYGON);
        glVertex2f(50,5);
        glVertex2f(50,35);
	glVertex2f(80,35);
	glVertex2f(80,5);
	glEnd();
	glColor3f(0.309804,0.309804,0.184314);
	glBegin(GL_POLYGON);
        glVertex2f(90,5);
        glVertex2f(90,35);
	glVertex2f(120,35);
	glVertex2f(120,5);
	glEnd();
	glColor3f(0.196078,0.6,0.8);
	glBegin(GL_POLYGON);
        glVertex2f(130,5);
        glVertex2f(130,35);
	glVertex2f(160,35);
	glVertex2f(160,5);
	glEnd();
	//gender
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
        glVertex2f(66,85);
        glVertex2f(74,85);
	glVertex2f(74,75);
	glVertex2f(66,75);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(70,75);
	glVertex2f(70,71);
	glVertex2f(65,61);
	glVertex2f(65,56);
	glVertex2f(75,61);
	glVertex2f(75,56);
	glVertex2f(63,66);
	glVertex2f(60,63);
	glVertex2f(77,66);
	glVertex2f(74,63);
	glVertex2f(77,66);
	glVertex2f(80,62);
	glEnd();
	glBegin(GL_POLYGON);
        glVertex2f(63,71);
        glVertex2f(77,71);
	glVertex2f(77,61);
	glVertex2f(63,61);
	glEnd();
	//female
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_POLYGON);
        glVertex2f(120,85);
        glVertex2f(130,85);
	glVertex2f(130,75);
	glVertex2f(120,75);
	glEnd();
	glBegin(GL_TRIANGLES);
        glVertex2f(125,75);
        glVertex2f(110,65);
	glVertex2f(140,65);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(120,65);
	glVertex2f(120,55);
	glVertex2f(130,65);
	glVertex2f(130,55);
	glVertex2f(121,72);
	glVertex2f(110,70);
	glVertex2f(129,72);
	glVertex2f(140,70);
	glEnd();
	//pclass
	glColor3f(0.81,0.71,0.23);
	glBegin(GL_POLYGON);
        glVertex2f(50,105);
        glVertex2f(50,135);
	glVertex2f(80,135);
	glVertex2f(80,105);
	glEnd();
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_POLYGON);
        glVertex2f(90,105);
        glVertex2f(90,135);
	glVertex2f(120,135);
	glVertex2f(120,105);
	glEnd();
	glColor3f(0.55,0.47,0.14);
	glBegin(GL_POLYGON);
        glVertex2f(130,105);
        glVertex2f(130,135);
	glVertex2f(160,135);
	glVertex2f(160,105);
	glEnd();
	//text
	glColor3f(1.0,1.0,1.0);
	output(0, 20, "select age group");
	glColor3f(1.0,1.0,1.0);
	output(0, 70, "select gender");
        glColor3f(1.0,1.0,1.0);
	output(0, 120, "select passenger class");
	glColor3f(0.0,0.0,0.0);
	output(65,120,"1st");
	output(105,120,"2nd");
	output(145,120,"3rd");
	output(65,10,"1st");
	output(105,10,"2nd");
	output(145,10,"3rd");
	glFlush();
	
}
void displayd()
{	//dectree
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f );
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(80,120);
	glVertex2i(80,140);
	glVertex2i(100,140);
	glVertex2i(100,120);
	glEnd();
	glColor3f(0.0,0.0,1.0);
        output(85,110,"2nd");
        if(pclass==2)
        glColor3f(1.0,0.0,0.0);
	else
        glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(90,120);
	glVertex2i(90,100);
	glEnd();
	if(pclass==2)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(80,80);
	glVertex2i(80,100);
	glVertex2i(100,100);
	glVertex2i(100,80);
	glEnd();
	if(pclass==1)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(90,120);
	glVertex2i(50,100);
	glEnd();
        glColor3f(0.0,0.0,1.0);
        output(60,110,"1st");
	if(pclass==1)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(40,80);
	glVertex2i(40,100);
	glVertex2i(60,100);
	glVertex2i(60,80);
	glEnd();
	if(pclass==3)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(90,120);
	glVertex2i(130,100);
	glEnd();
	glColor3f(0.0,0.0,1.0);
        output(120,110,"3rd");
	if(pclass==3)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(120,80);
	glVertex2i(120,100);
	glVertex2i(140,100);
	glVertex2i(140,80);
	glEnd();
	if(gender==1 && pclass==1)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(50,80);
	glVertex2i(50,60);
	glEnd();
	 glColor3f(0.0,0.0,1.0);
	output(45,70,"f");
	if(gender==1 && pclass==1)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(45,50);
	glVertex2i(45,60);
	glVertex2i(55,60);
	glVertex2i(55,50);
	glEnd();
	if(gender==0 && pclass==1)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(50,80);
	glVertex2i(65,60);
	glEnd();
	 glColor3f(0.0,0.0,1.0);
	output(60,70,"m");
	if(gender==0 && pclass==1)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(60,50);
	glVertex2i(60,60);
	glVertex2i(69,60);
	glVertex2i(69,50);
	glEnd();
	if(gender==0 && pclass==2)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(90,80);
	glVertex2i(105,60);
	glEnd();
	 glColor3f(0.0,0.0,1.0);
	output(100,70,"m");
	if(gender==0 && pclass==2)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(100,60);
	glVertex2i(100,50);
	glVertex2i(109,50);
	glVertex2i(109,60);
	glEnd();
	if(gender==1 && pclass==2)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(90,80);
	glVertex2i(75,60);
	glEnd();
	 glColor3f(0.0,0.0,1.0);
	output(80,70,"f");
	if(gender==1 && pclass==2)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(71,50);
	glVertex2i(71,60);
	glVertex2i(80,60);
	glVertex2i(80,50);
	glEnd();
	if(gender==1 && pclass==3)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(130,80);
	glVertex2i(115,60);
	glEnd();
	 glColor3f(0.0,0.0,1.0);
	output(120,70,"f");
	if(gender==1 && pclass==3)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(110,60);
	glVertex2i(110,50);
	glVertex2i(120,50);
	glVertex2i(120,60);
	glEnd();
	if(gender==0 && pclass==3)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(130,80);
	glVertex2i(130,60);
	glEnd();
        glColor3f(0.0,0.0,1.0);
	output(132,70,"m");
	if(gender==0 && pclass==3)
        glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(125,60);
	glVertex2i(125,50);
	glVertex2i(135,50);
	glVertex2i(135,60);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glLineWidth(5.0);
	glBegin(GL_LINES);
	if(pclass==1 && gender==1 && age==2.0)
	{
         glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(50,50);
	glVertex2i(50,40);
	if(pclass==1 && gender==1 && age==1.0)
	{
        glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(50,50);
	glVertex2i(43,40);
	if(pclass==1 && gender==1 && age==3.0)
	{
          glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(50,50);
	glVertex2i(57,40);
	if(pclass==1 && gender==0 && age==2.0)
	{
         glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
        glVertex2i(65,50);
	glVertex2i(65,40);
	if(pclass==1 && gender==0 && age==1.0)
	{
         glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(65,50);
	glVertex2i(59,40);
	if(pclass==1 && gender==0 && age==3.0)
	{
	 glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(65,50);
	glVertex2i(70,40);
	if(pclass==2 && gender==1 && age==2.0)
	{
          glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(75,50);
	glVertex2i(75,40);
	if(pclass==2 && gender==1 && age==1.0)
	{
          glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(75,50);
	glVertex2i(71,40);
	if(pclass==2 && gender==1 && age==3.0)
	{
          glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(75,50);
	glVertex2i(82,40);
	if(pclass==2 && gender==0 && age==2.0)
	{
          glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(105,50);
	glVertex2i(105,40);
	if(pclass==2 && gender==0 && age==1.0)
	{
        glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(105,50);
	glVertex2i(98,40);
	if(pclass==2 && gender==0 && age==3.0)
	{
          glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(105,50);
	glVertex2i(109,40);
	if(pclass==3 && gender==1 && age==2.0)
	{
         glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(115,50);
	glVertex2i(115,40);
	if(pclass==3 && gender==1 && age==1.0)
	{
        glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(115,50);
	glVertex2i(110,40);
	if(pclass==3 && gender==1 && age==3.0)
	{
          glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(115,50);
	glVertex2i(122,40);
	if(pclass==3 && gender==0 && age==2.0)
	{
          glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(130,50);
	glVertex2i(130,40);
	if(pclass==3 && gender==0 && age==1.0)
	{
          glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(130,50);
	glVertex2i(125,40);
	if(pclass==3 && gender==0 && age==3.0)
	{
          glColor3f(1.0,0.0,0.0);
	if(survive==1)
	glColor3f(1.0,0.0,0.0);
	else
	glColor3f(0.0,0.0,1.0);
	}
	else
	glColor3f(0.0,0.0,0.0);
	glVertex2i(130,50);
	glVertex2i(140,40);
	glEnd();
	  glColor3f(1.0,1.0,1.0);
 	 output(85, 125, "pclass");
  	 glColor3f(1.0,1.0,1.0);
  	output(82, 85, "gender");
	 glColor3f(1.0,1.0,1.0);
  	output(42, 85, "gender");
        glColor3f(1.0,1.0,1.0);
  	output(122, 85, "gender");
        glColor3f(0.0,0.0,1.0);
	
         glColor3f(1.0,1.0,1.0);
 	 output(111, 55, "age");
  	 glColor3f(1.0,1.0,1.0);
  	output(72, 55, "age");
	 glColor3f(1.0,1.0,1.0);
  	output(101, 55, "age");
	  glColor3f(1.0,1.0,1.0);
 	 output(61, 55, "age");
  	 glColor3f(1.0,1.0,1.0);
  	output(46, 55, "age");
	 glColor3f(1.0,1.0,1.0);
  	output(126, 55, "age");
	glFlush();
//glutPostRedisplay();
}
void onMouse(int button, int state, int x, int y) {
  if(state != GLUT_DOWN)
    return;
  count++;
  window_width = glutGet(GLUT_WINDOW_WIDTH);
  window_height = glutGet(GLUT_WINDOW_HEIGHT);
  GLbyte color[4];
  char survive[2];
  GLbyte fpink=0xff,mblue=0x00;
  GLbyte pclass1=0xcf,pclass2=0xe5,pclass3=0x8c;
  GLbyte age1=0x85,age2=0x4f,age3=0x32;
  glReadPixels(x, window_height - y - 1, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE,color);
  //csv
   if(count>=2 && count <=4)
   {
    if(fpink==color[0])
  gender=1;
  if(color[0]==pclass1)
  pclass=1;
  if(color[0]==pclass2)
  pclass=2;
  if(color[0]==pclass3)
  pclass=3;
   if(color[0]==age1)
  age=1.0;
  if(color[0]==age2)
  age=2.0;
  if(color[0]==age3)
  age=3.0;
  if(color[0]==mblue)
  gender=0;
  if(age==1 && gender==1)
  title=1;
  if(age==1 && gender==0)
  title=0;
  if(age==2 && gender==1)
  title=2;
   if(age==2 && gender==0)
  title=0;
   if(age==3 && gender==1)
  title=2;
    if(age==3 && gender==0)
  title=0;
  }
  //read
  /*ifstream rfile;
  rfile.open("random.txt");
  rfile.read(survive,1);
  cout<<survive[0]<<"\n";
  rfile.close();*/
  if(count==1)
  display22();
  if(count==4)
  {
   ofstream file;
  file.open("random.csv");
  file<<pid<<","<<pclass<<","<<gender<<","<<age<<","<<title;
  file.close();
  result_load();
  ifstream rfile;
  rfile.open("/home/sweta/result.txt");
  rfile.read(survive,1)	;
  rfile.close();
  }
  if(count==5)
  {
  displayd();
  }
  if(count>=6)
  {
    glScalef(0.6,0.6,0.0);
  glutTimerFunc(100,update,0);
  }
  printf("Clicked on pixel %d, %d, color %02hhx%02hhx%02hhx%02hhx"
        , x, y, color[0], color[1], color[2], color[3]);
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800,800);
    glutCreateWindow("An Example OpenGL....");
    glLineWidth(5.0);
      init();
     glutMouseFunc(onMouse);
     glutDisplayFunc(intro); 
    //glutTimerFunc(100,update,0);
     glutMainLoop();
    return 0;
 }

