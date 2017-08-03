#include"Creature.h"
#include"RandomNum.h"
#include<iostream>
using namespace std;
Creature::Creature(World& world,char name,int x,int y):world(world){
	this->name=name;
	this->x=x;
	this->y=y;
	age=0;
	ifDone=true;
}
void Creature::increaseAge(){
	age++;
}
void Creature::setIfDone(bool x){
	ifDone=x;
}
char Creature::getName(){
	return name;
}
int Creature::getAge(){
	return age;
}
