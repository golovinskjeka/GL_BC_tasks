#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char *title;
    int price;
    int numberOfPages;
    char *language;
    float weight;
    int year;
} book;

int main()
{   
    book part[] = {
        {"Harry Potter and the Philosopher's Stone", 150, 399, "English", 0.33, 2001},
        {"Harry Potter and the Chamber of Secrets", 200, 420, "English", 0.38, 2002},
        {"Harry Potter and the Prisoner of Azkaban", 230, 380, "English", 0.29, 2004},
        {"Harry Potter and the Goblet of Fire", 280, 415, "English", 0.37, 2005},
        {"Harry Potter and the Order of the Phoenix", 300, 395, "English", 0.32, 2007},
        {"Harry Potter and the Half-Blood Prince", 350, 435, "English", 0.4, 2009},
        {"Harry Potter and the Deathly Hallows – Part 1", 400, 379, "English", 0.29, 2010},
        {"Harry Potter and the Deathly Hallows – Part 2", 450, 412, "English", 0.36, 2011}
    };

    int numOfPart;
    printf("Enter the number of part which you would like to find out the informarion of (1-8): ");
    scanf("%d", &numOfPart);
    printf("\r\n");
    
    if(numOfPart >= 1 && numOfPart <= 8){
      printf("Title: %s;\r\n", part[numOfPart-1].title);  
      printf("Price: %d grn;\r\n", part[numOfPart-1].price);  
      printf("Number of pages: %d pages;\r\n", part[numOfPart-1].numberOfPages);  
      printf("Language: %s;\r\n", part[numOfPart-1].language);
      printf("Weight: %f kg;\r\n", part[numOfPart-1].weight);  
      printf("Title: %d year.\r\n", part[numOfPart-1].year);  
    }
    else{  
        printf("You entered the wrong number of part.Try again.\r\n");
    }
    return 0;   
}