// Algoritma pembuat lingkaran

#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>

using namespace std;

//identifier fungsi
void init();
void display(void);
void lingkaran(void);

//  posisi window di layar
int window_x;
int window_y;

//  ukuran window
int window_width = 480;
int window_height = 480;

//  judul window
char *judul_window = "Algoritma Pembuat Lingkaran";

void main(int argc, char **argv)
{
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	// set posisi window supaya berada di tengah 
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
	glutInitWindowSize(window_width, window_height); //set ukuran window 
	glutInitWindowPosition(window_x, window_y); //set posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // set display RGB dan double buffer
	glutCreateWindow(judul_window);

	init(); // jalankan fungsi init
	glutDisplayFunc(display); // set fungsi display
	glutMainLoop(); // set loop pemrosesan GLUT
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //set warna background 
	glColor3f(1.0, 1.0, 1.0); //set warna titik
	glPointSize(3.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan 
	glLoadIdentity(); // load matriks identitas
	gluOrtho2D(0.0, 600.0, 0.0, 600.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	lingkaran(); //jalankan fungsi lingkaran
	glutSwapBuffers(); //swap buffer 
}

void lingkaran(void) {
	//tentukan titik pusat dan jari-jari
	int r = 150;
	int xc = 300, yc = 300;
	int p;
	int xling = 0, yling;
	int i;

	//hitung p awal dan set nilai awal untuk x dan y
	p = 1 - r;
	yling = r;

	glBegin(GL_POINTS);

	//perulangan untuk menggambar titik
	/*while (xling < yling) {
		if (p < 0)
		{

			xling += 1;
			yling;
			p = p + 2 * xling + 1;

		}

		else {
			xling += 1;
			yling -= 1;
			p = p + 2 * (xling - yling) + 1;

		}

		// translasi terhadap titik pusat dan cerminkan
		glVertex2i(xc + xling, yc + yling);
		glVertex2i(xc - xling, yc + yling);
		glVertex2i(xc + xling, yc - yling);
		glVertex2i(xc - xling, yc - yling);
		glVertex2i(xc + yling, yc + xling);
		glVertex2i(xc - yling, yc + xling);
		glVertex2i(xc + yling, yc - xling);
		glVertex2i(xc - yling, yc - xling);
	}
	*/
	
	for (i = xling; i < yling; i++){
	if (p < 0)
	{

	xling += 1;
	yling;
	p = p + 2 * xling + 1;

	}

	else {
	xling += 1;
	yling -= 1;
	p = p + 2 * (xling - yling) + 1;

	}
	glVertex2i(xc + xling, yc + yling);
	glVertex2i(xc - xling, yc + yling);
	glVertex2i(xc + xling, yc - yling);
	glVertex2i(xc - xling, yc - yling);
	glVertex2i(xc + yling, yc + xling);
	glVertex2i(xc - yling, yc + xling);
	glVertex2i(xc + yling, yc - xling);
	glVertex2i(xc - yling, yc - xling);
	}

	glEnd();
	glFlush();
}

