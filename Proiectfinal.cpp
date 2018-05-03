#include<gl/freeglut.h>
#include<iostream>
#include<math.h>
#include <GL/glut.h>
#include<mmsystem.h>
//#include "main.h"
#include "SOIL.h"
#define	imageWidth 64
#define	imageHeight 64
#ifndef CALLBACK
#define CALLBACK
#endif
GLubyte image[3 * imageWidth*imageHeight];
GLuint texture1;
GLuint texture2;
GLuint texture3;
GLuint texture4;
GLuint texture5;
GLuint texture6;
GLuint texture7;
GLuint texture8;
GLuint texture9;
GLuint texture10;
GLUquadricObj *qobj;
GLuint startList;
bool	active = TRUE;
using namespace std;
#define PI 3.14159265
static GLint fogMode;
static GLdouble theta;
// angle of rotation for the camera direction
float angle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f, ly = 0.1f;
// XZ position of the camera
float x = 0.0f, z = 5.0f, y = 5.5f;

static int leftFirst = GL_TRUE;
unsigned char* image1;
unsigned char* image2;
unsigned char* image3;
unsigned char* image4;
unsigned char* image5;
unsigned char* image6;
unsigned char* image7;
unsigned char* image8;
unsigned char* image9;
unsigned char* image10;
int width, height;

static void init(void)
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_FLAT);
	{
		GLfloat mat[3] = { 0.1745, 0.01175, 0.01175 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
		mat[0] = 0.61424; mat[1] = 0.04136; mat[2] = 0.04136;
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
		mat[0] = 0.727811; mat[1] = 0.626959; mat[2] = 0.626959;
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
		glMaterialf(GL_FRONT, GL_SHININESS, 0.6*128.0);
	}

	glEnable(GL_FOG);
	{
		GLfloat fogColor[4] = { 0.5, 0.5, 0.5, 0.3 };

		fogMode = GL_EXP;
		glFogi(GL_FOG_MODE, fogMode);
		glFogfv(GL_FOG_COLOR, fogColor);
		glFogf(GL_FOG_DENSITY, 0.02);
		glHint(GL_FOG_HINT, GL_DONT_CARE);
		glFogf(GL_FOG_START, 1.0);
		glFogf(GL_FOG_END, 5.0);
	}
	glClearColor(0.5, 0.5, 0.5, 0.01);  /* fog color */


	startList = glGenLists(5);

	qobj = gluNewQuadric();

	gluQuadricDrawStyle(qobj, GLU_FILL);
	/* flat shaded */

	gluQuadricNormals(qobj, GLU_FLAT);

	glNewList(startList + 1, GL_COMPILE);

	gluCylinder(qobj, 0.2, 0.3, 0.9, 15, 10);

	glEndList();

	gluQuadricDrawStyle(qobj, GLU_FILL);
	/* flat shaded */

	gluQuadricNormals(qobj, GLU_FLAT);

	glNewList(startList + 2, GL_COMPILE);

	gluCylinder(qobj, 0.2, 0.3, 0.9, 15, 10);

	glEndList();

	gluQuadricDrawStyle(qobj, GLU_FILL);
	/* flat shaded */

	gluQuadricNormals(qobj, GLU_FLAT);

	glNewList(startList + 3, GL_COMPILE);

	gluCylinder(qobj, 0.2, 0.3, 0.9, 15, 10);

	glEndList();

	gluQuadricDrawStyle(qobj, GLU_FILL);
	/* flat shaded */

	gluQuadricNormals(qobj, GLU_FLAT);

	glNewList(startList + 4, GL_COMPILE);

	gluCylinder(qobj, 0.2, 0.3, 0.9, 15, 10);

	glEndList();

	gluQuadricDrawStyle(qobj, GLU_FILL);
	/* flat shaded */

	gluQuadricNormals(qobj, GLU_FLAT);

	glNewList(startList + 5, GL_COMPILE);

	gluCylinder(qobj, 0.2, 0.3, 0.9, 15, 10);

	glEndList();
}

void CALLBACK errorCallback(GLenum errorCode)

{

	const GLubyte *estring;


	estring = gluErrorString(errorCode);

	fprintf(stderr, "Quadric Error: %s\n", estring);

	exit(0);

}

GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat no_mat1[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_ambient[] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat mat_ambient4[] = { 0.04f, 0.05f, 0.0f, 1.0 };
GLfloat mat_ambient_color[] = { 0.0, 0.5, 1.0, 1.0 };
GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_diffuse2[] = { 0.1, 0.8, 0.3, 1.0 };
GLfloat mat_diffuse3[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat mat_diffuse4[] = { 0.59, 0.41, 0.31, 0.7 };
GLfloat mat_diffuse5[] = { 0.258824, 0.435294, 0.258824, 0.6 };
GLfloat mat_diffuse6[] = { 0.309804, 0.184314, 0.184314, 0.8 };
GLfloat mat_specular[] = { 0.2, 0.5, 0.3, 1.0 };
GLfloat no_shininess[] = { 0.0 };
GLfloat low_shininess[] = { 5.0 };
GLfloat high_shininess[] = { 10.0 };
GLfloat mat_emission[] = { 0.9, 0.0, 0.2, 0.0 };
GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat position[] = { 0.0, 20.0, 20.0, 0.0 };
GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
GLfloat local_view[] = { 0.0 };
GLfloat mat_verde[] = { 0.0f, 0.3f, 0.0f,1.0 };
GLfloat mat_verde1[] = { 0.0f, 0.3f, 0.0f,1.0 };
GLfloat mat_maro[] = { 0.5f, 0.35f, 0.05f,1.0 };
GLfloat mat_maro3[] = { 0.5f, 0.35f, 0.05f,1.0 };
GLfloat mat_maro1[] = { 0.5f, 0.35f, 0.05f,1.0 };
GLfloat mat_maro2[] = { 0.5f, 0.35f, 0.05f,1.0 };
GLfloat mat_albastru[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat mat_rosu[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_albcue[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_roz[] = { 1.0, 0.0, 1.0, 1.0 };
GLfloat mat_gri[] = { 0.329412f, 0.329412f, 0.329412f,1.0 };


GLfloat texpts[2][2][2] = { { { 1.0, 1.0 },{ 1.0, 0.0 } },
{ { 0.0, 1.0 },{ 0.0, 0.0 } } };

float deltaAngle = 0.0f;
int xOrigin = -1;

void mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}



void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-2.5, 2.5, -2.5*(GLfloat)h / (GLfloat)w,
			2.5*(GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-2.5*(GLfloat)w / (GLfloat)h,
			2.5*(GLfloat)w / (GLfloat)h, -2.5, 2.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}






void LoadTexture1(void)
{

	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image1 = SOIL_load_image("Caramida.png", &width, &height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image1);
	// SOIL_free_image_data(image);
	// glBindTexture(GL_TEXTURE_2D, 0);
}

void LoadTexture2(void)
{

	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image2 = SOIL_load_image("PamantGri.png", &width, &height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image2);
	// SOIL_free_image_data(image);
	// glBindTexture(GL_TEXTURE_2D, 0);
}
void LoadTexture3(void)
{

	glGenTextures(1, &texture3);
	glBindTexture(GL_TEXTURE_2D, texture3);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	image3 = SOIL_load_image("LemnMasa.png", &width, &height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image3);
	// SOIL_free_image_data(image);
	// glBindTexture(GL_TEXTURE_2D, 0);
}
void LoadTexture4(void)
{

	glGenTextures(1, &texture4);
	glBindTexture(GL_TEXTURE_2D, texture4);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	image4 = SOIL_load_image("VerdeMasa.png", &width, &height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image4);
	// SOIL_free_image_data(image);
	// glBindTexture(GL_TEXTURE_2D, 0);
}

void LoadTexture5(void)
{

	glGenTextures(1, &texture5);
	glBindTexture(GL_TEXTURE_2D, texture5);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image5 = SOIL_load_image("Masa1.png", &width, &height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image5);
	// SOIL_free_image_data(image);
	// glBindTexture(GL_TEXTURE_2D, 0);
}

void LoadTexture6(void)
{

	glGenTextures(1, &texture6);
	glBindTexture(GL_TEXTURE_2D, texture6);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image6 = SOIL_load_image("PiciorMasa.png", &width, &height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image6);
	// SOIL_free_image_data(image);
	// glBindTexture(GL_TEXTURE_2D, 0);
}

void LoadTexture7(void)
{

	glGenTextures(1, &texture7);
	glBindTexture(GL_TEXTURE_2D, texture7);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image7 = SOIL_load_image("Covor.png", &width, &height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image7);
	// SOIL_free_image_data(image);
	// glBindTexture(GL_TEXTURE_2D, 0);
}

void LoadTexture8(void)
{

	glGenTextures(1, &texture8);
	glBindTexture(GL_TEXTURE_2D, texture8);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    // Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	image8 = SOIL_load_image("Chiuveta.png", &width, &height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image8);
	// SOIL_free_image_data(image);
	// glBindTexture(GL_TEXTURE_2D, 0);
}
void LoadTexture9(void)
{

	glGenTextures(1, &texture9);
	glBindTexture(GL_TEXTURE_2D, texture9);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    // Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	image9 = SOIL_load_image("chiuvetatextura.png", &width, &height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image9);
	// SOIL_free_image_data(image);
	// glBindTexture(GL_TEXTURE_2D, 0);
}
void LoadTexture10(void)
{

	glGenTextures(1, &texture10);
	glBindTexture(GL_TEXTURE_2D, texture10);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    // Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	image10 = SOIL_load_image("chiuvetalanga.png", &width, &height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image10);
	// SOIL_free_image_data(image);
	// glBindTexture(GL_TEXTURE_2D, 0);
}


enum {
	NONE, VERDE
};

int rendermode = NONE;

void menu(int selection)
{
	rendermode = selection;
	glutPostRedisplay();
}

void changeSize(int w, int h)
{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}
void mutarep(void)
{

	theta = theta + 0.7;
	glutPostRedisplay();

}
void mutarem(void)
{
	theta = (NULL);
	glutPostRedisplay();
}


/*static int leftFirst = GL_TRUE;

//Initialize alpha blending function.

static void init(void)
{
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glShadeModel(GL_FLAT);

}*/





void drawsticla1()
{
	glDisable(GL_TEXTURE_2D);
	glColor3f(1.0f, 1.0f, 0.0f);


	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse5);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse5);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-3.2f, 2.44f, 0.0f);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glutSolidCylinder(0.2, 0.3, 50, 50);
		glPopMatrix();
	}
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse5);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse5);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-3.2f, 2.74f, 0.0f);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glutSolidSphere(0.2, 50, 50);
		glPopMatrix();
	}
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse5);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse5);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-3.2f, 2.58f, 0.0f);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glutSolidCylinder(0.08, 0.8, 50, 50);
		glPopMatrix();
	}
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse5);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse5);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-3.2f, 2.87f, 0.0f);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glutSolidCone(0.15, 0.3, 50, 50);
		glPopMatrix();
	}
}



