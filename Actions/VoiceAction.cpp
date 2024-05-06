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
	//The engine that we use to ginerate the audios at its place.
	//(FileName): The name of the file that we will play "It should be .wav file"
	if (Switcher) {
		PlaySound(TEXT(FileName), NULL, SND_FILENAME | SND_ASYNC);
	};
}

void VoiceAction::ReadActionParameters() {

}

void VoiceAction::Execute() {
	i++; //Increament i by 1 to switch between turning the voice action on or off.
	Output* pOut = pManager->GetOutput();
	//if i is odd -----> Turn the switcher on.
	//if i is even -----> Turn the switcher off.
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