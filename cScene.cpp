
#include "cScene.h"
#include <gl/glut.h>
#include <string.h>
#include <math.h>

cScene::cScene() {}
cScene::~cScene(){}

bool cScene::Init()
{
	return true;
}

void cScene::Render(cPlayer *Player,bool earthquake)
{
	Player->Look();

	//Room
	glColor3f(1.0f,1.0f,1.0f);
	glPushMatrix();
		if (earthquake){
			earthquakePos++;
			glTranslatef(0, earthquakePos % 2, 0);
		}

		glScalef(4.0f, 1.0f, 5.0f);
		RenderRoom();
	glPopMatrix();
}

void cScene::RenderRoom()
{
	glBegin(GL_TRIANGLE_STRIP);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f(-SIZE,-SIZE,-SIZE);
		glVertex3f(-SIZE, SIZE,-SIZE);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f( SIZE,-SIZE,-SIZE);
		glVertex3f( SIZE, SIZE,-SIZE);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f( SIZE,-SIZE, SIZE);
		glVertex3f( SIZE, SIZE, SIZE);
		glColor3f(1.0f,1.0f,0.0f);
		glVertex3f(-SIZE,-SIZE, SIZE);
		glVertex3f(-SIZE, SIZE, SIZE);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f(-SIZE,-SIZE,-SIZE);
		glVertex3f(-SIZE, SIZE,-SIZE);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex3f(-SIZE, -SIZE, -SIZE);
		glVertex3f(SIZE, -SIZE, -SIZE);
		glVertex3f(SIZE, -SIZE, SIZE);
		glVertex3f(-SIZE, -SIZE, SIZE);
	glEnd();
}