void drawsticla2()
{

	glColor3f(1.0f, 1.0f, 0.0f);


	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse4);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-3.2f, 2.50f, 0.0f);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glutSolidCylinder(0.27, 0.73, 15, 15);
		glPopMatrix();
	}
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse4);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-3.2f, 2.58f, 0.0f);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glutSolidCylinder(0.08, 1.1, 50, 50);
		glPopMatrix();
	}
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse4);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-3.2f, 3.30f, 0.0f);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glutSolidCone(0.25, 0.3, 50, 50);
		glPopMatrix();
	}
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse4);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-3.2f, 2.58f, 0.0f);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glutSolidCylinder(0.25, 0.73, 15, 15);
		glPopMatrix();
	}


}

void drawsticla3()
{

	glColor3f(1.0f, 1.0f, 0.0f);


	{
		glPushMatrix();
		glColor3f(0.0f, 0.0f, 0.0f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse6);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse6);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-3.2f, 1.94f, 0.0f);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glutSolidCylinder(0.2, 0.8, 50, 50);
		glPopMatrix();
	}
	{
		glPushMatrix();
		glColor3f(0.0f, 0.0f, 0.0f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse6);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse6);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-3.2f, 2.74f, 0.0f);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glutSolidSphere(0.2, 50, 50);
		glPopMatrix();
	}
	{
		glPushMatrix();
		glColor3f(0.0f, 0.0f, 0.0f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse6);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse6);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-3.2f, 2.58f, 0.0f);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glutSolidCylinder(0.08, 0.6, 50, 50);
		glPopMatrix();
	}
	{
		glPushMatrix();
		glColor3f(0.0f, 0.0f, 0.0f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse6);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse6);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-3.2f, 2.87f, 0.0f);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glutSolidCone(0.15, 0.3, 50, 50);
		glPopMatrix();
	}


}

void drawmasa1()
{
	glEnable(GL_TEXTURE_2D);


	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	// PICIOR 1
	glBindTexture(GL_TEXTURE_2D, texture6);
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.25f, 6.0f, -0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.25f, 6.0f, -0.25f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture6);
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.25f, 6.0f, -0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.25f, 6.0f, 0.25f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture6);
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.25f, 6.0f, 0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.25f, 6.0f, 0.25f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture6);
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.25f, 6.0f, -0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-0.25f, 6.0f, 0.25f);
	glEnd();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture5);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-3.0f, 0.2f, -3.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-3.0f, 0.0f, -3.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(3.0f, 0.0f, -3.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(3.0f, 0.2f, -3.0f);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture5);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-3.0f, 0.2f, 3.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-3.0f, 0.0f, 3.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(3.0f, 0.0f, 3.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(3.0f, 0.2f, 3.0f);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture5);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(3.0f, 0.2f, -3.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(3.0f, 0.0f, -3.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(3.0f, 0.0f, 3.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(3.0f, 0.2f, 3.0f);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture5);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-3.0f, 0.2f, -3.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-3.0f, 0.0f, -3.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-3.0f, 0.0f, 3.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-3.0f, 0.2f, 3.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture5);
	glTranslatef(0.0f, 6.2f, 0.0f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.0); glVertex3f(3.0f, 0.0f, -3.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(3.0f, 0.0f, 3.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-3.0f, 0.0f, 3.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-3.0f, 0.0f, -3.0f);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture5);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.0); glVertex3f(3.0f, 0.0f, -3.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(3.0f, 0.0f, 3.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-3.0f, 0.0f, 3.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-3.0f, 0.0f, -3.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture6);
	glTranslatef(0.0f, 2.03f, 0.0f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.5f, 0.0f, -1.5f);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.5f, 0.0f, 1.5f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.5f, 0.0f, 1.5f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.5f, 0.0f, -1.5f);
	glEnd();
	glPopMatrix();



	/*{
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	glutSolidCylinder(3.0, 0.2, 50, 50);
	glPopMatrix();
	}*/
}


//RAFT

void raftbarspate()
{
	glEnable(GL_TEXTURE_2D);

	//spate
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.0f, 0.0f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-5.0f, 1.4f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-5.0f, 1.4f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, 0.0f, -5.0f);
	glEnd();

	//podea
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.0f, 0.0f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-4.0f, 0.0f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-4.0f, 0.0f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, 0.0f, -5.0f);
	glEnd();

	//podea2
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.0f, -0.2f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-4.0f, -0.2f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-4.0f, -0.2f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, -0.2f, -5.0f);
	glEnd();

	//fata intre podea si podea2
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-4.0f, -0.2f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-4.0f, 0.0f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-4.0f, 0.0f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-4.0f, -0.2f, -5.0f);
	glEnd();

	//tavan
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.0f, 1.4f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-4.0f, 1.4f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-4.0f, 1.4f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, 1.4f, -5.0f);
	glEnd();

	//tavan2
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.0f, 1.6f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-4.0f, 1.6f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-4.0f, 1.6f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, 1.6f, -5.0f);
	glEnd();

	//fata intre tavan si tavan 2
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-4.0f, 1.4f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-4.0f, 1.6f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-4.0f, 1.6f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-4.0f, 1.4f, -5.0f);
	glEnd();

	//lateral1 sus
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-4.0f, 1.4f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-4.0f, 1.6f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-5.0f, 1.6f, 5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, 1.4f, 5.0f);
	glEnd();

	//lateral1 jos
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-4.0f, -0.2f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-4.0f, 0.0f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-5.0f, 0.0f, 5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, -0.2f, 5.0f);
	glEnd();

	//lateral2 sus
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-4.0f, 1.4f, -5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-4.0f, 1.6f, -5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-5.0f, 1.6f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, 1.4f, -5.0f);
	glEnd();

	//lateral2 jos
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-4.0f, -0.2f, -5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-4.0f, 0.0f, -5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-5.0f, 0.0f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, -0.2f, -5.0f);
	glEnd();

	//spate mare ca spatele lui johncena
	//lateral1
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.2f, -0.2f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-5.2f, 1.6f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-5.0f, 1.6f, 5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, -0.2f, 5.0f);
	glEnd();

	//lateral2
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.2f, -0.2f, -5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-5.2f, 1.6f, -5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-5.0f, 1.6f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, -0.2f, -5.0f);
	glEnd();

	//tavan
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.0f, 1.6f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-5.2f, 1.6f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-5.2f, 1.6f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, 1.6f, -5.0f);
	glEnd();

	//podea
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.0f, -0.2f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-5.2f, -0.2f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-5.2f, -0.2f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, -0.2f, -5.0f);
	glEnd();

	//spate
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro3);
	glBindTexture(GL_TEXTURE_2D, texture3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.2f, -0.2f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-5.2f, 1.6f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-5.2f, 1.6f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.2f, -0.2f, -5.0f);
	glEnd();

}


