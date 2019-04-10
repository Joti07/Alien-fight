#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED

bool fireBullet = false;// our ship fires bullet
bool fireBallbool = false;
bool startGame = false; 
int rcx=120;
int enm=150;


bool bulletCollision = false;
bool bulletCollision1 = false;
bool bulletCollision2 = false;
bool bulletCollision3 = false;

bool collution1 = false;
bool collution2 = false;
bool collution3 = false;
bool collution4 = false;
bool collission5 = false;
bool collission6 = false;
int fireBallLeft = 5;
int killboss = 0;
int im1,im2,im3,im4,im5;
int restartGame = 0;

int saveGame = 0;

bool loadGameLevel1 = false;
bool loadGameLevel2 = false;
bool loadGameLevel3 = false; 

int saveGamePic;
void loadSaveGamePic(){
	saveGamePic = iLoadImage("Menu\\GameOver.png");
}

void showSaveGamePic(){
	if(restartGame == 1)
		iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, saveGamePic);
}

///////text//////////
char buffer[20];
/////////////////////


/// Prototype Declearation...
void playGame();
void enemyShip();
void gunShot();
void change();
void changeGun();
void enemyCollution();
void saveScoretostruct();
void UP();
void DOWN();
void LEFT();
void RIGHT();
void fire();
void fireball();

// Structure for Enemy.. :-)
struct enemyCor{
	
	int corX; // x cordinate of enemy ship
	int corY; // y cordinate of enemy ship enemy 
	int gunCorX; // enemy's bullet x cordinate
	int gunCorY; // enemy's bullet y cordinate
	int x; // bullet will come throug the middle of the enemy, that's x some pixels has been added
	int y; //  bullet will come throug the middle of the enemy, that's y some pixels has been added
	int rockX;
	int rockY;	

	enemyCor(){

		
		x= 25;
		y = 35;
		gunCorX = (corX+x);
		gunCorY = (corY-y);
		rockX ;
		rockY ;
	}
	
}emyShip[6];


// Structure for our space craft 
struct ourShip{


	int ourX;
	int ourY;
	int bulletX;
	int bulletY;
	int score;
	int life;
	int fireBallX;
	int fireBallY;

	ourShip(){
		ourX = 500; // x cordinate of our ship
		ourY = 100; // y cordinate of our ship
		bulletX = (ourX + 24); // bullet will come throug the middle of our ship, that's y some pixels has been added
		life = 200; 
		fireBallX = (ourX + 24);
		fireBallY = (ourY + 45);
	}
}ourCraft;
/*
	
	void initialize() : initialize the position of The emeny craft by using Structure formed above. As we have 4 enemy the index on enemy array 
	goes from 0 to 3.

	emyShip[0].corX = X cordinate of enemy 
	emyShip[0].corY = Y cordinate of enemy

	as the bullets of enemy comes from the middle of the enemy. 

	emyShip[0].gunCorX = X cordinate of enemy's bullet
	emyShip[0].gunCorY = Y cordinate of enemy's bullet


*/
void initialize(){
	emyShip[0].corX = 200;
	emyShip[0].corY = 760;
	emyShip[0].gunCorX = (emyShip[0].corX + emyShip[0].x);
	emyShip[0].gunCorY = (emyShip[0].corY + emyShip[0].y);
	/////////
	emyShip[1].corX = 450;
	emyShip[1].corY = 760;
	emyShip[1].gunCorX = (emyShip[1].corX + emyShip[1].x);
	emyShip[1].gunCorY = (emyShip[1].corY + emyShip[1].y);
	/////////
	emyShip[2].corX = 600;
	emyShip[2].corY = 760;
	emyShip[2].gunCorX = (emyShip[2].corX + emyShip[2].x);
	emyShip[2].gunCorY = (emyShip[2].corY + emyShip[2].y);
	///////////
	emyShip[3].corX = 850;
	emyShip[3].corY = 760;
	emyShip[3].gunCorX = (emyShip[3].corX + emyShip[3].x);
	emyShip[3].gunCorY = (emyShip[3].corY + emyShip[3].y);
	/// rocks
	emyShip[4].rockX = 300;
	emyShip[4].rockY =760;

	emyShip[5].rockX = 750;
	emyShip[5].rockY =790;

	ourCraft.fireBallX = (ourCraft.ourX + 24);
	ourCraft.fireBallY = (ourCraft.ourY + 45);
}


