#ifndef BOSS_H_INCLUDED
#define BOSS_H_INCLUDED
#include "gamePlay.h"
int bos=220;

// Structure for boss
// all the variable for boss are here

struct boss{
	int bossCor_X;
	int bossCor_Y;
	int bossCor_YFinal;
	int bossMove;
	int bossBulletSpeed;
	int bossMiddleBulletCor_X;
	int bossMiddleBulletCor_Y;
	int dxm;
	int dym;
	bool bossMiddleBulletHit;

	int bossLeftBulletCor_X;
	int bossLeftBulletCor_Y;
	int dxl;
	int dyl;
	bool bossLeftBulletHit;

	int bossRightBulletCor_X;
	int bossRightBulletCor_Y;
	int dxr;
	int dyr;
	bool bossRightBulletHit;
	int life;
	
	// Constructor which initialize the value,,
	// for controling the boss..
	boss(){
		bossCor_Y = (1200/2);
		bossCor_X = 860;
		bossCor_YFinal = 550;
		bossMove = 5;
		bossBulletSpeed = 10;

		dxm = 78;
		dym = 84;
		dxl = 5;
		dyl = 84;
		dxr = 145;
		dyr = 84;
		life = 200;

		bossMiddleBulletCor_X = (bossCor_X + dxm);
		bossMiddleBulletCor_Y = (bossCor_Y + dym);
		bossMiddleBulletHit = false;

		bossLeftBulletCor_X = (bossCor_X + dxl);
		bossLeftBulletCor_Y = (bossCor_Y + dyl);
		bossLeftBulletHit = false;

		bossRightBulletCor_X = (bossCor_X + dxr);
		bossRightBulletCor_Y = (bossCor_Y + dyr);
		bossRightBulletHit = false;

		bossBulletSpeed = 10;
		
	}

}boss[3]; // three boss for three level 


// Prototype Declearation 
// all the function we have in this header file..
void boss1Life();
void changeBoss();
void showBossMiddleBullet();
void bossMiddleBullet();
void showBossLeftBullet();
void bossLeftBullet();
void showBossRightBullet();
void bossRightBullet();
void showBoss();
void bossMovement();
void boss1Fire();
void bossKill();


// this function controls the life of the boss
// in here we have collusion,,
// decrement of life for boss..
void boss1Life(){
	if(killboss == 0 || loadGameLevel1){

		// this block of code is the condition for collusion of,
		// our space craft bullet and boss 
		if(ourCraft.bulletY > boss[0].bossCor_Y && ourCraft.bulletY < boss[0].bossCor_Y + 165){
			if(ourCraft.bulletX > boss[0].bossCor_X && ourCraft.bulletX < boss[0].bossCor_X + 185){
				boss[0].life -= 1; // decrement of boss life

				// if boss life is less than 1
				// boss life will not decrement anymore
				// because the the boss will be dead then :v
				if(boss[0].life < 1){
					boss[0].life = 1;
				}
			}
		}	
	}

	// this block of code is the condition for collusion of,
	// our space craft bullet and boss 
	if(killboss == 1 || loadGameLevel2){

		// if boss life is less than 1
		// boss life will not decrement anymore
		// because the the boss will be dead then :v
		if(ourCraft.bulletY > boss[1].bossCor_Y && ourCraft.bulletY < boss[1].bossCor_Y + 165){
			if(ourCraft.bulletX > boss[1].bossCor_X && ourCraft.bulletX < boss[1].bossCor_X + 185){
				boss[1].life -= 1;
				if(boss[1].life < 1){
					boss[1].life = 1;
				}
			}
		}
	}


	if(killboss == 2 || loadGameLevel3){

		// this block of code is the condition for collusion of,
		// our space craft bullet and boss 
		if(ourCraft.bulletY > boss[2].bossCor_Y && ourCraft.bulletY < boss[2].bossCor_Y + 165){
			if(ourCraft.bulletX > boss[2].bossCor_X && ourCraft.bulletX < boss[2].bossCor_X + 185){
				boss[2].life -= 1;

				// if boss life is less than 1
				// boss life will not decrement anymore
				// because the the boss will be dead then :v
				if(boss[2].life < 1){
					boss[2].life = 1;
				}
			}
		}	
	}
}



