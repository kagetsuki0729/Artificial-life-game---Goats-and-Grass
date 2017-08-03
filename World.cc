#include<iostream>
#include"World.h"
#include"Goat.h"
#include"Grass.h"
using namespace std;
World::World(int numPasses,int seed):godKnows(seed),numPasses(numPasses){
	int x,y,i,j,initGoat=5,initGrass=10;
	for(i=0;i<maxX;i++){
		for(j=0;j<maxY;j++){
			map[i][j]=NULL;
		}
	}
	while(initGoat>0){
		x=godKnows.getRandomNum(0,maxX);
		y=godKnows.getRandomNum(0,maxY);
		if(map[x][y]==NULL){
			map[x][y]=new Goat(*this,'X',x,y);
			initGoat--;
		}
	}
	while(initGrass>0){
		x=godKnows.getRandomNum(0,maxX);
		y=godKnows.getRandomNum(0,maxY);
		if(map[x][y]==NULL){
			map[x][y]=new Grass(*this,'I',x,y);
			initGrass--;
		}
	}
}
void World::mainLoop(int displayInterval){
	int passCount=0;
	while(passCount<numPasses){
		for(int i=0;i<maxX;i++){
			for(int j=0;j<maxY;j++){
				if(map[i][j]!=NULL)
					map[i][j]->setIfDone(false);// initial the state
			}
		}

		for(int i=0;i<maxX;i++){
			for(int j=0;j<maxY;j++){
				if(map[i][j]!=NULL){
					if(!map[i][j]->work())
						kill(i,j);
				}
			}
		}
		if(passCount%displayInterval==0)
			display();
		passCount++;
	}
}
void World::display(){
	int i,j;
	int grassCount=0,goatCount=0;
	cout<<" ";
	for(i=0;i<maxY;i++)
		cout<<" "<<i%10;
	cout<<endl;
	for(i=0;i<maxX;i++){
		cout<<i%10;
		for(j=0;j<maxY;j++){
			if(map[i][j]!=NULL){
				cout<<" "<<map[i][j]->getName();
				if(map[i][j]->getName()=='I')
					grassCount++;
				else
					goatCount++;
			}
			else
				cout<<"  ";
		}
		cout<<endl;
	}
	for(i=0;i<72;i++)
		cout<<"-";
	cout<<endl;
}
void World::kill(int x,int y){
	delete map[x][y];
	map[x][y]=NULL;
}