/* 
	
	void playGame(): with iShowBMP2 we rendered Our Space ship and bullet of our space ship.

	ourCraft.ourX = X cordinate of our space ship
	ourCraft.ourY = Y cordinate of our space ship

	As the bullet of our ship comes from the middle of the space ship.

	ourCraft.bulletX = (ourX + 24)  [ourspaceShip's X cordinate + 24]
	ourCraft.bulletY = (ourY + 45)	[ourspaceShip's Y cordinate + 45]

	Score showing in Right Top with red color.

	the iText beneth the Score shows the score...it change the interger in the characater array and 10 for showing 
	the score in decimal

	iFilledRectangle is the life of our ship

*/
void playGame(){
		/////////// For All level
		if(startGame && (killboss == 0 || killboss == 1 || killboss == 2 || loadGameLevel1 || loadGameLevel2 || loadGameLevel3 )){
			if(ourCraft.score>900){

				if(fireBallbool && fireBallLeft > 0){
					iShowBMP2(ourCraft.fireBallX-22, ourCraft.fireBallY+10,"enemy\\fireball\\boom.bmp", 0);
				}
				if(!fireBallbool && fireBallLeft > 0){
					iShowBMP2(1000, 70,"enemy\\fireball\\boom.bmp", 0);
					iText(1000-15, 60, "FireBall Activated", GLUT_BITMAP_HELVETICA_18);
				}
			}
		}

		/////////// For level 1
		if(startGame && (killboss == 0 || loadGameLevel1)){
			iShowBMP2(ourCraft.bulletX, ourCraft.bulletY, "bullet\\bullet_1.bmp", 0);
			//iShowBMP2(ourCraft.ourX, ourCraft.ourY, "enemy\\ourShip\\ship-1.bmp",0);
			iShowImage(ourCraft.ourX, ourCraft.ourY,200,200,im1);                                                     ///ship-1
			iSetColor(255, 0, 0);
			iText(1150, 730, "SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(1160, 690, itoa(ourCraft.score, buffer, 10), GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(100, 100, 100);
			iFilledRectangle(100, 100, 20, ourCraft.life);
			iRectangle(100, 100, 20, ourCraft.life);
			iSetColor(0,0,0);
			iRectangle(100, 100, 20, 200);
		}

		

	/////////// For level 2
	if(startGame && (killboss == 1 || loadGameLevel2)){

		iShowBMP2(ourCraft.bulletX, ourCraft.bulletY, "bullet\\bullet_1.bmp", 0);
		iShowImage(ourCraft.ourX, ourCraft.ourY,200,200,im1);                            
		//iShowBMP2(ourCraft.ourX, ourCraft.ourY, "enemy\\ourShip\\ship-2.bmp",0);
		iSetColor(255, 0, 0);
		iText(1150, 730, "SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1160, 690, itoa(ourCraft.score, buffer, 10), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(100, 100, 100);
		iFilledRectangle(100, 100, 20, ourCraft.life);
		iRectangle(100, 100, 20, ourCraft.life);
		iSetColor(0,0,0);
		iRectangle(100, 100, 20, 200);
	}

	/////////// For level 3
	if(startGame && (killboss == 2 || loadGameLevel3)){

		iShowBMP2(ourCraft.bulletX, ourCraft.bulletY, "bullet\\bullet_1.bmp", 0);
		iShowImage(ourCraft.ourX, ourCraft.ourY,200,200,im1);                            
		//iShowBMP2(ourCraft.ourX, ourCraft.ourY, "enemy\\ourShip\\ship-3.bmp",0);
		iSetColor(255, 0, 0);
		iText(1150, 730, "SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1160, 690, itoa(ourCraft.score, buffer, 10), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(100, 100, 100);
		iFilledRectangle(100, 100, 20, ourCraft.life);	
		iRectangle(100, 100, 20, ourCraft.life);
		iSetColor(0,0,0);
		iRectangle(100, 100, 20, 200);
	}

}


/*

	enemyShip():

	Collition is initially 'False'

	When the collision is true the enemy ship will be showing as the game start
	
	The condition of Collision: if our ship's bullet's y axis is greater than enemy's y axis and lesser than (enemy's y +80)
								and if our ship's bullet's x axis is greater than enemy's (x axis -24) and lesser than
								enemy's x + 70 then collision will becomes 'true' 

	
	the score will increase each time colission happens with 100 number.


*/




void enemyShip(){
	if(startGame && (killboss < 2 || loadGameLevel1 || loadGameLevel2)){
		/////////////////////// enemy 1 collission
		if(!collution1){
			//iShowImage(ourCraft.ourX, ourCraft.ourY,200,200,im1);                          
			iShowImage(emyShip[0].corX,emyShip[0].corY,enm,enm,im2);                            
			//iShowBMP2(emyShip[0].corX,emyShip[0].corY,"enemy\\enemy\\enemy-1.bmp",0);
		}
		// when our bullet collide with enemy's bullet
		if(ourCraft.bulletY> emyShip[0].corY && ourCraft.bulletY < emyShip[0].corY + 80 && ourCraft.bulletX > emyShip[0].corX - 24 && ourCraft.bulletX < emyShip[0].corX + 70){
			collution1 = true;
			emyShip[0].corY = 40;
			if(collution1) 
				ourCraft.score+=100;
			emyShip[0].gunCorY = -10;
		}
			
		///////////////////// enemy 2 collission	
		if(!collution2){
			iShowImage(emyShip[0].corX,emyShip[0].corY,enm,enm,im2);        
			//iShowBMP2(emyShip[1].corX,emyShip[1].corY,"enemy\\enemy\\enemy-1.bmp",0);
		}
		if(ourCraft.bulletY > emyShip[1].corY && ourCraft.bulletY < emyShip[1].corY + 80 && ourCraft.bulletX > emyShip[1].corX - 24 && ourCraft.bulletX < emyShip[1].corX + 70){
			collution2 = true;
			emyShip[1].corY = 40;
			if(collution2) 
				ourCraft.score+=100;
			emyShip[1].gunCorY = -10;
		}

		////////////////////// enemy 3 collission
		if(!collution3){	
			iShowImage(emyShip[0].corX,emyShip[0].corY,enm,enm,im2);        
			//iShowBMP2(emyShip[2].corX,emyShip[2].corY,"enemy\\enemy\\enemy-1.bmp",0);
		}
		if(ourCraft.bulletY > emyShip[2].corY && ourCraft.bulletY < emyShip[2].corY + 80 && ourCraft.bulletX > emyShip[2].corX - 24 && ourCraft.bulletX < emyShip[2].corX + 70){
			collution3 = true;
			emyShip[2].corY = 40;
			if(collution3) 
				ourCraft.score+=100;
			emyShip[2].gunCorY = -10;
		}
		/////////////////////// enemy 4 collution
		if(!collution4){	
			//iShowBMP2(emyShip[3].corX,emyShip[3].corY,"enemy\\enemy\\enemy-1.bmp",0);
			iShowImage(emyShip[0].corX,emyShip[0].corY,enm,enm,im2);        
		}
		if(ourCraft.bulletY > emyShip[3].corY && ourCraft.bulletY < emyShip[3].corY + 80 && ourCraft.bulletX > emyShip[3].corX - 24 && ourCraft.bulletX < emyShip[3].corX + 70){
			collution4 = true;
			emyShip[3].corY = 40;
			if(collution4) 
				ourCraft.score+=100;
			emyShip[3].gunCorY = -10;
		}

		
	}


	if(startGame && (killboss == 1 || killboss == 2 || loadGameLevel2 || loadGameLevel3)){
		// rock 1
			
			//iShowBMP2(emyShip[4].rockX,emyShip[4].rockY,"enemy\\enemy\\rock.bmp",0);
						iShowImage(emyShip[4].rockX,emyShip[4].rockY, rcx, rcx,im4);
		

		if(ourCraft.ourY + 100 > emyShip[4].rockY && ourCraft.ourY < emyShip[4].rockY + 80 && ourCraft.ourX > emyShip[4].rockX - 24 && ourCraft.ourX < emyShip[4].rockX + 70){
			collission5 = true;
			ourCraft.life = 0;
		}
		// rock 2
		iShowImage(emyShip[5].rockX,emyShip[5].rockY, rcx, rcx,im4);

			//iShowBMP2(emyShip[5].rockX,emyShip[5].rockY,"enemy\\enemy\\rock.bmp",0);

		if(ourCraft.ourY +100> emyShip[5].rockY && ourCraft.ourY < emyShip[5].rockY + 80 && ourCraft.ourX > emyShip[5].rockX - 24 && ourCraft.ourX < emyShip[5].rockX + 70){
			collission6 = true;
			ourCraft.life = 0;
		}	
	}
	if(startGame && (killboss == 2 || loadGameLevel3)){

		if(!collution1){	
			iShowImage(emyShip[0].corX,emyShip[0].corY,enm,enm,im3);        
			//iShowBMP2(emyShip[0].corX,emyShip[0].corY,"enemy\\enemy\\enemy-2.bmp",0);
		}
		if(ourCraft.bulletY > emyShip[0].corY && ourCraft.bulletY < emyShip[0].corY + 80 && ourCraft.bulletX > emyShip[0].corX - 24 && ourCraft.bulletX < emyShip[0].corX + 70){
			collution1 = true;
			emyShip[0].corY = 40;
			if(collution1) 
				ourCraft.score+=100;
			emyShip[0].gunCorY = -10;
			
		}
			
		///////////////////// enemy 2 collution	
		if(!collution2){
				iShowImage(emyShip[1].corX,emyShip[1].corY,enm,enm,im3);        
			//iShowBMP2(emyShip[1].corX,emyShip[1].corY,"enemy\\enemy\\enemy-2.bmp",0);
		}
		if(ourCraft.bulletY > emyShip[1].corY && ourCraft.bulletY < emyShip[1].corY + 80 && ourCraft.bulletX > emyShip[1].corX - 24 && ourCraft.bulletX < emyShip[1].corX + 70){
			collution2 = true;
			emyShip[1].corY = 40;
			if(collution2) 
				ourCraft.score+=100;
			emyShip[1].gunCorY = -10;////////////////////////
			
		}

		////////////////////// enemy 3 collution
		if(!collution3){	
				iShowImage(emyShip[2].corX,emyShip[2].corY,enm,enm,im2);        
			//iShowBMP2(emyShip[2].corX,emyShip[2].corY,"enemy\\enemy\\enemy-1.bmp",0);
		}
		if(ourCraft.bulletY > emyShip[2].corY && ourCraft.bulletY < emyShip[2].corY + 80 && ourCraft.bulletX > emyShip[2].corX - 24 && ourCraft.bulletX < emyShip[2].corX + 70){
			collution3 = true;
			emyShip[2].corY = 40;
			if(collution3) 
				ourCraft.score+=100;
			emyShip[2].gunCorY = -10;/////////////////////////////
			
		}
		/////////////////////// enemy 4 collution
		if(!collution4){	
				iShowImage(emyShip[3].corX,emyShip[3].corY,enm,enm,im2);        
			//iShowBMP2(emyShip[3].corX,emyShip[3].corY,"enemy\\enemy\\enemy-1.bmp",0);
		}
		if(ourCraft.bulletY > emyShip[3].corY && ourCraft.bulletY < emyShip[3].corY + 80 && ourCraft.bulletX > emyShip[3].corX - 24 && ourCraft.bulletX < emyShip[3].corX + 70){
			collution4 = true;
			emyShip[3].corY = 40;
			if(collution4) 
				ourCraft.score+=100;
			emyShip[3].gunCorY = -10;///////////////////////////
			
		
		}
	}

}


/*
	
	void gunShot():

	when the game starts the enemys start to shoot the bullets and this function shows the bullet images


*/
void gunShot(){

	if(startGame){
		if(!bulletCollision){
			iShowBMP2(emyShip[0].gunCorX,emyShip[0].gunCorY,"enemy\\gunShot\\gun2.bmp",0);
		}
		if(!bulletCollision1){
			iShowBMP2(emyShip[1].gunCorX,emyShip[1].gunCorY,"enemy\\gunShot\\gun2.bmp",0);
		}
		if(!bulletCollision2){
			iShowBMP2(emyShip[2].gunCorX,emyShip[2].gunCorY,"enemy\\gunShot\\gun2.bmp",0);
		}
		if(!bulletCollision3){
			iShowBMP2(emyShip[3].gunCorX,emyShip[3].gunCorY,"enemy\\gunShot\\gun2.bmp",0);
		}
	}

}
/*
	void change(): 

	when the enemy ship's y cordinate is lesser than 10 , at that time collission is not possible so it's false and
	the y cordinate of enemy is going to outside of the screen

	In case of avoiding overlap in x axis of enmey ship we created a random value in x axis and added with the enemy's x
	position. Similar for the bullet of enemy

	when the x cordinate of enemey crosses the 1150 which is the limit of screen , the position of enemey and bulle of enemy will
	be 200;

*/

void change(){  /// change kora lagte pare load game er jonnno
	if(startGame){
		//1 number
		if(emyShip[0].corY <= 10){
			collution1 = false;
			emyShip[0].corY = 800;
			int r;
			r = rand()%300;
			emyShip[0].corX = (emyShip[0].corX + r); // enemy ship ar enemy ship er gulir x cordinate same hobe because duitai randomly hobe.
			emyShip[0].gunCorX = (emyShip[0].corX + emyShip[0].x + r);
			if(emyShip[0].corX > 1150){
				emyShip[0].corX = 200;
				emyShip[0].gunCorX = 200;

			}
		}	
		// 2 number
		if(emyShip[1].corY <= 10){
			collution2 = false;
			emyShip[1].corY = 800;
			int r;
			r = rand()%200;
			emyShip[1].corX = (emyShip[1].corX + r); // enemy ship ar enemy ship er gulir x cordinate same hobe because duitai randomly hobe.
			emyShip[1].gunCorX = (emyShip[1].corX + emyShip[1].x + r);
			if(emyShip[1].corX > 1150){
				emyShip[1].corX = 450;
				emyShip[1].gunCorX = 450;
			}
		}
		// 3 number
		if(emyShip[2].corY <= 0){
			collution3 = false;
			emyShip[2].corY = 800;
			int r;
			r = rand()%100;
			emyShip[2].corX = (emyShip[2].corX - r); // enemy ship ar enemy ship er gulir x cordinate same hobe because duitai randomly hobe.
			emyShip[2].gunCorX = (emyShip[2].corX + emyShip[2].x - r);
			if(emyShip[2].corX < 100){
				emyShip[2].corX = 650;
				emyShip[2].gunCorX = 650;
			}
		}
		
		// 4 number

		if(emyShip[3].corY <= 0){
			collution4 = false;
			emyShip[3].corY = 800;
			int r;
			r = rand()%100;
			emyShip[3].corX = emyShip[3].corX - r; // enemy ship ar enemy ship er gulir x cordinate same hobe because duitai randomly hobe.	
			emyShip[3].gunCorX = (emyShip[3].corX + emyShip[3].x - r);
			if(emyShip[3].corX < 100){
				emyShip[3].corX = 800;
				emyShip[3].gunCorX = 800;
			}
		}

		if(startGame && (killboss == 1 || killboss == 2 || loadGameLevel2 || loadGameLevel3)){
		
			//rock1
			emyShip[4].rockY -= 5;

			if(emyShip[4].rockY <= 10){
				collission5 = false;
				emyShip[4].rockY = 1500;
				int r;
				r = rand()%1100;
				emyShip[4].rockX = (emyShip[4].rockX + r);
				if(emyShip[4].rockX > 1150){
					emyShip[4].rockX = 200;

				}
			}
			// rock 2

			emyShip[5].rockY -= 6;

			if(emyShip[5].rockY <= 10){
				collission6 = false;
				emyShip[5].rockY = 1700;
				int r;
				r = rand()%1100;
				emyShip[5].rockX = (emyShip[6].rockX + r);
				if(emyShip[5].rockX > 1150){
					emyShip[5].rockX = 200;
				}
			}
		}

		//////////// speeding up the enemy ship///////////////////
		int eSpeed = 2;
		if(ourCraft.score > -1 && ourCraft.score < 500){
			emyShip[0].corY -= 5;
			emyShip[1].corY -= 7;
			emyShip[2].corY -= 8;
			emyShip[3].corY -= 6;
		}
		if(ourCraft.score > 499 && ourCraft.score < 1000){
			emyShip[0].corY -= 5 + eSpeed;
			emyShip[1].corY -= 7 + eSpeed;
			emyShip[2].corY -= 8 + eSpeed;
			emyShip[3].corY -= 6 + eSpeed;
		}
		if(ourCraft.score > 999 && ourCraft.score < 1500){
			emyShip[0].corY -= 5 + (2*eSpeed);
			emyShip[1].corY -= 7 + (2*eSpeed);
			emyShip[2].corY -= 8 + (2*eSpeed);
			emyShip[3].corY -= 6 + (2*eSpeed);
		}
		if(ourCraft.score > 1499 && ourCraft.score < 2000){
			emyShip[0].corY -= 5 + (3*eSpeed);
			emyShip[1].corY -= 7 + (3*eSpeed);
			emyShip[2].corY -= 8 + (3*eSpeed);
			emyShip[3].corY -= 6 + (3*eSpeed);
		}
		if(ourCraft.score > 1999 && ourCraft.score < 2500){
			emyShip[0].corY -= 5 + (4*eSpeed);
			emyShip[1].corY -= 7 + (4*eSpeed);
			emyShip[2].corY -= 8 + (4*eSpeed);
			emyShip[3].corY -= 6 + (4*eSpeed);
		}
		if(ourCraft.score > 2499){
			emyShip[0].corY -= 5 + (5*eSpeed);
			emyShip[1].corY -= 7 + (5*eSpeed);
			emyShip[2].corY -= 8 + (5*eSpeed);
			emyShip[3].corY -= 6 + (5*eSpeed);
		}
	}
}


/*
	

	void changeGun():

	When The bulles of enemy goes down by -7 each time and pass our ship and the whole y axis , the position is initialized of the bullets

	When the bullets of enemy does a collision with our space ship the bullet image vanishes and life decrease.


*/
void changeGun(){

	if(startGame){ /// change kora lagte pare loadGame er jonno

		////////////// For ENEMY 1 //////////////
		emyShip[0].gunCorY -= 10; // speed bullet

		// this block of code is for realoading enemy bullet.....
		// when enemy bullet goes less than -756 in y axis,,
		// then we throw the bullet to the middle of the enemy,,
		// from where the bullet is actually shooting. :=)


		if(emyShip[0].gunCorY <= -756){
			emyShip[0].gunCorX = emyShip[0].corX + emyShip[0].x; 
			emyShip[0].gunCorY = emyShip[0].corY - emyShip[0].y;
			bulletCollision = false;
		}

		//this block of code is for the Collission of enemy(number 1) bullet and our space craft :-)
		if(emyShip[0].gunCorY<= ourCraft.ourY +77 && emyShip[0].gunCorY >= ourCraft.ourY){
			if(emyShip[0].gunCorX >= ourCraft.ourX - 30 && emyShip[0].gunCorX <= ourCraft.ourX + 85){
				bulletCollision = true;
				if(ourCraft.life >= 0){
					if(killboss == 0 || killboss == 1 || killboss == 2)
						ourCraft.life--;
					if(killboss == 2)
						ourCraft.life -= 4;
				}
			}
		}

		/////////// End of CODE for Enemy 1 /////////////

		////////////// For ENEMY 2 //////////////
		emyShip[1].gunCorY -= 10; // speed bullet

		// this block of code if for realoading enemy bullet...
		// when enemy bullet goes less than -756 in y axis,,
		// then we throw the bullet to the middle of the enemy,,
		// from where the bullet is actually shooting. :=)
		if(emyShip[1].gunCorY <= -756){
			emyShip[1].gunCorX = emyShip[1].corX + emyShip[1].x; 
			emyShip[1].gunCorY = emyShip[1].corY - emyShip[1].y;
			bulletCollision1 = false;
		}

		//this block of code is for the COLLUTION of enemy(number 2) bullet and our space craft :-)
		if(emyShip[1].gunCorY<= ourCraft.ourY +77 && emyShip[1].gunCorY >= ourCraft.ourY){
			if(emyShip[1].gunCorX >= ourCraft.ourX - 30 && emyShip[1].gunCorX <= ourCraft.ourX + 85){
				bulletCollision1 = true;
				if(ourCraft.life >= 0){
					if(killboss == 0 || killboss == 1 || killboss == 2)
						ourCraft.life--;
					if(killboss == 2)
						ourCraft.life -= 4;
				}
			}
		}
		/////////// End of CODE for Enemy 2 /////////////


		////////////// For ENEMY 3 //////////////
		emyShip[2].gunCorY -= 10; // speed bullet

		// this block of code if for realoading enemy bullet...
		// when enemy bullet goes less than -756 in y axis,,
		// then we throw the bullet to the middle of the enemy,,
		// from where the bullet is actually shooting. :=)
		if(emyShip[2].gunCorY <= -756){
			emyShip[2].gunCorX = emyShip[2].corX + emyShip[2].x; 
			emyShip[2].gunCorY = emyShip[2].corY - emyShip[2].y;
			bulletCollision2 = false;
		}

		//this block of code is for the COLLUTION of enemy(number 3) bullet and our space craft :-)
		if(emyShip[2].gunCorY<= ourCraft.ourY +77 && emyShip[2].gunCorY >= ourCraft.ourY){
			if(emyShip[2].gunCorX >= ourCraft.ourX - 30 && emyShip[2].gunCorX <= ourCraft.ourX + 85){
				bulletCollision2 = true;
				if(ourCraft.life >= 0){
					if(killboss == 0 || killboss == 1 || killboss == 2)
						ourCraft.life--;
					if(killboss == 2)
						ourCraft.life -= 4;
				}
			}
		}
		/////////// End of CODE for Enemy 3 /////////////

		////////////// For ENEMY 4 //////////////
		emyShip[3].gunCorY -= 10; // speed bullet

		// this block of code if for realoading enemy bullet...
		// when enemy bullet goes less than -756 in y axis,,
		// then we throw the bullet to the middle of the enemy,,
		// from where the bullet is actually shooting. :=)
		if(emyShip[3].gunCorY <= -756){
			emyShip[3].gunCorX = emyShip[3].corX + emyShip[3].x; 
			emyShip[3].gunCorY = emyShip[3].corY - emyShip[3].y;
			bulletCollision3 = false;
		}

		//this block of code is for the COLLUTION of enemy(number 4) bullet and our space craft :-)
		if(emyShip[3].gunCorY<= ourCraft.ourY +77 && emyShip[3].gunCorY >= ourCraft.ourY){
			if(emyShip[3].gunCorX >= ourCraft.ourX - 30 && emyShip[3].gunCorX <= ourCraft.ourX + 85){
				bulletCollision3 = true;
				if(ourCraft.life >= 0){
					if(killboss == 0 || killboss == 1 || killboss == 2)
						ourCraft.life--;
					if(killboss == 2)
						ourCraft.life -= 4;
				}
			}
		}
		/////////// End of CODE for Enemy 4 /////////////

		// this is for pausing the game..
		if(ourCraft.life < 1 && (killboss == 0 || killboss == 1 || killboss == 2)){  //// change korsi eikhane
			restartGame = 1;
			iPauseTimer(0);
			initialize();
			startGame = false;
			ourCraft.life = 1;
		}

		if(restartGame == 2){
			iResumeTimer(0);
			startGame = true;
			restartGame = 0;
			ourCraft.life = 200;
		}
	
	}
}


// this is for enemy collution...
// when collution is happend..
// our life decrease
// and the enemy is disappeared.
void enemyCollution(){
	// condition for collution of enemy 1 and our craft
	if(emyShip[0].corY < ourCraft.ourY + 70 && emyShip[0].corY + 1 > ourCraft.ourY){
		if(emyShip[0].corX > ourCraft.ourX && emyShip[0].corX < ourCraft.ourX + 70){
			collution1 = true;
			ourCraft.life -= 1;
		}
	}

	// condition for collution of enemy 2 and our craft
	if(emyShip[1].corY < ourCraft.ourY + 70 && emyShip[1].corY + 1 > ourCraft.ourY){
		if(emyShip[1].corX > ourCraft.ourX && emyShip[1].corX < ourCraft.ourX + 70){
			collution2 = true;
			ourCraft.life -= 1;
		}
	}

	// condition for collution of enemy 3 and our craft
	if(emyShip[2].corY < ourCraft.ourY + 70 && emyShip[2].corY + 1 > ourCraft.ourY){
		if(emyShip[2].corX > ourCraft.ourX && emyShip[2].corX < ourCraft.ourX + 70){
			collution3 = true;
			ourCraft.life -= 1;
		}
	}

	// condition for collution of enemy 4 and our craft
	if(emyShip[3].corY < ourCraft.ourY + 70 && emyShip[3].corY + 1 > ourCraft.ourY){
		if(emyShip[3].corX > ourCraft.ourX && emyShip[3].corX < ourCraft.ourX + 100){
			collution4 = true;
			ourCraft.life -= 1;
		}
	}
}


void saveScoretostruct(){

	p.score =  ourCraft.score;

}

/*
	
	with the keyboard input of up, down, right and left key our ship goes up, down , left and right with -10 px each time 
	when our ship's y is greater than 500 it can't go up and when lesser 85 can;t go down which is done in the if statement


	as the spaceship goes up the bullets also goes up. 45 is the height of the bullets that comes from the missle of our ship
*/


// our Craft goes up.
// our craft can not go more than 500 pixel in Y axis
void UP(){
	ourCraft.ourY += 10;
	ourCraft.bulletY += 10;
	if(ourCraft.ourY > 500 || ourCraft.bulletY < 40 + 45){
		ourCraft.ourY = 500;
		ourCraft.bulletY = 500 + 45;
	}
}

// our craft goes down.
// our craft cannot go less than 110 pixel in Y axis.
void DOWN(){
	ourCraft.ourY -= 10;
	ourCraft.bulletY -= 10;
	if(ourCraft.ourY < 111 || ourCraft.bulletY < 111 - 45){
		ourCraft.ourY = 111;
		ourCraft.bulletY = 111 + 45;
	}
}

// our craft goes left.
// our craft can not go less than 5 px in X axis
void LEFT(){
	ourCraft.ourX -= 10;
	
	ourCraft.bulletX -= 10;
	ourCraft.fireBallX -=10;
	if(ourCraft.ourX < 5 || ourCraft.bulletX < 5 - 24){
		ourCraft.ourX = 5;
		ourCraft.bulletX = 5 + 24;
	}	
}

// our craft goes right.
// our craft cannot go more than 1180 pixel in X axis.
void RIGHT(){
	ourCraft.ourX += 10;
	ourCraft.bulletX += 10;
	ourCraft.fireBallX +=10;
	if(ourCraft.ourX > 1180 || ourCraft.bulletX > 1180 + 24){
		ourCraft.ourX = 1180;
		ourCraft.bulletX = 1180 + 24;
	}	
}

// this is the firing function of our craft.
// our craft fire bullet using this function.
// when bullet goes more than 720 pixel
// we throw the bullet to our craft
// from where the bullet is actually fireing 
void fire(){
	if(fireBullet){
		ourCraft.bulletY += 20;
		if(ourCraft.bulletY > 720){
			ourCraft.bulletY = (ourCraft.ourY + 45);
		}
	}
}


// this is for firing FIREBALL
// initially we have 2 fireball
// it will activate when the score is more than 3500
// we can only fire twis

void fireball(){
	if(ourCraft.score>900 && (fireBallLeft > 0)){
		if(fireBallbool){
		
			ourCraft.fireBallY += 10; // speed of fireball

			// when the fire ball is fired,,
			// no matter where the enemy is,,
			// all the enemy will be disppeared,,
			// we make this by making the collution true,,
			// after collution we throw the enemy to a certain distance
			// so than enemy will come after a few time
			if(ourCraft.fireBallY > 500 && ourCraft.fireBallY<800){
				collution1 = true;
				collution2 = true;
				collution3 = true;
				collution4 = true;
				bulletCollision = true;
				bulletCollision1 = true;
				bulletCollision2 = true;
				bulletCollision3 = true;
				
				// throwing enemy to a certain distance
				emyShip[0].corY = 1000;
				emyShip[1].corY = 1000;
				emyShip[2].corY = 1000;
				emyShip[3].corY = 1000;
				emyShip[0].gunCorY = (emyShip[0].corY + emyShip[0].y)+1000;
				emyShip[1].gunCorY = (emyShip[1].corY + emyShip[1].y)+1000;
				emyShip[2].gunCorY = (emyShip[2].corY + emyShip[2].y)+1000;
				emyShip[3].gunCorY = (emyShip[3].corY + emyShip[3].y)+1000;
			 
				if(emyShip[0].corY < 900){
					emyShip[0].gunCorY = (emyShip[0].corY + emyShip[0].y);
				
				}
				if(emyShip[1].corY < 900){
					emyShip[1].gunCorY = (emyShip[1].corY + emyShip[1].y);
				
				}
				if(emyShip[2].corY < 900){
					emyShip[2].gunCorY = (emyShip[2].corY + emyShip[2].y);
				
				}
				if(emyShip[3].corY < 900){
					emyShip[3].gunCorY = (emyShip[3].corY + emyShip[3].y);
				
				}
			}
			if(emyShip[0].corY > 900 && emyShip[0].corY < 1500){
				emyShip[0].corY -= 5;
				emyShip[1].corY -= 7;
				emyShip[2].corY -= 8;
				emyShip[3].corY -= 6;
			}

			// after firing,,
			// we decrease the fireball
			if(ourCraft.fireBallY > 799){
				fireBallLeft--;
				fireBallbool = false; // making it false allows us to use the fire ball again
				ourCraft.score += 300;
				ourCraft.fireBallX = (ourCraft.ourX + 24);
				ourCraft.fireBallY = (ourCraft.ourY + 45);
			}
		}
	}

}

#endif 