#include"SortedList.cpp"
#include"StatImp.cpp"
#include"Game.cpp"
#include<fstream>

using namespace std;

NodePtr loadCharacter(SortedList *myList)
{
	string name;
	cout<<"Enter the name of the character you'd like to load: "<<endl;
	cin>>name;
	
	NodePtr loadCharacter = new NodeType;
	while(myList->HasNext())
	{
		NodeType *node = myList->getNextItem();
		if(node->name == name)
		{
			loadCharacter->name = node->name;
			loadCharacter->strength = node->strength;
			loadCharacter->dexterity = node->dexterity;
			loadCharacter->magic = node->magic;
			loadCharacter->charisma = node->charisma;
		}
	}

	return loadCharacter;
}

string newCharacter(SortedList *myList, int STR, int DEX, int CHA, int MAG)
{	
	NodePtr newCharacter = new NodeType;
	string newName;
	
	cout<<"Enter the name of your new character: ";
	cin>>newName;
	
	newCharacter->name = newName;
	newCharacter->strength = STR;
	newCharacter->dexterity = DEX;
	newCharacter->magic = MAG;
	newCharacter->charisma = CHA;
	
	myList->Insert(newCharacter);
	
	delete newCharacter;
	return newName;	
}

void deleteCharacter(SortedList *myList)
{
	string deleteName;
	cout<<"Enter the name of the character you'd like to delete: "<<endl;
	cin>> deleteName;
	
	myList->Delete(deleteName);
	myList->resetList();
}

