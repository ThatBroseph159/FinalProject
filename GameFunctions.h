typedef struct word_struct{
    char word[20];
    int xPos;
    int yPos;
} wordInfoList;

void getNumberOfWords(int* NUM_WORDS, FILE* wordsList);
void getMinimumWords(int* MinimumWordPlay);
void startUpFunction(bool validStartUp, char startUpButton, bool* playMode, bool* writeMode);
void fileScan(char* strWordList[], int strLength[]);
void startUpPrompt(int NUM_WORDS);
void appendFunc(void);
void drawGameBorder(void);
void addWord(char* WL[], int NUM_WORDS, int MinimumWordPlay, wordInfoList gameWords[], int* wordArray);
void moveWords(wordInfoList gameWords[], int* wordArray);
