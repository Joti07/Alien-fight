#ifndef OPTIONSYSTEM_H_INCLUDED
#define OPTIONSYSTEM_H_INCLUDED

#include"music.h"

//////////////////////////////////////////////////////////

/*
	these variables contains the integer values of all the pictures element
	and the function helps us to load the images before the game

*/

int optionbg;
int gamesound[2];
int gamesoundOnClick[2];
int firesound[2];
int firesoundOnClick[2];
int controlss;
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

	controlss = iLoadImage("Options\\Controls.png");
}

///////////////////////////////////////////////////////////

bool controls = false; ////// if the player is in controls section this variable turn true and let he program know it
bool backtooptions = false; /////// this is used to back to go back to the main menu




void showOptionbg();
void musicMenu();
void showControls();

/*
	this function shows the image of the option menu system
*/
void showOptionbg(){
	iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, optionbg);
}

/*
	this function controls the on of animation of the option system

	this function depends on the music.h header file
*/

void musicMenu(){
	if(!menuMusicOn){
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, gamesound[0]);
		iShowBMP2(0, 0, "Options\\offClick.bmp", 0);
	}
	if(menuMusicOn){
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, gamesound[1]);
		iShowBMP2(0, 0, "Options\\onClick.bmp", 0);
	}
}

////////////////////////////////////////////////////
//// for test purpose


void fireSoundMenu(){
	if(!menuMusicOn){
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, firesound[0]);
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, firesoundOnClick[1]);
	}
	if(menuMusicOn){
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, firesound[1]);
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, firesoundOnClick[0]);
	}
}
/////////////////////////////////////////////////////



/*
	when the player click the controls section the player will be able to go to the controls section of the option system
*/
void showControls(){
	iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, controlss);
}


#endif