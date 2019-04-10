#ifndef	FILEINPUTOUTPUT_H_INCLUDED
#define FILEINPUTOUTPUT_H_INCLUDED
#include<algorithm>
#include<iostream>
#include <string>

///// file name /// this is constant
char fileName[25] = "highScore.bin";

/// buf is declared for itoa function
//// see doc for itoa
char buf[20];


///// writing is used for wrinting the structure data to file.
/// see iMain for usages
bool writing = false;


/*
	this structure is created to save the data into file
*/
struct Person{

	int score;
	char name[25];
	//int level;

	Person(){
		score = 0;
		strcpy(name, "");
	}

	void printData(){
		printf("%s\t%d\n", name, score);
	}

} person[5], person1[5], p;

bool acompare(Person lhs, Person rhs);
void createFile();
void writeInBinary();
void readInBinary(Person p1[]);
void check();
void fileInput();
void fileOutput();
void readFile();

/* this function is declared to sort the structure according o highscore
	see fileOutput function for usages
*/
bool acompare(Person lhs, Person rhs) { 
	return lhs.score > rhs.score;
}

/*
	this is created for test purpose only
*/

void createFile(){
	FILE *fp = fopen(fileName, "ab+");
	fclose(fp);
}
/*
	writeInBinary is created to write the data from structure to file
*/
void writeInBinary(){
    FILE *fp = fopen(fileName, "wb");
    for(int i = 0; i < 5; i++){

        fwrite(&person1[i], sizeof(struct Person), 1, fp);
    }
    fclose(fp);
	writing = true;
}

/*
	readInBinary is created to read the data from file to structure
*/
void readInBinary(Person p1[]){
    FILE *fp = fopen(fileName, "rb");
    for(int i = 0; i < 5; i++){
        fread(&p1[i], sizeof(struct Person), 1, fp);
    }
    fclose(fp);
}


//// for test purpose only
void writeFile(){
	FILE *fp = fopen(fileName, "w");
	for(int i = 0; i < 5; i++){
		fprintf(fp, "%s %d", person[i].name, person[i].score);
	}
	fclose(fp);
	writing = true;
}

//// for test purpose only
void readFile1(){
	FILE *fp = fopen(fileName, "r");
	for(int i = 0; i < 5; i++){
		fscanf(fp, "%s %d", person1[i].name, person1[i].score);
	}
	fclose(fp);
}	

/*
	this function is checking the score of a player and setting the new value of the particular
	player. Also this check function sorts the structure array according to highscore
*/
void check(){

	bool trial = false;
	
	for(int i = 0; i < 5; i++){
		if(strcmp(person1[i].name, p.name) == 0){

			if(p.score >= person1[i].score){
				//printf("checked\n");
				person1[i].score = p.score;
				strcpy(person1[i].name, p.name);
				trial = true;
				break;
			}
		}
	}
	
	if(!trial){
		person1[4].score = p.score;
		strcpy(person1[4].name, p.name);
	}
	std::sort(person1, person1 + 5, acompare);
}

/*
	fileInput function read the file and save it to person1 array and then check person1 array 
	and also write the values in the file
*/

void fileInput(){
	if(!writing){
		readInBinary(person1);
		check();
		writeInBinary();
	}
}

/*
	fileOutput function read the file and also sort it to recheck and stores the data in person array
*/
void fileOutput(){
	if(writing){
		readInBinary(person);
		std::sort(person, person + 5, acompare);
		writeInBinary();
		writing = false;
	}
}

/*
	readFile function reads the data from person array then shows it to highscore menu
*/
void readFile(){
	iSetColor(25, 255, 255);
	iText(650, 600, "HIGH SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500, 500, "1", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(550, 500, person[0].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(900, 500, itoa(person[0].score, buf, 10), GLUT_BITMAP_TIMES_ROMAN_24);

	iText(500, 450, "2", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(550, 450, person[1].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(900, 450, itoa(person[1].score, buf, 10), GLUT_BITMAP_TIMES_ROMAN_24); ////// change made in this function

	iText(500, 400, "3", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(550, 400, person[2].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(900, 400, itoa(person[2].score, buf, 10), GLUT_BITMAP_TIMES_ROMAN_24);

	iText(500, 350, "4", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(550, 350, person1[3].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(900, 350, itoa(person[3].score, buf, 10), GLUT_BITMAP_TIMES_ROMAN_24);

	iText(500, 300, "5", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(550, 300, person[4].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(900, 300, itoa(person[4].score, buf, 10), GLUT_BITMAP_TIMES_ROMAN_24);
}


/// for test purpose only
void test(){
	for(int i = 0; i < 6; i++){
		person[i].printData();
	}
}
#endif