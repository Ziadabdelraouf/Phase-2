#include "VoiceAction.h"
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "../ApplicationManager.h"
#include "Action.h"

VoiceAction::VoiceAction(ApplicationManager *pApp) :Action(pApp){
	Switcher = false;
}

void VoiceAction::AudioPlayer(char* FileName) {
	if (Switcher) {
		PlaySound(TEXT(FileName), NULL, SND_FILENAME | SND_ASYNC);
	};
}

void VoiceAction::ReadActionParameters() {

}

void VoiceAction::Execute() {
	i++;
	Output* pOut = pManager->GetOutput();
	if ((i % 2) != 0) {
		Switcher = true;
		pOut->PrintMessage("Voice Action turned on");
		AudioPlayer("Audio\\TurnOnVoiceAction.wav");
	}
	else if ((i % 2) == 0) {
		pOut->PrintMessage("Voice Action turned off");
		Switcher = true;
		AudioPlayer("Audio\\TurnOffVoiceAction.wav");
		Switcher = false;
	}
	

}