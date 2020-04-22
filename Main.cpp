///PROIECT GRAFICA SCENA DE TRAFIC
/// STRATON BOGDAN și TURCULET PAULA GRUPA 353

#include<windows.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 600

double x_1 = -80.0, y_1 = 260.0, x_2 = -350.0, y_2 = 260, x_3 = 160.0, y_3 = -290.0;
int vehicleX = 30, vehicleY = 15, l;
double rotatie = -90.0;


void init(void)  // initializare fereastra de vizualizare
{
	
	glClearColor(0.26, 0.43, 0.26, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION); 
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT); 
	glClear(GL_COLOR_BUFFER_BIT); 

}

void deseneazaPunct(int x, int y)
{

	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void plotPuncte(int h, int k, int x, int y)
{
	deseneazaPunct(x + h, y + k);
	deseneazaPunct(-x + h, y + k);
	deseneazaPunct(x + h, -y + k);
	deseneazaPunct(-x + h, -y + k);
	deseneazaPunct(y + h, x + k);
	deseneazaPunct(-y + h, x + k);
	deseneazaPunct(y + h, -x + k);
	deseneazaPunct(-y + h, -x + k);
}

void deseneazaCercuri(int h, int k, int r)
{
	int d = 1 - r, x = 0, y = r;
	while (y > x)
	{
		plotPuncte(h, k, x, y);
		if (d < 0) d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			--y;
		}
		++x;
	}
	plotPuncte(h, k, x, y);
}

void sosea()
{
	{
		glClear(GL_COLOR_BUFFER_BIT); // Sosea principala
		glColor3f(0, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 250);
		glVertex2f(700, 250);
		glVertex2f(700, 350);
		glVertex2f(0, 350);
		glEnd();

		glColor3f(0, 0, 0); //Sosea jos stanga
		glBegin(GL_POLYGON);
		glVertex2f(100, 0);
		glVertex2f(100, 250);
		glVertex2f(200, 250);
		glVertex2f(200, 0);
		glEnd();

		glColor3f(0, 0, 0); // Sosea sus dreapta
		glBegin(GL_POLYGON);
		glVertex2f(500, 350);
		glVertex2f(600, 350);
		glVertex2f(600, 600);
		glVertex2f(500, 600);
		glEnd();


		glLineStipple(12, 0xAAAA); // Linie punctata sosea principala
		glLineWidth(5);
		glColor3f(1, 1, 1);
		glEnable(GL_LINE_STIPPLE);
		glBegin(GL_LINES);
		glVertex2f(0, 300);
		glVertex2f(700, 300);
		glEnd();


		glLineWidth(5); // Linie punctata sosea stanga
		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(150, 0);
		glVertex2f(150, 200);
		glEnd();

		glLineWidth(5); // Linie punctata sosea drepta
		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(550, 600);
		glVertex2f(550, 400);
		glEnd();



	}
}

void trecerePietoni(int x, int y)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 20, y);
	glVertex2f(x + 20, y + 40);
	glVertex2f(x + 30, y + 40);
	glVertex2f(x + 30, y);
	glEnd();
}


void casa()
{
	{
		glColor3f(0.8, 0.8, 0); //Casa 
		glBegin(GL_POLYGON);
		glVertex2f(120, 380);
		glVertex2f(250, 380);
		glVertex2f(250, 500);
		glVertex2f(120, 500);
		glEnd();

		glColor3f(0, 0, 0.97); //Geam stanga
		glBegin(GL_POLYGON);
		glVertex2f(135, 450);
		glVertex2f(155, 450);
		glVertex2f(155, 470);
		glVertex2f(135, 470);
		glEnd();

		glColor3f(0, 0, 0.97); //Geam dreapta
		glBegin(GL_POLYGON);
		glVertex2f(235, 450);
		glVertex2f(215, 450);
		glVertex2f(215, 470);
		glVertex2f(235, 470);
		glEnd();

		glColor3f(0.64, 0.16, 0.17); //Usa
		glBegin(GL_POLYGON);
		glVertex2f(170, 380);
		glVertex2f(170, 425);
		glVertex2f(200, 425);
		glVertex2f(200, 380);
		glEnd();

		glColor3f(0.64, 0.16, 0.17); //Acoperis
		glBegin(GL_TRIANGLES);
		glVertex2f(100, 500);
		glVertex2f(270, 500);
		glVertex2f(185, 570);
		glEnd();

	}
}

