#ifndef INTRODUCTION_H_INCLUDED
#define INTRODUCTION_H_INCLUDED
#include"Allheaderfiles.h"
#include"fileInputOutput.h"
#include"loadGame.h"



int highLight = 0;//// helps to highlight the box where the player will give the input

//////////////////////////////////////////////////////////////////////////

/*
	this variables stores the integer values of the pictures

	and the functions help us to load the images before the game starts
	( see main function in iMain )
*/


int introduction1, introduction2, introduction3, introduction4;

char str[26];
int indexNumber = 0;
int saveName = 0;

void intro(){

	introduction1 = iLoadImage("intro\\intro-1.jpg");
	introduction2 = iLoadImage("intro\\intro-2.png");
	introduction3 = iLoadImage("intro\\intro-3.png");
	introduction4 = iLoadImage("intro\\login.png");

}
////////////////////////////////////////////////////////////////////


bool menuShow = false;//// helps us to show the main menu

int introCount = 1;//////////// this helps us to count how manty introduction has skipped by the player

/*
	this function helps the player to skip the intro backgrounds by pressing 'space'

*/



void increaseCount();
bool makeMenuShowTrue();
void saveNametoStruct();
void introbg();


void increaseCount(){
	if(introCount <= 5){
		introCount++;
	}
}

/*
	when player has entered the name, pressed enter and then pressed space this function will take the player to main menu

*/
bool makeMenuShowTrue(){
	if(introCount == 5){
		menuShow = true;
	}
	return menuShow;
}

/*
	this function saves the name to the person structure in fileInputOutput.h header file

	converts the name into uppercase and then copy the name to person variable p

*/

void saveNametoStruct(){

	char str2[26];

	strcpy(str2, str);
	int n = strlen(str2);
	for(int i = 0; i < n; i++){
		str2[i] = toupper(str2[i]);
	}

	strcpy(p.name, str2);

}

/*
	this function changes the intro pages according to the player and then
	show it to the screen

*/
void introbg(){

	bgMovedy = 0;

	if(introCount == 1){
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, introduction1);
	}
	if(introCount == 2){
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, introduction2);
	}	
	if(introCount == 3){
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, introduction3);
	}
	if(introCount == 4){
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, introduction4);
		if(highLight == 1){
			iSetColor(255, 255, 255);
			iFilledRectangle(422, 165, 401, 30);
			iSetColor(255, 0, 0);
			iText(425, 176, str, GLUT_BITMAP_TIMES_ROMAN_24);
			if(saveName == 1){
				iSetColor(255, 255, 255);
				iText(850, 175, "Name saved", GLUT_BITMAP_TIMES_ROMAN_24);
				saveNametoStruct();
			}
		}
	}
}



#endif