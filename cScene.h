
#pragma once

#include "cPlayer.h"

#define SIZE		5.0f

class cScene  
{
public:
	cScene();
	virtual ~cScene();
	int earthquakePos;
	void Render(cPlayer *Player,bool earthquake);
	bool Init();

private:
	void RenderRoom();
};