void copaci(int x, int y)
{
	{
		glColor3f(0.9, 0.2, 0.0); // Tulpina
		glBegin(GL_POLYGON);
		glVertex2f(x - 120, y);
		glVertex2f(x - 120, y + 70);
		glVertex2f(x - 105, y + 70);
		glVertex2f(x - 105, y);
		glEnd();

		for (l = 0; l <= 30; l++) // Frunzis
		{
			glColor3f(0.0, 0.5, 0.0);
			deseneazaCercuri(x - 130, y + 65, l);
			deseneazaCercuri(x - 90, y + 65, l);
		}

		for (l = 0; l <= 25; l++)
		{
			glColor3f(0.0, 0.5, 0.0);
			deseneazaCercuri(x - 120, y + 105, l);
			deseneazaCercuri(x - 100, y + 105, l);
		}

		for (l = 0; l <= 20; l++)
		{
			glColor3f(0.0, 0.5, 0.0);
			deseneazaCercuri(x - 110, y + 130, l);
		}
	}
}

void brazi(int x, int y)
{
	{
		glColor3f(0.9, 0.2, 0.0);// Tulpina
		glBegin(GL_POLYGON);
		glVertex2f(x + 20, y);
		glVertex2f(x + 20, y + 50);
		glVertex2f(x + 35, y + 50);
		glVertex2f(x + 35, y);

		glEnd();

		for (l = 0; l <= 30; l++) // Parte sus a copacilor
		{
			glColor3f(0.0, 0.7, 0.2);
			glBegin(GL_TRIANGLES);
			glVertex2f(x + 10 - l, y + 50 + l);
			glVertex2f(x + 22, y + 65 + l);
			glVertex2f(x + 45 + l, y + 50 + l);
			glEnd();
		}

	}
}




void masina1()
{
	{

		glPushMatrix();
		glTranslated(x_1, y_1, 0.0);

		glBegin(GL_POLYGON); // Corpul din mijloc
		glColor3f(1, 0, 0);
		glVertex2f(vehicleX - 15, vehicleY + 10);
		glColor3f(0, 1, 0);
		glVertex2f(vehicleX - 15, vehicleY - 10);
		glColor3f(0, 0, 1);
		glVertex2f(vehicleX + 15, vehicleY - 10);
		glColor3f(1, 0, 1);
		glVertex2f(vehicleX + 15, vehicleY + 10);
		glEnd();

		glBegin(GL_POLYGON);//Fata
		glColor3f(0, 0, 1);
		glVertex2f(vehicleX + 15, vehicleY + 10);
		glVertex2f(vehicleX + 30, vehicleY + 5);
		glVertex2f(vehicleX + 30, vehicleY - 5);
		glVertex2f(vehicleX + 15, vehicleY - 10);
		glEnd();

		glBegin(GL_POLYGON);//Spate
		glColor3f(0, 0, 1);
		glVertex2f(vehicleX - 15, vehicleY + 10);
		glVertex2f(vehicleX - 25, vehicleY + 5);
		glVertex2f(vehicleX - 25, vehicleY - 5);
		glVertex2f(vehicleX - 15, vehicleY - 10);
		glEnd();

		glPopMatrix();
	}
}

void masina2()
{
	{
		glColor3f(0.0, 0.0, 1.0);

		glPushMatrix();
		if (x_1 >= 0 && x_2 >= 0)
		{
			if (x_1 - x_2 <= 150) {
				if (y_2 <= 310)
					y_2 += 0.5;
				if (x_2 - x_1 >= 10 && y_2 > 260)
					y_2 -= 0.7;
				glTranslated(x_2, y_2, 0);
			}
		}
		else glTranslated(x_2, y_2, 0);

		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);//Corpul din mijloc
		glVertex2f(vehicleX - 15, vehicleY + 10);
		glVertex2f(vehicleX - 15, vehicleY - 10);
		glVertex2f(vehicleX + 15, vehicleY - 10);
		glVertex2f(vehicleX + 15, vehicleY + 10);
		glEnd();

		glBegin(GL_POLYGON);//Fata
		glColor3f(0, 0, 1);
		glVertex2f(vehicleX + 15, vehicleY + 10);
		glColor3f(0, 1, 0);
		glVertex2f(vehicleX + 30, vehicleY + 5);
		glColor3f(1, 0, 0);
		glVertex2f(vehicleX + 30, vehicleY - 5);
		glColor3f(1, 0, 1);
		glVertex2f(vehicleX + 15, vehicleY - 10);
		glEnd();

		glBegin(GL_POLYGON);//Spate
		glColor3f(0, 0, 1);
		glVertex2f(vehicleX - 15, vehicleY + 10);
		glColor3f(1, 0, 1);
		glVertex2f(vehicleX - 25, vehicleY + 5);
		glColor3f(1, 0, 0);
		glVertex2f(vehicleX - 25, vehicleY - 5);
		glColor3f(1, 1, 0);
		glVertex2f(vehicleX - 15, vehicleY - 10);
		glEnd();

		glPopMatrix();
	}
}

