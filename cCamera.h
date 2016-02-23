
#pragma once

#include <gl\glut.h>

#define PI			3.1415265359
#define PIdiv180	0.0174529252

/////////////////////////////////
//Note: All angles in degrees  //
/////////////////////////////////

#include "cVector3D.h" 

class cCamera
{
private:
	cVector3D Position;
	cVector3D ViewDir;		/*Not used for rendering the camera, but for "moveforwards"
							So it is not necessary to "actualize" it always. It is only
							actualized when ViewDirChanged is true and moveforwards is called*/
	bool ViewDirChanged;
	GLfloat RotatedX, RotatedY, RotatedZ;


	int middleX,middleY;
	float speed;

	void GetViewDir (void);

public:
	cCamera();						
	void Init(int cx,int cy,float s);	//necessary for input updates
	void Look();						//glRotate+glTranslate commands
	
	void Rotate	(cVector3D Angles);
	void Update (bool keys[256], int mouseX, int mouseY);

	void GetPosition(cVector3D *pos);
	void GetRotated(cVector3D *rot);
	void SetPosition(cVector3D pos);
	void MoveForwards(GLfloat distance);

	void Teleport();

private:
	void RotateX(GLfloat angle);
	void RotateY(GLfloat angle);
	void RotateZ(GLfloat angle);

	void StrafeRight(GLfloat distance);
};

