#include <stdio.h>
#include <string.h>
/**
 * The following program prompts user to input 5 player jersey numbers and their rating. The progam then displays
 * a menu to replace, update, and output roster members by selecting certain prompted options.
 * @author brycekratzer
*/
int main(void) {

   const int ARRAY_SIZE = 5;
   int playerRating[ARRAY_SIZE];
   int playerNumber[ARRAY_SIZE];
   const char menuOptions[ARRAY_SIZE + 1] = {'u', 'a', 'r', 'o', 'q', 'd'}; //u - update roster; a - output players rating; r - replace player; o - output roster; q - quit; d - default(for input variable)
   char userInput = menuOptions[ARRAY_SIZE]; //sets as default option
   int userInputInt = 0;

   for(int i = 0; i < ARRAY_SIZE; ++i) { //prompts user to enter 5 different player jersey and rating
      printf("Enter player %d's jersey number: ", i + 1);
      while(scanf("%d", &playerNumber[i]) != 1){
         printf("Enter player %d's jersey number: ", i + 1);
         scanf("%*[^\n]"); 
      }

      printf("Enter player %d's rating number: ", i + 1);
      while(scanf("%d", &playerRating[i]) != 1) {
         printf("Enter player %d's rating number: ", i + 1);
         scanf("%*[^\n]"); 
      }
   }

   printf("\n\nROSTER\n");
   for(int i = 0; i < ARRAY_SIZE; ++i) { //prints ratings and jersey for each player
      printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, playerNumber[i], playerRating[i]);
   }
   

   printf("\n\nMENU\n");
   printf("u - Update player Rating\na - Output players above a rating\n");
   printf("r - Replace player\no - Output roster\nq - Quit\n\n");
   printf("Choose an option: ");
   scanf("%c", &userInput);

   while(scanf("%c", &userInput) != 1 || userInput != 'q') {

      if(menuOptions[0] == userInput) { //if user inputs 'u' then prompts user for input to update player
         
         printf("Enter a jersey number:\n");
         int playerArrayIndex = -1;
         while(playerArrayIndex == -1) {
            int rc = scanf("%d", &userInputInt);
            if (rc == 1) {
               for(int i = 0; i < ARRAY_SIZE; ++i) { //searches for player in array
                  if(playerNumber[i] == userInputInt) {
                     playerArrayIndex = i;
                     break;
                  }
               }
               if(playerArrayIndex == -1) { //if not found, user is prompted to try again
                  printf("Error: Non-existent jersey number selected, please check your data and try again \n");
                  break;
               }
            } else {
               scanf("%*[^\n]"); 
               printf("Error: Non-integer value detected, please check your data and try again\n");
               break;
            }
         }
         if(playerArrayIndex != -1) {
            printf("Enter a new rating for player:\n");
            int rc = scanf("%d", &playerRating[playerArrayIndex]);
            if (rc != 1) {
               scanf("%*[^\n]"); 
               printf("Error: Non-integer value detected, please check your data and try again\n");
            }
         }

      } else if(menuOptions[1] == userInput) { //if user inputs 'a' then program outputs player above user entered rating

         printf("Enter a rating: \n");
         int rc = scanf("%d", &userInputInt);
         if(rc == 1) {
            printf("\nABOVE %d\n", userInputInt);
            for(int i = 0; i < ARRAY_SIZE; ++i) {
                  if(playerRating[i] > userInputInt) {
                     printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, playerNumber[i], playerRating[i]);  
                  }
            }
         } else {
            scanf("%*[^\n]"); 
            printf("Error: Non-integer value detected, please check your data and try again\n");
         }

      } else if(menuOptions[2] == userInput) { //if user inputs 'r' then program replaces said player with another user inputted player
         
         printf("Enter a jersey number:\n");
         int playerArrayIndex = -1;
         while(playerArrayIndex == -1) {
            int rc = scanf("%d", &userInputInt);
            if(rc == 1) {
               for(int i = 0; i < ARRAY_SIZE; ++i) {
                  if(playerNumber[i] == userInputInt) {
                     playerArrayIndex = i;
                     break;
                  }
               }
               if(playerArrayIndex == -1) {
                  printf("Error: Non-existent jersey number selected, please check your data and try again \n");
                  break;
               }
            } else {
               scanf("%*[^\n]"); 
               printf("Error: Non-integer value detected, please check your data and try again\n");
               break;
            }
         }

         if(playerArrayIndex != -1) {
            
            printf("Enter a new jersey:\n");
            int rc = scanf("%d", &playerNumber[playerArrayIndex]);
            if(rc != 1) {
               scanf("%*[^\n]"); 
               printf("Error: Non-integer value detected, please check your data and try again\n");
            } else {
               printf("Enter a rating for the new player:\n");
               rc = scanf("%d", &playerRating[playerArrayIndex]);
               if(rc != 1) {
                  scanf("%*[^\n]"); 
                  printf("Error: Non-integer value detected, please check your data and try again\n");
               }
            }
         }

      } else if(menuOptions[3] == userInput) { //if user inputs 'o' then program outputs current roster

         printf("\n\nROSTER\n");
         for(int i = 0; i < ARRAY_SIZE; ++i) {
            printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, playerNumber[i], playerRating[i]);
         }

      } else { //if invalid menu option is selected then error message displays 
         printf("Error: Unknown option selected");
      }
      printf("\n\nMENU\n");
      printf("u - Update player Rating\na - Output players above a rating\n");
      printf("r - Replace player\no - Output roster\nq - Quit\n\n");
      printf("Choose an option: ");
      scanf("%c", &userInput);

   }
   return 0;
}