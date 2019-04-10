#ifndef ALLPICTURES_H_INCLUDED
#define ALLPICTURES_H_INCLUDED
#include"Allheaderfiles.h"
#define SCREENWIDTH  1280
#define SCREENHEIGHT 756



void intro();
void menuImage();
void newGameImage();
void loadGameImage();
void highScoreImage();
void optionImage();
void aboutImage();
void ExitImage();
void loadgameMenu();

/////////////////// introduction ////////////////////////////
int introduction1, introduction2, introduction3;

void intro(){
	introduction1 = iLoadImage("intro\\inro-1.png");
	introduction2 = iLoadImage("intro\\inro-2.png");
	introduction3 = iLoadImage("intro\\inro-3.png");
}
////////////////////////////////////////////////////////////

////////////////////// Menu ///////////////////////////////

int menu, menuButton[6];

void menuImage(){
	menu = iLoadImage("Menu\\Menu.png"); 
	menuButton[0] = iLoadImage("Menu\\NewGame.png");
	menuButton[1] = iLoadImage("Menu\\LoadGame.png");
	menuButton[2] = iLoadImage("Menu\\HighScore.png");
	menuButton[3] = iLoadImage("Menu\\Options.png");
	menuButton[4] = iLoadImage("Menu\\About.png");
	menuButton[5] = iLoadImage("Menu\\Exit.png");
}

////////////////////////////////////////////////////////

////////////// New Game /////////////////////
int newgame;
void newGameImage(){
	newgame = iLoadImage("Gamebg\\level1.png");
}

////////////////////////////////////////////

/////////////////// Load Game//////////////
int loadgame;
void loadGameImage(){
	loadgame = iLoadImage("Loadgame\\LevelSelect.png");
}
//////////////////////////////////////////

/////////////// HighScore ////////////////
int highscore;
void highScoreImage(){
	highscore = iLoadImage("Highscore\\HighScore.png");
}
//////////////////////////////////////////

///////////////// Option Image ////////////
int optionbg;
int gamesound[2];
int gamesoundOnClick[2];
int firesound[2];
int firesoundOnClick[2];
int controls;
void optionImage(){
	optionbg = iLoadImage("Options\\Options.png");
	
	gamesound[0] = iLoadImage("Options\\Gamesound On.png");
	gamesound[1] = iLoadImage("Options\\Gamesound off.png");
	
	gamesoundOnClick[0] = iLoadImage("Options\\onClick.png");
	gamesoundOnClick[1] = iLoadImage("Options\\offClick.png");
	
	firesound[0] = iLoadImage("Options\\firing sound on.png");
	firesound[1] = iLoadImage("Options\\firing sound off.png");
	
	firesoundOnClick[0] = iLoadImage("Options\\firing sound on onclick.png");
	firesoundOnClick[1] = iLoadImage("Options\\firing sound on onclick.png");

	controls = iLoadImage("Options\\Controls.png");
}
//////////////////////////////////////////

//////////////// About /////////////////
int about, story;

void aboutImage(){
	about = iLoadImage("About\\About.png");
	story = iLoadImage("About\\story.png");
}

//////////////////////////////////////

///////////////// Exit //////////////////////
int exit;
void ExitImage(){
	exit = iLoadImage("Menu\\sure.png");
}
//////////////////////////////////////////////

/////////// load Game/////////////////////////
int loadgameButton[3];
int level[3];

void loadgameMenu(){
	
	level[0] = iLoadImage("Gamebg\\level1.png");
	level[1] = iLoadImage("Gamebg\\level2.png");
	level[2] = iLoadImage("Gamebg\\level3.png");

	loadgameButton[0] = iLoadImage("Loadgame\\level1Button.png");
	loadgameButton[1] = iLoadImage("Loadgame\\level2Button.png");
	loadgameButton[2] = iLoadImage("Loadgame\\level3Button.png");
}
void allImages(){
	intro();
	menuImage();
	newGameImage();
	loadGameImage();
	highScoreImage();
	optionImage();
	aboutImage();
	ExitImage();
	loadgameMenu();

}
/////////////////////////////////////////////

#endif