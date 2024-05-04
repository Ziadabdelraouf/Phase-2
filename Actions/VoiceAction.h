#pragma once
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "Action.h"
#include "string"
#pragma comment(lib,"Winmm.lib")

static bool Switcher;
static int i=0;
class VoiceAction: public Action{
private:

public:
	VoiceAction(ApplicationManager*);
	
	static void AudioPlayer(char*);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	
};

