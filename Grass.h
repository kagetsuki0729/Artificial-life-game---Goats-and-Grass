#ifndef _GARSS_H_
#define _GARSS_H_
#include"Creature.h"
class Grass:virtual public Creature{
	public:
		Grass(World& world,char name,int x,int y);
		bool work();
};
#endif
