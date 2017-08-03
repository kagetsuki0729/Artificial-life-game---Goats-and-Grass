#ifndef _WORLD_H_
#define _WORLD_H_
#include"RandomNum.h"
class Goat;
class Grass;
class Creature;
const int maxX=20;
const int maxY=35;
class World{
	friend class Goat;
	friend class Grass;
	public:
        World(int numPasses,int seed);
		void mainLoop(int displayInterval);
		void display();
		void kill(int x,int y);
	private:
		Creature* map[maxX][maxY];
		RandomNum godKnows;
		int numPasses;
};
#endif
