#define OLC_PGE_APPLICATION

#include "SceneSierpinski.h"

void main()
{
	SceneSierpinski App;

	if (App.Construct(600, 550, 1, 1))
		App.Start();
}