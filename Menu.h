#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "gamePlay.h"


/////////////////////////////////////////////////

/*
	all these variables and function are used to show the png files to in the menu option

	variables are declared to store the integer value of the picture files

	functions are declared to load the png files before the game start
*/

int exitt;
int aboutt, story;
int menu, menuButton[6];
int newgame;
int loadgame;
int highscore;
int congrats;
void ExitImage(){
	exitt = iLoadImage("Menu\\sure.png");
}

void aboutImage(){
	aboutt = iLoadImage("About\\about.jpg");
	story = iLoadImage("About\\story.png");
}

void menuImage(){
	menu = iLoadImage("Menu\\Menu.png"); 
	menuButton[0] = iLoadImage("Menu\\NewGame.png");
	menuButton[1] = iLoadImage("Menu\\LoadGame.png");
	menuButton[2] = iLoadImage("Menu\\HighScore.png");
	menuButton[3] = iLoadImage("Menu\\Options.png");
	menuButton[4] = iLoadImage("Menu\\About.png");
	menuButton[5] = iLoadImage("Menu\\Exit.png");
}

void newGameImage(){
	newgame = iLoadImage("Gamebg\\level1.png");
}

void loadGameImage(){
	loadgame = iLoadImage("Loadgame\\LevelSelect.png");
}

void highScoreImage(){
	highscore = iLoadImage("Highscore\\HighScore.png");
}

void congratsImage(){
	congrats = iLoadImage("Gamebg\\congrats.png");
}
///////////////////////////////////////////////////////////


//////////////////////////////////////////////////

/*
	these variables are declared to show the menubars and the selected menus 

	these variables allows us to control the menu according to the game plan

	all of these variables are named after its work

*/
int selectMenu = 0;

int menuBarNumber = 1;
bool newGame = false;
bool loadGame = false;
bool highScore = false;
bool options = false;
bool about = false;
bool aboutUs = false;
bool ex = false;
int exitButton = 1;
bool returnToMainMenu = true;
/////////////////////////////////////////////////

//int bgMovedy = 0;

/////////////////////////////////
/// for back button
/*
	these variables gives us the ability to control the option menu
	(option to controls // controls to option // option to main menu)
*/
int newg = 0;
bool opt = true;
int opttomain = 0;

//////////////////////////////



/*
	makeReturnToMainMenu() makes all the initial variables to zero after every menu change and also when
		we return from a game or any menu bar

*/


void makeRetuenToMainMenuTrue();
void showMenu();
void dropMenu();
void upMenu();
void changeMenu();
void NewGame();
void LoadGame();
void HighScore();
void Options();
void About();
void Exit();
void Menu();


void makeRetuenToMainMenuTrue(){

	returnToMainMenu = true;
	selectMenu = 0;
	menuBarNumber = 1;
	newGame = false;
	startGame = false;
	loadGame = false;
	highScore = false;
	options = false;
	about = false;
	aboutUs = false;
	exitButton = 1;
	ex = false;
	newg = 0;
	opt = true;
	opttomain = 0;
	makeLoadGameNumberToZero();
	restartGame = 2;
	killboss = 0;
	ourCraft.score = 0;
	boss[0].life = 200;
	boss[1].life = 200;
	boss[2].life = 200;
	bgMovedy = 0;
	fireBallLeft = 5;
	fireBallbool = false;
	boss[0].bossCor_Y = 860;
	boss[1].bossCor_Y = 860;
	boss[2].bossCor_Y = 860;
}

/*
	showMenu() function shows us the the bg image of the
	menu and also the menu bars of main menu

*/

void showMenu(){
	if(menuBarNumber){
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, menu);
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, menuButton[menuBarNumber - 1]);
	}
}





/*
	dropMenu() helps to navigate the manu bars from top to bottom
	when the user tries to go down the menu multiple times
	this functon locks the menu bar in exit position
*/
void dropMenu(){
    if(!newGame && !loadGame && !highScore && !options && !about && !ex)
	{
		menuBarNumber +=1;
	}
    if(menuBarNumber >= 6){
        menuBarNumber = 6;
    }
}


