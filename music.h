#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;




bool menuMusicOn = false; ////// helps to control the musix on off system (when true; music is on , else off)
bool musicControl = false; ////// it controls the on off animation inside options


void playMenuMusic();
void stopMenuMusic();
void mouseControlForGameMusic(int mx, int my);

/*
	this function starts the music initially when the player starts the game
*/

void playMenuMusic(){
	if(menuMusicOn){
		PlaySound("space.wav", NULL, SND_LOOP| SND_ASYNC);
	}
}


/*
	it starts and stops the tmusic according to the player
	when off is clicked then misuc will be off
	when on is clicked music will be on

*/

void stopMenuMusic(){
	if(menuMusicOn)
		{
			menuMusicOn = false;
			PlaySound(0, 0, 0);

		}else{
			menuMusicOn = true;
			PlaySound("space.wav", NULL, SND_LOOP| SND_ASYNC);

		}
}


/*
	it handles the on off system of music.
	see iMain for further clarification

*/

void mouseControlForGameMusic(int mx, int my){
	if(!menuMusicOn){
		if(mx > 390 && mx < 480 && my > 510 && my < 553){
			PlaySound("space.wav", NULL, SND_LOOP| SND_ASYNC);
			menuMusicOn = true;
		}
	}

	if(menuMusicOn){
		if(mx > 500 && mx < 610 && my > 515 && my < 555){
			stopMenuMusic();
		}
	}
	musicControl = true;
}

////////////////////////////////////////////////

// test purpose
void mouseControlForFireMusic(int mx, int my){
	if(!menuMusicOn){
		if(mx > 741 && mx < 826 && my > 445 && my < 482){
			PlaySound("space.wav", NULL, SND_LOOP| SND_ASYNC);
			menuMusicOn = true;
		}
	}

	if(menuMusicOn){
		if(mx > 857 && mx < 960 && my > 445 && my < 482){
			stopMenuMusic();
		}
	}
}

#endif 