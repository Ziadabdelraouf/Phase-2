#pragma once
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "Action.h"
#include "string"
#pragma comment(lib,"Winmm.lib")


class VoiceAction: public Action{
public:
	static bool Switcher;
	static int i;
	VoiceAction(ApplicationManager*);
	
	static void AudioPlayer(char*);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	
};

