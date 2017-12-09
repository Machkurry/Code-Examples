
#include <iostream>
using namespace std;
class Creation
{
public:
	Creation();
	void allocate(int stat);
	void fallocate(int stat);
	void assignstats();
	~Creation();

private:
	int STR;
	int DEX;
	int MAG;
	int CHA;
};

Creation::Creation()
{
	int STR = 5;
	int DEX = 5;
	int MAG = 5;
	int CHA = 5;
}

 void Creation::allocate(int stat)
{
	 if (stat == 1)
	 {
		 STR + 1;
	 }
	 else if (stat == 2)
	 {
		 DEX + 1;
	 }
	 else if (stat == 3)
	 {
		 CHA + 1;
	 }
	 else if (stat == 4)
	 {
		 MAG + 1;
	 }
	 else
	 {
		 cout << "Invalid Choice";
	 }
	 
}

 void Creation::fallocate(int stat)
 {
		 if (stat == 1)
		 {
			 STR + 2;
		 }
		 else if (stat == 2)
		 {
			 DEX + 2;
		 }
		 else if (stat == 3)
		 {
			 CHA + 2;
		 }
		 else if (stat == 4)
		 {
			 MAG + 2;
		 }
		 else
		 {	
			 cout << "You where known for being stupid";
		 }
 }

 inline void Creation::assignstats()
 {

 }

Creation::~Creation()
{

}
