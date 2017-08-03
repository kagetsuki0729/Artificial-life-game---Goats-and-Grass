#include"Goat.h"
#include"World.h"
#include<iostream>
using namespace std;
Goat::Goat(World &world,char name,int x,int y):Creature(world,name,x,y){
	foodPoint=foodPointMAX;
}
void Goat::setFoodPointConsume(){
	foodPoint-=consume;
}
void Goat::setFoodPointGain(){
	foodPoint+=gain;
}
bool Goat::work(){
	int direction;
	if(ifDone)
	    return true;
	increaseAge();
	setFoodPointConsume();
	if(age>=70||foodPoint<=0){
		return false;
	}
	if(age>=50&&age<=55){
		direction=world.godKnows.getRandomNum(0,3);
		if(direction==0){
			if(x-1>=0&&(world.map[x-1][y]==NULL||world.map[x-1][y]->getName()=='I')){
				if(world.map[x-1][y]!=NULL&&world.map[x-1][y]->getName()=='I'){
					setFoodPointGain();
					world.kill(x-1,y);
				}
				world.map[x-1][y]=new Goat(world,'X',x-1,y);
			}
		}
		else if(direction==1){
			if(x+1<maxX&&(world.map[x+1][y]==NULL||world.map[x+1][y]->getName()=='I')){
				if(world.map[x+1][y]!=NULL&&world.map[x+1][y]->getName()=='I'){
					setFoodPointGain();
					world.kill(x+1,y);
				}
				world.map[x+1][y]=new Goat(world,'X',x+1,y);
			}
		}
		else if(direction==2){
			if(y-1>=0&&(world.map[x][y-1]==NULL||world.map[x][y-1]->getName()=='I')){
				if(world.map[x][y-1]!=NULL&&world.map[x][y-1]->getName()=='I'){
					setFoodPointGain();
					world.kill(x,y-1);
				}
				world.map[x][y-1]=new Goat(world,'X',x,y-1);
			}
		}
		else if(direction==3){
			if(y+1<maxY&&(world.map[x][y+1]==NULL||world.map[x][y+1]->getName()=='I')){
				if(world.map[x][y+1]!=NULL&&world.map[x][y+1]->getName()=='I'){
					setFoodPointGain();
					world.kill(x,y+1);
				}
				world.map[x][y+1]=new Goat(world,'X',x,y+1);
			}
		}
	}
	else{
		move();
	}
	ifDone=true;
	return true;
}
void Goat::move(){
	int direction=world.godKnows.getRandomNum(0,3);
	if(direction==0){
		if(x-1>=0&&(world.map[x-1][y]==NULL||world.map[x-1][y]->getName()=='I')){
			if(world.map[x-1][y]!=NULL&&world.map[x-1][y]->getName()=='I'){
				setFoodPointGain();
				world.kill(x-1,y);
			}
			world.map[x-1][y]=this;
	        world.map[x][y]=NULL;		
			x--;
		}
	}
	else if(direction==1){
		if(x+1<maxX&&(world.map[x+1][y]==NULL||world.map[x+1][y]->getName()=='I')){
			if(world.map[x+1][y]!=NULL&&world.map[x+1][y]->getName()=='I'){
				setFoodPointGain();
				world.kill(x+1,y);
			}
			world.map[x+1][y]=this;
	        world.map[x][y]=NULL;		
			x++;
		}
	}
	else if(direction==2){
		if(y-1>=0&&(world.map[x][y-1]==NULL||world.map[x][y-1]->getName()=='I')){
			if(world.map[x][y-1]!=NULL&&world.map[x][y-1]->getName()=='I'){
				setFoodPointGain();
				world.kill(x,y-1);
			}
			world.map[x][y-1]=this;
	        world.map[x][y]=NULL;		
			y--;
		}
	}
	else if(direction==3){
		if(y+1<maxY&&(world.map[x][y+1]==NULL||world.map[x][y+1]->getName()=='I')){
			if(world.map[x][y+1]!=NULL&&world.map[x][y+1]->getName()=='I'){
				setFoodPointGain();
				world.kill(x,y+1);
			}
			world.map[x][y+1]=this;
	        world.map[x][y]=NULL;		
			y++;
		}
	}
}