void changeBoss(){
	if(startGame && ourCraft.score > 3000 && (killboss == 0 || loadGameLevel1)){
		if(boss[0].bossCor_Y <= 0){
			boss[0].bossCor_Y = 860;
		}
		boss[0].bossCor_Y -= 5;
		if(boss[0].bossCor_Y <= boss[0].bossCor_YFinal){
			boss[0].bossCor_Y = boss[0].bossCor_YFinal;
		}
	}

	if(startGame && (killboss == 1 || loadGameLevel2) && ourCraft.score > 8000){
		if(boss[1].bossCor_Y <= 0){
			boss[1].bossCor_Y = 860;
		}
		boss[1].bossCor_Y -= 5;
		if(boss[1].bossCor_Y <= boss[1].bossCor_YFinal){
			boss[1].bossCor_Y = boss[1].bossCor_YFinal;
		}	
	}
	if(startGame && (killboss == 2 || loadGameLevel3) && ourCraft.score > 13000){
		if(boss[2].bossCor_Y <= 0){
			boss[2].bossCor_Y = 860;
		}
		boss[2].bossCor_Y -= 5;
		if(boss[2].bossCor_Y <= boss[2].bossCor_YFinal){
			boss[2].bossCor_Y = boss[2].bossCor_YFinal;
		}	
	}
}



//int t1 = 5;

// this function is onlu for displaying the boss middle bullet
void showBossMiddleBullet(){

	// for level 1
	if(startGame && ourCraft.score > 3000 && (killboss == 0 || loadGameLevel1)){
		// this is for displaying the middle bullet
		// if the bullet hit our craft,,
		// is will be disappeared.
		if(!boss[0].bossMiddleBulletHit){
			iShowBMP2(boss[0].bossMiddleBulletCor_X, boss[0].bossMiddleBulletCor_Y,"enemy\\gunShot\\gun2.bmp",0);
		}
	}

	// for level 2
	if(startGame && (killboss == 1 || loadGameLevel2) && ourCraft.score > 8000){
		// this is for displaying the middle bullet
		// if the bullet hit our craft,,
		// is will be disappeared.
		if(!boss[1].bossMiddleBulletHit){
			iShowBMP2(boss[1].bossMiddleBulletCor_X, boss[1].bossMiddleBulletCor_Y,"enemy\\gunShot\\gun2.bmp",0);
		}
	}

	// for level 3
	if(startGame && (killboss == 2 || loadGameLevel3) && ourCraft.score > 13000){
		// this is for displaying the middle bullet
		// if the bullet hit our craft,,
		// is will be disappeared.
		if(!boss[2].bossMiddleBulletHit){
			iShowBMP2(boss[2].bossMiddleBulletCor_X, boss[2].bossMiddleBulletCor_Y,"enemy\\gunShot\\gun2.bmp",0);
		}
	}
}

