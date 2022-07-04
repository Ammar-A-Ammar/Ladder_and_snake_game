#include "SwithchToPlayMode.h"
#include "Grid.h"
#include "Player.h"

SwithchToPlayMode::SwithchToPlayMode(ApplicationManager *pApp) : Action(pApp)
{
}

void SwithchToPlayMode::ReadActionParameters()
{
}

void SwithchToPlayMode::Execute()
{
	pManager->GetGrid()->GetOutput()->CreatePlayModeToolBar();
}

SwithchToPlayMode::~SwithchToPlayMode()
{

}