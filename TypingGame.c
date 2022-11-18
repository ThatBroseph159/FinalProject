/* SE 185: Final Project //
Team ##
Team member 1 "Sam Carroll" | "50%"
Team member 2 "Joseph Sheets" | "50%"

// Coded By Joseph Sheets
// Last Coded On 11/15/22

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "GameFunctions.h"
#include <ncurses/ncurses.h>

//Struct Definitions

//Functions Declarations

//Code

int main(){
    int NUM_WORDS;
    int MinimumWordPlay;
	int strLength[50];
	int xPosition;
	int yPosition;
    char startUpButton;
	char guessWord[25];
	char* strWordList[50];
    bool validStartUp = false;
    bool writeMode = false;
    bool playMode = false;;
    FILE* wordsList = NULL;
	//int theTimer;
	//int theTime;
	int i;
	
    wordsList = fopen("wordsList.txt", "r");
	if(wordsList == NULL){
		return 0; // Error Opening File
	}
	
	getNumberOfWords(&NUM_WORDS, wordsList);
	startUpPromot(NUM_WORDS);
	startUpFunction(validStartUp, startUpButton, &playMode, &writeMode);
	
	while(writeMode){
		appendFunc();
		wordsList = fopen("wordsList.txt", "r");
		getNumberOfWords(&NUM_WORDS, wordsList);
		fclose(wordsList);
		startUpPromot(NUM_WORDS);
		startUpFunction(validStartUp, startUpButton, &playMode, &writeMode);
	}

    if(NUM_WORDS == 0){
        playMode = false;
        printf("You need atleast 1 words to play!\n");
        return 0;
    }
	getMinimumWords(&MinimumWordPlay);
	fileScan(strWordList, strLength);
	
	initscr();
	drawGameBorder();
	addWord(strWordList, NUM_WORDS, &xPosition, &yPosition);

    while(playMode){
		refresh();
        mvprintw(42,16, "");
		scanw("%s", guessWord);
		for(i = 0 ; i < 100; i++){
			mvprintw(42,16+i, " ");
		}

	}

	endwin();
}

//Function Definitions