// and this function controls the boss middle bullet  :-)
void bossMiddleBullet(){

	//////// For Level 1
	if(startGame && ourCraft.score > 3000 && (killboss == 0 || loadGameLevel1)){
		
		// if boss middle bullet crosses -84,,
		// the bullet will throw back to the boss,,
		// which we can call realoading
		// we use the same bullet over and over again
		if(boss[0].bossMiddleBulletCor_Y < -boss[0].dym){
			boss[0].bossMiddleBulletCor_X = (boss[0].bossCor_X + boss[0].dxm);
			boss[0].bossMiddleBulletCor_Y = (boss[0].bossCor_Y + boss[0].dym);
			boss[0].bossMiddleBulletHit = false;
		}
		boss[0].bossMiddleBulletCor_Y -= boss[0].bossBulletSpeed;
		
		// this block of code is for the collusion of our craft and boss middle bullet
		// if the bullet hit our craft
		// our life will decrease
		// and the bullet will be disappeared.
		if(boss[0].bossMiddleBulletCor_Y < ourCraft.ourY + 77 && boss[0].bossMiddleBulletCor_Y > ourCraft.ourY){
			if(boss[0].bossMiddleBulletCor_X > ourCraft.ourX && boss[0].bossMiddleBulletCor_X < ourCraft.ourX + 100){
				boss[0].bossMiddleBulletHit = true;
				ourCraft.life -= 3;
			}
		}
	}
	
	//////// For Level 2
	if(startGame && (killboss == 1 || loadGameLevel2) && ourCraft.score > 8000){
		// if boss middle bullet crosses -84,,
		// the bullet will throw back to the boss,,
		// which we can call realoading
		// we use the same bullet over and over again
		if(boss[1].bossMiddleBulletCor_Y < -boss[1].dym){
			boss[1].bossMiddleBulletCor_X = (boss[1].bossCor_X + boss[1].dxm);
			boss[1].bossMiddleBulletCor_Y = (boss[1].bossCor_Y + boss[1].dym);
			boss[1].bossMiddleBulletHit = false;
		}
		boss[1].bossMiddleBulletCor_Y -= boss[1].bossBulletSpeed;
		
		// this block of code is for the collusion of our craft and boss middle bullet
		// if the bullet hit our craft
		// our life will decrease
		// and the bullet will be disappeared.
		if(boss[1].bossMiddleBulletCor_Y < ourCraft.ourY + 77 && boss[1].bossMiddleBulletCor_Y > ourCraft.ourY){
			if(boss[1].bossMiddleBulletCor_X > ourCraft.ourX && boss[1].bossMiddleBulletCor_X < ourCraft.ourX + 100){
				boss[1].bossMiddleBulletHit = true;
				ourCraft.life -= 3;
			}
		}	
	}

	//////// For Level 3
	if(startGame && (killboss == 2 || loadGameLevel3) && ourCraft.score > 13000){
		// if boss middle bullet crosses -84,,
		// the bullet will throw back to the boss,,
		// which we can call realoading
		// we use the same bullet over and over again
		if(boss[2].bossMiddleBulletCor_Y < -boss[2].dym){
			boss[2].bossMiddleBulletCor_X = (boss[2].bossCor_X + boss[2].dxm);
			boss[2].bossMiddleBulletCor_Y = (boss[2].bossCor_Y + boss[2].dym);
			
			boss[2].bossMiddleBulletHit = false;
		}
		boss[2].bossMiddleBulletCor_Y -= boss[2].bossBulletSpeed;
		
		// this block of code is for the collusion of our craft and boss middle bullet
		// if the bullet hit our craft
		// our life will decrease
		// and the bullet will be disappeared.
		if(boss[2].bossMiddleBulletCor_Y < ourCraft.ourY + 77 && boss[2].bossMiddleBulletCor_Y > ourCraft.ourY){
			if(boss[2].bossMiddleBulletCor_X > ourCraft.ourX && boss[2].bossMiddleBulletCor_X < ourCraft.ourX + 100){
				boss[2].bossMiddleBulletHit = true;
				ourCraft.life -= 3;
			}
		}	

	}

}


// this function is onlu for displaying the boss middle bullet
void showBossLeftBullet(){
	/////////// For Level 1
	if(startGame && ourCraft.score > 3000 && (killboss == 0 || loadGameLevel1)){
		// this is for displaying the left bullet
		// if the bullet hit our craft,,
		// is will be disappeared.
		if(!boss[0].bossLeftBulletHit){
			iShowBMP2(boss[0].bossLeftBulletCor_X, boss[0].bossLeftBulletCor_Y,"enemy\\gunShot\\gun2.bmp",0);
		}
	}

	/////////// For Level 2
	if(startGame && (killboss == 1 || loadGameLevel2) && ourCraft.score > 8000){
		// this is for displaying the left bullet
		// if the bullet hit our craft,,
		// is will be disappeared.
		if(!boss[1].bossLeftBulletHit){
			iShowBMP2(boss[1].bossLeftBulletCor_X, boss[1].bossLeftBulletCor_Y,"enemy\\gunShot\\gun2.bmp",0);
		}	
	}

	/////////// For Level 3
	if(startGame && (killboss == 2 || loadGameLevel3) && ourCraft.score > 13000){
		// this is for displaying the left bullet
		// if the bullet hit our craft,,
		// is will be disappeared.
		if(!boss[2].bossLeftBulletHit){
			iShowBMP2(boss[2].bossLeftBulletCor_X, boss[2].bossLeftBulletCor_Y,"enemy\\gunShot\\gun2.bmp",0);
		}
	}
}

