/* SE 185: Final Project //
Team ##
Team member 1 "Sam Carroll" | "50%"
Team member 2 "Joseph Sheets" | "50%"

 // Last Coded On 11/15/22

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "GameFunctions.h"
#include <ncurses/ncurses.h>
#include <string.h>

//Struct Definitions

//Functions Declarations

//Code

int main(){
    int NUM_WORDS;
    int MinimumWordPlay;
	int strLength[50];
    char startUpButton = '\0';
	char guessWord[25];
	char* strWordList[50];
    bool validStartUp = false;
    bool writeMode = false;
    bool playMode = false;
    FILE* wordsList = NULL;
    int gameSpeed = 5;
	int gameLoad = 3000;
	int i = 5;
	int wordArray;
	time_t startTime;
	time_t endTime;
	clock_t before;
	long int elapsedTime;
		
    wordsList = fopen("wordsList.txt", "r");
	if(wordsList == NULL){
		return 0; // Error Opening File
	}
	getNumberOfWords(&NUM_WORDS, wordsList);
	startUpPrompt(NUM_WORDS);
	startUpFunction(validStartUp, startUpButton, &playMode, &writeMode);
	
	while(writeMode){
		appendFunc();
		wordsList = fopen("wordsList.txt", "r");
		getNumberOfWords(&NUM_WORDS, wordsList);
		fclose(wordsList);
		startUpPrompt(NUM_WORDS);
		startUpFunction(validStartUp, startUpButton, &playMode, &writeMode);
	}
    if(NUM_WORDS == 0){
        playMode = false;
        printf("You need atleast 1 words to play!\n");
        return 0;
    }
    getMinimumWords(&MinimumWordPlay);
	fileScan(strWordList, strLength);
    wordInfoList gameWords[NUM_WORDS];
	
	printf("Loading Game in 3 Seconds.... \n");
	
	before = clock();
    while(before + gameLoad > clock()){
	
	}
	
    initscr();
	drawGameBorder();
	addWord(strWordList, NUM_WORDS, MinimumWordPlay, gameWords, &wordArray);
	
	time(&startTime);
    while(playMode){
		refresh();
		time(&endTime);
		elapsedTime = endTime - startTime;
		mvprintw(43,107, "Elasped Time: %ld Seconds", elapsedTime);
        mvprintw(42,16, "");
		scanw("%s", guessWord);
		for(i = 0 ; i < 117; i++){
			mvprintw(42,16+i, " ");
		}
		if(elapsedTime % gameSpeed == 0 && gameSpeed > 1){
			moveWords(gameWords, &wordArray);
		}
		if(elapsedTime % 30 == 0 && gameSpeed > 2){
			gameSpeed--;
		}
	}

	endwin();
}

//Function Definitions


void addWord(char* WL[], int NUM_WORDS, int MinimumWordPlay, wordInfoList gameWords[], int* wordArray){
    srand((int)time(NULL));
	int randx;
	int randWordIndex = rand() % NUM_WORDS;
	int loop = 1;
	while(loop){
		randx = (rand() % 127) + 4;
		gameWords[randWordIndex].xPos = randx;
		gameWords[randWordIndex].yPos = 3;
		strcpy(gameWords[randWordIndex].word, WL[randWordIndex]);
        if(strlen(WL[randWordIndex]) > MinimumWordPlay && randx + strlen(WL[randWordIndex]) < 130){
            loop = 0;
        }

	}
	mvprintw(3, randx, "%s", gameWords[randWordIndex].word);
	*wordArray = randWordIndex;
}

void moveWords(wordInfoList gameWords[], int* wordArray){
	int tempY = gameWords[*wordArray].yPos;
	gameWords[*wordArray].yPos = gameWords[*wordArray].yPos + 1;
	mvprintw();
	for(int i = 0; i < strlen(gameWords[*wordArray].word); i++){
		mvprintw(gameWords[tempY].yPos, gameWords[*wordArray].xPos + i, " ");
	}
	
}
