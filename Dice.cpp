#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

class Dice
{
	private:
		int stat;
	public:
		Dice();
		void setStat(int s);
		int getStat() const;
		bool strRoll();
};

Dice::Dice()
{
	stat = 0;
}

void Dice::setStat(int s)
{
	stat = s;
}

int Dice::getStat() const
{
	return stat;
}

bool Dice::strRoll()
{
	int outcome;
	bool next;
	
	int str = getStat();
	
	srand(time(NULL));
	outcome = rand() % str + 1;
	
	if(outcome < str || outcome > str)
		return true;
	else
		return false;
}