// and this function controls the boss middle bullet  :-)
void bossLeftBullet(){
	
	////////// For level 1
	if(startGame && ourCraft.score > 3000 && (killboss == 0 || loadGameLevel1)){
		// if boss middle bullet crosses -84,,
		// the bullet will throw back to the boss,,
		// which we can call realoading
		// we use the same bullet over and over again
		if(boss[0].bossLeftBulletCor_Y < -boss[0].dyl){
			boss[0].bossLeftBulletCor_X = (boss[0].bossCor_X + boss[0].dxl);
			boss[0].bossLeftBulletCor_Y = (boss[0].bossCor_Y + boss[0].dyl);
			
			boss[0].bossLeftBulletHit = false;
		}
		boss[0].bossLeftBulletCor_Y -= boss[0].bossBulletSpeed;
		
		// this block of code is for the collusion of our craft and boss middle bullet
		// if the bullet hit our craft
		// our life will decrease
		// and the bullet will be disappeared.
		if(boss[0].bossLeftBulletCor_Y < ourCraft.ourY + 77 && boss[0].bossLeftBulletCor_Y > ourCraft.ourY){
			if(boss[0].bossLeftBulletCor_X > ourCraft.ourX && boss[0].bossLeftBulletCor_X < ourCraft.ourX + 100){
				boss[0].bossLeftBulletHit = true;
				ourCraft.life -= 3;
			}
		}
	}

	////////// For level 2
	if(startGame && (killboss == 1 || loadGameLevel2) && ourCraft.score > 8000){
		// if boss middle bullet crosses -84,,
		// the bullet will throw back to the boss,,
		// which we can call realoading
		// we use the same bullet over and over again
		if(boss[1].bossLeftBulletCor_Y < -boss[1].dyl){
			boss[1].bossLeftBulletCor_X = (boss[1].bossCor_X + boss[1].dxl);
			boss[1].bossLeftBulletCor_Y = (boss[1].bossCor_Y + boss[1].dyl);
			
			boss[1].bossLeftBulletHit = false;
		}
		boss[1].bossLeftBulletCor_Y -= boss[1].bossBulletSpeed;
		
		// this block of code is for the collusion of our craft and boss middle bullet
		// if the bullet hit our craft
		// our life will decrease
		// and the bullet will be disappeared.
		if(boss[1].bossLeftBulletCor_Y < ourCraft.ourY + 77 && boss[1].bossLeftBulletCor_Y > ourCraft.ourY){
			if(boss[1].bossLeftBulletCor_X > ourCraft.ourX && boss[1].bossLeftBulletCor_X < ourCraft.ourX + 100){
				boss[1].bossLeftBulletHit = true;
				ourCraft.life -= 3;
			}
		}
	}

	////////// For level 3
	if(startGame && (killboss == 2 || loadGameLevel3) && ourCraft.score > 13000){
		// if boss middle bullet crosses -84,,
		// the bullet will throw back to the boss,,
		// which we can call realoading
		// we use the same bullet over and over again
		if(boss[2].bossLeftBulletCor_Y < -boss[2].dyl){
			boss[2].bossLeftBulletCor_X = (boss[2].bossCor_X + boss[2].dxl);
			boss[2].bossLeftBulletCor_Y = (boss[2].bossCor_Y + boss[2].dyl);
			
			boss[2].bossLeftBulletHit = false;
		}
		boss[2].bossLeftBulletCor_Y -= boss[2].bossBulletSpeed;
		
		// this block of code is for the collusion of our craft and boss middle bullet
		// if the bullet hit our craft
		// our life will decrease
		// and the bullet will be disappeared.
		if(boss[2].bossLeftBulletCor_Y < ourCraft.ourY + 77 && boss[2].bossLeftBulletCor_Y > ourCraft.ourY){
			if(boss[2].bossLeftBulletCor_X > ourCraft.ourX && boss[2].bossLeftBulletCor_X < ourCraft.ourX + 100){
				boss[2].bossLeftBulletHit = true;
				ourCraft.life -= 3;
			}
		}	
	}
}