//CHIUVETA

void chiuveta()
{
	glEnable(GL_TEXTURE_2D);

	//podea chiuveta
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_gri);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_gri);
	glBindTexture(GL_TEXTURE_2D, texture9);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.0f, 0.0f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-3.5f, 0.0f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-3.5f, 0.0f, 3.5f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, 0.0f, 3.5f);
	glEnd();



	//gaura chiuveta
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_gri);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_gri);
	glBindTexture(GL_TEXTURE_2D, texture8);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-4.35f, 0.02f, 4.35f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-4.15f, 0.02f, 4.35f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-4.15f, 0.02f, 4.15f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-4.35f, 0.02f, 4.15f);
	glEnd();


	//lateral chiuveta
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_gri);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_gri);
	glBindTexture(GL_TEXTURE_2D, texture9);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.0f, 0.6f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-5.0f, 0.0f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-5.0f, 0.0f, 3.5f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, 0.6f, 3.5f);
	glEnd();

	//lateral chiuveta
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_gri);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_gri);
	glBindTexture(GL_TEXTURE_2D, texture9);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-3.5f, 0.6f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-3.5f, 0.0f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-3.5f, 0.0f, 3.5f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-3.5f, 0.6f, 3.5f);
	glEnd();

	//lateral chiuveta
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_gri);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_gri);
	glBindTexture(GL_TEXTURE_2D, texture9);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.0f, 0.6f, 3.5f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-5.0f, 0.0f, 3.5f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-3.5f, 0.0f, 3.5f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-3.5f, 0.6f, 3.5f);
	glEnd();

	//lateral chiuveta
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_gri);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_gri);
	glBindTexture(GL_TEXTURE_2D, texture9);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.0f, 0.6f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-5.0f, 0.0f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-3.5f, 0.0f, 5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-3.5f, 0.6f, 5.0f);
	glEnd();

	//margine chiuveta
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_gri);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_gri);
	glBindTexture(GL_TEXTURE_2D, texture9);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.0f, 0.6f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-2.0f, 0.6f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-2.0f, 0.6f, 5.2f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, 0.6f, 5.2f);
	glEnd();

	//margine chiuveta
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_gri);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_gri);
	glBindTexture(GL_TEXTURE_2D, texture9);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.0f, 0.6f, 3.5f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-2.0f, 0.6f, 3.5f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-2.0f, 0.6f, 3.3f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0f, 0.6f, 3.3f);
	glEnd();

	//margine chiuveta
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_gri);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_gri);
	glBindTexture(GL_TEXTURE_2D, texture9);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-5.2f, 0.6f, 5.2f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-5.0f, 0.6f, 5.2f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-5.0f, 0.6f, 3.3f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.2f, 0.6f, 3.3f);
	glEnd();

	//margine chiuveta
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_gri);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_gri);
	glBindTexture(GL_TEXTURE_2D, texture10);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(-3.5f, 0.6f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-2.0f, 0.6f, 5.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-2.0f, 0.6f, 3.5f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-3.5f, 0.6f, 3.5f);
	glEnd();

	//margine chiuveta
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_gri);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_gri);
	glBindTexture(GL_TEXTURE_2D, texture9);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(-2.0f, 0.6f, 5.2f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-1.8f, 0.6f, 5.2f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.8f, 0.6f, 3.3f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-2.0f, 0.6f, 3.3f);
	glEnd();



	glDisable(GL_TEXTURE_2D);
}


