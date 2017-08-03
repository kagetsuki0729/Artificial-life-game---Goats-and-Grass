#ifndef _CREATURE_H_
#define _CREATURE_H_
class World;
class Creature{
	public:
		Creature(World& world,char name,int x,int y);
		virtual ~Creature(){/*do nothing*/}
		void increaseAge();
		void setIfDone(bool x);
		char getName();
		int getAge();
		virtual bool work()=0; //abstract
	protected:
		char name;
		int x;//index
		int y;//index
		int age;
		bool ifDone;// if done work()
		World& world;
};
#endif
