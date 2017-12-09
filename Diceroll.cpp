//Diceroll
#include <cstdlib>
#include<ctime>
#include<iostream>
using namespace std;

class Dice{
virtual void setStat(int s) = 0;
virtual int getStat() = 0;
virtual bool statRoll() = 0;
virtual void outCome() = 0;
};

class Strength:public Dice
{
	private:
		int strength;
		
	public:
		void setStat(int s);
		int getStat();
		bool statRoll();
		void outCome();
		
};

class Luck
{
	private:
		int luck;
		
	public:
		void setStat(int s);
		int getStat();
		bool statRoll();
		void outCome();
		
};
class Dexterity:public Dice
{
	private:
		int dexterity;
		
	public:
		void setStat(int s);
		int getStat();
		bool statRoll();
		void outCome();
		
};
class Magick:public Dice
{
	private:
		int magick;
		
	public:
		void setStat(int s);
		int getStat();
		bool statRoll();
		void outCome();
		
};
class Charisma:public Dice
{
	private:
		int charisma;
		
	public:
		void setStat(int s);
		int getStat();
		bool statRoll();
		void outCome();
		
};