// MASA BILIARD
void masabiliard()
{
	glEnable(GL_TEXTURE_2D);

	//lungime 1
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(5.0f, 0.8f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(5.0f, 1.4f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(5.0f, 1.4f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(5.0f, 0.8f, -5.0f);
	glEnd();

	//lungime 2
	glBindTexture(GL_TEXTURE_2D, texture3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.0f, 0.8f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.0f, 1.4f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0f, 1.4f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0f, 0.8f, -5.0f);
	glEnd();

	//podea maro
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.0f, 0.8f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.0f, 0.8f, -5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(5.0f, 0.8f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(5.0f, 0.8f, 5.0f);
	glEnd();

	//latime 1
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.0f, 0.8f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.0f, 1.4f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(5.0f, 1.4f, 5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(5.0f, 0.8f, 5.0f);
	glEnd();

	//latime 2
	glBindTexture(GL_TEXTURE_2D, texture3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.0f, 0.8f, -5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.0f, 1.4f, -5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(5.0f, 1.4f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(5.0f, 0.8f, -5.0f);
	glEnd();

	//podea verde
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.0f, 1.1f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.0f, 1.1f, -5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(5.0f, 1.1f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(5.0f, 1.1f, 5.0f);
	glEnd();

	//margine maro latime 1
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.4f, 1.4f, 4.9f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.6f, 1.4f, 4.7f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.4f, 1.4f, 4.7f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.6f, 1.4f, 4.9f);
	glEnd();

	//margine maro latime 2
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.4f, 1.4f, -4.9f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.6f, 1.4f, -4.7f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.4f, 1.4f, -4.7f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.6f, 1.4f, -4.9f);
	glEnd();

	//margine maro lungime 11
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.1f, 1.4f, 4.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.3f, 1.4f, 4.4f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.3f, 1.4f, 0.20f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.1f, 1.4f, 0.15f);
	glEnd();


	//margine maro lungime 12
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.1f, 1.4f, -4.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.3f, 1.4f, -4.4f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.3f, 1.4f, -0.20f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.1f, 1.4f, -0.15f);
	glEnd();



	//margine maro lungime 2
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.9f, 1.4f, 4.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.7f, 1.4f, 4.4f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.7f, 1.4f, 0.20f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.9f, 1.4f, 0.15f);
	glEnd();

	//margine maro lungime 2
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.9f, 1.4f, -4.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.7f, 1.4f, -4.4f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.7f, 1.4f, -0.20f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.9f, 1.4f, -0.15f);
	glEnd();

	//margine verde latime 1
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.6f, 1.4f, 4.7f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.7f, 1.4f, 4.6f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.3f, 1.4f, 4.6f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.4f, 1.4f, 4.7f);
	glEnd();

	//margine verde latime 2
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.6f, 1.4f, -4.7f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.7f, 1.4f, -4.6f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.3f, 1.4f, -4.6f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.4f, 1.4f, -4.7f);
	glEnd();

	//margine verde lungime 11
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.3f, 1.4f, 4.4f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.4f, 1.4f, 4.3f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.4f, 1.4f, 0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.3f, 1.4f, 0.20f);
	glEnd();

	//margine verde lungime 11 jos
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.4f, 1.4f, 4.3f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.3f, 1.1f, 4.3f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.3f, 1.1f, 0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.4f, 1.4f, 0.25f);
	glEnd();

	//margine verde lungime 11 jos 1
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.4f, 1.4f, 4.3f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.3f, 1.1f, 4.3f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.2f, 1.1f, 4.4f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.3f, 1.4f, 4.4f);
	glEnd();

	//margine verde lungime 11 jos 2
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.4f, 1.4f, 0.25f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.3f, 1.1f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.2f, 1.1f, 0.20f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.3f, 1.4f, 0.20f);
	glEnd();

	//margine verde lungime 12
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.3f, 1.4f, -4.4f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.4f, 1.4f, -4.3f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.4f, 1.4f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.3f, 1.4f, -0.20f);
	glEnd();

	//margine verde lungime 12 jos
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.4f, 1.4f, -4.3f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.3f, 1.1f, -4.3f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.3f, 1.1f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.4f, 1.4f, -0.25f);
	glEnd();

	//margine verde lungime 12 jos 1
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.4f, 1.4f, -0.25f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.3f, 1.1f, -0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.2f, 1.1f, -0.20f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.3f, 1.4f, -0.20f);
	glEnd();

	//margine verde lungime 12 jos 2
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.4f, 1.4f, -4.3f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.3f, 1.1f, -4.3f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.2f, 1.1f, -4.4f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.3f, 1.4f, -4.4f);
	glEnd();

	//margine verde lungime 21
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.7f, 1.4f, 4.4f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.6f, 1.4f, 4.3f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.6f, 1.4f, 0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.7f, 1.4f, 0.20f);
	glEnd();

	//margine verde lungime 21 jos
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.6f, 1.4f, 4.3f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.7f, 1.1f, 4.3f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.7f, 1.1f, 0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.6f, 1.4f, 0.25f);
	glEnd();

	//margine verde lungime 21 jos 1
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.6f, 1.4f, 4.3f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.7f, 1.1f, 4.3f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.8f, 1.1f, 4.4f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.7f, 1.4f, 4.4f);
	glEnd();

	//margine verde lungime 21 jos 2
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.6f, 1.4f, 0.25f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.7f, 1.1f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.8f, 1.1f, 0.20f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.7f, 1.4f, 0.20f);
	glEnd();



	//margine verde lungime 22
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.7f, 1.4f, -4.4f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.6f, 1.4f, -4.3f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.6f, 1.4f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.7f, 1.4f, -0.20f);
	glEnd();

	//margine verde lungime 22 jos
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.6f, 1.4f, -4.3f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.7f, 1.1f, -4.3f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.7f, 1.1f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.6f, 1.4f, -0.25f);
	glEnd();

	//margine verde lungime 22 jos 1
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.6f, 1.4f, -0.25f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.7f, 1.1f, -0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.8f, 1.1f, -0.20f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.7f, 1.4f, -0.20f);
	glEnd();

	//margine verde lungime 22 jos 2
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.6f, 1.4f, -4.3f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.7f, 1.1f, -4.3f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.8f, 1.1f, -4.4f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.7f, 1.4f, -4.4f);
	glEnd();

	//margine maro latime 1.1
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro3);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 1.4f, 5.0f);
	glVertex3f(0.0f, 1.4f, 4.9f);
	glVertex3f(5.0f, 1.4f, 4.9f);
	glVertex3f(5.0f, 1.4f, 5.0f);
	glEnd();

	//margine maro latime 2.1
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.0f, 1.4f, -5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.0f, 1.4f, -4.9f);
	glTexCoord2f(0.0, 0.0); glVertex3f(5.0f, 1.4f, -4.9f);
	glTexCoord2f(0.0, 1.0); glVertex3f(5.0f, 1.4f, -5.0f);
	glEnd();

	//margine maro lungime 1.1
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.0f, 1.4f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.1f, 1.4f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.1f, 1.4f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0f, 1.4f, -5.0f);
	glEnd();

	//margine maro lungime 2.1
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.9f, 1.4f, 5.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(5.0f, 1.4f, 5.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(5.0f, 1.4f, -5.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.9f, 1.4f, -5.0f);
	glEnd();
	/*
	glPushMatrix();
	glTranslatef(0.3f, 1.1f, 4.7f);
	glRotatef(-90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, no_mat);
	glutSolidCylinder(0.25, 0.3, 15, 15);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glPopMatrix();
	*/
	//margine verde latime 1
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.7f, 1.4f, 4.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.7f, 1.1f, 4.7f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.3f, 1.1f, 4.7f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.3f, 1.4f, 4.6f);
	glEnd();
	//margine verde latime 1 1
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.7f, 1.4f, 4.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.7f, 1.1f, 4.7f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.6f, 1.1f, 4.8f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.6f, 1.4f, 4.7f);
	glEnd();

	//margine verde latime 1 2
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.3f, 1.4f, 4.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.3f, 1.1f, 4.7f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.4f, 1.1f, 4.8f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.4f, 1.4f, 4.7f);
	glEnd();


	//margine verde latime 2
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.7f, 1.4f, -4.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.7f, 1.1f, -4.7f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.3f, 1.1f, -4.7f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.3f, 1.4f, -4.6f);
	glEnd();

	//margine verde latime 2 1
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.7f, 1.4f, -4.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.7f, 1.1f, -4.7f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.6f, 1.1f, -4.8f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.6f, 1.4f, -4.7f);
	glEnd();

	//margine verde latime 2 2
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.3f, 1.4f, -4.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.3f, 1.1f, -4.7f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.4f, 1.1f, -4.8f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.4f, 1.4f, -4.7f);
	glEnd();

	//glDisable(GL_TEXTURE_2D);
	//gaura 1
	//glBindTexture(GL_TEXTURE_2D, texture5);
	glPushMatrix();
	glTranslatef(0.35f, 1.1f, 4.65f);
	glRotatef(-90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, no_mat);
	glutSolidCylinder(0.3, 0.01, 15, 15);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glPopMatrix();

	//glEnable(GL_TEXTURE_2D);
	//perete gaura 1
	//margine verde latime 1 1
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.1f, 1.4f, 4.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.3f, 1.4f, 4.4);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.2f, 1.1f, 4.4f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.1f, 1.1f, 4.6f);
	glEnd();

	//margine verde latime 1 2
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.4f, 1.4f, 4.9f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.6f, 1.4f, 4.7f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.6f, 1.1f, 4.8f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.4f, 1.1f, 4.9f);
	glEnd();

	//margine verde latime 1 3
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.4f, 1.4f, 4.9f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.4f, 1.1f, 4.9f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.1f, 1.1f, 4.6f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.1f, 1.4f, 4.6f);
	glEnd();

	//margine maro latime 1 4 sus
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.1f, 1.4f, 4.9f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.4f, 1.4f, 4.9);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.1f, 1.4f, 4.6f);
	glEnd();

	//perete gaura 2
	//margine maro latime 2 4 sus
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.9f, 1.4f, 4.9f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.6f, 1.4f, 4.9);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.9f, 1.4f, 4.6f);
	glEnd();

	//margine verde latime 2 3
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.6f, 1.4f, 4.9f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.6f, 1.1f, 4.9f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.9f, 1.1f, 4.6f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.9f, 1.4f, 4.6f);
	glEnd();

	//margine verde latime 2 2
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.6f, 1.4f, 4.9f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.4f, 1.4f, 4.7f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.4f, 1.1f, 4.8f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.6f, 1.1f, 4.9f);
	glEnd();

	//margine verde latime 2 1
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.9f, 1.4f, 4.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.7f, 1.4f, 4.4);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.8f, 1.1f, 4.4f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.9f, 1.1f, 4.6f);
	glEnd();

	//glDisable(GL_TEXTURE_2D);
	//gaura 2
	//glBindTexture(GL_TEXTURE_2D, texture5);
	glPushMatrix();
	glTranslatef(4.65f, 1.1f, 4.65f);
	glRotatef(-90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, no_mat);
	glutSolidCylinder(0.3, 0.01, 15, 15);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glPopMatrix();

	//gaura 3 centru
	//glBindTexture(GL_TEXTURE_2D, texture5);
	glPushMatrix();
	glTranslatef(0.23f, 1.1f, -0.0f);
	glRotatef(-90, 1, 0, 0);
	glScalef(0.7, 1, 1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, no_mat);
	glutSolidCylinder(0.25, 0.01, 15, 15);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glPopMatrix();


	//glEnable(GL_TEXTURE_2D);
	//margine verde latime 3 1
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.1f, 1.4f, 0.15f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.1f, 1.1f, 0.15f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.3f, 1.1f, 0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.3f, 1.4f, 0.20f);
	glEnd();

	//margine verde latime 3 2
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.1f, 1.4f, -0.15f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.1f, 1.1f, -0.15f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.3f, 1.1f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.3f, 1.4f, -0.20f);
	glEnd();

	//margine verde latime 3 3 sus
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.1f, 1.4f, 0.15f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.1f, 1.1f, 0.15f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.1f, 1.1f, -0.15f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.1f, 1.4f, -0.15f);
	glEnd();

	//glDisable(GL_TEXTURE_2D);

	//gaura 4 centru
	//glBindTexture(GL_TEXTURE_2D, texture5);
	glPushMatrix();
	glTranslatef(4.77f, 1.1f, -0.0f);
	glRotatef(-90, 1, 0, 0);
	glScalef(0.7, 1, 1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, no_mat);
	glutSolidCylinder(0.25, 0.01, 15, 15);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glPopMatrix();

	//glEnable(GL_TEXTURE_2D);

	//margine verde latime 4 1
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.9f, 1.4f, 0.15f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.9f, 1.1f, 0.15f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.7f, 1.1f, 0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.7f, 1.4f, 0.20f);
	glEnd();

	//margine verde latime 4 2
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.9f, 1.4f, -0.15f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.9f, 1.1f, -0.15f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.7f, 1.1f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.7f, 1.4f, -0.20f);
	glEnd();

	//margine verde latime 4 3 sus
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.9f, 1.4f, 0.15f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.9f, 1.1f, 0.15f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.9f, 1.1f, -0.15f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.9f, 1.4f, -0.15f);
	glEnd();

	//glDisable(GL_TEXTURE_2D);

	//gaura 5
	//glBindTexture(GL_TEXTURE_2D, texture5);
	glPushMatrix();
	glTranslatef(0.35f, 1.1f, -4.65f);
	glRotatef(-90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, no_mat);
	glutSolidCylinder(0.3, 0.01, 15, 15);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glPopMatrix();

	//glEnable(GL_TEXTURE_2D);

	//perete gaura 5
	//margine verde latime 5 1
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.1f, 1.4f, -4.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.3f, 1.4f, -4.4);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.2f, 1.1f, -4.4f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.1f, 1.1f, -4.6f);
	glEnd();

	//margine verde latime 5 2
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.4f, 1.4f, -4.9f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.6f, 1.4f, -4.7f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.6f, 1.1f, -4.8f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.4f, 1.1f, -4.9f);
	glEnd();

	//margine verde latime 5 3
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.4f, 1.4f, -4.9f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.4f, 1.1f, -4.9f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.1f, 1.1f, -4.6f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.1f, 1.4f, -4.6f);
	glEnd();

	//margine maro latime 5 4 sus
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.1f, 1.4f, -4.9f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.4f, 1.4f, -4.9);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.1f, 1.4f, -4.6f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture4);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, no_mat1);
	//glDisable(GL_TEXTURE_2D);

	//gaura 6
	//glBindTexture(GL_TEXTURE_2D, texture5);
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(4.65f, 1.1f, -4.65f);
	glRotatef(-90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, no_mat);
	glutSolidCylinder(0.3, 0.01, 15, 15);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glPopMatrix();

	//glEnable(GL_TEXTURE_2D);

	//perete gaura 6
	//margine verde latime 6 1
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.9f, 1.4f, -4.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.7f, 1.4f, -4.4);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.8f, 1.1f, -4.4f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.9f, 1.1f, -4.6f);
	glEnd();

	//margine verde latime 6 2
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.6f, 1.4f, -4.9f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.4f, 1.4f, -4.7f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.4f, 1.1f, -4.8f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.6f, 1.1f, -4.9f);
	glEnd();

	//margine verde latime 6 3
	glBindTexture(GL_TEXTURE_2D, texture4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_verde1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.6f, 1.4f, -4.9f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.6f, 1.1f, -4.9f);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.9f, 1.1f, -4.6f);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.9f, 1.4f, -4.6f);
	glEnd();

	//margine maro latime 6 4 sus
	glBindTexture(GL_TEXTURE_2D, texture3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_maro3);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.9f, 1.4f, -4.9f);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.6f, 1.4f, -4.9);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.9f, 1.4f, -4.6f);
	glEnd();

	// PICIOARE
	// PICIOR 1
	glPushMatrix();
	glTranslatef(1, -2, 4);
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.25f, 3.0f, -0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.25f, 3.0f, -0.25f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.25f, 3.0f, -0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.25f, 3.0f, 0.25f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.25f, 3.0f, 0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.25f, 3.0f, 0.25f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.25f, 3.0f, -0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-0.25f, 3.0f, 0.25f);
	glEnd();
	glPopMatrix();

	// PICIOR 2
	glPushMatrix();
	glTranslatef(4, -2, 4);
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.25f, 3.0f, -0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.25f, 3.0f, -0.25f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.25f, 3.0f, -0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.25f, 3.0f, 0.25f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.25f, 3.0f, 0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.25f, 3.0f, 0.25f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.25f, 3.0f, -0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-0.25f, 3.0f, 0.25f);
	glEnd();
	glPopMatrix();

	// PICIOR 3
	glPushMatrix();
	glTranslatef(1, -2, -4);
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.25f, 3.0f, -0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.25f, 3.0f, -0.25f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.25f, 3.0f, -0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.25f, 3.0f, 0.25f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.25f, 3.0f, 0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.25f, 3.0f, 0.25f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.25f, 3.0f, -0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-0.25f, 3.0f, 0.25f);
	glEnd();
	glPopMatrix();

	// PICIOR 4
	glPushMatrix();
	glTranslatef(4, -2, -4);
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.25f, 3.0f, -0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.25f, 3.0f, -0.25f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.25f, 3.0f, -0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.25f, 3.0f, 0.25f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.25f, 3.0f, 0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.25f, 3.0f, 0.25f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.25f, 3.0f, -0.25f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-0.25f, 3.0f, 0.25f);
	glEnd();
	glPopMatrix();






	glDisable(GL_TEXTURE_2D);
}


