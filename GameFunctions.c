#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#include <string.h>
#include <time.h>

void getNumberOfWords(int* NUM_WORDS, FILE* wordsList){ //Coded By Joseph Sheets
    *NUM_WORDS = -1;
	char currentWord[20];
    while(!feof(wordsList)){
		fgets(currentWord, 50, wordsList);
        *NUM_WORDS = *NUM_WORDS + 1;
    }
	fclose(wordsList);
}

void getMinimumWords(int* MinimumWordPlay){
	printf("\nPlease enter the minimum word count: ");
	scanf("%d", MinimumWordPlay);
}

void startUpFunction(bool validStartUp, char startUpButton, bool* playMode, bool* writeMode){ //Coded By Joseph Sheets
	while(!validStartUp){
		scanf(" %c", &startUpButton);
        if(startUpButton == 'w' || startUpButton == 'W'){
			*writeMode = true;
            *playMode = false;
            validStartUp = true;
        }
        else if(startUpButton == 'p' || startUpButton == 'P'){
			*playMode = true;
            *writeMode = false;
            validStartUp = true;
        }
        else{
			printf("Invalid Input! Try Again!\n"); 
        }
    }
}

void startUpPrompt(int NUM_WORDS){ //Coded By Joseph Sheets
	printf("\nHello! This is a very fun typing game! You will need to type the words as they appear.\n");
	printf("Would you like to play or add a word?\n");
	printf("You currently have %d words that be used. (P/W) ", NUM_WORDS);
}

void appendFunc(){ //Coded By Sam Carroll
	FILE* fp;
	int wordInsert;
	int wordClear;
	char tempString[50];
	char input;
	int ask = 1;
	
	while(ask){
		printf("\nEnter 'A' to add words or 'C' to clear the word library: ");
		scanf(" %c", &input);
	
		if(input == 'A' || input == 'a'){
			wordInsert = 1;
			fp = fopen("wordslist.txt", "a");
			ask = 0;
		}
		else if(input == 'C' || input == 'c'){
			wordClear = 1;
			fp = fopen("wordslist.txt", "w");
			ask = 0;
		}
		else{
			printf("Invalid input. Try again.\n");
		}
	
	}
	
	while(wordInsert){
		printf("Enter a string to add to the library of words(when finished enter \"done\"): ");
		scanf("%s", tempString);
		
		if(strcmp(tempString, "done") == 0 || strcmp(tempString, "Done") == 0){
			break;
		}
		
		else{
			fprintf(fp, "%s\n", tempString);
		}
		
	}
	
	if(wordClear == 1){
		fprintf(fp, " ");
	}
	fclose(fp);
	
}

void drawGameBorder(void){ //Coded By Joseph Sheets
	for(int i = 0; i < 130; i++){
		mvprintw(2, 4+i, "-");
	}
		for(int i = 0; i < 130; i++){
			mvprintw(44, 3+i, "-");
		}
		for(int i = 0; i < 130; i++){
			mvprintw(40, 3+i, "-");
		}
		
	for(int i = 0; i < 43; i++){
			mvprintw(2+i, 133, "|");
		}
		for(int i = 0; i < 43; i++){
			mvprintw(2+i, 3, "|");
		}
	
	mvprintw(42,5, "Type Here: ");	
	
}

void fileScan(char* strWordList[], int strLength[]){
	FILE* fp;
	char tempString[30];
	fp = fopen("wordslist.txt", "r");
	int i = 0;
	while(!feof(fp)){
		fscanf(fp, "%s", tempString);
		strWordList[i] = (char*) malloc(sizeof(tempString) + 1);
		strcpy(strWordList[i], tempString);
		strLength[i] = strlen(strWordList[i]);
		++i;
	}
}

void moveWords(wordInfoList gameWords[], int wordArray, int spaces){ //Coded by Sam Carroll
	
	int temp;
	int i;
	
	temp = gameWords[wordArray].yPos;
	gameWords[wordArray].yPos += spaces;
	mvprintw(gameWords[wordArray].yPos, gameWords[wordArray].xPos, "%s", gameWords[wordArray].word);
	
	if(temp != 5){
		for(i = 0; i < strlen(gameWords[wodArray].name); ++i)
		{
		mvprintw(temp, gameWords[wordArray].xPos + i, "%s", " ");
		}
	}
	
}

void deleteWord(wordInfoList gameWords[], int wordArray){ //Coded by Sam Carroll
	
	int i;
	
	for(i = 0; i < strlen(gameWords[wordArray].name); ++i){
		
		mvprintw(gameWords[wordArray].yPos, gameWords[wodArray].xPos, " ");
		
	}
}
