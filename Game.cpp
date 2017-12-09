#include <iostream>
using namespace std;

class Creation
{
public:
	Creation();
	void allocate();
	int strength();
	int dexterity();
	int magick();
	int charisma();
	~Creation();

private:
	int STR;
	int DEX;
	int MAG;
	int CHA;
};

Creation::Creation()
{
	STR = 5;
	DEX = 5;
	MAG = 5;
	CHA = 5;
}

 void Creation::allocate()
{
	int stat;
	
	for(int i = 0; i<5; i++)
	{
		cout<<"Here are your current stats: "<<endl;
		cout<<"Strength: "<<STR<<endl;
		cout<<"Dexterity: "<<DEX<<endl;
		cout<<"Magick: "<<MAG<<endl;
		cout<<"Charisma: "<<CHA<<endl<<endl;
		
		if(i == 0)
		{
			cout<<"As a child, you were known for..."<<endl;
			cout<<"1.tellin people to hold things before Wrastlin'! (Strength + 2)"<<endl;
			cout<<"2. being a loner, and the best at everything! (Dexterity + 2)"<<endl;
			cout<<"3. being able to talk your way out of anything! (Charsima + 2)"<<endl;
			cout<<"4. being able to create gold from tears! (Magick + 2)"<<endl;
			cout<<"Enter a choice: "<<endl;
			cin>>stat;
		}
		else
		{
			cout<<"You now have "<<5-i<<" skill points to allocate!"<<endl;
			cout<<"Enter 1 to increase strength: \nEnter 2 to increase dexterity: \nEnter 3 to increase charisma: \nEnter 4 to increase magic: "<<endl;
			cin>>stat;
		}
		
		if (stat == 1)
	 	{
	 		if(i == 0)
				STR += 2;
			else
				STR += 1; 
	 	}
	 	else if (stat == 2)
	 	{
			if(i == 0)
				DEX += 2;
			else
				DEX += 1;
	 	}
	 	else if (stat == 3)
	 	{
			if(i == 0)
				CHA += 2;
			else
				CHA += 1; 
	    }
	 	else if (stat == 4)
	  	{
			if(i == 0)
				MAG += 2;
			else
				MAG += 1; 
	 	}
	 	else
	 	{
			cout << "Invalid Choice";
			exit(0);
	 	}
	 	system("CLS");
	}
	
	cout<<"Here's what you'll be using in your game: "<<endl;
	cout<<"Strength: "<<STR<<endl;
	cout<<"Dexterity: "<<DEX<<endl;
	cout<<"Magick: "<<MAG<<endl;
	cout<<"Charisma: "<<CHA<<endl<<endl;
	
	system("PAUSE");
	system("CLS");
	 
}

int Creation::strength()
{
	return STR;
}

int Creation::dexterity()
{
	return DEX;
}

int Creation::charisma()
{
	return CHA;
}

int Creation::magick()
{
	return MAG;
}

Creation::~Creation()
{

}