void bilabiliard()
{

	//albastra
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_rosu);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_rosu);
	glutSolidSphere(0.1, 50, 50);

	//rosu
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_rosu);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_rosu);
	glutSolidSphere(0.1, 50, 50);

}
void tac()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_maro);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_maro);
	glutSolidCylinder(0.05, 7, 20, 20);
}




void drawmasa(float xxx, float yyy, float zzz) {
	glPushMatrix();
	glTranslatef(10.0 + xxx, 0.0 + yyy, 5.0 + zzz);
	glPushMatrix();
	glTranslatef(5.6f + xxx, 1.7f + yyy, 0.0f + zzz);
	drawsticla1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7.6f + xxx, 1.7f + yyy, 0.0f + zzz);
	drawsticla2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.6f + xxx, 2.2f + yyy, 4.0f + zzz);
	drawsticla3();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.0 + xxx, -2.0 + yyy, 2.0 + zzz);
	drawmasa1();
	glPopMatrix();

	glPopMatrix();

}




void drawcopac2() {

	glColor3f(0.0f, 1.0f, 0.0f);

	//cap
	//glPushMatrix();
	//glColor3f(0.5f, 15.35f, 0.05f);
	/*
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glTranslatef(0.0f, 3.0f, 0.0f);
	//glutSolidRhombicDodecahedron();
	glutSolidSphere(1.0f, 10, 10);
	//glPopMatrix();
	glPopMatrix();
	*/

	//trunchi principal
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(0.0f, -1.5f, 0.0f);
		glutSolidSphere(1.2f, 12, 12);
		glRotatef(-90, 120.0f, 55.75f, 0.0f);
		glutSolidCylinder(0.4, 2.7, 50, 50);
		glPopMatrix();
	}

	//creanga dreapta 1
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-1.25f, 0.99f, 0.0f);
		glRotatef(-90, 120.0f, 234.0f, 0.0f);
		glutSolidCylinder(0.3, 2, 50, 50);
		glPopMatrix();
	}

	//creanga dreapta 1 partea 2
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-3.2f, 1.94f, 0.0f);
		glRotatef(-90, 120.0f, 42342.0f, 0.0f);
		glutSolidCylinder(0.2, 2, 50, 50);
		glPopMatrix();
	}

	//con baza
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(0.0f, -1.3f, 0.0f);
		glRotatef(-90, 120.0f, 55.75f, 0.0f);
		glutSolidCone(1, 2, 11, 11);
		glPopMatrix();
	}

	//con creanga dreapta 1 prelungire
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-3.03f, 1.9f, 0.0f);
		glRotatef(-90, 120.0f, 234.75f, 0.0f);
		glutSolidCone(0.3, 0.5, 15, 15);
		glPopMatrix();
	}

	//intersectie1
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-1.15f, 0.94f, 0.0f);
		glutSolidSphere(0.46f, 7, 7);
		//glRotatef(-90, 120.0f, 55.75f, 0.0f);
		//glutSolidCylinder(0.4, 2.5, 50, 50);
		glPopMatrix();
	}
	// Draw Head
	//glTranslatef(0.0f, 1.0f, 0.0f);
	//glutSolidSphere(0.25f, 20, 20);
	/*
	// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f, 10, 10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f, 10, 10);
	glPopMatrix();

	// Draw Nose
	glColor3f(1.0f, 0.5f, 0.5f);
	glutSolidCone(0.08f, 0.5f, 10, 2);
	*/

	//trunchi partea 2
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-1.15f, 0.94f, 0.0f);
		//glutSolidSphere(1.2f, 12, 12);
		glRotatef(230, 1.0f, 0.0f, 0.0f);
		glutSolidCylinder(0.27, 2.7, 50, 50);
		glPopMatrix();
	}
	//intersectie2
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-1.15f, 3.0f, -1.7f);
		glutSolidSphere(0.32f, 7, 7);
		//glRotatef(-90, 120.0f, 55.75f, 0.0f);
		//glutSolidCylinder(0.4, 2.5, 50, 50);
		glPopMatrix();
	}
	//creanga spate 1
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-1.15f, 3.0f, -1.7f);
		glRotatef(-90, 120.0f, -234.0f, 234.0f);
		glutSolidCylinder(0.25, 2.6, 50, 50);
		glPopMatrix();
	}
	//con creanga spate 1 prelungire
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-2.90f, 3.94f, -1.7f);
		glRotatef(-90, 120.0f, 23543.75f, -2323.0f);
		glutSolidSphere(0.24f, 7, 7);
		glutSolidCone(0.25, 1, 15, 15);
		glPopMatrix();
	}
	//creanga spate 1 prelungire 2
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-3.20f, 3.94f, -1.7f);
		glRotatef(-90, 1220.0f, 232344.0f, 20.0f);
		glutSolidCylinder(0.175, 1.6, 50, 50);
		glPopMatrix();
	}
	//creanga spate 2
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-1.15f, 3.0f, -1.7f);
		glRotatef(-90, 120.0f, 234.0f, 2.0f);
		glutSolidCylinder(0.255, 2, 50, 50);
		glPopMatrix();
	}
	//intersectie3
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(1.15f, 2.75f, -0.6f);
		glutSolidSphere(0.3f, 7, 7);
		//glRotatef(-90, 120.0f, 55.75f, 0.0f);
		//glutSolidCylinder(0.4, 2.5, 50, 50);
		glPopMatrix();
	}
	//creanga spate 1 prelungire 2
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(2.55f, 3.22f, 0.2f);
		glRotatef(120, 51.0f, -250.0f, 25.0f);
		glutSolidCylinder(0.175, 1.6, 50, 50);
		glPopMatrix();
	}
	//trunchi partea 2
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(0.15f, 2.4f, 1.7f);
		//glutSolidSphere(1.2f, 12, 12);
		glRotatef(-230, 2341.0f, -2340.0f, 0.0f);
		glutSolidCylinder(0.23, 2.7, 50, 50);
		glPopMatrix();
	}
	//intersectie2
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(0.15f, 2.4f, 1.7f);
		glutSolidSphere(0.26f, 7, 7);
		//glRotatef(-90, 120.0f, 55.75f, 0.0f);
		//glutSolidCylinder(0.4, 2.5, 50, 50);
		glPopMatrix();
	}
	//trunchi partea 2
	//trunchi partea 2
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-1.15f, 4.3f, -0.5f);
		//glutSolidSphere(1.2f, 12, 12);
		glRotatef(-230, 1.0f, 0.0f, 0.0f);
		glutSolidCylinder(0.19, 1.7, 50, 50);
		glPopMatrix();
	}

	//intersectiewhatever
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-1.15f, 4.3f, -0.5f);
		glutSolidSphere(0.21f, 7, 7);
		//glRotatef(-90, 120.0f, 55.75f, 0.0f);
		//glutSolidCylinder(0.4, 2.5, 50, 50);
		glPopMatrix();
	}
	//frunze
	{
		glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(1.0, 0.3, 0.5);
		glTranslatef(-1.15f, 14.3f, -1.8f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		//glutSolidRhombicDodecahedron();
		glutSolidSphere(1.56f, 10, 10);
		glPopMatrix();
	}
	//frunze
	{
		glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(1.0, 0.3, 0.5);
		glTranslatef(0.0f, 8.3f, 2.8f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		//glutSolidRhombicDodecahedron();
		glutSolidSphere(1.56f, 10, 10);
		glPopMatrix();
	}

	//intersectiewhatever
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-4.9f, 3.95f, -1.7f);
		glutSolidSphere(0.21f, 7, 7);
		//glRotatef(-90, 120.0f, 55.75f, 0.0f);
		//glutSolidCylinder(0.4, 2.5, 50, 50);
		glPopMatrix();
	}
	//frunze
	{
		glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(1.0, 0.3, 0.5);
		glTranslatef(-4.9f, 14.54f, -3.7f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		//glutSolidRhombicDodecahedron();
		glutSolidSphere(1.56f, 10, 10);
		glPopMatrix();
	}
	//frunze
	{
		glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(1.0, 0.3, 0.5);
		glTranslatef(-3.9f, 14.54f, -3.7f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		//glutSolidRhombicDodecahedron();
		glutSolidSphere(1.56f, 10, 10);
		glPopMatrix();
	}
	//intersectiewhatever
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(2.5f, 3.2f, 0.2f);
		glutSolidSphere(0.21f, 7, 7);
		//glRotatef(-90, 120.0f, 55.75f, 0.0f);
		//glutSolidCylinder(0.4, 2.5, 50, 50);
		glPopMatrix();
	}
	//intersectiewhatever
	{
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(-5.25f, 1.95f, 0.0f);
		glutSolidSphere(0.21f, 7, 7);
		//glRotatef(-90, 120.0f, 55.75f, 0.0f);
		//glutSolidCylinder(0.4, 2.5, 50, 50);
		glPopMatrix();
	}
	//frunze
	{
		glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(1.0, 0.3, 0.5);
		glTranslatef(2.5f, 11.20f, -0.3f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		//glutSolidRhombicDodecahedron();
		glutSolidSphere(1.56f, 10, 10);
		glPopMatrix();
	}
	//frunze
	{
		glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(1.0, 0.3, 0.5);
		glTranslatef(1.5f, 11.0f, -0.45f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		//glutSolidRhombicDodecahedron();
		glutSolidSphere(1.56f, 10, 10);
		glPopMatrix();
	}
	//frunze
	{
		glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(1.0, 0.3, 0.5);
		glTranslatef(-5.25f, 7.90f, 0.0f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		//glutSolidRhombicDodecahedron();
		glutSolidSphere(1.56f, 10, 10);
		glPopMatrix();
	}
	//frunze
	{
		glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(1.0, 0.3, 0.5);
		glTranslatef(-4.25f, 7.85f, 0.0f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		//glutSolidRhombicDodecahedron();
		glutSolidSphere(1.56f, 10, 10);
		glPopMatrix();
	}
}













void renderScene(void) {

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
	glTranslatef(0.1f, 1.0f, 0.0f);
	masabiliard();
	glTranslatef(0.0f, 0.0f, 0.0f);


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	/*glLoadIdentity();
	// Set the camera
	gluLookAt(x, 1.0f, z,
	x + lx, 1.0f, z + lz,
	0.0f, 1.0f, 0.0f);
	*/


	glLoadIdentity();
	// Set the camera
	gluLookAt(x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, y, 0.0f);




	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, no_mat1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse6);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, no_mat1);


	// PORNESTE TEXTURA PENTRU FUNDAL DE AICI. ATENTIE CALCULATORU POATE LUA FOC!!!
	glEnable(GL_TEXTURE_2D);




	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);



	glBindTexture(GL_TEXTURE_2D, texture1);


	/*//patrat 3
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(12.0, 12.0); glVertex3f(20.0f, 0.0f, 20.0f);
	glTexCoord2f(12.0, 0.0); glVertex3f(20.0f, 20.0f, 20.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-20.0f, 20.0f, 20.0f);
	glTexCoord2f(0.0, 12.0); glVertex3f(-20.0f, 0.0f, 20.0f);
	glEnd();*/
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, texture1);
	//patrat 1
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(12.0, 0.0); glVertex3f(-20.0f, 12.0f, -20.0f);
	glTexCoord2f(12.0, 12.0); glVertex3f(-20.0f, -8.0f, -20.0f);
	glTexCoord2f(0.0, 12.0); glVertex3f(20.0f, -8.0f, -20.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(20.0f, 12.0f, -20.0f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, texture1);
	//patrat 4
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(12.0, 0.0); glVertex3f(-20.0f, 12.0f, 20.0f);
	glTexCoord2f(12.0, 12.0); glVertex3f(-20.0f, -8.0f, 20.0f);
	glTexCoord2f(0.0, 12.0); glVertex3f(-20.0f, -8.0f, -20.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-20.0f, 12.0f, -20.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture1);
	//patrat 2
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(0.0, 12.0); glVertex3f(20.0f, -8.0f, 20.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(20.0f, 12.0f, 20.0f);
	glTexCoord2f(12.0, 0.0); glVertex3f(20.0f, 12.0f, -20.0f);
	glTexCoord2f(12.0, 12.0); glVertex3f(20.0f, -8.0f, -20.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture1);
	//tavan
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.4f, 0.6f);
	glTexCoord2f(14.0, 14.0); glVertex3f(20.0f, 12.0f, 20.0f);
	glTexCoord2f(0.0, 14.0); glVertex3f(-20.0f, 12.0f, 20.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-20.0f, 12.0f, -20.0f);
	glTexCoord2f(14.0, 0.0); glVertex3f(20.0f, 12.0f, -20.0f);

	glEnd();

	//textura enable


	/*	//TINTA
	glPointSize(5);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, no_mat);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(x + lx, 1.0f, z + lz);
	glVertex3f(x + lx, 1.02f, z + lz);
	glVertex3f(x + lx, 0.98f, z + lz);
	glVertex3f(x + lx, 1.0f, z + lz);
	glVertex3f(x + lx, 1.0f, z + lz);
	glEnd();
	*/

	// Draw ground
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	glBindTexture(GL_TEXTURE_2D, texture2);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-100.0f, 0.0f, -100.0f);
	glTexCoord2f(0.0, 10.0); glVertex3f(-100.0f, 0.0f, 100.0f);
	glTexCoord2f(10.0, 10.0); glVertex3f(100.0f, 0.0f, 100.0f);
	glTexCoord2f(10.0, 0.0); glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture7);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-17.0f, 0.02f, -17.0f);
	glTexCoord2f(0.0, 10.0); glVertex3f(-17.0f, 0.02f, 17.0f);
	glTexCoord2f(10.0, 10.0); glVertex3f(17.0f, 0.02f, 17.0f);
	glTexCoord2f(10.0, 0.0); glVertex3f(17.0f, 0.02f, -17.0f);
	glEnd();


	// Draw Bar Interior
	glBindTexture(GL_TEXTURE_2D, texture7);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-17.0f, 0.02f, -17.0f);
	glTexCoord2f(0.0, 10.0); glVertex3f(-17.0f, 0.02f, 17.0f);
	glTexCoord2f(10.0, 10.0); glVertex3f(17.0f, 0.02f, 17.0f);
	glTexCoord2f(10.0, 0.0); glVertex3f(17.0f, 0.02f, -17.0f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, texture3);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(-0.2f, 3.6f, -15.2f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-0.2f, 3.6f, -20.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.7f, 3.6f, -20.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.7f, 3.6f, -15.2f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(1.7f, 3.6f, -13.5f);
	glTexCoord2f(0.0, 4.0); glVertex3f(1.7f, 3.6f, -20.0f);
	glTexCoord2f(4.0, 4.0); glVertex3f(1.7f, 0.0f, -20.0f);
	glTexCoord2f(4.0, 0.0); glVertex3f(1.7f, 0.0f, -13.5f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture3);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(1.7f, 3.6f, -13.5f);
	glTexCoord2f(0.0, 1.0); glVertex3f(19.9999f, 3.6f, -13.5f);
	glTexCoord2f(1.0, 1.0); glVertex3f(19.9999f, 3.6f, -11.75f);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.7f, 3.6f, -11.75);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(1.7f, 3.6f, -13.5f);
	glTexCoord2f(0.0, 4.0); glVertex3f(18.19f, 3.6f, -13.5f);
	glTexCoord2f(4.0, 4.0); glVertex3f(18.19f, 0.0f, -13.5f);
	glTexCoord2f(4.0, 0.0); glVertex3f(1.7f, 0.0f, -13.5f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(18.19f, 3.6f, -13.5f);
	glTexCoord2f(0.0, 4.0); glVertex3f(18.19f, 3.6f, -11.79f);
	glTexCoord2f(4.0, 4.0); glVertex3f(18.19f, 0.0f, -11.79f);
	glTexCoord2f(4.0, 0.0); glVertex3f(18.19f, 0.0f, -13.5f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture3);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(18.1899f, 4.8f, -11.79f);
	glTexCoord2f(0.0, 1.0); glVertex3f(18.1899f, 4.8f, -11.79f);
	glTexCoord2f(1.0, 1.0); glVertex3f(18.1899f, 0.0f, -11.79f);
	glTexCoord2f(1.0, 0.0); glVertex3f(18.1899f, 0.0f, -11.79f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(19.9999f, 3.6f, -13.5f);
	glTexCoord2f(0.0, 4.0); glVertex3f(18.19f, 3.6f, -13.5f);
	glTexCoord2f(4.0, 4.0); glVertex3f(18.19f, 3.4f, -13.5f);
	glTexCoord2f(4.0, 0.0); glVertex3f(19.9999f, 3.4f, -13.5f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(19.9999f, 3.6f, -11.79f);
	glTexCoord2f(0.0, 4.0); glVertex3f(18.19f, 3.6f, -11.79f);
	glTexCoord2f(4.0, 4.0); glVertex3f(18.19f, 3.4f, -11.79f);
	glTexCoord2f(4.0, 0.0); glVertex3f(19.9999f, 3.4f, -11.79f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture3);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(19.9999f, 3.4f, -13.5f);
	glTexCoord2f(0.0, 4.0); glVertex3f(18.19f, 3.4f, -13.5f);
	glTexCoord2f(4.0, 4.0); glVertex3f(18.19f, 3.4f, -11.79f);
	glTexCoord2f(4.0, 0.0); glVertex3f(19.9999f, 3.4f, -11.79f);
	glEnd();


	// PAHAR 1
	glPushMatrix();
	glTranslatef(1.0, 4.8, -11.0);
	//glutSolidCylinder(0.2, 0.01, 15, 10);
	glRotatef(270.0, 1.0, 0.0, 0.0);

	glCallList(startList + 1);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0, 4.8, -11.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutSolidCylinder(0.2, 0.01, 15, 10);
	glPopMatrix();

	// PAHAR 2
	glPushMatrix();
	glTranslatef(12.0, 4.8, -11.0);
	//glutSolidCylinder(0.2, 0.01, 15, 10);
	glRotatef(270.0, 1.0, 0.0, 0.0);

	glCallList(startList + 2);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(12.0, 4.8, -11.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutSolidCylinder(0.2, 0.01, 15, 10);
	glPopMatrix();

	// PAHAR 3
	glPushMatrix();
	glTranslatef(3.2, 4.8, -11.0);
	//glutSolidCylinder(0.2, 0.01, 15, 10);
	glRotatef(270.0, 1.0, 0.0, 0.0);

	glCallList(startList + 3);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.2, 4.8, -11.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutSolidCylinder(0.2, 0.01, 15, 10);
	glPopMatrix();

	// PAHAR 4
	glPushMatrix();
	glTranslatef(17.0, 4.8, -11.0);
	//glutSolidCylinder(0.2, 0.01, 15, 10);
	glRotatef(270.0, 1.0, 0.0, 0.0);

	glCallList(startList + 4);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(17.0, 4.8, -11.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutSolidCylinder(0.2, 0.01, 15, 10);
	glPopMatrix();

	// PAHAR 5
	glPushMatrix();
	glTranslatef(6.4, 4.8, -11.0);
	//glutSolidCylinder(0.2, 0.01, 15, 10);
	glRotatef(270.0, 1.0, 0.0, 0.0);

	glCallList(startList + 5);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.4, 4.8, -11.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutSolidCylinder(0.2, 0.01, 15, 10);
	glPopMatrix();

	//glCallList(startList + 1);
	//S A TERMINAT PAHARU



	switch (rendermode) {

	case NONE:
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT_MODEL_AMBIENT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glColor3f(0.9f, 0.9f, 0.9f);
		glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, -100.0f);
		glEnd();



	}
	break;

	case VERDE:
	{glPushMatrix();
	//glTranslatef(0.0, 20.0, 20.0);
	//drawSun();

	/*glPushMatrix();
	glTranslatef(0.0, 1.0, 3.0);
	drawcopac2();
	glPopMatrix();*/

	drawmasa(2, 0, 0);
	drawmasa(-3, 0, 0);
	drawmasa(-3, 0, 5);
	drawmasa(2, 0, 5);


	//raft bar
	glPushMatrix();
	glTranslatef(14.99f, 11.09f, -19.39f);//aseaza pe perete
	glRotated(-90, 0, 1, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.0f, 11.09f, -19.39f);//aseaza pe perete
	glRotated(-90, 0, 1, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(14.99f, 9.29f, -19.39f);//aseaza pe perete
	glRotated(-90, 0, 1, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(5.0f, 9.29f, -19.39f);//aseaza pe perete
	glRotated(-90, 0, 1, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(14.99f, 7.49f, -19.39f);//aseaza pe perete
	glRotated(-90, 0, 1, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(5.0f, 7.49f, -19.39f);//aseaza pe perete
	glRotated(-90, 0, 1, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();



	glPushMatrix();
	glTranslatef(14.99f, 5.69f, -19.39f);//aseaza pe perete
	glRotated(-90, 0, 1, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(5.0f, 5.69f, -19.39f);//aseaza pe perete
	glRotated(-90, 0, 1, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	//bar stang
	glPushMatrix();
	glTranslatef(-1.1f, 4.2f, -14.99f);//aseaza pe perete
	glRotated(-90, 0, 0, 1);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.1f, 3.0f, -14.99f);//aseaza pe perete
	glRotated(-90, 0, 0, 1);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.1f, 1.8f, -14.99f);//aseaza pe perete
	glRotated(-90, 0, 0, 1);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.1f, 0.6f, -14.99f);//aseaza pe perete
	glRotated(-90, 0, 0, 1);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.1f, -0.6f, -14.99f);//aseaza pe perete
	glRotated(-90, 0, 0, 1);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();
	//bar drept
	glPushMatrix();
	glTranslatef(3.21f, 4.2f, -10.889f);//aseaza pe perete
	glRotated(-90, 0, 0, 1);
	glRotated(90, 1, 0, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.21f, 3.0f, -10.889f);//aseaza pe perete
	glRotated(-90, 0, 0, 1);
	glRotated(90, 1, 0, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.21f, 1.8f, -10.889f);//aseaza pe perete
	glRotated(-90, 0, 0, 1);
	glRotated(90, 1, 0, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.21f, 0.6f, -10.889f);//aseaza pe perete
	glRotated(-90, 0, 0, 1);
	glRotated(90, 1, 0, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.21f, -0.6f, -10.889f);//aseaza pe perete
	glRotated(-90, 0, 0, 1);
	glRotated(90, 1, 0, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(13.19f, 4.2f, -10.889f);//aseaza pe perete
	glRotated(-90, 0, 0, 1);
	glRotated(90, 1, 0, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(13.19f, 3.0f, -10.889f);//aseaza pe perete
	glRotated(-90, 0, 0, 1);
	glRotated(90, 1, 0, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(13.19f, 1.8f, -10.889f);//aseaza pe perete
	glRotated(-90, 0, 0, 1);
	glRotated(90, 1, 0, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(13.19f, 0.6f, -10.889f);//aseaza pe perete
	glRotated(-90, 0, 0, 1);
	glRotated(90, 1, 0, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(13.19f, -0.6f, -10.889f);//aseaza pe perete
	glRotated(-90, 0, 0, 1);
	glRotated(90, 1, 0, 0);
	glTranslatef(4.6f, -0.7f, 0.0f);//centreaza in origine.
	raftbarspate();
	glPopMatrix();

	//MASA CU STICLE


	glPopMatrix();
	}

	glPushMatrix();
	glTranslatef(-7.0f, 2.0f, 4.0f);
	masabiliard();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-17.0f, 2.0f, 4.0f);
	masabiliard();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-17.0f, 2.0f, -11.0f);
	masabiliard();
	glPopMatrix();





	//albastra
	glPushMatrix();
	glTranslatef(-5.0f, 3.2f, 1.0f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_rosu);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_rosu);
	bilabiliard();
	glPopMatrix();

	//rosu
	glPushMatrix();
	glTranslatef(-5.8f, 3.2f, 3.2f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_rosu);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_rosu);
	bilabiliard();
	glPopMatrix();

	//rosu
	glPushMatrix();
	glTranslatef(-5.3f, 3.2f, 3.3f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_rosu);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_rosu);
	bilabiliard();
	glPopMatrix();

	//rosu
	glPushMatrix();
	glTranslatef(-2.7f, 3.2f, 2.1f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_rosu);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_rosu);
	bilabiliard();
	glPopMatrix();

	//rosu
	glPushMatrix();
	glTranslatef(-3.1f, 3.2f, 5.6f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_rosu);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_rosu);
	bilabiliard();
	glPopMatrix();

	//rosu
	glPushMatrix();
	glTranslatef(-4.5f, 3.2f, 0.1f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_albcue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_albcue);
	bilabiliard();
	glPopMatrix();

	//roz
	glPushMatrix();
	glTranslatef(-3.0f, 3.2f, 0.1f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_roz);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_roz);
	bilabiliard();
	glPopMatrix();

	//verde
	glPushMatrix();
	glTranslatef(-3.5f, 3.2f, 7.1f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_verde);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_verde);
	bilabiliard();
	glPopMatrix();

	//tac
	glPushMatrix();
	glTranslatef(-7.5f, 3.45f, -1.1f);
	glRotatef(60, 0, 1, 0);
	tac();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-10.0f, 0, 0);
	{

		glPushMatrix();
		glTranslatef(-5.0f, 3.2f, 1.0f);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_rosu);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_rosu);
		bilabiliard();
		glPopMatrix();

		//rosu
		glPushMatrix();
		glTranslatef(-5.8f, 3.2f, 3.2f);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_rosu);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_rosu);
		bilabiliard();
		glPopMatrix();

		//rosu
		glPushMatrix();
		glTranslatef(-5.3f, 3.2f, 3.3f);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_rosu);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_rosu);
		bilabiliard();
		glPopMatrix();

		//rosu
		glPushMatrix();
		glTranslatef(-2.7f, 3.2f, 2.1f);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_rosu);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_rosu);
		bilabiliard();
		glPopMatrix();

		//rosu
		glPushMatrix();
		glTranslatef(-3.1f, 3.2f, 5.6f);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_rosu);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_rosu);
		bilabiliard();
		glPopMatrix();

		//rosu
		glPushMatrix();
		glTranslatef(-4.5f, 3.2f, 0.1f);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_albcue);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_albcue);
		bilabiliard();
		glPopMatrix();

		//roz
		glPushMatrix();
		glTranslatef(-3.0f, 3.2f, 0.1f);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_roz);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_roz);
		bilabiliard();
		glPopMatrix();

		//verde
		glPushMatrix();
		glTranslatef(-3.5f, 3.2f, 7.1f);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_verde);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_verde);
		bilabiliard();
		glPopMatrix();

		//tac
		glPushMatrix();
		glTranslatef(-4.5f, 3.45f, 0.0f);
		glRotatef(20, 0, 1, 0);
		tac();
		glPopMatrix();
	}
	glPopMatrix();

	//chiuveta
	glPushMatrix();
	glTranslatef(0.8f, 3.0f, -13.45f);
	glRotated(-90, 0, 1, 0);
	glTranslatef(3.45f, 0.0f, -4.2f);
	chiuveta();
	glPopMatrix();





	break;

	/*case ROSU:
	for (int i = -2; i < 2; i++)
	for (int j = -2; j < 2; j++) {
	if (i == 0 && j == 0)
	{
	break;
	}
	glPushMatrix();
	glTranslatef(i * 15.0, 0, j * 15.0);

	drawSnowMan();
	//drawDatBoi();

	glPopMatrix();
	}
	break;*/
	};


	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(mutarep);
		//PlaySound("C:\\Users\\Cristi\\Desktop\\boi.WAV", NULL, SND_FILENAME | SND_ASYNC);

		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(mutarem);
		break;
	default:
		break;
	}
}


