
#pragma warning(disable:4996) 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 



void printString(char arr[]) {


    for (int i = 0; i < strlen(arr); i++)
    {
        printf("%c", arr[i]);

    }
}


void splitToTwo(char arr[])
{
    int length = strlen(arr);

    char strPart1[100];
    char strPart2[100];

    for (int i = 0; i < length; i++)
    {
        if (i < length / 2) {

            strPart1[i] = arr[i];
        }
        if (i == length / 2) strPart1[i] = '\0';

        if (i >= length / 2) {

            strPart2[i - (length / 2)] = arr[i];
        }
        if (i == length - 1) strPart2[i / 2 + 1] = '\0';

    }

    printString(strPart1);
    printf("\n");
    printString(strPart2);


}

void splitToInfinite(char arr[]) {

    int length = strlen(arr);
    char strPart1[100];
    int strlenInfinite= length;

    while (1)
    {
        int i;
        for ( i = 0; i < strlenInfinite /2; i++)
        {
            if (i < strlenInfinite / 2) {

                strPart1[i] = arr[i];
            }

        }
        strPart1[i] = '\0';
        strlenInfinite = strlen(strPart1);
        if (strlenInfinite == 0) return;
        printString(strPart1);
        printf("\n");

    }
}

   
int add222(int num)
{

    printf("%d\n", num);
    if(num!=100) return(add222(num + 1));
}


struct loto {

    char lotoNum[50];
    char lotoDate[50];
    struct loto* next;
    struct loto* prev;
    
};

struct loto* HEAD=NULL;
struct loto* TAIL=NULL;
void linkTheList(struct loto* current)
{
    if (!HEAD) { //need to check if it the first item in the list (all this part was missing)

        current->next = NULL;
        current->prev = NULL;
        HEAD = TAIL = current;

    }
    else {

        TAIL->next = current;

        current->prev = TAIL;

        current->next = NULL;//change form TAIL->next to letterItem->next

        TAIL = current;
    }

}

void printList()
{
    struct loto* ptrMover = HEAD;

    while (ptrMover)
    {
        printf("loto num%s and loto date%s \n", ptrMover->lotoNum, ptrMover->lotoDate);
        ptrMover = ptrMover->next;

    }
}

void readFile(char fileName[100])
{

    FILE* f;

    f = fopen(fileName, "r");
    if (f == NULL) {
        printf("Error opening file");
        return(-1);
    }
    else {
        char readLine[200];
        // Display the content of myFile.txt and count letters 
        fgets(readLine, 200, f);
        char* tokenNum;
        char* tokenDate;
        while (fgets(readLine, 200, f)) {
          
            struct loto* current = (struct loto*)malloc(sizeof(struct loto));
            if(current)
            { 
            tokenNum = strtok(readLine, ",");
            strcpy(current->lotoNum, tokenNum);
            tokenDate = strtok(NULL, ",");
            strcpy(current->lotoDate, tokenDate);
            linkTheList(current);
            }
        }
        fclose(f);
        printList();

        return(0);
    }
}

void searchIt(char lotoNum[])
{
    struct loto* ptrMover = HEAD;

    while (ptrMover)
    {
        if (!strcmp(ptrMover->lotoNum, lotoNum))
        {
            printf("This loto date is %s\n", ptrMover->lotoDate);
            break;
        }

        ptrMover = ptrMover->next;

        if (!ptrMover) printf("there isn't loto num like you chose\n");
    }
}

void userRespones() {

    char userResponse = NULL;
    char numChoose[50];

    while (userResponse != 'Q')
    {
        printf("please choose your action from the list:\n 1 - choose a loto number \n 2 - Q - to quite the program\n");
        userResponse = getch();

        switch (userResponse)
        {

        case 'N':
            printf("please enter a loto number.\n");
            scanf("%s", &numChoose);
            searchIt(numChoose);
            break;

        case 'Q':
            printf("Thank you for use our Great service. See you next time.\n");
            break;

        default:
            printf("Wrong selection. Try be more sharp\n");
            break;
  
        }

    }
}

int main()
{
    char str[] = "abvdefghijkel";
    //splitToTwo(str); Q1
    //splitToInfinite(str); Q2
    //add222(1); Q3
    readFile("Lotto.txt"); 
    userRespones();
    return 0;
}