// this function is onlu for displaying the boss middle bullet
void showBossRightBullet(){
	//////// For Level 1
	if(startGame && ourCraft.score > 3000 && (killboss == 0 || loadGameLevel1)){
		// Same as middle and left bullet
		if(!boss[0].bossRightBulletHit){
			iShowBMP2(boss[0].bossRightBulletCor_X, boss[0].bossRightBulletCor_Y,"enemy\\gunShot\\gun2.bmp",0);
		}
	}

	//////// For Level 2
	if(startGame && (killboss == 1 || loadGameLevel2) && ourCraft.score > 8000){
		// Same as middle and left bullet
		if(!boss[1].bossRightBulletHit){
			iShowBMP2(boss[1].bossRightBulletCor_X, boss[1].bossRightBulletCor_Y,"enemy\\gunShot\\gun2.bmp",0);
		}	
	}

	//////// For Level 3
	if(startGame && (killboss == 2 || loadGameLevel3) && ourCraft.score > 13000){
		// Same as middle and left bullet
		if(!boss[2].bossRightBulletHit){
			iShowBMP2(boss[2].bossRightBulletCor_X, boss[2].bossRightBulletCor_Y,"enemy\\gunShot\\gun2.bmp",0);
		}		
	}
}

// and this function controls the boss middle bullet  :-)
void bossRightBullet(){
	//////// For Level 1
	if(startGame && ourCraft.score > 3000 && (killboss == 0 || loadGameLevel1)){
		// Same as middle and left bullet
		if(boss[0].bossRightBulletCor_Y < -84){
			boss[0].bossRightBulletCor_X = (boss[0].bossCor_X + boss[0].dxr);
			boss[0].bossRightBulletCor_Y = (boss[0].bossCor_Y + boss[0].dyr);
			boss[0].bossRightBulletHit = false;
		}
		boss[0].bossRightBulletCor_Y -= boss[0].bossBulletSpeed;
		
		// Same as middle and left bullet
		if(boss[0].bossRightBulletCor_Y < ourCraft.ourY + 77 && boss[0].bossRightBulletCor_Y > ourCraft.ourY){
			if(boss[0].bossRightBulletCor_X > ourCraft.ourX && boss[0].bossRightBulletCor_X < ourCraft.ourX + 100){
				boss[0].bossRightBulletHit = true;
				ourCraft.life -= 3;
			}
		}
	}

	//////// For Level 2
	if(startGame && (killboss == 1 || loadGameLevel2) && ourCraft.score > 8000){
		// Same as middle and left bullet
		if(boss[1].bossRightBulletCor_Y < -84){
			boss[1].bossRightBulletCor_X = (boss[1].bossCor_X + boss[1].dxr);
			boss[1].bossRightBulletCor_Y = (boss[1].bossCor_Y + boss[1].dyr);
			boss[1].bossRightBulletHit = false;
		}
		boss[1].bossRightBulletCor_Y -= boss[1].bossBulletSpeed;
		
		// Same as middle and left bullet
		if(boss[1].bossRightBulletCor_Y < ourCraft.ourY + 77 && boss[1].bossRightBulletCor_Y > ourCraft.ourY){
			if(boss[1].bossRightBulletCor_X > ourCraft.ourX && boss[1].bossRightBulletCor_X < ourCraft.ourX + 100){
				boss[1].bossRightBulletHit = true;
				ourCraft.life -= 3;
			}
		}
	}

	//////// For Level 3
	if(startGame && (killboss == 2 || loadGameLevel3) && ourCraft.score > 13000){
		// Same as middle and left bullet
		if(boss[2].bossRightBulletCor_Y < -84){
			boss[2].bossRightBulletCor_X = (boss[2].bossCor_X + boss[2].dxr);
			boss[2].bossRightBulletCor_Y = (boss[2].bossCor_Y + boss[2].dyr);
			boss[2].bossRightBulletHit = false;
		}
		boss[2].bossRightBulletCor_Y -= boss[2].bossBulletSpeed;
		
		// Same as middle and left bullet
		if(boss[2].bossRightBulletCor_Y < ourCraft.ourY + 77 && boss[2].bossRightBulletCor_Y > ourCraft.ourY){
			if(boss[2].bossRightBulletCor_X > ourCraft.ourX && boss[2].bossRightBulletCor_X < ourCraft.ourX + 100){
				boss[2].bossRightBulletHit = true;
				ourCraft.life -= 3;
			}
		}
	}
}