void processNormalKeys(unsigned char key, int xx, int yy)
{
	float fraction = 1.6f;
	switch (key) {
	case 'l':
		y -= ly*fraction;
		break;
	case 'q':
		ly = ly + 0.01f;
		break;
	case 'e':
		ly = ly - 0.01f;
		break;
	case 'k':
	{
		y += ly*fraction;
		break;
	}

	}
	switch (key) {
	case 'a':
		angle -= 0.1f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case 'd':
		angle += 0.1f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case 'w':
		x += lx * fraction;
		z += lz * fraction;
		break;
	case 's':
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	case 'z':
		y++;
		x -= lx * fraction;
		z -= lz * fraction;
		break;

	case 'f':
		if (fogMode == GL_EXP) {
			glEnable(GL_FOG);
			fogMode = GL_EXP2;
			printf("Fog mode is GL_EXP2\n");
		}

		else if (fogMode == GL_EXP2) {
			glEnable(GL_FOG);
			fogMode = GL_EXP;
			printf("Fog mode is GL_EXP\n");
		}
		glFogi(GL_FOG_MODE, fogMode);
		glutPostRedisplay();
		break;

	case 'x':
		glDisable(GL_FOG);
		break;
	}
	if (key == 27)
		exit(0);
}


int main(int argc, char **argv) {

	// init GLUT and create window



	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");

	// register callbacks
	glutReshapeFunc(reshape);
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutMouseFunc(mouse);
	//objCamera.Mouse_Move(640, 480);
	//glutSpecialFunc(processSpecialKeys);
	glutMouseFunc(mouseButton);

	init();
	glutCreateMenu(menu);
	glutAddMenuEntry("Original", NONE);
	glutAddMenuEntry("SpreBar", VERDE);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);
	LoadTexture1();
	LoadTexture2();
	LoadTexture3();
	LoadTexture4();
	LoadTexture5();
	LoadTexture6();
	LoadTexture7();
	LoadTexture8();
	LoadTexture9();
	LoadTexture10();


	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}