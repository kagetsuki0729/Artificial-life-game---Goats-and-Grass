#include"Grass.h"
#include"World.h"
#include<iostream>
using namespace std;
Grass::Grass(World& world,char name,int x,int y):Creature(world,name,x,y){}
bool Grass::work(){
	int direction;
	if(ifDone)
		return true;
	increaseAge();
	if(age>=6){
		return false;
	}
	if(age>=3&&age<=5){
		direction=world.godKnows.getRandomNum(0,3);
		if(direction==0){
			if(x-1>=0&&world.map[x-1][y]==NULL)
				world.map[x-1][y]=new Grass(world,'I',x-1,y);
		}
		else if(direction==1){
			if(x+1<maxX&&world.map[x+1][y]==NULL)
				world.map[x+1][y]=new Grass(world,'I',x+1,y);
		}
		else if(direction==2){
			if(y-1>=0&&world.map[x][y-1]==NULL)
				world.map[x][y-1]=new Grass(world,'I',x,y-1);
		}
		else if(direction==3){
			if(y+1<maxY&&world.map[x][y+1]==NULL)
				world.map[x][y+1]=new Grass(world,'I',x,y+1);
		}
	}
	ifDone=true;
	return true;
}

