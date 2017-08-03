#ifndef _GOAT_H_
#define _GOAT_H_
#include"Creature.h"
const int foodPointMAX=20;
const int consume=1;
const int gain=5;

class Goat:virtual public Creature{
	public:
		Goat(World& world,char name,int x,int y);
		int getFoodPoint();
		void setFoodPointConsume();
		void setFoodPointGain();
		bool work();
		void move();
	private:
		int foodPoint;
};
#endif
