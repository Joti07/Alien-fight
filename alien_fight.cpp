#include"Allheaderfiles.h"
#include"introduction.h"
#include <iostream>
using namespace std;
void iDraw()
{
	//place your drawing codes here
	iClear();
	if(!menuShow){
		introbg();  ///// intoruction pictures
	}
	if(makeMenuShowTrue()){
		Menu(); ///////// all the functions of menu and games are shown here
	}
	
}

void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//printf("x = %d, y= %d\n",mx,my); //// for test purpose
		
		mouseControlForGameMusic(mx, my); ////// controls the music option(see declaration is music.h)
		//mouseControlForFireMusic(mx, my);
		///////////// about ///////////////////////////
		/*
			when the player click the stroy in about section 
			this condition takes the player to the story part
		
		*/
		
		if(about){
			if(mx > 426 && mx < 855 && my > 164 && my < 220){
				aboutUs = true;
			}
		}
		////////////////////////////////////////////////

		//////////////////// Options /////////////////////////

		/*
			this function controls the option to move to controls section when the player click the controls
		*/
		if(options){
			if(mx > 112 && mx < 322 && my > 380 && my < 416){
				controls = true;
				backtooptions = true;
				opt = true;
			}
		}
		//////////////////////////////////////////////////

		///////////////// exit ///////////////////////////
		/*
			this condition controls the exit button on main menu section. 
			when we press the exit button on main menu it turns the ex to true and change tha state of tha menu
			see the decalation in Menu.h
				
		*/

		if(ex == true){
			if(mx >= 356 && mx <= 644 && my >= 158 && my <= 211){
				exitButton = 2;				
			}
			if(mx >= 654 && mx <= 941 && my >=157 && my <= 209 ){
				exitButton = 3;
			}
		}
		/////////////////////////////////////////////////

		//////////////////// new Game//////////////////
		/*
			this condition controls the exit button of the newGame section
			when we prace the esc key and then ther yes/no section this condition helps us to save the score 
			and also to go to the main menu after taking the decision
		
		*/
		if(mx >= 356 && mx <= 644 && my >= 158 && my <= 211){
			if(menuBarNumber == 1 && selectMenu == 1){
				newg = 2;
				saveScoretostruct();
			}
			/// this conditon helps us to go back to load game menu from a load game
			if(menuBarNumber == 2 && selectMenu == 2){
				loadg = 2;
			}
				
		}

		if(mx >= 654 && mx <= 941 && my >= 157 && my <= 209 ){
			if(menuBarNumber == 1 && selectMenu == 1){
				newg = 0;
			}
			if(menuBarNumber == 2 && selectMenu == 2){
				loadg = 0;
			}	
		}
		//////////////////////////////////////////////////////
		/////////////////// input highilighting////////////////
		/*
			this condition helps us to make the input event highlighted 
			when the player clicked the box to input the name of the 
			player
		*/
		if(introCount == 4){
			if(mx >= 415 && mx <= 828 && my >= 160 && my <= 200){
				highLight = 1;
			}
		}
		///////////////////////////////////////////////////
		// boss
		/*
			this conditon controls the bosses in the game
			it also reinitialize the crafts and the background movement
		*/
		if(killboss >= 0 && killboss < 4){
			if(mx >= 362  && mx <= 915 && my >= 387 && my <= 455){
				bossKill(); 
				restartGame = 2;
				initialize();
				bgMovedy = 0;
			}
		}

		//////////////////////////////////////////////////
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