void masina3()
{
	
	
		glPushMatrix();

		glTranslated(x_3, y_3, 0.0);

		if (y_3 >= 280 && y_3 <= 350 and rotatie == -90) // Primul viraj la dreapta, care se realizeaza automat
		{
			glRotatef(rotatie, 0.0, 0.0, 1.0);
			x_3 += 0.4;
			y_3 -= 0.6;
		}

		if (x_3 >= 500 and x_3 <= 600 and rotatie == 0) //Viraj la stanga pe strada de sus, realizat cu apasarea tastei 's' 
		{
			
			glRotatef(rotatie, 0.0, 0.0, 1.0);
			y_3 += 0.6;
			
		}

		if (y_3 >= 400 and y_3 <= 460 and rotatie == 90)//Viraj in curte realizat cu apasarea tastei 's'
		{
				
			glRotatef(rotatie, 0.0, 0.0, 1.0);
			if(x_3 > 380)
				x_3 -= 0.6;
			y_3 -= 0.6;
		}


		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);//Corpul din mijloc
		glVertex2f(vehicleX - 25, vehicleY);
		glVertex2f(vehicleX - 25, vehicleY + 25);
		glVertex2f(vehicleX - 5, vehicleY + 25);
		glVertex2f(vehicleX - 5, vehicleY);
		glEnd();

		glBegin(GL_POLYGON);//Fata
		glColor3f(0, 0, 1);
		glVertex2f(vehicleX - 25, vehicleY + 25);
		glVertex2f(vehicleX - 20, vehicleY + 45);
		glVertex2f(vehicleX - 10, vehicleY + 45);
		glVertex2f(vehicleX - 5, vehicleY + 25);
		glEnd();

		glBegin(GL_POLYGON);//Spate
		glColor3f(0, 0, 1);
		glVertex2f(vehicleX - 25, vehicleY);
		glVertex2f(vehicleX - 20, vehicleY - 10);
		glVertex2f(vehicleX - 10, vehicleY - 10);
		glVertex2f(vehicleX - 5, vehicleY);
		glEnd();

		glPopMatrix();

	
}

void daleCurte(int x, int y)
{
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_POLYGON);
	glVertex2f(x , y);
	glVertex2f(x + 10, y);
	glVertex2f(x + 10, y + 5);
	glVertex2f(x , y + 5);
	glEnd();
}

void animatie(void)
{
	
	sosea();
	for (int i = 400; i <= 460; i += 6)
		for (l = 291; l + 11 <= 500; l += 11)
			daleCurte(l, i);
	for (int i = 85; i + 20 < 190; i = i + 20)
		trecerePietoni(i, 208), trecerePietoni(400 + i, 350);
	casa();
	for (int i = 400; i < 700; i = i + 70)
		copaci(i, 70);
	
	for (int i = 300; i < 450; i = i + 50)
		brazi(i, 490);
	masina1();
	masina2();
	masina3();
	
	glutSwapBuffers();
	glFlush();
}

void start(void)
{
	x_1 += 0.5; //viteza masina1
	x_2 += 1; // viteza masina2
	y_3 += 0.6;//viteza masina3
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(start);
		break;
	default:
		break;
	}
}

void taste(unsigned char tasta, int x, int y)
{
	if (tasta == 's' || tasta == 'S')
		rotatie += 90;
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowPosition(0, 0); 
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); 
	glutCreateWindow("Proiect 1"); 
	init();
	glutDisplayFunc(animatie); 
	glutMouseFunc(mouse);
	glutKeyboardFunc(taste);
	glutMainLoop(); 

}
