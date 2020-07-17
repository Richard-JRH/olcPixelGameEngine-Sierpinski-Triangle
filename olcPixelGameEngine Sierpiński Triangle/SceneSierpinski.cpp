#include "SceneSierpinski.h"

SceneSierpinski::SceneSierpinski()
{
}

SceneSierpinski::~SceneSierpinski()
{
}

bool SceneSierpinski::OnUserCreate()
{
	// Init
	sTriangle* tri = new sTriangle( Vec2D(ScreenWidth() / 2, 0),
									Vec2D(ScreenWidth(), ScreenHeight() - 1),
									Vec2D(0, ScreenHeight() - 1));

	DrawTri(tri, ScreenWidth(), ScreenHeight(), 1);

	return true;
}

bool SceneSierpinski::OnUserUpdate(float dt)
{
	return true;
}

void SceneSierpinski::DrawTri(sTriangle* tri, int width, int height, int Lvl)
{
	if (Lvl == MAX_LVL)
		return;

	DrawLine(tri->p[0].x, tri->p[0].y, tri->p[1].x, tri->p[1].y, olc::GREEN);
	DrawLine(tri->p[1].x, tri->p[1].y, tri->p[2].x, tri->p[2].y, olc::GREEN);
	DrawLine(tri->p[2].x, tri->p[2].y, tri->p[0].x, tri->p[0].y, olc::GREEN);
	

	float subWidth = width / 2;
	float subHeight = height / 2;

	DrawTri(new sTriangle( Vec2D(tri->p[0].x, tri->p[0].y),
							Vec2D(tri->p[1].x - subWidth / 2, tri->p[1].y - subHeight),
							Vec2D(tri->p[2].x + subWidth / 2, tri->p[2].y - subHeight)),
							subWidth, subHeight, Lvl + 1 );

	DrawTri(new sTriangle(Vec2D(tri->p[0].x + subWidth / 2, tri->p[0].y + subHeight),
							Vec2D(tri->p[1].x, tri->p[1].y),
							Vec2D(tri->p[2].x + subWidth, tri->p[2].y)),
							subWidth, subHeight, Lvl + 1);

	DrawTri(new sTriangle(Vec2D(tri->p[0].x - subWidth / 2, tri->p[0].y + subHeight),
							Vec2D(tri->p[1].x - subWidth, tri->p[1].y),
							Vec2D(tri->p[2].x, tri->p[2].y)),
							subWidth, subHeight, Lvl + 1);

	return;
}