void iKeyboard(unsigned char key)
{
	/////////// input taking condition////////
	/*
		this condition hepls us to illuminate the input taking dialouge box
		in the introduction process.
		checks for back space and enter 
	*/
	if(introCount == 4 && highLight == 1){
		if(key != '\b'){
			str[indexNumber] = key;
			str[indexNumber + 1] = '\0';
			indexNumber++;
		}
		else{
			str[indexNumber] = '\0';	
			indexNumber--;
			if(indexNumber < 0){
				indexNumber = 0;
			}
		}
		if(key == '\r'){
			saveName = 1;
		}
	}
/////////////////////////////////////////////////////////
	////////// our craft left right methods///////////
	/*
		this conditions controls the movement of our spaceCraft
	*/
	if (key == 'w'){
		UP();
	}	
	else if (key == 's'){
		DOWN();
	}
	else if (key == 'a'){
		LEFT();
	}
	else if (key == 'd'){
		RIGHT();
	}
	////////////////////////////////////////////////
	////////////// to stop and start the gun in our ship/////////
	else if (key == 'e'){
		fireBullet = true;
	}
	else if(key == 'f'){ //////special power section
		if(ourCraft.score>900 ){
			fireBallbool = true;
		}
	}
	else if (key == 'q'){
		fireBullet = false;
		ourCraft.bulletY = (ourCraft.ourY + 45);
	}
	////////////////////////////////////////////////////////
	/*
		this condition changes the state of the main menu
		is we select select the highscore section, then this will trigger
		the initial condition to go to the highscore menu section

		see menu.h for declaration
	*/

	else if(key == '\r'){ /// enter
		if(makeMenuShowTrue()){
			changeMenu();
			changeLoadGame();
			fileInput();
			fileOutput();
		}
	}
	/////////////////////////////////////////
	/*
		this controls the introduction images
		when we press the spacebar it changes the introduction images
	*/
	else if(key == ' '){
		increaseCount();
	}
	//////////////////////////////////////////
	
	////////////////////////////////////////
	/*
		this controls all the functionlaties of the esc key

		in controls the back button of all the menu buttons according to the 
		conditions

		see the menu.h to for further dclarations
	*/
	else if(key == 27){ ////esc
		if(newGame){
			newg = 1;
			if(boss[0].life < 30){
				boss[0].life = 200;
			}
		}
		if(loadGame && selectLoadGame){
			loadg = 1;
		}
		if(options){
			opt = false;
			controls = false;
		}
		if(menuBarNumber == 4 && selectMenu == 4){
			makeRetuenToMainMenuTrue();
		}
		if(loadGame && selectLoadGame == 0){
			makeRetuenToMainMenuTrue();
		}
		if(menuBarNumber == 5 && selectMenu == 5){
			makeRetuenToMainMenuTrue();
		}
		if(menuBarNumber == 3 && selectMenu == 3){
			makeRetuenToMainMenuTrue();
		}

	}
	//////////////////////////////////////////////
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	/////// controls the up movement of the menu bar//////
	if(key == GLUT_KEY_UP){
		if(makeMenuShowTrue()){
			upMenu();
		}
	}
///////////////////////////////////////////////////////////
	if(key == GLUT_KEY_DOWN){
		if(makeMenuShowTrue()){
			dropMenu();
		}	
	}

	if(key == GLUT_KEY_HOME){
		
	}
	if(key == GLUT_KEY_INSERT){

	}
	if(key == GLUT_KEY_F1){

	}
	///////////////// controls the right movement of the loadgame menu bar////
	if(key == GLUT_KEY_RIGHT){
		rightShift();
	}
	////////////////////////////////////////////////////////////////////////

	///////////////// controls the left movement of the loadgame menu bar////
	if(key == GLUT_KEY_LEFT){
		leftShift();
	}
	////////////////////////////////////////////////////////////////////////
	//place your codes for other keys here
}



int main()
{
	//place your own initialization codes here.
	initialize();
	cout << "Loading...";

	//playMenuMusic();
	iSetTimer(60, change);
	iSetTimer(2, changeGun);
	iSetTimer(200, fire);
	iSetTimer(5,fireball);
	iSetTimer(15,bossMovement);
	iSetTimer(10,boss1Fire);
	iSetTimer(5, bgMove);
	iInitialize(SCREENWIDTH, SCREENHEIGHT, "ALIEN FIGHT");
	im1 = iLoadImage("enemy\\ourShip\\ship-1.png");
	im2=iLoadImage("enemy\\enemy\\enemy-1.png");
	im3=iLoadImage("enemy\\enemy\\enemy-2.png");
	im4=iLoadImage("enemy\\enemy\\rock.png");
	im5=iLoadImage("enemy\\boss\\boss-1.png");
	intro();
	menuImage();
	newGameImage();
	loadGameImage();
	highScoreImage();
	aboutImage();
	ExitImage();
	optionImage();
	loadgameMenu();
	loadSaveGamePic();
	congratsImage();
	playMenuMusic();

	//test();

	iStart(); // it will start drawing

	return 0;
}



