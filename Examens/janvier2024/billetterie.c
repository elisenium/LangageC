#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/** CONSTANTS **/

// indexes of ticket information
#define NBR_INFOS   4
#define USERID_IDX  0
#define FROM_IDX    1
#define TO_IDX      2
#define DATE_IDX    3

#define MAX_LENGTH    50 // maximal number of characters for ticket information
#define DATE_LENGTH   8  // fixed length of date format (i.e. "20190628")

// TODO



/** DECLARATION OF FUNCTIONS **/

bool get_data_from_user(char* buffer, int size);
char** create_ticket(char* user_id, char* from, char* to, char* date);
bool add_ticket_to_db(char*** db, int db_sz, int* nbr_tickets, char** ticket);
int find_ticket(char*** db, int nbr_tickets, char* user_id, char* date);
bool update_ticket(char** ticket, char* from, char* to);
void free_db(char*** db, int* nbr_tickets);
void print_all_tickets(char*** db, int nbr_tickets);
// given functions
void print_ticket(char** ticket);
int menu();
void printErrMsg(char* msg, int option);


/** MAIN PROGRAM **/

int main(int argc, char const *argv[])
{
  // main variables
  int index = -1;
  // TODO declare here: the db, the number of tickets 

  // buffers to read from stdin
  // TODO declare here all the buffers to record data from stdin
  
  // main interactive loop
  int user_choice = -1;
  while (user_choice != 0) {
    user_choice = menu();
    switch (user_choice) {
    case 1 :
      //1. ADD A TICKET IN DB
      //1.a collect ticket information from user
      printf("What is the user ID ?\n");
      // TODO
      printf("What is the departure train station ?\n");
      // TODO
      printf("What is the destination train station ?\n");
      // TODO
      printf("What is the date ?\n");
      // TODO

      //1.b create ticket with collected information
      // TODO

      //1.c add ticket to DB
      // TODO
      
      printf("Ticket added with success!\n");
      break;

    case 2:
      //2. MODIFY A TICKET
      //2.a collect user ID and date of ticket
      printf("What is the user id ?\n");
      // TODO
      
      printf("What is the date?\n");
      // TODO

      //2.b find ticket in DB
      // TODO
      
      if (index == -1) {
        // TODO print error message
        break;
      }

      //2.c collect new ticket information
      printf("Ready to modify ticket at index %d\n", index);
      printf("Modify the FROM station ? (press Enter with empty response to unchange)\n");
      // TODO
      printf("Modify the TO station ? (press Enter with empty response to unchange)\n");
      // TODO
      
      //2.d update ticket information in DB
      // TODO

      printf("Ticket updated with success!\n");
      break;

    case 3:
      //3. PRINT ALL TICKETS FROM DB
      // TODO
      
      break;
      
    case 0:
      //0. FREE DB AND QUIT
      // TODO
      
      printf("Bye bye!\n\n");
      break;

    default:
      printErrMsg("\n!! WARN: '%d' is not a valid option !!\n", user_choice);
      break;
    }
  }
}


/** FUNCTIONS TO IMPLEMENT **/

/**
 * PRE: buffer is a string of size sz
 * POST: reads at most sz-1 characters from stdin, stores them into buffer,
 *       and removes the '\n' from buffer if it is present
 * RES: returns true in case of success, false otherwise
 */
bool get_data_from_user(char* buffer, int sz){
  // TODO
  
  return false;
}

/**
 * PRE: userID, from, to: pointers to strings of maximal MAX_LENGTH characters
 *      date: pointer to a string of exactly MAX_DATE characters
 * POST: creates a valid ticket and deeply copies all the given strings 
 *       into expected locations in the new ticket
 * RES: returns a pointer to the new ticket or NULL in case of error
 */
char** create_ticket(char* userID, char* from, char* to, char* date) {
  // dynamic allocations and checks
  // TODO

  // make the informations copies
  // TODO

  return NULL;
}

/**
 * PRE: db: a pointer to a list of capacity db_sz, containing nbr_tickets tickets
 *      ticket: a pointer to a valid ticket
 * POST: the ticket is added at the end of the db, and the number of tickets 
 *       is updated
 * RES: returns true in case of success, false if db is full
 */
bool add_ticket_to_db(char*** db, int db_sz, int* nbr_tickets, char** ticket) {
  // check if bd is not full
  // TODO
  
  // add the new ticket
  // TODO
  
  return false;
}

/**
 * PRE: db: list of nbr_tickets tickets
 *      userID, date: pointers to strings
 * RES: returns the index of the first ticket in db with both userID and date matching
 *      -1 if no match is found
 */
int find_ticket(char*** db, int nbr_tikets, char* userID, char* date) {
  // TODO
  
  return -1;
}

/**
 * PRE: ticket: pointer to a valid ticket
 *      from, to: pointers to strings of maximal MAX_LENGTH characters
 * POST: if from's size > 0, the corresponding emplacement in given ticket 
 *          is resized and the content of 'from' is deeply copied into the ticket 
 *       if to's size > 0, the corresponding emplacement in given ticket
 *          is resized and the content of 'to' is deeply copied into the ticket
 * RES: returns true in case of success, false otherwise
 */
bool update_ticket(char** ticket, char* from, char* to) {
  // TODO
  
  return false;
}

/**
 * PRE: db: list of nbr_tickets tickets
 * POST: all the tickets and their data are freed ; nbr_tickets is set to 0
 */
void free_db(char*** db, int* nbr_tickets){
  // TODO
  
}

/**
 * PRE: db: list of nbr_tickets tickets
 * POST: prints all the tickets on stdout
 */
void print_all_tickets(char*** db, int nbr_tickets){
  printf("Database of the tickets:\n");
  // TODO
  
} 


// =====================================================
//        DO NOT MODIFY THESE FUNCTIONS/MACROS           
// =====================================================

/**
 * PRE: ticket: pointer to a ticket
 * POST: prints all the information of the ticket on stdout
 */
void print_ticket(char** ticket){
  printf(
    "Ticket:\n\tClientID: %s\n\tFROM: %s\n\tTO: %s\n\tDate: %s\n",
    ticket[USERID_IDX], ticket[FROM_IDX], ticket[TO_IDX], ticket[DATE_IDX]
    );
} 

enum {BLACK_TEXT=30,RED_TEXT,GREEN_TEXT,YELLOW_TEXT,BLUE_TEXT,PURPLE_TEXT,CYAN_TEXT,WHITE_TEXT};
#define colorOn(mode,textColor) printf("\033[%d;%dm",mode,textColor)   // mode: 0 normal ; 1 bold
#define colorOff() printf("\033[0m");  // text color reset

/**
 * POST: displays the menu and the uers's choice on stdout
 * RES: returns the user's choice
 */
int menu() {
  colorOn(1,PURPLE_TEXT);
  printf("\n" \
    "1. Add a ticket\n" \
    "2. Modify a ticket\n" \
    "3. Cancel a ticket\n" \
    "4. Print all tickets\n" \
    "0. Quit\n");
  colorOn(1,CYAN_TEXT);
  printf("What is your choice ? ");
  int choice = 0;
  scanf("%d", &choice);
  getchar(); // get EOL
  printf("\n>> You wisely choose: %d\n", choice);
  colorOff();
  return choice;
}

void printErrMsg(char* msg, int option) {
  char buf[256];
  sprintf(buf, msg, option);
  colorOn(1,RED_TEXT);
  printf("%s", buf);
  colorOff();
}