int main()
{	

	int gameSTR, gameDEX, gameCHA, gameMAG, difficulty;
	string name;
	

	SortedList myList;

	//Game Start
	cout<<"Welcome to Die or Be Died, a game of chance!"<<endl;
	cout<<"Here are the rules of the game: "<<endl;
	cout<<"- Press the requested key to perform"<<endl;
	cout<<"- During each event you are given the option to respond to a scenario using one of your four skills, Strength, Dexterity, Charisma, or Magick."<<endl;
	cout<<"- You have a 1/STAT chance to fail each scenario. For example, you have a 1/5 (20%) chance to fail a strength response if your Strength stat is 5."<<endl;
	cout<<"- The further you go in the game, the harder a stat response will become. For example, a level 2 event will substract 2 from your skill before determing pass or fail."<<endl;
	cout<<"- In this game, you cannot die! If you fail a scenario, you can still carry on to the next event."<<endl<<endl;
	cout<<"Select a difficulty for the game: \n"
		<<"1. I JUST WANT TO READ THE STORY (MAX LUCK) \n"
		<<"2. Normal (NORMAL LUCK)\n"
		<<"3. I AM NO PUNK, I WISH FOR A SMALL CHALLENGE (BARELY ANY LUCK) \n"
		<<"4. FOOL. DO I LOOK LIKE A CASUL!? COME AT ME BRO #MLG #1V1MEBROZ LOL SMILEY FACE (SKILLS ONLY)"<<endl;
	cin>>difficulty;
	
	system("PAUSE");
	system("CLS");
	ifstream inFile("oldCharacters.txt");
	
	do
	{
		NodePtr character = new NodeType;
		inFile >> character->name;
		inFile >> character->strength;
		inFile >> character->dexterity;
		inFile >> character->charisma;
		inFile >> character->magic;

		myList.Insert(character);
		
	}while(!inFile.eof());
	
	myList.resetList();
	
	char loadchoice, addchoice, deletechoice;

	//load Character
	cout<<"Would you like to load a saved character? (y for yes, n for no)"<<endl;
	cin>>loadchoice;
	cout<<endl;
	
	while ( loadchoice == 'y' )
	{
		NodePtr load = new NodeType;
		load = loadCharacter(&myList);
		name = load->name;
		gameSTR = load->strength;
		gameDEX = load->dexterity;
		gameCHA = load->charisma;
		gameMAG = load->magic;
		
		cout<<"\n"
			<<"Load Character info:\n"
			<<"Name: "<<name<<"\n"
			<<"Strength: "<<gameSTR<<"\n"
			<<"Dexterity: "<<gameDEX<<"\n"
			<<"Charisma: "<<gameCHA<<"\n"
			<<"Magick: "<<gameMAG<<"\n"<<endl<<endl;
			
		cout<<"Is this correct? (y for yes, n for no)"<<endl;
		cin>>loadchoice;
		
		if(loadchoice == 'y')
			loadchoice =  'n';
		else
			loadchoice = 'y';
	}
	system("PAUSE");
	system("CLS");
	
	//New Character	
	cout<<"Would you like to create a new character? (y for yes, n for no)"
		<<" WARNING: THIS WILL OVERWRITE THE LOADED CHARACTER!"<<endl;
	cin>>addchoice;
	cout<<endl;
	
	while ( addchoice == 'y' )
	{	
		Creation creation;
		creation.allocate();
		
		gameSTR = creation.strength();
		gameDEX = creation.dexterity();
		gameCHA = creation.charisma();
		gameMAG = creation.magick();
	
		name = newCharacter(&myList, gameSTR, gameDEX, gameCHA, gameMAG);
		addchoice = 'n';
	}
	
	myList.resetList();
	
	//Delete Character
	cout<<"Would you like to delete a character? (y for yes, n for no)"<<endl;
	cin>>deletechoice;
	
	while ( deletechoice == 'y' )
	{
		deleteCharacter(&myList);
		myList.resetList();
		deletechoice = 'n';
	}
	
	
	ofstream outputFile("newCharacters.txt");
	
	while (myList.HasNext()) 
	{
		NodeType *node = myList.getNextItem();
		outputFile << node->name << endl;
		outputFile << node->strength << endl;
		outputFile << node->dexterity << endl;
		outputFile << node->charisma << endl;
		outputFile << node->magic << endl;
	}
	
	bool event1Flag, event2Flag, event3Flag, event4Flag, event5Flag;
	
	cout<<"The game will now start!"<<endl;
	system("CLS");
	
	Luck luck;
	switch(difficulty)
	{
		case 1:
			luck.setStat(1);
			break;
		case 2:
			luck.setStat(5);
			break;
		case 3:
			luck.setStat(10);
			break;
		case 4:
			luck.setStat(100000);
			break;
		default:
			luck.setStat(10);
			break;
	}
	//Event 1
	do
	{
		int event1Choice;
		cout<<"Character: "<<name<<endl<<endl;
		cout<<"You enter Zark, a dungeon of utmost scariness. The walls are thick with the funk of a thousand dead souls. \nYou have entered the first hallway and are confronted by an ogre. In a booming voice he exclaims, "
			<<"\nMEEK LITTLE HYOOOMAN, I AM THE GREAT AND TERRIBLE HABBSA. I HAVE DEVOURED HUNDREDS OF ADVENTURERS LIKE YOU! \nWHAT HOPE DO YOU HAVE AGAINST MY MIGHTINESS?"
			<<". \nHe brandishes what looks to be a giant chicken bone at you. What do you do?"<<endl<<endl;
		cout<<"Select an option: "<<endl<<endl;
		cout<<"1. Hold my beer, I'm gunna wrastle him. (Strength)"<<endl;
		cout<<"2. I pull out my totally sick swords of ogre slaying, and kill him with a twirl. (Dexterity)"<<endl;
		cout<<"3. Obviously, I can talk some sense into ole gruesome. (Charisma)"<<endl;
		cout<<"4. As a wizard, I'm well versed in... HA-DOUKEN!!!! (Magick)"<<endl<<endl;
		cin>>event1Choice;
		
		luck.statRoll();
		if(luck.outCome())
		{
			cout<<"The god of programming, Prof Mehri hath taken pity upon thee" 
			<<"\nand hath shone his brilliance upon ye\n"<<endl;
		}
		else
		{
			if(event1Choice == 1)
			{
				Dice* dice = new Strength;
				dice->setStat(gameSTR);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event1Flag = 0;
			}
			else if(event1Choice == 2)
			{
				Dice* dice = new Dexterity;
				dice->setStat(gameDEX);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event1Flag = 0;
			}
			else if(event1Choice == 3)
			{
				Dice* dice = new Charisma;
				dice->setStat(gameCHA);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event1Flag = 0;
			}
			else if(event1Choice == 4)
			{
				Dice* dice = new Magick;
				dice->setStat(gameMAG);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event1Flag = 0;
			}
			else
			{
				cout<<"You have entered an invalid choice! Try again..."<<endl;
				event1Flag = 1;
			}
		}
		system("PAUSE");
		system("CLS");
	}while(event1Flag);
	//Event 2
	do
	{
		int event2Choice;
		cout<<"Character: "<<name<<endl<<endl;
		cout<<"After dealing with the ogre, you wander further into the dungeon. \nThe smell of water fills your nostrils as the halls open up to a small underground river."
			<<"\nThe sound of rushing waters feels soothing at first, \nbut quickly turns to horror as you see what lurks underneath the waves."
			<<" \nA terror from beyond understanding, an aboleth, slowly emerges from the depths. \nAs the aboleth rises, its tentacles and column of three eyes are revealed. "
			<<"\nMucus sloughs off into the water as it speaks with a mouth indistinguishable from the rest of its features.\n""Ahhhh it has been quite a long time since an adventurer arrived in my domain. "
			<<"\nI shall turn your insides to mush and sup on your tortured screams."" Sounds scary, how do you react?"<<endl<<endl;
		cout<<"Select an option: "<<endl<<endl;
		cout<<"1. Hold my chicken, I'm gunna wrastle him. (Strength -2)"<<endl;
		cout<<"2. Like a ninja with a blood shadow edge, I utterly destroy this thing. (Dexterity -2)."<<endl;
		cout<<"3. Dude, first off... you're being totally uncool. I have a sandwich we can split. (Charisma -2)"<<endl;
		cout<<"4. Water huh? It'd be a shame if I shot electricity into there huh? (Magick -2)"<<endl;
		cin>>event2Choice;
		
		luck.statRoll();
		if(luck.outCome())
		{
			cout<<"The god of programming, Prof Mehri hath taken pity upon thee" 
			<<"\nand hath shone his brilliance upon ye\n"<<endl;
		}
		else
		{	
			if(event2Choice == 1)
			{
				Dice* dice = new Strength;
				dice->setStat(gameSTR-2);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event2Flag = 0;
			}
			else if(event2Choice == 2)
			{
				Dice* dice = new Dexterity;
				dice->setStat(gameDEX-2);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event2Flag = 0;
			}
			else if(event2Choice == 3)
			{
				Dice* dice = new Charisma;
				dice->setStat(gameCHA-2);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event2Flag = 0;
			}
			else if(event2Choice == 4)
			{
				Dice* dice = new Magick;
				dice->setStat(gameMAG-2);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event2Flag = 0;
			}
			else
			{
				cout<<"You have entered an invalid choice! Try again..."<<endl;
				event2Flag = 1;
			}
		}
		system("PAUSE");
		system("CLS");
	}while(event2Flag);
	//Event 3
	do
	{
		int event3Choice;
		cout<<"Character: "<<name<<endl<<endl;
		cout<<"Crawling out of the waters takes some effort but you finally make it away from the river. \n you move further into the urine soaked depths of Zark, you see an eerie light at the end of a dark tunnel."
			<<"\nThe light becomes more intense the closer you get to the room. \nMagic symbols circle around a hooded figure while zombies begin to rise from the ground. \nYou've stumbled into the lair of a powerful necromancer!"
			<<"\nThe hood falls back and reveals glowing green eyes and a gaunt skeletal face. \nThe sallow faced necromancer booms, ""I could use another adventurer in my army of undead. \nYou will make a fine addition to my collection."
			<<"\nKILL HIM AND BRING HIS BONES TO ME MY MINIONS!"". The zombies begin a strangely coordinated attack. Your move adventurer!"<<endl<<endl;
		cout<<"Select an option: "<<endl<<endl;
		cout<<"1. Hold my pants, I'm gunna wrestle this nerd. (Strength -3)"<<endl;
		cout<<"2. I shoot an arrow and ricochet it against zombie skulls, killing the necromancer. Nothing personal, kid.(Dexterity -3)"<<endl;
		cout<<"3. Can the undead beat the power of rythym? CAUSE THIS IS THRILLER! (Charisma -3)"<<endl;
		cout<<"4. You summon the undead? Oh yeah! I summon HARAMBE!(Magick -3)"<<endl;
		cin>>event3Choice;
		
		luck.statRoll();
		if(luck.outCome())
		{
			cout<<"The god of programming, Prof Mehri hath taken pity upon thee" 
			<<"\nand hath shone his brilliance upon ye\n"<<endl;
		}
		else
		{
			if(event3Choice == 1)
			{
				Dice* dice = new Strength;
				dice->setStat(gameSTR-3);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event3Flag = 0;
			}
			else if(event3Choice == 2)
			{
				Dice* dice = new Dexterity;
				dice->setStat(gameDEX-3);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event3Flag = 0;
			}
			else if(event3Choice == 3)
			{
				Dice* dice = new Charisma;
				dice->setStat(gameCHA-3);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event3Flag = 0;
			}
			else if(event3Choice == 4)
			{
				Dice* dice = new Magick;
				dice->setStat(gameMAG-3);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event3Flag = 0;
			}
			else
			{
				cout<<"You have entered an invalid choice! Try again..."<<endl;
				event3Flag = 1;
			}
		}
		system("PAUSE");
		system("CLS");
	}while(event3Flag);
	//Event 4
	do
	{
		int event4Choice;
		cout<<"Character: "<<name<<endl<<endl;
		cout<<"Dusting the bones and cleaning the viscera from your jacket, you come near the final chamber \nin the dungeon. You are very tired. No adventurer in the history of Zark has made it this far! That's congratulations enough. \nThe door to the final chamber opens up and the glow of gold is almost blinding. As your eyes scan the various golden cups,\n bowls, coins, and jeweled weapons you are almost mesmerized until your eyes find the dragon atop the heap. \nIn a baritone voice the dragon thunders, 'WELCOME MORTAL, I HAVE BEEN EXPECTING YOU FOR SOME TIME. YOU SEEK TO ACQUIRE MY TREASURE FOR YOURSELF? \nI WILL KILL YOU WITH A SIMPLE BREATH OF FIRE. YOU'RE JUST ANOTHER MEAL TO ME.' \nThe dragon unfurls its wings, swoops towards you with a gaping maw full of flame! Defend yourself adventurer!"<<endl<<endl;
		cout<<"Select an option: "<<endl<<endl;
		cout<<"1. Hold my horse, I'm gunna wrastle it. (Strength -4)"<<endl;
		cout<<"2. You're already dead, you just don't know it wyrm. I then perform one slash and cut the air so hard it slices the dragon in half.(Dexterity -4)"<<endl;
		cout<<"3. I reflect my winning smile across every piece of gold in the room. GET BLINDED BY THE POWER OF FRIENDSHIP!(Charisma -4)"<<endl;
		cout<<"4. I'll just fight fire with MOAR FIRE!! AND ICE! YOU CAN'T STOP ME! BAHAHAHAHAHA! (Magick -4)"<<endl;
		cin>>event4Choice;
		
		luck.statRoll();
		if(luck.outCome())
		{
			cout<<"The god of programming, Prof Mehri hath taken pity upon thee" 
			<<"\nand hath shone his brilliance upon ye\n"<<endl;
		}
		else
		{
			if(event4Choice == 1)
			{
				Dice* dice = new Strength;
				dice->setStat(gameSTR-4);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event4Flag = 0;
			}
			else if(event4Choice == 2)
			{
				Dice* dice = new Dexterity;
				dice->setStat(gameDEX-4);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event4Flag = 0;
			}
			else if(event4Choice == 3)
			{
				Dice* dice = new Charisma;
				dice->setStat(gameCHA-4);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event4Flag = 0;
			}
			else if(event4Choice == 4)
			{
				Dice* dice = new Magick;
				dice->setStat(gameMAG-4);
				dice->statRoll();
				dice->outCome();
				dice->~Dice();
				event4Flag = 0;
			}
			else
			{
				cout<<"You have entered an invalid choice! Try again..."<<endl;
				event4Flag = 1;
			}
		}
		system("PAUSE");
		system("CLS");
	}while(event4Flag);
	//Event 5
	do
	{
		int event5Choice;
		cout<<"Character: "<<name<<endl<<endl;
		cout<<"After getting past the dragon, you find a ostentatious door. \n door is decorated in various images and frescas of your deeds throughout Zark. \nAlong the top of the door the words Transcendence appear in gilded letters. \nIts golden frame houses a face in the center. \nThe face begins to move and it begins to speak! 'Egads, good show adventurer! \nWhile you may now have mountains and mountains of treasure, the real prize is the answer to this question. \nWhat is the best thing in life?'. Your answer?"<<endl<<endl;
		cout<<"Select an option: "<<endl<<endl;
		cout<<"1. Hold my assload of money, Imagunna wrastle the door. (DO YOU DARE: Strength -5)"<<endl;
		cout<<"2. Myself. Me. I'm the most amazing thing ever. (Dexterity)"<<endl;
		cout<<"3. Having a positive outlook on life. Oh, and extra food for people you meet. (Charisma)"<<endl;
		cout<<"4. Knowledge, and the pursuit of it. That's the best thing. Well, that and lots of magick. (Magick)"<<endl;
		cin>>event5Choice;
		
		luck.statRoll();
		if(luck.FinalOutCome())
		{
			cout<<"Professor Mehri comes down from Canvas and gives you an A. A sense of accomplishment washes over you as you move on to the next semester through the door"<<endl;

		}
		else
		{
			if(event5Choice == 1)
			{
				Dice* dice = new Strength;
				dice->setStat(gameSTR-5);
				dice->statRoll();
				dice->FinalOutCome();
				dice->~Dice();
				event5Flag = 0;
			}
			else if(event5Choice == 2)
			{
				Dice* dice = new Dexterity;
				dice->setStat(gameDEX);
				dice->statRoll();
				dice->FinalOutCome();
				dice->~Dice();
				event5Flag = 0;
			}
			else if(event5Choice == 3)
			{
				Dice* dice = new Charisma;
				dice->setStat(gameCHA);
				dice->statRoll();
				dice->FinalOutCome();
				dice->~Dice();
				event5Flag = 0;
			}
			else if(event5Choice == 4)
			{
				Dice* dice = new Magick;
				dice->setStat(gameMAG);
				dice->statRoll();
				dice->FinalOutCome();
				dice->~Dice();
				event5Flag = 0;
			}
			else
			{
				cout<<"You have entered an invalid choice! Try again..."<<endl;
				event5Flag = 1;
			}
		}
		system("PAUSE");
		system("CLS");
	}while(event5Flag);
	
	cout<<"THE END! Thank you for playing! Created by Jamil Ahmed, Alec Johnson, Myleek Chase, and Imani Johnson. \nGitGudSoftware (c) 2016."<<endl;
	system("PAUSE");
	
	return 0;
}
