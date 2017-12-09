//implementation file for Diceroll
#include"Diceroll.h"

Dice::~Dice(void){
	cout<<"Hope you enjoyed the game."<<endl;
};

void Strength::setStat(int s)//each stat takes in an int from character creation
{	
	strength = s;
};

int Strength::getStat() //displays individual stat for character
{
	return strength;
};

bool Strength::statRoll()	 //this is where the magic happens, or doesn't.
{							//each stat rolls against itself 
	srand(time(NULL));		//if the roll is less than the stat, then the player has succeeded
	int roll= rand()%strength +1;
	if(roll< strength)
	return true;
	else
	return false;
	
};
void Strength::outCome() //this is where the outcomes for failure and success are output
{
	bool outcome = statRoll();
	if(outcome)
	cout<<"Your strength has won the day!"<<endl;
	else
	cout<<"Your have weak baby arms! You ran away!"<<endl;
};

void Strength::FinalOutCome() //this is where the outcomes for failure and success are output
{
	bool outcome = statRoll();
	if(outcome)
	cout<<"You have completely destroyed the door, revealing a C++ class in session. WHY!?!? WHAT WAS TO BE GAINED? You learn nothing, but you've successfully killed everything in Zark."<<endl;
	else
	cout<<"Your weak baby arms have gotten you killed when the door exploded and sent you into a paradoxal loop. "<<endl;
};
void Dexterity::setStat(int s)
{	
	dexterity = s;
};

int Dexterity::getStat()
{
	return dexterity;
};

bool Dexterity::statRoll()
{
	srand(time(NULL));
	int roll= rand()%dexterity +1;
	if(roll< dexterity)
	return true;
	else
	return false;
	
};
void Dexterity::outCome()
{
	bool outcome = statRoll();
	if(outcome)
	cout<<"Your catlike reflexes helped you win the day "<<endl;
	else
	cout<<"Your stupid banana hands have lost! You ran away!"<<endl;
};
void Dexterity::FinalOutCome() //this is where the outcomes for failure and success are output
{
	bool outcome = statRoll();
	if(outcome)
	cout<<"The door looks confused and explodes from how edgy and tough you are. Serves the door right, also you didn't want congratulations anyway."<<endl;
	else
	cout<<"You accidently cut yourself on the monofilament edge you call your personality. Have fun playing Bloodborne "<<endl;
};
void Magick::setStat(int s)
{	
	magick = s;
};

int Magick::getStat()
{
	return magick;
};

bool Magick::statRoll()
{
	srand(time(NULL));
	int roll= rand()%magick +1;
	if(roll< magick)
	return true;
	else
	return false;
	
};
void Magick::outCome()
{
	bool outcome = statRoll();
	if(outcome)
	cout<<"Through wizardy you have won the day "<<endl;
	else
	cout<<"Something exploded because you're bad at magic, go back to school loser! You ran away!"<<endl;
};
void Magick::FinalOutCome() //this is where the outcomes for failure and success are output
{
	bool outcome = statRoll();
	if(outcome)
	cout<<"With your answer the door smiles and vanishes, within the door a small desk is revealed. You sit at it and realize you have finally become a PhD. All knowledge is at your fingertips, have fun!"<<endl;
	else
	cout<<"Your head explodes from the amount of knowledge forced into your mind at once. And you were doing so well. "<<endl;
};
void Charisma::setStat(int s)
{	
	charisma = s;
};

int Charisma::getStat()
{
	return charisma;
};

bool Charisma::statRoll()
{
	srand(time(NULL));
	int roll= rand()%charisma +1;
	if(roll< charisma)
	return true;
	else
	return false;
	
};
void Charisma::outCome()
{
	bool outcome = statRoll();
	if(outcome)
	cout<<"Your handsome looks have won the day "<<endl;
	else
	cout<<"You've literally insulted everyone's mother with your face and have ran away!"<<endl;
};
void Charisma::FinalOutCome() //this is where the final outcomes for failure and success are output
{
	bool outcome = statRoll();
	if(outcome)
	cout<<"The door smiles and opens. The room in front is filled with your friends you've made from your adventure in Zark.\nLooks like they're throwing a pizza party for you. \nEnjoy!"<<endl;
	else
	cout<<"Your smile causes the door to get angry and punch you into oblivion, you need a lesson in etiquette. Maybe brush your teeth once in a while."<<endl;
};

int Luck::getStat()
{
return 	0;
};

void Luck::setStat(int s) //difficulty setting
{
 	luck = s;
};

bool Luck::statRoll() 	//This is the secret sauce
{						// Luck is the hidden stat that overrides all other stats
	srand(time(NULL));	//representing a player's dumb luck winning the day
	int roll= rand()%luck +1;
	if(roll== luck)
	return true;
	else
	return false;
		
};
bool Luck::outCome()
{
	bool outcome = statRoll();
	if(outcome)
		return true;
	else
		return false;
		
};
bool Luck::FinalOutCome() //this is where the outcomes for failure and success are output
{
	bool outcome = statRoll();
	if(outcome)
		return true;
	else
		return false;
};