/*
	upManu() helps us to navigate the menu bars from bottom to top 
	when the user tries to go up the menu multiple times

	this function locks the menu bar in new game position
*/
void upMenu(){
	if(!newGame && !loadGame && !highScore && !options && !about && !ex)
	{
		menuBarNumber -= 1;
	}
    if(menuBarNumber <=1){
        menuBarNumber = 1;
    }
}


/* 
	changeMenu function helps us to detect whenever the user select a menu to mone on
	see the NewGame(), LoadGame(), Highscore(), Options(), About() funtions for further query
*/
void changeMenu(){
	if(menuBarNumber == 1)
	{
		selectMenu = 1;
	}
	else if(menuBarNumber == 2)
	{
		selectMenu = 2;
	}
	else if(menuBarNumber == 3)
	{
		selectMenu = 3;
	}
	else if(menuBarNumber == 4)
	{
		selectMenu = 4;
	}
	else if(menuBarNumber == 5)
	{
		selectMenu = 5;
	}
	else if(menuBarNumber == 6)
	{
		selectMenu = 6;	
	}
}

/*
	game starts from this function and also all the level functiona will be called here to start the game

	in new game all the new game functuions and exit picture is called
*/


void NewGame(){
	if(menuBarNumber == 1 && selectMenu == 1){
		newGame = true;
		startGame = true;
		returnToMainMenu = false;
		if(newg == 0){
			if(killboss == 0){
				iShowImage(0, 0 + bgMovedy, SCREENWIDTH, 5000, newgame);
				Level1();
			}
			if(killboss == 1){
				iShowImage(0, 0 + bgMovedy, SCREENWIDTH, 5000, level[1]);
				Level1();
			}
			if(killboss == 2){
				iShowImage(0, 0 + bgMovedy, SCREENWIDTH, 5000, level[2]);
				Level1();
			}
			if(killboss == 3){
				iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, congrats);
			}
		}
		if(newg == 1){
			iShowImage(350, 150, 600, 400, exitt);
		}
		if(newg == 2){
			initialize();
			makeRetuenToMainMenuTrue();
			killboss = 0;
			ourCraft.score = 0;
		}
	}
}





/*
	loag game will start from here. all the function of load Game will be called here for further playing
*/


void LoadGame(){
	if(menuBarNumber == 2 && selectMenu == 2){
		
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, loadgame);
		loadGame = true;
		returnToMainMenu = false;
		makeOpenLoadGameTrue();
		showLoadGameMenuBar();	
		startLoadGame();
	}	
}




/*
	it show us the highscore and also the bgImage of HighScore
*/
void HighScore(){
	if(menuBarNumber == 3 && selectMenu == 3){
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, highscore);
		highScore = true;
		returnToMainMenu = false;
		readFile();
	}	
}




/*
	all the options function will be called here for further functionalities

	also to controls the music
*/
void Options(){
	if(menuBarNumber == 4 && selectMenu == 4){
		showOptionbg();
		musicMenu();
		options = true;
		returnToMainMenu = false;
		if(controls){
			if(opt){
				showControls();
			}
		}
	}
}




/*
	it show the about image and also shows the story of the game
*/
void About(){
	if(menuBarNumber == 5 && selectMenu == 5){
		if(aboutUs)
			iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, story);
		else
			iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, aboutt);
		about = true;
		returnToMainMenu = false;
	}
}




/*
	it show us the exit image and also performs the exit fuctionalities
*/
void Exit(){
	if(menuBarNumber == 6 && selectMenu == 6){
		ex = true;
		if(ex){
			iShowImage(350, 150, 600, 400, exitt); /// pic size is 600 X 400
			if(exitButton == 2){
				exit(0);
			}
		}
		if(exitButton == 3){
			makeRetuenToMainMenuTrue();
		}
	}
}





/*

	this funtion calls all the functions above and this function is called in main
*/

void Menu(){
	if(returnToMainMenu){
		showMenu();
	}
	NewGame();
	LoadGame();
	HighScore();
	Options();
	About();
	Exit();
}



#endif // MENU_H_INCLUDED
