#ifndef LEVELS_H_INCLUDED
#define LEVELS_H_INCLUDED
//#include"gamePlay.h"
#include"boss.h"




/*
	all levels will be declared here and from here all the levels will be controlled

*/
void Level1(){

	playGame();
	enemyShip();
	gunShot();
	enemyCollution();
	fire();
	if(ourCraft.score > 3000){
		showBossMiddleBullet();
		showBossRightBullet();
		showBossLeftBullet();
		showBoss();
		changeBoss();
		boss1Life();
	}
	showSaveGamePic();
	
}


void loadLevel1(){
	playGame();
	enemyShip();
	gunShot();
	enemyCollution();
	fire();
	if(ourCraft.score > 3000){
		showBossMiddleBullet();
		showBossRightBullet();
		showBossLeftBullet();
		showBoss();
		changeBoss();
		boss1Life();
	}
	showSaveGamePic();
}
// for test pupose
void loadLevel2(){
	killboss = 1;
	killboss = 0;
	playGame();
	enemyShip();
	gunShot();
	enemyCollution();
	fire();
	if(ourCraft.score > 8000){
		showBossMiddleBullet();
		showBossRightBullet();
		showBossLeftBullet();
		showBoss();
		changeBoss();
		boss1Life();
	}
	showSaveGamePic();
}
// for test purpose
void loadLevel3(){
	killboss = 2;
	playGame();
	enemyShip();
	gunShot();
	enemyCollution();
	fire();
	if(ourCraft.score > 13000){
		showBossMiddleBullet();
		showBossRightBullet();
		showBossLeftBullet();
		showBoss();
		changeBoss();
		boss1Life();
	}
	showSaveGamePic();
}


///////////for load Game

#endif 