// This function is for moving the boss
// to left and right
void bossMovement(){

	//////// For Level 1
	if(startGame && ourCraft.score > 3000 && (killboss == 0 || loadGameLevel1)){
		boss[0].bossCor_X += boss[0].bossMove;
		// changing the direction of movement
		// like left to right or 
		// right to left
		if(boss[0].bossCor_X > 1100 || boss[0].bossCor_X < 0){
			boss[0].bossMove *= (-1);
		}
	}

	//////// For Level 2
	if(startGame && (killboss == 1 || loadGameLevel2) && ourCraft.score > 8000){
		boss[1].bossCor_X += boss[1].bossMove;
		// changing the direction of movement
		// like left to right or 
		// right to left
		if(boss[1].bossCor_X > 1100 || boss[1].bossCor_X < 0){
			boss[1].bossMove *= (-1);
		}
	}

	//////// For Level 3
	if(startGame && (killboss == 2 || loadGameLevel3) && ourCraft.score > 13000){
		boss[2].bossCor_X += boss[2].bossMove;
		// changing the direction of movement
		// like left to right or 
		// right to left
		if(boss[2].bossCor_X > 1100 || boss[2].bossCor_X < 0){
			boss[2].bossMove *= (-1);
		}
	}
}


// boss fire three bullet at the same time
// so we make this function 
// to call the controling function of middle, left, and right bullet..
void boss1Fire(){
		bossMiddleBullet();
		bossLeftBullet();
		bossRightBullet();
}

// This is for Displaying the boss to screen
void showBoss(){

	////////// for Level 1
	// the boss will come when the score is more than 3000
	// also displaying the life bar
	if(startGame && ourCraft.score > 3000 && (killboss == 0 || loadGameLevel1)){
      iShowImage(boss[0].bossCor_X,boss[0].bossCor_Y,bos,bos,im5);
		

		iSetColor(255,0,0);
		iFilledRectangle(50,100, 20,boss[0].life);
		iSetColor(0,0,0);
		iRectangle(50, 100, 20, 200);
		if(boss[0].life < 4 && !loadGameLevel1){
			iShowBMP(0,0,"next.bmp");
		}
		// when the boss is dead a page will pop up 
		// asking for playing next level
		if(boss[0].life < 4 && loadGameLevel1){
			iShowBMP(0,0,"next1.bmp");
		} 
	}

	////////// for Level 2
	// the boss will come when the score is more than 8000
	// also displaying the life bar
	if(startGame && (killboss == 1 || loadGameLevel2) && ourCraft.score > 8000){
		    iShowImage(boss[1].bossCor_X,boss[0].bossCor_Y,bos,bos,im5);
	
		iSetColor(255,0,0);
		iFilledRectangle(50,100, 20,boss[1].life);
		iSetColor(0,0,0);
		iRectangle(50, 100, 20, 200);
		if(boss[1].life < 4 && !loadGameLevel2){
			iShowBMP(0,0,"next.bmp");
		}
		// when the boss is dead a page will pop up 
		// asking for playing next level
		if(boss[1].life < 4 && loadGameLevel2){
			iShowBMP(0,0,"next1.bmp");
		} 
	}

	////////// for Level 3
	// the boss will come when the score is more than 13000
	// also displaying the life bar
	if(startGame && (killboss == 2 || loadGameLevel3) && ourCraft.score > 13000){

		 iShowImage(boss[2].bossCor_X,boss[2].bossCor_Y,bos,bos,im5);
		
		iSetColor(255,0,0);
		iFilledRectangle(50,100, 20,boss[2].life);
		iSetColor(0,0,0);
		iRectangle(50, 100, 20, 200);
		if(boss[2].life < 4 && !loadGameLevel3){
			iShowBMP(0,0,"next.bmp");
		}

		// when the boss is dead a page will pop up 
		// asking for playing next level
		if(boss[2].life < 4 && loadGameLevel3){
			iShowBMP(0,0,"next1.bmp");
		}
	}
}

// this function is for initializing the value of kissboss
// which we used many time in our code 
// to seperate the 3 level  bosses
void bossKill(){
	if(boss[0].life < 4){
		killboss = 1;
	}
	if(boss[1].life < 4){
		killboss = 2;
	}
	if(boss[2].life < 4){
		killboss = 3;
	}
}

#endif