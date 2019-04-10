#ifndef LOADGAME_H_INCLUDED
#define LOADGAME_H_INCLUDED
//#include "AllPictures.h"
//#include"Allheaderfiles.h"
#include"levels.h"
//////////////////////////////////

/*

	the variables are declared to store the valus of the pictures and
	the function is used to load the png images before the game

	see main function to for declaration
*/



int loadgameButton[3];
int level[3];
int ex1;
void loadgameMenu(){
	
	level[0] = iLoadImage("Gamebg\\level1.png");
	level[1] = iLoadImage("Gamebg\\level2.png");
	level[2] = iLoadImage("Gamebg\\level3.png");

	loadgameButton[0] = iLoadImage("Loadgame\\level1Button.png");
	loadgameButton[1] = iLoadImage("Loadgame\\level2Button.png");
	loadgameButton[2] = iLoadImage("Loadgame\\level3Button.png");
	ex1 = iLoadImage("Menu\\sure.png");
}


/////////////////////////////////////


////////////////////////////////////////

/*
	this variables are declared to control the load gaame menu inside the 

	main menu. this also works as main menu

	the variables work as the name follows
*/

int selectLoadGame = 0;
int loadGameNumber = 1;
bool level1 = false;
bool level2 = false;
bool level3 = false;
bool openLoadGame = false;
////////////////////////////////////////
/// for back button

int loadg = 0; /// this variabe is used to back to load game from a game inside the load game

int bgMovedy = 0;

void bgMove();
void makeLoadGameNumberToZero();
void makeOpenLoadGameTrue();
void rightShift();
void leftShift();
void changeLoadGame();
void showLoadGameMenuBar();
void startLevel1();
void startLevel2();
void startLevel3();
void startLoadGame();


/* this function moves the backgraound of all levels*/
void bgMove(){
	if(bgMovedy != -4244)
		bgMovedy -= 1;
	else
		bgMovedy = -4244;
}




/*
	this makes all the loadGame variables to zero when any load game is finished and also if the players return to 
	the load game menu
*/
void makeLoadGameNumberToZero(){

	openLoadGame = false;
	loadGameNumber = 1;
	level1 = false;
	level2 = false;
	level3 = false;
	selectLoadGame = 0;
	loadg = 0;
	loadGameLevel1 = false;
	loadGameLevel2 = false;
	loadGameLevel3 = false;
	initialize();
	killboss = 0;
	restartGame = 2;
	bgMovedy = 0;

}



/*
	when the player selects the load Game option then this function makes openLoadGame to true 
	and we can enter the load Game menu section
*/
void makeOpenLoadGameTrue(){
	openLoadGame = true;
}


/*
	this function helps us to show the loadGame bar images according to the user from left to right
*/

void rightShift(){
	if(!level1 && !level2 && !level3){
		loadGameNumber++;
	}
	if(loadGameNumber >= 3){
		loadGameNumber = 3;
	}
}


/*
	this function helps us to show the loadGame bar images according to the user from right to left
*/


void leftShift(){
	if(!level1 && !level2 && !level3){
		loadGameNumber--;
	}
	if(loadGameNumber <= 1){
		loadGameNumber = 1;
	}
}


/*
	this function helps us to track the player when he is trying to move the loadGamebars and whicjh level he has selected
		(same as changeMenu() in Menu.h)

*/

void changeLoadGame(){

	if(loadGameNumber == 1 && openLoadGame){

		selectLoadGame = 1;
		ourCraft.score = 0;
		killboss = 0;
		initialize();
		ourCraft.life = 200;
		boss[0].life = 200;
	}
	else if(loadGameNumber == 2 && openLoadGame){

		selectLoadGame = 2;
		ourCraft.score = 3100;
		killboss = 1;
		initialize();
		ourCraft.life = 200;
		boss[1].life = 200;

	}
	else if(loadGameNumber == 3 && openLoadGame){
		selectLoadGame = 3;
		ourCraft.score = 8100;
		killboss = 2;
		initialize();
		ourCraft.life = 200;
		boss[2].life = 200;
	}
}

/*
	this fuction is called in LoadGame() function in Menu.h
	this shows the images of the menuBars
*/

void showLoadGameMenuBar(){
	
	if(loadGameNumber == 1){
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, loadgameButton[0]);
	}
	if(loadGameNumber == 2){
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, loadgameButton[1]);
	}
	if(loadGameNumber == 3){
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, loadgameButton[2]);
	}
}


////////////////////////////

/*
	this is where level 1 will start
	inside the 2nd if condition

*/

void startLevel1(){

	if(loadGameNumber == 1 && selectLoadGame == 1){
		iShowImage(0, 0 + bgMovedy, SCREENWIDTH, 5000, level[0]);
		startGame = true;
		loadGameLevel1 = true;
		loadGameLevel2 = false;
		loadGameLevel3 = false;     
		loadLevel1();
		level1 = true;
		openLoadGame = false;
		if(loadg == 1){

			iShowImage(350, 150, 600, 400, ex1);

		}
		if(loadg == 2){

			makeLoadGameNumberToZero();

		}
	}
}

/*
	this is where level 2 will start
	inside the 2nd if condition

*/


void startLevel2(){
	if(loadGameNumber == 2 && selectLoadGame == 2){
		iShowImage(0, 0 + bgMovedy, SCREENWIDTH, 5000, level[1]);
		startGame = true;
		loadGameLevel1 = false;
		loadGameLevel2 = true;
		loadGameLevel3 = false;
		//Level1();
		loadLevel1();
		level2 = true;
		openLoadGame = false;
		if(loadg == 1){
			iShowImage(350, 150, 600, 400, ex1);
		}
		if(loadg == 2){
			makeLoadGameNumberToZero();
		}
	}
}


/*
	this is where level 3 will start
	inside the 2nd if condition

*/

void startLevel3(){
	if(loadGameNumber == 3 && selectLoadGame == 3){
		iShowImage(0, 0 + bgMovedy, SCREENWIDTH, 5000, level[2]);
		startGame = true;
		loadGameLevel1 = false;
		loadGameLevel2 = false;
		loadGameLevel3 = true;
		//Level1();
		loadLevel1();
		level3 = true;
		openLoadGame = false;
		if(loadg == 1){
			iShowImage(350, 150, 600, 400, ex1);
		}
		if(loadg == 2){
			makeLoadGameNumberToZero();
		}

	}
}

/*
	this is called in LoadGame in Menu.h
	
	this functios handles all the loadGame functionalities

*/
void startLoadGame(){
	startLevel1();
	startLevel2();
	startLevel3();
}

#endif // LOADGAME_H_INCLUDED