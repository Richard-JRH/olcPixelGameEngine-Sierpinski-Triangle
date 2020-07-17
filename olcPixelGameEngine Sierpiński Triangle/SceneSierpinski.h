#ifndef SCENE_SIERPINSKI_H
#define SCENE_HSIERPINSKI_H

#include "olcPixelGameEngine.h"

class SceneSierpinski : public olc::PixelGameEngine
{
public: 
	static const int MAX_LVL = 7;
public:
	struct Vec2D {
		float x, y;

		Vec2D() {
			x = y = 0;
		}

		Vec2D(float _x, float _y) {
			x = _x;
			y = _y;
		}
	};

	struct sTriangle {
		Vec2D p[3];
		int Lvl;
		
		sTriangle() {
			p[0] = Vec2D(0, 0);
			p[1] = Vec2D(0, 0);
			p[2] = Vec2D(0, 0);
			Lvl = 0;
		}

		sTriangle(Vec2D _p1, Vec2D _p2, Vec2D _p3) {
			p[0] = _p1;
			p[1] = _p2;
			p[2] = _p3;
		}
	};
public:
	SceneSierpinski();
	~SceneSierpinski();

	bool OnUserCreate();
	bool OnUserUpdate(float dt);

	void DrawTri(sTriangle* tri, int width, int height, int Lvl);
};

#endif

