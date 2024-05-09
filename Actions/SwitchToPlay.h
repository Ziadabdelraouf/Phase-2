#pragma once
#include "Action.h"
#include <fstream>

class SwitchToPlay :
    public Action
{
private:
    
    
public: 
    SwitchToPlay(ApplicationManager *pApp);

    virtual void ReadActionParameters();

    void Load();

    void Save();

    virtual void Execute();

};

