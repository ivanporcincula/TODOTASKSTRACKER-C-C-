// WRITTEN BY:  I. Porcincula
// SECTION: EQ1        
//                
// FOR COURSE: LBYEC2B
//
// PURPOSE:
// This program aims to help out students and citizens 
// to keep track of their things they need to do.
// The TO-DO Tracker Program is a user defined function by passing
// the structure types through methods.
//
// OVERALL METHOD/ALGORITHM:
// The list of general tasks is:
// 1. Display main menu and ask the user to input their choice.

// 2. Execute the main menu item.
//    2-1. If selected main menu item is '1', the user is then 
//           asked to create a new account.
//    2-2. If selected main menu item is '2', the user is then
//           asked to login their account.
//	  2-3. If selected main menu item is '3', the program will
//            exit.
// 3. If the user chose to login their account, the second menu
//    		 "Add new tasks to do" is displayed.
//    3-1. If selected menu item is '1', the user is then
//           asked to add the task they want to add and put them
//			 in a specific category (Home, Education, Games, Meeting)
// 
//           The user is prompted to choose the type of 
//           task_name (High, Medium, Low).       
//
//			 PLEASE NOTE: THE USER HAS TO CHOOSE OPTION [5] UNDER THIS
//					      MENU TO SAVE CHANGES TO THEIR ADDED TASKS      
//    3-2. If selected menu item is '2', the user is then
//			asked to input the task they have accomplished.
//    3-3. If selected menu item is '3', the user is then 
//          asked to input to sort according to date & time,
//			task_name, category or suggested order from the
//			application on accomplishing tasks.
//	  3-4. If selected menu item is '4', the program will 
//         display the list of all the accomplished tasks 
//         that the user has accomplished.
//
// CREDITS:
//
// STRUCTURES:
// accountInfo
//   has variables which stores account info
// accountDatabases
//   initializes accountInfo as 1D array
//   and counter variables for counting
//
// CLASSES:
// Tasks
//   methods:
//      getDelimitedItem
//			-returns the string from file reading
//
//		removeAll
//			-removes the finished task from database
//
//		addHigh
//			-adds the high task_name tasks
//
//		addMed
//			-adds the medium task_name tasks
//
//		addLow
//			-adds the low task_name tasks
//
//		storeTimeAndDate
//			-stores the time and date from database after the
//			program reads the database file
//			-also displays the the tasks according to time and date
//			 in ascending order
//
//		highPrioritySort 
//			-reads the database file sorted according to high task_name
//
//		sortTimeAndDateHigh
//			-sorts and displays the tasks according to high task_name and time & date
//			 in ascending order
//
//		medPrioritySort
//			-reads the database file sorted according to medium task_name
//
//		sortTimeAndDateMedium
//			-sorts and displays the tasks according to medium task_name and time & date
//			 in ascending order
//
//		lowPrioritySort
//			-reads the database file sorted according to low task_name
//
//		sortTimeAndDateLow
//			-sorts and displays the tasks according to low task_name and time & date
//			 in ascending order
//
//		displayTaskPriority
//			-displays the tasks according to high, medium, low task_name only
//		
//		taskRemoval
//			-removes the accomplished task
//
//		displayAccomplished
//			-displays the list of accomplished tasks
//		
// Home
//	methods:
//		addHigh
//			-adds the high task_name tasks
//
//		addMed
//			-adds the medium task_name tasks
//
//		addLow
//			-adds the low task_name tasks
//
//		categorySorted
//			-sorts the tasks according to category
//
//		displayCategory
//			-displays to the program according to category
//
//
// Education
//	methods:
//		addHigh
//			-adds the high task_name tasks
//
//		addMed
//			-adds the medium task_name tasks
//
//		addLow
//			-adds the low task_name tasks
//
//		categorySorted
//			-sorts the tasks according to category
//
//		displayCategory
//			-displays to the program according to category
//
// Games
//	methods:
//		addHigh
//			-adds the high task_name tasks
//
//		addMed
//			-adds the medium task_name tasks
//
//		addLow
//			-adds the low task_name tasks
//
//		categorySorted
//			-sorts the tasks according to category
//
//		displayCategory
//			-displays to the program according to category
//
// Meeting
//	methods:
//		addHigh
//			-adds the high task_name tasks
//
//		addMed
//			-adds the medium task_name tasks
//
//		addLow
//			-adds the low task_name tasks
//
//		categorySorted
//			-sorts the tasks according to category
//
//		displayCategory
//			-displays to the program according to category
// Account
//	methods:
//      getDelimitedItem
//			-returns the string from file reading
//
//		createAccount
//			-creates an account for the user and stores it in a database
//
//		loginAccount
//			-asks the user to login from their existing account		
// AllMenu
//	attributes:
//		accDb (object Account)
//	methods:
//		Menu_1
//		-displays the main menu
//
//		Menu_2
//		-displays the 2nd menu
//		
//		Menu_3
//		-displays the 3rd menu
//
//		Menu_4_
//		-displays the 4th menu for Home
//
//		Menu_5
//		-displays the 5th menu
//
// FUNCTIONS:
//
// promptWelcome
//   display welcome prompt
//
// INCLUDED FILES:
// stdio.h, stdlib.h, string.h, time.h
//
//DATA FILES:
// -accountDatabase.dat
// File name depends on the who is using the program:
//	wherein i is any value from 0 to 49 as only 50 users can register an account
// -homei.dat
// -educationi.dat
// -gamesi.dat
// -meetingi.dat
// highi.dat
// mediumi.dat
// lowi.dat
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <iostream>
#define BUFFER_SIZE 1000

//Structures
typedef struct {
  
   char username[50];
   char password[50]; 
   int month[4][50];
   int day[4][50];
   int year[4][50];
   int hours[4][50];
   int minutes[4][50];
   int seconds[4][50];
   char task_name[4][50][40];
  

  
} accountInfo;
typedef struct {
	int count;
	int count1;
	int count2[4];
	int count3[4];
	int count4[4];
    accountInfo accDatabase[50];
    
} accountDatabases;


class Tasks{
	private:
		// FUNCTION NAME: removeAll
		// CREDITS: Pankaj Prakash
		//           
		// PARAMETERS: char *str, const char *toRemove
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: none
		//
		// CALLED FROM: taskRemoval()
		//
		// METHOD:
		// 1. Get the length of the string and the word to remove
		// 2. Match word with string which is variable found
		// 3. If word is found then shift all characters to left
		//    and decrement the string length
		// This function removes the word from the string
		void removeAll(char * str, const char * toRemove){
				    int i, j, stringLen, toRemoveLen;
				    int found;
				
				    stringLen   = strlen(str);      // Length of string
				    toRemoveLen = strlen(toRemove); // Length of word to remove
				
				
				    for(i=0; i <= stringLen - toRemoveLen; i++)
				    {
				    	
				        /* Match word with string */
				        found = 1;
				        for(j=0; j < toRemoveLen; j++)
				        {
				            if(str[i + j] != toRemove[j])
				            {
				                found = 0;
				                break;
				            }
				        }
				
				        /* If it is not a word */
				        if(str[i + j] != '\t' && str[i + j] != '\n' && str[i + j] != '\0' && str[i + j] != '|') 
				        {
				            found = 0;
				        }
				
				        /*
				         * If word is found then shift all characters to left
				         * and decrement the string length
				         */
				        if(found == 1)
				        {
				            for(j=i; j <= stringLen - toRemoveLen; j++)
				            {
				                str[j] = str[j + toRemoveLen];
				            }
				
				            stringLen = stringLen - toRemoveLen;
				
				            // We will match next occurrence of word from current index.
				            i--;
				        }
				    }
			}
	protected:
		// FUNCTION NAME: getDelimitedItem
		// CREDITS: J. Catalan
		//           
		// PARAMETERS: char s[], char d, FILE *fp
		//
		// RETURN VALUE: integer         
		//
		// CALLS TO: none
		//
		// CALLED FROM: highPrioritySort(), medPrioritySort(), lowPrioritySort(), 
		//
		// METHOD:
		// 1. Reads the content of the file.
		// This function reads the content of a file.
		virtual int getDelimitedItem(char s[],char d, FILE *fp) {
		    int c;
		    int i=0;
		    c=0;
		    s[i]=0;
		    
		    while (!feof(fp)) {
		        c=fgetc(fp);
		        if (c==d||c=='\n'||c=='/'||c==':'||c==40||c==EOF) return i;
		        else {
		            s[i]=c;
		            i++;
		            s[i]=0;
		        }
		    }
		    return i;
		}
	public:
		
		/*inherited methods*/
		virtual void addHigh(accountDatabases *ad){
		}
		virtual void addMed(accountDatabases *ad){
		}
		virtual void addLow(accountDatabases *ad){
		}
		/*inherited methods*/
		
		// FUNCTION NAME: storeTimeAndDate
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. If count of HOME category is not equal to 0
		//	  store the value into the given progYear and etc. 1D arrays
		//	
		// 2. If count of EDUCATION catgeory is not equal to 0
		//	  store the value into the given progYear and etc. 1D Arrays
		//
		// 3. If count of GAMES catgeory is not equal to 0
		//	  store the value into the given progYear and etc. 1D Arrays
		//
		// 4. If count of MEETING catgeory is not equal to 0
		//	  store the value into the given progYear and etc. 1D Arrays
		//
		// 5. Using a nested for loop, arrange the time and date in ascending
		//	  order.
		//
		// 6. Display the tasks in sorted time and date.
		//
		// This function stores the time and data and then sorts them in ascending order
		// and then displays the sorted time and data.
		
		void storeTimeAndDate(accountDatabases *ad){
			int i,j,counter, tempYear,tempMonth,tempDay,tempMinute,tempHour,tempSecond; //counter, increment, and temporary variables
			int control; //control variable
			int totalEntries = ad->count2[0] + ad->count2[1] + ad->count2[2] + ad->count2[3]; //total number of tasks
			int progYear[totalEntries],progMonth[totalEntries],progHour[totalEntries];   //array size is total number of tasks
			int progDay[totalEntries], progMinute[totalEntries], progSecond[totalEntries];  //array size is total number of tasks
			char progTask[totalEntries][40], tempTask[40]; //array size is total number of tasks and maximum string size is 40
			counter=0;
			
			
			
			/*HOME CATEGORY*/
			if(ad->count2[0] != 0){
				for(i=0;i<ad->count2[0];i++){
				strcpy(progTask[i],ad->accDatabase[ad->count1].task_name[0][i]);
				progMonth[i]=ad->accDatabase[ad->count1].month[0][i];
				progDay[i]=ad->accDatabase[ad->count1].day[0][i];
				progYear[i]=ad->accDatabase[ad->count1].year[0][i];
				progHour[i]=ad->accDatabase[ad->count1].hours[0][i];
				progMinute[i]=ad->accDatabase[ad->count1].minutes[0][i];
				progSecond[i]=ad->accDatabase[ad->count1].seconds[0][i];
				counter++;
				}
			}
			
			control=0;
			
			/*EDUCATION CATEGORY*/
			if(ad->count2[1]!=0){
				for(i=counter;i<ad->count2[0]+ad->count2[1];i++){
					strcpy(progTask[i],ad->accDatabase[ad->count1].task_name[1][control]);
					
					progMonth[i]=ad->accDatabase[ad->count1].month[1][control];
					progDay[i]=ad->accDatabase[ad->count1].day[1][control];
					progYear[i]=ad->accDatabase[ad->count1].year[1][control];
					progHour[i]=ad->accDatabase[ad->count1].hours[1][control];
					progMinute[i]=ad->accDatabase[ad->count1].minutes[1][control];
					progSecond[i]=ad->accDatabase[ad->count1].seconds[1][control];
				
					control++;
					counter++;
				}
			}
			
			control=0;
			
			/*GAMES CATEGORY*/
			if(ad->count2[2]!=0){
				for(i=counter;i<ad->count2[0]+ad->count2[1]+ ad->count2[2];i++){
					strcpy(progTask[i],ad->accDatabase[ad->count1].task_name[2][control]);
					progMonth[i]=ad->accDatabase[ad->count1].month[2][control];
					progDay[i]=ad->accDatabase[ad->count1].day[2][control];
					progYear[i]=ad->accDatabase[ad->count1].year[2][control];
					progHour[i]=ad->accDatabase[ad->count1].hours[2][control];
					progMinute[i]=ad->accDatabase[ad->count1].minutes[2][control];
					progSecond[i]=ad->accDatabase[ad->count1].seconds[2][control];
					
					control++;
					counter++;
				}
			}
			
			control=0;
			
			/*MEETING CATEGORY*/
			if(ad->count2[3]!=0){
				for(i=counter;i<totalEntries;i++){
					strcpy(progTask[i],ad->accDatabase[ad->count1].task_name[3][control]);
					progMonth[i]=ad->accDatabase[ad->count1].month[3][control];
					progDay[i]=ad->accDatabase[ad->count1].day[3][control];
					progYear[i]=ad->accDatabase[ad->count1].year[3][control];
					progHour[i]=ad->accDatabase[ad->count1].hours[3][control];
					progMinute[i]=ad->accDatabase[ad->count1].minutes[3][control];
					progSecond[i]=ad->accDatabase[ad->count1].seconds[3][control];
					control++;
					counter++;
				}		
			}
			
			
			for(i=0;i<totalEntries;i++){
				for(j=i+1;j<totalEntries;j++){
					/*arrange year if the other year is less than*/
					if(progYear[i]>progYear[j]){
						strcpy(tempTask,progTask[i]);
						strcpy(progTask[i],progTask[j]);
						strcpy(progTask[j],tempTask);
						
						tempYear = progYear[i];
						progYear[i]=progYear[j];
						progYear[j]=tempYear;
						
						
						tempMonth = progMonth[i];
						progMonth[i] = progMonth[j];
						progMonth[j]=tempMonth;
						
						tempDay = progDay[i];
						progDay[i] = progDay[j];
						progDay[j]=tempDay;
						
						tempHour = progHour[i];
						progHour[i] = progHour[j];
						progHour[j]=tempHour;
					
						tempMinute = progMinute[i];
						progMinute[i] = progMinute[j];
						progMinute[j]=tempMinute;
						
						tempSecond = progSecond[i];
						progSecond[i] = progSecond[j];
						progSecond[j]=tempSecond;	
					}
					/*if they are at the same year*/
					else if(progYear[i]==progYear[j]){
						
						/*arrange month if the other month is less than*/
						if(progMonth[i]>progMonth[j]){
							strcpy(tempTask,progTask[i]);
							strcpy(progTask[i],progTask[j]);
							strcpy(progTask[j],tempTask);
							
							tempMonth = progMonth[i];
							progMonth[i] = progMonth[j];
							progMonth[j]=tempMonth;
							
							tempDay = progDay[i];
							progDay[i] = progDay[j];
							progDay[j]=tempDay;
							
							tempHour = progHour[i];
							progHour[i] = progHour[j];
							progHour[j]=tempHour;
							
							tempMinute = progMinute[i];
							progMinute[i] = progMinute[j];
							progMinute[j]=tempMinute;
							
							tempSecond = progSecond[i];
							progSecond[i] = progSecond[j];
							progSecond[j]=tempSecond;
							
						}
						/*if they are at the same month */
						else if(progMonth[i]==progMonth[j]){
							/*arrange day if the other day is less than*/
							if(progDay[i]>progDay[j]){
								strcpy(tempTask,progTask[i]);
								strcpy(progTask[i],progTask[j]);
								strcpy(progTask[j],tempTask);
								
								tempDay = progDay[i];
								progDay[i] = progDay[j];
								progDay[j]=tempDay;
								
								tempHour = progHour[i];
								progHour[i] = progHour[j];
								progHour[j]=tempHour;
								
								tempMinute = progMinute[i];
								progMinute[i] = progMinute[j];
								progMinute[j]=tempMinute;
								
								tempSecond = progSecond[i];
								progSecond[i] = progSecond[j];
								progSecond[j]=tempSecond;
							
							}
							/*if they have the same day*/
							else if(progDay[i]==progDay[j]){
								/*arrange hour if the other hour is less than*/
								if(progHour[i]>progHour[j]){
									strcpy(tempTask,progTask[i]);
									strcpy(progTask[i],progTask[j]);
									strcpy(progTask[j],tempTask);
									
									tempHour = progHour[i];
									progHour[i] = progHour[j];
									progHour[j]=tempHour;
									
									tempMinute = progMinute[i];
									progMinute[i] = progMinute[j];
									progMinute[j]=tempMinute;
									
									tempSecond = progSecond[i];
									progSecond[i] = progSecond[j];
									progSecond[j]=tempSecond;
								}
								/*if they have the same hour*/
								else if(progHour[i]==progHour[j]){
									/*arrange minute if the other minute is less than*/
									if(progMinute[i]>progMinute[j]){
										strcpy(tempTask,progTask[i]);
										strcpy(progTask[i],progTask[j]);
										strcpy(progTask[j],tempTask);
										
										tempMinute = progMinute[i];
										progMinute[i] = progMinute[j];
										progMinute[j]=tempMinute;
										
										tempSecond = progSecond[i];
										progSecond[i] = progSecond[j];
										progSecond[j]=tempSecond;
									}
									/*if they have the same minute*/
									else if(progMinute[i]==progMinute[j]){
										/*arrange second if the other second is less than*/
										if(progSecond[i]>progSecond[j]){
											strcpy(tempTask,progTask[i]);
											strcpy(progTask[i],progTask[j]);
											strcpy(progTask[j],tempTask);
											
											tempSecond = progSecond[i];
											progSecond[i] = progSecond[j];
											progSecond[j]=tempSecond;
										}
									}
								}
							}
						}
					}
				}
			}
			
			/*displays the tasks and its deadline according to time & date in ascending order*/	
			for(i=0;i<totalEntries;i++){	
			    if(strlen(progTask[i]) != 0){
			    	printf("Name of task: %s\n",progTask[i]);
					printf("Deadline: %i/%i/%i %i:%i:%i\n\n",progMonth[i],progDay[i],progYear[i],progHour[i],progMinute[i],progSecond[i]);
				}
				
			}	
			
	}
		
		// FUNCTION NAME: highPrioritySort
		// CREDITS: Ivan Porcincula, Jack Catalan
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: getDelimitedItem()
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. Set custom file name according to the current user
		//	  
		// 2. Open the file and if the file is not null, read the file.
		//
		// This function reads and reads the content of HIGH task_name file
		
		void highPrioritySort(accountDatabases *ad){
			FILE *fp;
			   int i;
			   char s[100];
			   char customFile[500];  
			   sprintf(customFile, "high%i.dat", ad->count1); //set custom file name according to the current user
			   fp = fopen(customFile,"r"); //open the file
			   
			   if(fp!=NULL){
			   	getDelimitedItem(s,'|',fp);
			      ad->count2[0] = atoi(s);       //reads the first text in the file before | , then converts to int 
			      
				  for (i=0; i<ad->count2[0]; i++) {
				  	  getDelimitedItem(ad->accDatabase[ad->count1].task_name[0][i], '|',fp);	//reads the whole text before |
					  
					  getDelimitedItem(s, '|',fp);
					  ad->accDatabase[ad->count1].month[0][i] = atoi(s); //reads the whole text before |, then converts to int 
			          
			          getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].day[0][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].year[0][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].hours[0][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].minutes[0][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].seconds[0][i] = atoi(s); //reads the whole text before |, then converts to int 
	      		}
	      		fclose(fp);
			   	
			   }
			   
			   
	
		}
		
		// FUNCTION NAME: sortTimeAndDateHigh
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. Set custom file name according to the current user
		//	  
		// 2. Open the file and if the file is not null, read the file.
		//
		// This function reads the content of HIGH task_name file and displays 
		// the tasks in medium task_name according to time and date 
		
		void sortTimeAndDateHigh(accountDatabases *ad){
			int i,j,tempYear,tempMonth,tempDay,tempMinute,tempHour,tempSecond; //counter, and temporary variables
			int progYear[ad->count2[0]],progMonth[ad->count2[0]],progHour[ad->count2[0]]; //array size is the number of high task_name tasks
			int progDay[ad->count2[0]], progMinute[ad->count2[0]], progSecond[ad->count2[0]]; //array size is the number of high task_name tasks		
			char progTask[ad->count2[0]][40],tempTask[40]; //array size is the number of high task_name tasks and maximum string size is 40
				
				/*store the data in a 1D array*/
				for(i=0;i<ad->count2[0];i++){
					strcpy(progTask[i],ad->accDatabase[ad->count1].task_name[0][i]);
					progMonth[i]=ad->accDatabase[ad->count1].month[0][i];
					progDay[i]=ad->accDatabase[ad->count1].day[0][i];
					progYear[i]=ad->accDatabase[ad->count1].year[0][i];
					progHour[i]=ad->accDatabase[ad->count1].hours[0][i];
					progMinute[i]=ad->accDatabase[ad->count1].minutes[0][i];
					progSecond[i]=ad->accDatabase[ad->count1].seconds[0][i];
					
				}
				
				for(i=0;i<ad->count2[0];i++){
					for(j=i+1;j<ad->count2[0];j++){
						/*compare which year comes first*/
						if(progYear[i]>progYear[j]){
							strcpy(tempTask,progTask[i]);
							strcpy(progTask[i],progTask[j]);
							strcpy(progTask[j],tempTask);
							
							tempYear = progYear[i];
							progYear[i]=progYear[j];
							progYear[j]=tempYear;
							
							
							tempMonth = progMonth[i];
							progMonth[i] = progMonth[j];
							progMonth[j]=tempMonth;
							
							tempDay = progDay[i];
							progDay[i] = progDay[j];
							progDay[j]=tempDay;
							
							tempHour = progHour[i];
							progHour[i] = progHour[j];
							progHour[j]=tempHour;
						
							tempMinute = progMinute[i];
							progMinute[i] = progMinute[j];
							progMinute[j]=tempMinute;
							
							tempSecond = progSecond[i];
							progSecond[i] = progSecond[j];
							progSecond[j]=tempSecond;	
						}
						/*if they have the same year*/
						else if(progYear[i]==progYear[j]){
							/*compare which month comes first*/
							if(progMonth[i]>progMonth[j]){
								strcpy(tempTask,progTask[i]);
								strcpy(progTask[i],progTask[j]);
								strcpy(progTask[j],tempTask);
								
								tempMonth = progMonth[i];
								progMonth[i] = progMonth[j];
								progMonth[j]=tempMonth;
								
								tempDay = progDay[i];
								progDay[i] = progDay[j];
								progDay[j]=tempDay;
								
								tempHour = progHour[i];
								progHour[i] = progHour[j];
								progHour[j]=tempHour;
								
								tempMinute = progMinute[i];
								progMinute[i] = progMinute[j];
								progMinute[j]=tempMinute;
								
								tempSecond = progSecond[i];
								progSecond[i] = progSecond[j];
								progSecond[j]=tempSecond;
								
							}
							/*if they have the same month*/
							else if(progMonth[i]==progMonth[j]){
								/*compare which day comes first*/
								if(progDay[i]>progDay[j]){
									strcpy(tempTask,progTask[i]);
									strcpy(progTask[i],progTask[j]);
									strcpy(progTask[j],tempTask);
									
									tempDay = progDay[i];
									progDay[i] = progDay[j];
									progDay[j]=tempDay;
									
									tempHour = progHour[i];
									progHour[i] = progHour[j];
									progHour[j]=tempHour;
									
									tempMinute = progMinute[i];
									progMinute[i] = progMinute[j];
									progMinute[j]=tempMinute;
									
									tempSecond = progSecond[i];
									progSecond[i] = progSecond[j];
									progSecond[j]=tempSecond;
								
								}
								/*if they have the same day*/
								else if(progDay[i]==progDay[j]){
									/*compare which hour comes first*/
									if(progHour[i]>progHour[j]){
										strcpy(tempTask,progTask[i]);
										strcpy(progTask[i],progTask[j]);
										strcpy(progTask[j],tempTask);
										
										tempHour = progHour[i];
										progHour[i] = progHour[j];
										progHour[j]=tempHour;
										
										tempMinute = progMinute[i];
										progMinute[i] = progMinute[j];
										progMinute[j]=tempMinute;
										
										tempSecond = progSecond[i];
										progSecond[i] = progSecond[j];
										progSecond[j]=tempSecond;
									}
									/*if they have the same hour*/
									else if(progHour[i]==progHour[j]){
										/*compare which minute comes first*/
										if(progMinute[i]>progMinute[j]){
											strcpy(tempTask,progTask[i]);
											strcpy(progTask[i],progTask[j]);
											strcpy(progTask[j],tempTask);
											
											tempMinute = progMinute[i];
											progMinute[i] = progMinute[j];
											progMinute[j]=tempMinute;
											
											tempSecond = progSecond[i];
											progSecond[i] = progSecond[j];
											progSecond[j]=tempSecond;
										}
										
										/*if they have the same minute*/
										else if(progMinute[i]==progMinute[j]){
											/*compare which second comes first*/
											if(progSecond[i]>progSecond[j]){
												strcpy(tempTask,progTask[i]);
												strcpy(progTask[i],progTask[j]);
												strcpy(progTask[j],tempTask);
												
												tempSecond = progSecond[i];
												progSecond[i] = progSecond[j];
												progSecond[j]=tempSecond;
											}
										}
									}
								}
							}
						}
					}
				}
				/*display the arranged time & date*/
				
				if(ad->count2[0] != 0){
					printf("HIGH PRIORITY\n");
					for(i=0;i<ad->count2[0];i++){
						if(strlen(progTask[i]) != 0){
					    	printf("Name of task: %s\n",progTask[i]);
							printf("Deadline: %i/%i/%i %i:%i:%i\n\n",progMonth[i],progDay[i],progYear[i],progHour[i],progMinute[i],progSecond[i]);
					}
				}	
					
					
				}
				
			
		}
		
		// FUNCTION NAME: medPrioritySort
		// CREDITS: Ivan Porcincula, Jack Catalan
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: getDelimitedItem()
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. Set custom file name according to the current user
		//	  
		// 2. Open the file and if the file is not null, read the file.
		//
		// This function reads the content of MEDIUM task_name file
		void medPrioritySort(accountDatabases *ad){
			FILE *fp;
			   int i;
			   char s[100];
			   char customFile[500];  
			   sprintf(customFile, "medium%i.dat", ad->count1);
			   fp = fopen(customFile,"r");
			   
			   if(fp != NULL){
			   		getDelimitedItem(s,'|',fp);
			        ad->count3[0] = atoi(s);       //reads the first text before |, then converts to int 
			      
				  for (i=0; i<ad->count3[0]; i++) {
				  	  getDelimitedItem(ad->accDatabase[ad->count1].task_name[1][i], '|',fp);	 //reads the whole text before | 
					  
					  getDelimitedItem(s, '|',fp);
					  ad->accDatabase[ad->count1].month[1][i] = atoi(s); //reads the whole text before |, then converts to int 
			          
			          getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].day[1][i] = atoi(s);  //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].year[1][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].hours[1][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].minutes[1][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].seconds[1][i] = atoi(s); //reads the whole text before |, then converts to int 
	      		}
	      		fclose(fp);
			   	
			   }
		}
		
		// FUNCTION NAME: sortTimeAndDateMedium
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: getDelimitedItem()
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. Using a nested for loop, arrange the time and date in ascending
		//	  order.
		//
		// 2. Display the tasks in sorted time and date.
		// This function reads the content of MEDIUM task_name file and displays 
		// the tasks in medium task_name according to time and date 
		
		void sortTimeAndDateMedium(accountDatabases *ad){
			int i,j,tempYear,tempMonth,tempDay,tempMinute,tempHour,tempSecond; //counter, temporary variables
			int progYear[ad->count3[0]],progMonth[ad->count3[0]],progHour[ad->count3[0]]; //array size is the number of medium task_name tasks
			int progDay[ad->count3[0]], progMinute[ad->count3[0]], progSecond[ad->count3[0]]; //array size is the number of medium task_name tasks		
			char progTask[ad->count3[0]][40],tempTask[40]; //array size is the number of medium task_name tasks and maximum string size is 40
				
				/*store the data in 1D array*/
				for(i=0;i<ad->count3[0];i++){
					strcpy(progTask[i],ad->accDatabase[ad->count1].task_name[1][i]);
					progMonth[i]=ad->accDatabase[ad->count1].month[1][i];
					progDay[i]=ad->accDatabase[ad->count1].day[1][i];
					progYear[i]=ad->accDatabase[ad->count1].year[1][i];
					progHour[i]=ad->accDatabase[ad->count1].hours[1][i];
					progMinute[i]=ad->accDatabase[ad->count1].minutes[1][i];
					progSecond[i]=ad->accDatabase[ad->count1].seconds[1][i];
					
				}
				
				for(i=0;i<ad->count3[0];i++){
					for(j=i+1;j<ad->count3[0];j++){
						/*compare which year comes first*/
						if(progYear[i]>progYear[j]){
							strcpy(tempTask,progTask[i]);
							strcpy(progTask[i],progTask[j]);
							strcpy(progTask[j],tempTask);
							
							tempYear = progYear[i];
							progYear[i]=progYear[j];
							progYear[j]=tempYear;
							
							
							tempMonth = progMonth[i];
							progMonth[i] = progMonth[j];
							progMonth[j]=tempMonth;
							
							tempDay = progDay[i];
							progDay[i] = progDay[j];
							progDay[j]=tempDay;
							
							tempHour = progHour[i];
							progHour[i] = progHour[j];
							progHour[j]=tempHour;
						
							tempMinute = progMinute[i];
							progMinute[i] = progMinute[j];
							progMinute[j]=tempMinute;
							
							tempSecond = progSecond[i];
							progSecond[i] = progSecond[j];
							progSecond[j]=tempSecond;	
						}
						/*if they have the same year*/
						else if(progYear[i]==progYear[j]){
							/*compare which month comes first*/
							if(progMonth[i]>progMonth[j]){
								strcpy(tempTask,progTask[i]);
								strcpy(progTask[i],progTask[j]);
								strcpy(progTask[j],tempTask);
								
								tempMonth = progMonth[i];
								progMonth[i] = progMonth[j];
								progMonth[j]=tempMonth;
								
								tempDay = progDay[i];
								progDay[i] = progDay[j];
								progDay[j]=tempDay;
								
								tempHour = progHour[i];
								progHour[i] = progHour[j];
								progHour[j]=tempHour;
								
								tempMinute = progMinute[i];
								progMinute[i] = progMinute[j];
								progMinute[j]=tempMinute;
								
								tempSecond = progSecond[i];
								progSecond[i] = progSecond[j];
								progSecond[j]=tempSecond;
								
							}
							/*if they have the same month*/
							else if(progMonth[i]==progMonth[j]){
								/*compare which day comes first*/
								if(progDay[i]>progDay[j]){
									strcpy(tempTask,progTask[i]);
									strcpy(progTask[i],progTask[j]);
									strcpy(progTask[j],tempTask);
									
									tempDay = progDay[i];
									progDay[i] = progDay[j];
									progDay[j]=tempDay;
									
									tempHour = progHour[i];
									progHour[i] = progHour[j];
									progHour[j]=tempHour;
									
									tempMinute = progMinute[i];
									progMinute[i] = progMinute[j];
									progMinute[j]=tempMinute;
									
									tempSecond = progSecond[i];
									progSecond[i] = progSecond[j];
									progSecond[j]=tempSecond;
								
								}
								/*if they have the same day*/
								else if(progDay[i]==progDay[j]){
									/*compare which hour comes first*/
									if(progHour[i]>progHour[j]){
										strcpy(tempTask,progTask[i]);
										strcpy(progTask[i],progTask[j]);
										strcpy(progTask[j],tempTask);
										
										tempHour = progHour[i];
										progHour[i] = progHour[j];
										progHour[j]=tempHour;
										
										tempMinute = progMinute[i];
										progMinute[i] = progMinute[j];
										progMinute[j]=tempMinute;
										
										tempSecond = progSecond[i];
										progSecond[i] = progSecond[j];
										progSecond[j]=tempSecond;
									}
									/*if they have the same hour*/
									else if(progHour[i]==progHour[j]){
										/*compare which minute comes first*/
										if(progMinute[i]>progMinute[j]){
											strcpy(tempTask,progTask[i]);
											strcpy(progTask[i],progTask[j]);
											strcpy(progTask[j],tempTask);
											
											tempMinute = progMinute[i];
											progMinute[i] = progMinute[j];
											progMinute[j]=tempMinute;
											
											tempSecond = progSecond[i];
											progSecond[i] = progSecond[j];
											progSecond[j]=tempSecond;
										}
										/*if they have the same minute*/
										else if(progMinute[i]==progMinute[j]){
											/*compare which second comes first*/
											if(progSecond[i]>progSecond[j]){
												strcpy(tempTask,progTask[i]);
												strcpy(progTask[i],progTask[j]);
												strcpy(progTask[j],tempTask);
												
												tempSecond = progSecond[i];
												progSecond[i] = progSecond[j];
												progSecond[j]=tempSecond;
											}
										}
									}
								}
							}
						}
					}
				}
				/*display the tasks in medium task_name sorted according to time and date*/
				
				if(ad->count3[0] != 0){
					printf("MEDIUM PRIORITY\n");
					for(i=0;i<ad->count3[0];i++){
						if(strlen(progTask[i]) != 0){
					    	printf("Name of task: %s\n",progTask[i]);
							printf("Deadline: %i/%i/%i %i:%i:%i\n\n",progMonth[i],progDay[i],progYear[i],progHour[i],progMinute[i],progSecond[i]);
						}
					}	
					
				}
				
			
		}
		
		// FUNCTION NAME: lowPrioritySort
		// CREDITS: Ivan Porcincula, Jack Catalan
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: getDelimitedItem()
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. Set custom file name according to the current user
		//	  
		// 2. Open the file and if the file is not null, read the file.
		//
		// This function reads the content of LOW task_name file
		void lowPrioritySort(accountDatabases *ad){
			FILE *fp;
			   int i;
			   char s[100];
			   char customFile[500];  
		   	   sprintf(customFile, "low%i.dat", ad->count1);
		       fp = fopen(customFile,"r");
		       
			   if(fp!= NULL){
		       	getDelimitedItem(s,'|',fp);
			      ad->count4[0] = atoi(s);       //reads the first text before |, then converts to int 
				  for (i=0; i<ad->count4[0]; i++) {
				  	  getDelimitedItem(ad->accDatabase[ad->count1].task_name[2][i], '|',fp);	
					  
					  getDelimitedItem(s, '|',fp);
					  ad->accDatabase[ad->count1].month[2][i] = atoi(s); //reads the whole text before | 
			          
			          getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].day[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].year[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].hours[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].minutes[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].seconds[2][i] = atoi(s); //reads the whole text before |, then converts to int 
	      		}
	      		fclose(fp);
		       	
			   }
			
		}
		
		// FUNCTION NAME: sortTimeAndDateLow
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: getDelimitedItem()
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. Using a nested for loop, arrange the time and date in ascending
		//	  order.
		//
		// 2. Display the tasks in sorted time and date.
		// This function reads the content of MEDIUM task_name file and displays 
		// the tasks in medium task_name according to time and date 
		void sortTimeAndDateLow(accountDatabases *ad){
			int i,j,tempYear,tempMonth,tempDay,tempMinute,tempHour,tempSecond; //counter variables and temporary variables
			int progYear[ad->count4[0]],progMonth[ad->count4[0]],progHour[ad->count4[0]]; //array size is number of low task_name tasks
			int progDay[ad->count4[0]], progMinute[ad->count4[0]], progSecond[ad->count4[0]]; //array size is number of low task_name tasks		
			char progTask[ad->count4[0]][40],tempTask[40]; //array size is number of low task_name tasks and maximum string size is 40
			
				for(i=0;i<ad->count4[0];i++){
					strcpy(progTask[i],ad->accDatabase[ad->count1].task_name[2][i]);
					progMonth[i]=ad->accDatabase[ad->count1].month[2][i];
					progDay[i]=ad->accDatabase[ad->count1].day[2][i];
					progYear[i]=ad->accDatabase[ad->count1].year[2][i];
					progHour[i]=ad->accDatabase[ad->count1].hours[2][i];
					progMinute[i]=ad->accDatabase[ad->count1].minutes[2][i];
					progSecond[i]=ad->accDatabase[ad->count1].seconds[2][i];
					
				}
				
				for(i=0;i<ad->count4[0];i++){
					for(j=i+1;j<ad->count4[0];j++){
						/*compare which year comes first*/
						if(progYear[i]>progYear[j]){
							strcpy(tempTask,progTask[i]);
							strcpy(progTask[i],progTask[j]);
							strcpy(progTask[j],tempTask);
							
							tempYear = progYear[i];
							progYear[i]=progYear[j];
							progYear[j]=tempYear;
							
							
							tempMonth = progMonth[i];
							progMonth[i] = progMonth[j];
							progMonth[j]=tempMonth;
							
							tempDay = progDay[i];
							progDay[i] = progDay[j];
							progDay[j]=tempDay;
							
							tempHour = progHour[i];
							progHour[i] = progHour[j];
							progHour[j]=tempHour;
						
							tempMinute = progMinute[i];
							progMinute[i] = progMinute[j];
							progMinute[j]=tempMinute;
							
							tempSecond = progSecond[i];
							progSecond[i] = progSecond[j];
							progSecond[j]=tempSecond;	
						}
						/*if they have the same year*/
						else if(progYear[i]==progYear[j]){
							/*compare which month comes first*/
							if(progMonth[i]>progMonth[j]){
								strcpy(tempTask,progTask[i]);
								strcpy(progTask[i],progTask[j]);
								strcpy(progTask[j],tempTask);
								
								tempMonth = progMonth[i];
								progMonth[i] = progMonth[j];
								progMonth[j]=tempMonth;
								
								tempDay = progDay[i];
								progDay[i] = progDay[j];
								progDay[j]=tempDay;
								
								tempHour = progHour[i];
								progHour[i] = progHour[j];
								progHour[j]=tempHour;
								
								tempMinute = progMinute[i];
								progMinute[i] = progMinute[j];
								progMinute[j]=tempMinute;
								
								tempSecond = progSecond[i];
								progSecond[i] = progSecond[j];
								progSecond[j]=tempSecond;
								
							}
							/*if they have the same month*/
							else if(progMonth[i]==progMonth[j]){
								/*compare which day comes first*/
								if(progDay[i]>progDay[j]){
									strcpy(tempTask,progTask[i]);
									strcpy(progTask[i],progTask[j]);
									strcpy(progTask[j],tempTask);
									
									tempDay = progDay[i];
									progDay[i] = progDay[j];
									progDay[j]=tempDay;
									
									tempHour = progHour[i];
									progHour[i] = progHour[j];
									progHour[j]=tempHour;
									
									tempMinute = progMinute[i];
									progMinute[i] = progMinute[j];
									progMinute[j]=tempMinute;
									
									tempSecond = progSecond[i];
									progSecond[i] = progSecond[j];
									progSecond[j]=tempSecond;
								
								}
								/*if they have the same day*/
								else if(progDay[i]==progDay[j]){
									/*compare which hour comes first*/
									if(progHour[i]>progHour[j]){
										strcpy(tempTask,progTask[i]);
										strcpy(progTask[i],progTask[j]);
										strcpy(progTask[j],tempTask);
										
										tempHour = progHour[i];
										progHour[i] = progHour[j];
										progHour[j]=tempHour;
										
										tempMinute = progMinute[i];
										progMinute[i] = progMinute[j];
										progMinute[j]=tempMinute;
										
										tempSecond = progSecond[i];
										progSecond[i] = progSecond[j];
										progSecond[j]=tempSecond;
									}
									/*if they have the same hour*/
									else if(progHour[i]==progHour[j]){
										/*compare which minute comes first*/
										if(progMinute[i]>progMinute[j]){
											strcpy(tempTask,progTask[i]);
											strcpy(progTask[i],progTask[j]);
											strcpy(progTask[j],tempTask);
											
											tempMinute = progMinute[i];
											progMinute[i] = progMinute[j];
											progMinute[j]=tempMinute;
											
											tempSecond = progSecond[i];
											progSecond[i] = progSecond[j];
											progSecond[j]=tempSecond;
										}
										/*if they have the same minute*/
										else if(progMinute[i]==progMinute[j]){
											/*compare which second comes first*/
											if(progSecond[i]>progSecond[j]){
												strcpy(tempTask,progTask[i]);
												strcpy(progTask[i],progTask[j]);
												strcpy(progTask[j],tempTask);
												
												tempSecond = progSecond[i];
												progSecond[i] = progSecond[j];
												progSecond[j]=tempSecond;
											}
										}
									}
								}
							}
						}
					}
				}
				
				/*display according to low task_name time & date order*/
				
				if(ad->count4[0]){
					printf("LOW PRIORITY\n");
					for(i=0;i<ad->count4[0];i++){
						
					if(strlen(progTask[i]) != 0){
					    	printf("Name of task: %s\n",progTask[i]);
							printf("Deadline: %i/%i/%i %i:%i:%i\n\n",progMonth[i],progDay[i],progYear[i],progHour[i],progMinute[i],progSecond[i]);
						}
					}	
					
				}
			
			
		}
		
		// FUNCTION NAME: displayTaskPriority
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. Using a for loop display task names according to HIGH, MEDIUM and LOW task_name.
		// This function displays the tasks and deadline according to task_name only.
		void displayTaskPriority(accountDatabases *ad){
			int i;
			
			
			if(ad->count2[0] != 0){
				printf("HIGH\n");
				for(i=0;i<ad->count2[0];i++){
					if(strlen(ad->accDatabase[ad->count1].task_name[0][i]) != 0){
						printf("Task name: %s",ad->accDatabase[ad->count1].task_name[0][i]);
						printf("\nDue on: %i/%i/%i %i:%i:%i\n\n",ad->accDatabase[ad->count1].month[0][i],
						ad->accDatabase[ad->count1].day[0][i],ad->accDatabase[ad->count1].year[0][i],
						ad->accDatabase[ad->count1].hours[0][i], ad->accDatabase[ad->count1].minutes[0][i],
						ad->accDatabase[ad->count1].seconds[0][i]);
					}	
				}
				
			}
			
			if(ad->count3[0]!=0){
				printf("MEDIUM\n");
				for(i=0;i<ad->count3[0];i++){
					if(strlen(ad->accDatabase[ad->count1].task_name[1][i]) != 0){
			    	printf("Task name: %s",ad->accDatabase[ad->count1].task_name[1][i]);
					printf("\nDue on: %i/%i/%i %i:%i:%i\n\n",ad->accDatabase[ad->count1].month[1][i],
					ad->accDatabase[ad->count1].day[1][i],ad->accDatabase[ad->count1].year[1][i],
					ad->accDatabase[ad->count1].hours[1][i], ad->accDatabase[ad->count1].minutes[1][i],
					ad->accDatabase[ad->count1].seconds[1][i]);
				}
				}
			}
			
			if(ad->count4[0]!=0){
				printf("LOW\n");
				for(i=0;i<ad->count4[0];i++){
					if(strlen(ad->accDatabase[ad->count1].task_name[2][i]) != 0){
						printf("Task name: %s",ad->accDatabase[ad->count1].task_name[2][i]);
						printf("\nDue on: %i/%i/%i %i:%i:%i\n\n",ad->accDatabase[ad->count1].month[2][i],
						ad->accDatabase[ad->count1].day[2][i],ad->accDatabase[ad->count1].year[2][i],
						ad->accDatabase[ad->count1].hours[2][i], ad->accDatabase[ad->count1].minutes[2][i],
						ad->accDatabase[ad->count1].seconds[2][i]);
					}
					
				}
			}
			
		}
		
		
		
		// FUNCTION NAME: displayTaskPriority
		// CREDITS: Pankaj Prakash, Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: removeAll()
		//
		// CALLED FROM: Menu_2()
		//
		// METHOD:
		// 1. Open all database related file for tasks to check if the word exists in that task_name
		// 	  or category.
		//
		// 2. Search for the word and remove it. 
		//
		// 3. Append to the database the task accomplished and its the current time and date it got removed and accomplished
		//	  from the database.
		//This function removes the task from the database of the user.
		
		
		void taskRemoval(accountDatabases *ad){
			
			
				FILE * fPtr,*fp1,*fp2,*fp3,*fp4,*fp5,*fp6, *fp7, *fp8;
			    FILE * fTemp, *fTemp1, *fTemp2, *fTemp3, *fTemp4, *fTemp5, *fTemp6, *fTemp7;

				/*string variales*/
			    char toRemove[100];
			    char buffer[1000];
			    char buff[BUFFER_SIZE] = {0};
			    
			    /*files with custom file name*/
			    char customFile1[100];  
			    char customFile2[100];  
			    char customFile3[100];  
			    char customFile4[100];  
			    char customFile5[100];  
			    char customFile6[100];  
			    char customFile7[100];  
			    char customFile8[100];
			    
			    /*get current time as when the user accomplished a specific task*/
			    time_t currentTime;
   				currentTime = time(NULL);
   				tm *ptm = localtime(&currentTime);
   				strftime(buff, BUFFER_SIZE, "%A %B %d, %Y %I:%M:%S %p", ptm);
	 	   		
	 	   		/*this sets the custom filename to for the customFile variables*/
				sprintf(customFile1, "high%i.dat", ad->count1);
				sprintf(customFile2, "medium%i.dat", ad->count1);
				sprintf(customFile3, "low%i.dat", ad->count1);
				sprintf(customFile4, "home%i.dat", ad->count1);
				sprintf(customFile5, "education%i.dat", ad->count1);
				sprintf(customFile6, "games%i.dat", ad->count1);
				sprintf(customFile7, "meeting%i.dat", ad->count1);
				sprintf(customFile8, "accomplished%i.dat", ad->count1);
				
				/*buffer the memory to prevent problems*/
				fflush(stdin);
			    printf("Enter name of finished task: ");
			    gets(toRemove);
			    
		
			    /*open files 1 to 7 in read mode and file 8 to append mode*/
			    /*file 8 will be used for storing the accomplished tasks*/
			    fp1 = fopen(customFile1,"r");
			    fp2 = fopen(customFile2,"r");
			    fp3 = fopen(customFile3,"r");
			    fp4 = fopen(customFile4,"r");
			    fp5 = fopen(customFile5,"r");
			    fp6 = fopen(customFile6,"r");
			    fp7 = fopen(customFile7,"r");
			    fp8 = fopen(customFile8,"a");
			    
			    
			    /*open the temporary file variable with specific filenames in write-mode*/
			    fTemp1 = fopen("delete1.tmp", "w"); 
			    fTemp2 = fopen("delete2.tmp", "w"); 
			    fTemp3 = fopen("delete3.tmp", "w"); 
			    fTemp4 = fopen("delete4.tmp", "w"); 
			    fTemp5 = fopen("delete5.tmp", "w"); 
			    fTemp6 = fopen("delete6.tmp", "w"); 
			    fTemp7 = fopen("delete7.tmp", "w"); 
			    
			    
			
			    
			    if(fp1 != NULL){
				      /*
				     * Read line from source file and write to destination 
				     * file after removing given word.
				     */
				    while ((fgets(buffer, BUFFER_SIZE, fp1)) != NULL)
				    {
				        // Remove all occurrence of word from current line
				        removeAll(buffer, toRemove);
				
				        // Write to temp file
				        fputs(buffer, fTemp1);
				    }
				
				
				    /* Close all files to release resource */
				    fclose(fp1);
				    fclose(fTemp1);
				
				
				    /* Delete original source file */
				    remove(customFile1);
				
				    /* Rename temp file as original file */
				    rename("delete1.tmp", customFile1);
				
				
				   
			    	
				}
				
				if(fp2 != NULL){
				      /*
				     * Read line from source file and write to destination 
				     * file after removing given word.
				     */
				    while ((fgets(buffer, BUFFER_SIZE, fp2)) != NULL)
				    {
				        // Remove all occurrence of word from current line
				        removeAll(buffer, toRemove);
				
				        // Write to temp file
				        fputs(buffer, fTemp2);
				    }
				
				
				    /* Close all files to release resource */
				    fclose(fp2);
				    fclose(fTemp2);
				
				
				    /* Delete original source file */
				    remove(customFile2);
				
				    /* Rename temp file as original file */
				    rename("delete2.tmp", customFile2);
				
				
				    
			    	
				}
				
				if(fp3 != NULL){
				      /*
				     * Read line from source file and write to destination 
				     * file after removing given word.
				     */
				    while ((fgets(buffer, BUFFER_SIZE, fp3)) != NULL)
				    {
				        // Remove all occurrence of word from current line
				        removeAll(buffer, toRemove);
				
				        // Write to temp file
				        fputs(buffer, fTemp3);
				    }
				
				
				    /* Close all files to release resource */
				    fclose(fp3);
				    fclose(fTemp3);
				
				
				    /* Delete original source file */
				    remove(customFile3);
				
				    /* Rename temp file as original file */
				    rename("delete3.tmp", customFile3);
				
			    	
				}
				
				if(fp4 != NULL || fTemp4 != NULL){
				      /*
				     * Read line from source file and write to destination 
				     * file after removing given word.
				     */
				    while ((fgets(buffer, BUFFER_SIZE, fp4)) != NULL)
				    {
				        // Remove all occurrence of word from current line
				        removeAll(buffer, toRemove);
				
				        // Write to temp file
				        fputs(buffer, fTemp4);
				    }
				
				
				    /* Close all files to release resource */
				    fclose(fp4);
				    fclose(fTemp4);
				
				
				    /* Delete original source file */
				    remove(customFile4);
				
				    /* Rename temp file as original file */
				    rename("delete4.tmp", customFile4);
			    	
				}
				
				if(fp5 != NULL){
				      /*
				     * Read line from source file and write to destination 
				     * file after removing given word.
				     */
				    while ((fgets(buffer, BUFFER_SIZE, fp5)) != NULL)
				    {
				        // Remove all occurrence of word from current line
				        removeAll(buffer, toRemove);
				
				        // Write to temp file
				        fputs(buffer, fTemp5);
				    }
				
				
				    /* Close all files to release resource */
				    fclose(fp5);
				    fclose(fTemp5);
				
				
				    /* Delete original source file */
				    remove(customFile5);
				
				    /* Rename temp file as original file */
				    rename("delete5.tmp", customFile5);

			    	
				}
				
				if(fp6 != NULL){
				      /*
				     * Read line from source file and write to destination 
				     * file after removing given word.
				     */
				    while ((fgets(buffer, BUFFER_SIZE, fp6)) != NULL)
				    {
				        // Remove all occurrence of word from current line
				        removeAll(buffer, toRemove);
				
				        // Write to temp file
				        fputs(buffer, fTemp6);
				    }
				
				
				    /* Close all files to release resource */
				    fclose(fp6);
				    fclose(fTemp6);
				
				
				    /* Delete original source file */
				    remove(customFile6);
				
				    /* Rename temp file as original file */
				    rename("delete6.tmp", customFile6);
				
			    	
				}
				if(fp7 != NULL){
				      /*
				     * Read line from source file and write to destination 
				     * file after removing given word.
				     */
				    while ((fgets(buffer, BUFFER_SIZE, fp7)) != NULL)
				    {
				        // Remove all occurrence of word from current line
				        removeAll(buffer, toRemove);
				
				        // Write to temp file
				        fputs(buffer, fTemp7);
				    }
				
				
				    /* Close all files to release resource */
				    fclose(fp7);
				    fclose(fTemp7);
				
				
				    /* Delete original source file */
				    remove(customFile7);
				
				    /* Rename temp file as original file */
				    rename("delete7.tmp", customFile7);
				
				
				    
			    	
				}
				
				printf("\nThe task '%s' has been finished!\n\n", toRemove);
				
				fflush(stdin);
				
				/*stores the task name and the date it is accomplished into file 8*/
				fprintf(fp8,"Name of task: %s\n",toRemove);
   				fprintf(fp8,"Date finished: %s\n",buff);
			
			   	fclose(fp8);
			}
		

		// FUNCTION NAME: displayAccomplished()
		// CREDITS: Alok Singhal
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_2()
		//
		// METHOD:
		// 1. This function removes the task from the database of the user.
		//
		
		void displayAccomplished(accountDatabases *ad){
				int c;
   				FILE *fpRead; //file reading variable
   				
   				char customFile8[100]; //custom file 8
   				sprintf(customFile8, "accomplished%i.dat", ad->count1); //custom file name
				fpRead = fopen(customFile8, "r"); //open in read mode
				
				/*this is to read the contents of the file and display it into the program*/
				if (fpRead) {
				    while ((c = getc(fpRead)) != EOF)
				        putchar(c);
				    fclose(fpRead);
				}
			}
			
	
};

class Home : public Tasks{
	
	public:
		
		// FUNCTION NAME: addHigh
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none        
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_4()
		//
		// METHOD:
		// 1. Get input from user: the name of the task
		// 2. Get input from user: date and time
		// 3. Store the data.
		// This function gets the input from user.
		
	

		/*high task_name*/
		void addHigh(accountDatabases *ad){
			char customFile[100], csFile[100],s[100],s1[100], name[50];
			
			FILE *fp, *fPtr, *fT, *fp1, *fPtr1, *fT1;
	 		sprintf(customFile, "high%i.dat", ad->count1); //HIGH PRIORITY DATABASE
	 		int month,day,year,minutes,hours,seconds,count;  
	 			printf("Name of the task: ");
				gets(name);
				fflush(stdin);
				printf("Deadline of the task\n");
				printf("Date in format (MM/DD/YYYY): ");
				scanf("%i/%i/%i",&month,&day,&year);
				fflush(stdin); 
				printf("The time format uses a 24-hour format clock.\n");
				printf("Please enter the time in format (HH:MM:SS): ");
				scanf("%i:%i:%i",&hours,&minutes,&seconds);
				fflush(stdin);
				
			fp = fopen(customFile,"r");
			
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp != NULL){
				getDelimitedItem(s,'|',fp);
				ad->count2[0] = atoi(s);
				for(int i = 0 ; i<ad->count2[0];i++){
						
				  getDelimitedItem(ad->accDatabase[ad->count1].task_name[0][i], '|',fp); //reads the whole text before |t	
				  
				  getDelimitedItem(s, '|',fp);
				  ad->accDatabase[ad->count1].month[0][i] = atoi(s); //reads the whole text before |, then converts to int 
		          
		          getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].day[0][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].year[0][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].hours[0][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].minutes[0][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].seconds[0][i] = atoi(s); //reads the whole text before |, then converts to int 
						
				}
				ad->count2[0]++;
					
					
				fPtr = fopen("temphigh.tmp","w");
					
					
				fprintf(fPtr,"%i\n",ad->count2[0]);
				for(int i = 0 ; i<ad->count2[0]-1; i++){
					fprintf(fPtr,"%s|%i/%i/%i|%i:%i:%i\n",ad->accDatabase[ad->count1].task_name[0][i],
				 	ad->accDatabase[ad->count1].month[0][i],ad->accDatabase[ad->count1].day[0][i],ad->accDatabase[ad->count1].year[0][i],
					ad->accDatabase[ad->count1].hours[0][i],ad->accDatabase[ad->count1].minutes[0][i],
				 	ad->accDatabase[ad->count1].seconds[0][i]);
				}
				fprintf(fPtr,"%s|%i/%i/%i|%i:%i:%i\n",name,month,day,year,hours,minutes,seconds);
					
				fclose(fp);
				fclose(fPtr);
				
				remove(customFile);
				rename("temphigh.tmp",customFile);
				
				
			}
			else{
				
				fflush(stdin);
				ad->count2[0]++;
				fT = fopen(customFile,"w");
				fprintf(fT,"%i\n",ad->count2[0]);
				fprintf(fT,"%s|%i/%i/%i|%i:%i:%i\n",name,month,day,year,hours,minutes,seconds);
				fclose(fT);
				
					
				}
			sprintf(csFile, "home%i.dat", ad->count1);
			fp1=fopen(csFile, "r");
			
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data.*/
			if(fp1 != NULL){
					
				getDelimitedItem(s1,'|',fp1);
				ad->count2[0] = atoi(s1);
			
					
				for(int i = 0 ;i<ad->count2[0];i++){
						
				  getDelimitedItem(ad->accDatabase[ad->count1].task_name[0][i], '|',fp1); //reads the whole text before |t	
				  
				  getDelimitedItem(s1, '|',fp1);
				  ad->accDatabase[ad->count1].month[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
		          
		          getDelimitedItem(s1, '|',fp1);	
				  ad->accDatabase[ad->count1].day[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s1, '|',fp1);	
				  ad->accDatabase[ad->count1].year[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s1, '|',fp1);	
				  ad->accDatabase[ad->count1].hours[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s1, '|',fp1);	
				  ad->accDatabase[ad->count1].minutes[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s1, '|',fp1);	
				  ad->accDatabase[ad->count1].seconds[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
						
				}
				ad->count2[0]++;
				fPtr1 = fopen("hometemp.tmp","w");
				
				fprintf(fPtr1,"%i\n",ad->count2[0]);
				for(int i = 0 ; i<ad->count2[0]-1; i++){
					fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[0][i],
				 	ad->accDatabase[ad->count1].month[0][i],
					 ad->accDatabase[ad->count1].day[0][i],ad->accDatabase[ad->count1].year[0][i],
					ad->accDatabase[ad->count1].hours[0][i],ad->accDatabase[ad->count1].minutes[0][i],
				 	ad->accDatabase[ad->count1].seconds[0][i]);
				}
				fprintf(fPtr1,"%s|%i/%i/%i|%i:%i:%i\n",name,month,day,year,hours,minutes,seconds);
				
				fclose(fp1);
				fclose(fPtr1);
					
				remove(csFile);
				rename("hometemp.tmp",csFile);
						
				}
				else{
					int count=0;
					count++;
					fT1 = fopen(csFile,"w");
					fprintf(fT1,"%i\n",count);
					fprintf(fT1,"%s|%i/%i/%i|%i:%i:%i\n",name,month,day,year,hours,minutes,seconds);
					fclose(fT1);
			}
			 	fflush(stdin);
		}	
		
		// FUNCTION NAME: addMed
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none        
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_4()
		//
		// METHOD:
		// 1. Get input from user: the name of the task
		// 2. Get input from user: date and time
		// 3. Store the data.
		// This function gets the input from user.
		
		/*medium task_name*/
		void addMed(accountDatabases *ad){
			char customFile[500], csFile[500],s[100],s1[100];  
			FILE *fp, *fPtr, *fT, *fp1, *fPtr1, *fT1;
	 		sprintf(customFile, "medium%i.dat", ad->count1); //MEDIUM PRIORITY DATABASE
	 		
	 		int month,day,year,minutes,hours,seconds,count;  
	 		char name[50];
	 		
	 		printf("Name of the task: ");
			gets(name);
			fflush(stdin);
			printf("Deadline of the task\n");
			printf("Date in format (MM/DD/YYYY): ");
			scanf("%i/%i/%i",&month,&day,&year);
			fflush(stdin); 
				
			printf("The time format uses a 24-hour format clock.\n");
			printf("Please enter the time in format (HH:MM:SS): ");
			scanf("%i:%i:%i",&hours,&minutes,&seconds);
				
			fp = fopen(customFile,"r");
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp != NULL){
				getDelimitedItem(s,'|',fp);
				ad->count3[0] = atoi(s);
				for(int i = 0; i<ad->count3[0];i++){
						
				getDelimitedItem(ad->accDatabase[ad->count1].task_name[1][i], '|',fp); //reads the whole text before |t	
				  
				  getDelimitedItem(s, '|',fp);
				  ad->accDatabase[ad->count1].month[1][i] = atoi(s); //reads the whole text before |, then converts to int 
		          
		          getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].day[1][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].year[1][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].hours[1][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].minutes[1][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].seconds[1][i] = atoi(s); //reads the whole text before |, then converts to int 
						
				}
				ad->count3[0]++;
					
			
				fPtr = fopen("tempmed.tmp","w");
					
					
				fprintf(fPtr,"%i\n",ad->count3[0]);
				for(int i = 0 ; i<ad->count3[0]-1; i++){
					fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[1][i],
				 	ad->accDatabase[ad->count1].month[1][i],ad->accDatabase[ad->count1].day[1][i],ad->accDatabase[ad->count1].year[1][i],
					ad->accDatabase[ad->count1].hours[1][i],ad->accDatabase[ad->count1].minutes[1][i],
				 	ad->accDatabase[ad->count1].seconds[1][i]);
				}
				fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
				fclose(fp);
				fclose(fPtr);
				remove(customFile);
				rename("tempmed.tmp",customFile);
				
			}
			else{
				ad->count3[0]++;
				fT = fopen(customFile,"w");
				fprintf(fT,"%i\n",ad->count3[0]);
				fprintf(fT,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
				fclose(fT);
				}
			sprintf(csFile, "home%i.dat", ad->count1);
			fp1=fopen(csFile, "r");
			
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp1 != NULL){
					
				getDelimitedItem(s1,'|',fp1);
				ad->count3[0] = atoi(s1);
	
					
				for(int i = 0 ;i<ad->count3[0];i++){
						
				  getDelimitedItem(ad->accDatabase[ad->count1].task_name[1][i], '|',fp1); //reads the whole text before |t	
				  
				  getDelimitedItem(s1, '|',fp1);
				  ad->accDatabase[ad->count1].month[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
		          
		          getDelimitedItem(s1, '|',fp1);	
				  ad->accDatabase[ad->count1].day[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s1, '|',fp1);	
				  ad->accDatabase[ad->count1].year[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s1, '|',fp1);	
				  ad->accDatabase[ad->count1].hours[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s1, '|',fp1);	
				  ad->accDatabase[ad->count1].minutes[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s1, '|',fp1);	
				  ad->accDatabase[ad->count1].seconds[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
						
				}
				ad->count3[0]++;
				fPtr1 = fopen("hometemp.tmp","w");
				fprintf(fPtr1,"%i\n",ad->count3[0]);
				for(int i = 0 ; i<ad->count3[0]-1; i++){
					fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[1][i],
				 	ad->accDatabase[ad->count1].month[1][i],
					 ad->accDatabase[ad->count1].day[1][i],ad->accDatabase[ad->count1].year[1][i],
					ad->accDatabase[ad->count1].hours[1][i],ad->accDatabase[ad->count1].minutes[1][i],
				 	ad->accDatabase[ad->count1].seconds[1][i]);
				}
				fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
				fclose(fp1);
				fclose(fPtr1);
					
				remove(csFile);
				rename("hometemp.tmp",csFile);
						
				}
				else{
					count=0;
					fT1 = fopen(csFile,"w");
					count++;
					fprintf(fT1,"%i\n",count);
					fprintf(fT1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					fclose(fT1);	
				
			}
			fflush(stdin);
			
	}
		
		// FUNCTION NAME: addLow
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none        
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_4()
		//
		// 1. Get input from user: the name of the task
		// 2. Get input from user: date and time
		// 3. Store the data.
		// This function gets the input from user.
		/*low task_name*/
		void addLow(accountDatabases *ad){
			
			
				char customFile[100], csFile[100],s[100],s1[100];  
				FILE *fp, *fPtr, *fT, *fp1, *fPtr1, *fT1;
	 			sprintf(customFile, "low%i.dat", ad->count1); //LOW PRIORITY DATABASE
	 			
	 			int month,day,year,minutes,hours,seconds,count;  
		 		char name[50];
		 		
		 		printf("Name of the task: ");
				gets(name);
				fflush(stdin);
				printf("Deadline of the task\n");
				printf("Date in format (MM/DD/YYYY): ");
				scanf("%i/%i/%i",&month,&day,&year);
				fflush(stdin); 
					
				printf("The time format uses a 24-hour format clock.\n");
				printf("Please enter the time in format (HH:MM:SS): ");
				scanf("%i:%i:%i",&hours,&minutes,&seconds);
				
				fp = fopen(customFile,"r");
				/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
				if(fp != NULL){
					getDelimitedItem(s,'|',fp);
					ad->count4[0] = atoi(s);
					for(int i = 0; i<ad->count4[0];i++){
						
					  getDelimitedItem(ad->accDatabase[ad->count1].task_name[2][i], '|',fp); //reads the whole text before |t	
					  
					  getDelimitedItem(s, '|',fp);
					  ad->accDatabase[ad->count1].month[2][i] = atoi(s); //reads the whole text before |, then converts to int 
			          
			          getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].day[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].year[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].hours[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].minutes[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].seconds[2][i] = atoi(s); //reads the whole text before |, then converts to int 
						
					}
					ad->count4[0]++;
					
					fPtr = fopen("templow.tmp","w");
					
					fprintf(fPtr,"%i\n",ad->count4[0]);
					for(int i = 0 ; i<ad->count4[0]-1; i++){
						fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[2][i],
					 	ad->accDatabase[ad->count1].month[2][i],ad->accDatabase[ad->count1].day[2][i],ad->accDatabase[ad->count1].year[2][i],
						ad->accDatabase[ad->count1].hours[2][i],ad->accDatabase[ad->count1].minutes[2][i],
					 	ad->accDatabase[ad->count1].seconds[2][i]);
					}
					fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					
					fclose(fp);
					fclose(fPtr);
					
					remove(customFile);
					rename("templow.tmp",customFile);
				
					
				}
				else{	
					fT = fopen(customFile,"w");
					ad->count4[0]++;
					fprintf(fT,"%i\n",ad->count4[0]);
					fprintf(fT,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					fclose(fT);
				}
				sprintf(csFile, "home%i.dat", ad->count1);
				fp1=fopen(csFile, "r");
				/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
				if(fp1 != NULL){
					
					getDelimitedItem(s1,'|',fp1);
					ad->count4[0] = atoi(s1);
					
					for(int i = 0 ;i<ad->count4[0];i++){
						
						getDelimitedItem(ad->accDatabase[ad->count1].task_name[2][i], '|',fp1); //reads the whole text before |t	
					  
					  getDelimitedItem(s1, '|',fp1);
					  ad->accDatabase[ad->count1].month[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
			          
			          getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].day[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].year[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].hours[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].minutes[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].seconds[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
						
					}
					ad->count4[0]++;
					fPtr1 = fopen("hometemp.tmp","w");
					fprintf(fPtr1,"%i\n",ad->count4[0]);
					for(int i = 0 ; i<ad->count4[0]-1; i++){
						fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[2][i],
					 	ad->accDatabase[ad->count1].month[2][i],ad->accDatabase[ad->count1].day[2][i],ad->accDatabase[ad->count1].year[2][i],
						ad->accDatabase[ad->count1].hours[2][i],ad->accDatabase[ad->count1].minutes[2][i],
					 	ad->accDatabase[ad->count1].seconds[2][i]);
					}
					fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					fclose(fp1);
					fclose(fPtr1);
					
					remove(csFile);
					rename("hometemp.tmp",csFile);
						
					}
					else{
						count=0;
						fT1 = fopen(csFile,"w");
						count++;
						fprintf(fT1,"%i\n",count);
						fprintf(fT1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
						fclose(fT1);	
						
					}
				fflush(stdin);
	
			
			
		}
		// FUNCTION NAME: categorySorted
		// CREDITS: Ivan Porcincula, Jack Catalan
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: getDelimitedItem()
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. Set custom file name according to the current user
		//	  
		// 2. Open the file and if the file is not null, read the file.
		//
		// This function reads the content of HOME category file
		void categorySorted(accountDatabases *ad){
		   FILE *fp;
		   int i;
		   char s[100];
		   char customFile[500];  
	 	   
			sprintf(customFile, "home%i.dat", ad->count1);
		   fp = fopen(customFile,"r");
		   
		   if (fp!=NULL) {
		       getDelimitedItem(s,'|',fp);
		      ad->count2[0] = atoi(s);       //reads the first text before |, then converts to int 
		      
			  for (i=0; i<ad->count2[0]; i++) {
			  	  getDelimitedItem(ad->accDatabase[ad->count1].task_name[0][i], '|',fp); //reads the whole text before |t	
				  
				  getDelimitedItem(s, '|',fp);
				  ad->accDatabase[ad->count1].month[0][i] = atoi(s); //reads the whole text before |, then converts to int 
		          
		          getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].day[0][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].year[0][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].hours[0][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].minutes[0][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].seconds[0][i] = atoi(s); //reads the whole text before |, then converts to int 
      		}
      		fclose(fp);
		}
		     
	}
		// FUNCTION NAME: displayCategory
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. Using a for loop, display all the tasks under HOME category.
		//
		// This function displays all the tasks under HOME category
	
	    void displayCategory(accountDatabases *ad){
		int i;
		printf("HOME\n");
		for(i=0;i<ad->count2[0];i++){
			if(strlen(ad->accDatabase[ad->count1].task_name[0][i]) != 0){
				printf("Task name: %s",ad->accDatabase[ad->count1].task_name[0][i]);
				printf("\nDue on: %i/%i/%i %i:%i:%i\n\n",ad->accDatabase[ad->count1].month[0][i],
				ad->accDatabase[ad->count1].day[0][i],ad->accDatabase[ad->count1].year[0][i],
				ad->accDatabase[ad->count1].hours[0][i], ad->accDatabase[ad->count1].minutes[0][i],
				ad->accDatabase[ad->count1].seconds[0][i]);
			}
			
		}
	}
	
	
	
};

class Education:public Tasks{
	
	public:
		
		
		// FUNCTION NAME: addHigh
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none        
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_4()
		//
		// 1. Get input from user: the name of the task
		// 2. Get input from user: date and time
		// 3. Store the data.
		// This function gets the input from user and saves to database.
		
		void addHigh(accountDatabases *ad){
			char customFile[100], csFile[100],s[100],s1[100];  
			FILE *fp, *fPtr, *fT, *fp1, *fPtr1, *fT1;
	 		sprintf(customFile, "high%i.dat", ad->count1); //HIGH PRIORITY DATABASE
			int month,day,year,minutes,hours,seconds,count;  
	 		char name[50];
	 		
	 		printf("Name of the task: ");
			gets(name);
			fflush(stdin);
			printf("Deadline of the task\n");
			printf("Date in format (MM/DD/YYYY): ");
			scanf("%i/%i/%i",&month,&day,&year);
			fflush(stdin); 
				
			printf("The time format uses a 24-hour format clock.\n");
			printf("Please enter the time in format (HH:MM:SS): ");
			scanf("%i:%i:%i",&hours,&minutes,&seconds);
				
			fp = fopen(customFile,"r");
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp != NULL){
				getDelimitedItem(s,'|',fp);
				ad->count2[1] = atoi(s);
				for(int i = 0; i<ad->count2[1];i++){
						
				  getDelimitedItem(ad->accDatabase[ad->count1].task_name[0][i], '|',fp); //reads the whole text before | 
				  
				  getDelimitedItem(s, '|',fp);
				  ad->accDatabase[ad->count1].month[0][i] = atoi(s); //reads the whole text before |, then converts to int 
		          
		          getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].day[0][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].year[0][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	 
				  ad->accDatabase[ad->count1].hours[0][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].minutes[0][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].seconds[0][i] = atoi(s); //reads the whole text before |, then converts to int 
						
				}
				ad->count2[1]++;
					
				fPtr = fopen("temphigh.tmp","w");
					
				
				fprintf(fPtr,"%i\n",ad->count2[1]);
				for(int i = 0 ; i<ad->count2[1]-1; i++){
					fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[0][i],
				 	ad->accDatabase[ad->count1].month[0][i],ad->accDatabase[ad->count1].day[0][i]
					 ,ad->accDatabase[ad->count1].year[0][i],
					ad->accDatabase[ad->count1].hours[0][i],ad->accDatabase[ad->count1].minutes[0][i],
				 	ad->accDatabase[ad->count1].seconds[0][i]);
				}
				fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					
				fclose(fp);
				fclose(fPtr);
				
				remove(customFile);
				rename("temphigh.tmp",customFile);
				
				
			}
			else{
				ad->count2[1]++;
				fT = fopen(customFile,"w");
				fprintf(fT,"%i\n",ad->count2[1]);
				fprintf(fT,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
				fclose(fT);
				
				}
				
			sprintf(csFile, "education%i.dat", ad->count1);
			fp1=fopen(csFile, "r");
			
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp1 != NULL){
				getDelimitedItem(s1,'|',fp1);
				ad->count2[1] = atoi(s1);

					
				for(int i = 0; i<ad->count2[1];i++){
						
				getDelimitedItem(ad->accDatabase[ad->count1].task_name[0][i], '|',fp1); //reads the whole text before | 
				  
				  getDelimitedItem(s1, '|',fp1);
				  ad->accDatabase[ad->count1].month[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
		          
		          getDelimitedItem(s1, '|',fp1);	
				  ad->accDatabase[ad->count1].day[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s1, '|',fp1);	
				  ad->accDatabase[ad->count1].year[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s1, '|',fp1);	 
				  ad->accDatabase[ad->count1].hours[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s1, '|',fp1);	
				  ad->accDatabase[ad->count1].minutes[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s1, '|',fp1);	
				  ad->accDatabase[ad->count1].seconds[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
						
				}
				ad->count2[1]++;
				fPtr1 = fopen("educationtemp.tmp","w");
				fprintf(fPtr1,"%i\n",ad->count2[1]);
				for(int i = 0 ; i<ad->count2[1]-1; i++){
					fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[0][i],
				 	ad->accDatabase[ad->count1].month[0][i],
					 ad->accDatabase[ad->count1].day[0][i],ad->accDatabase[ad->count1].year[0][i],
					ad->accDatabase[ad->count1].hours[0][i],ad->accDatabase[ad->count1].minutes[0][i],
				 	ad->accDatabase[ad->count1].seconds[0][i]);
				}
				fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					
				fclose(fp1);
				fclose(fPtr1);
					
				remove(csFile);
				rename("educationtemp.tmp",csFile);
						
				}
				
				else{
					count=0;
					fT1 = fopen(csFile,"w");
					count++;
					
					fprintf(fT1,"%i\n",count);
					fprintf(fT1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					fclose(fT1);	
					
			}
			fflush(stdin);
			 
		}
		// FUNCTION NAME: addMed
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none        
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_4()
		//
		// 1. Get input from user: the name of the task
		// 2. Get input from user: date and time
		// 3. Store the data.
		// This function gets the input from user and saves to database.
		
		void addMed(accountDatabases *ad){
			
			char customFile[500], csFile[500],s[100],s1[100];  
			FILE *fp, *fPtr, *fT, *fp1, *fPtr1, *fT1;
	 		sprintf(customFile, "medium%i.dat", ad->count1); //MEDIUM PRIORITY DATABASE
			
			int month,day,year,minutes,hours,seconds,count;  
	 		char name[50];
	 		
	 		printf("Name of the task: ");
			gets(name);
			fflush(stdin);
			printf("Deadline of the task\n");
			printf("Date in format (MM/DD/YYYY): ");
			scanf("%i/%i/%i",&month,&day,&year);
			fflush(stdin); 
				
			printf("The time format uses a 24-hour format clock.\n");
			printf("Please enter the time in format (HH:MM:SS): ");
			scanf("%i:%i:%i",&hours,&minutes,&seconds);
			
			fp = fopen(customFile,"r");
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp != NULL){
				getDelimitedItem(s,'|',fp);
				ad->count3[1] = atoi(s);
				for(int i = 0; i<ad->count3[1];i++){
						
				  getDelimitedItem(ad->accDatabase[ad->count1].task_name[1][i], '|',fp); //reads the whole text before | 
				  	
				  getDelimitedItem(s, '|',fp);
				  ad->accDatabase[ad->count1].month[1][i] = atoi(s); //reads the whole text before |, then converts to int 
		          
		          getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].day[1][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].year[1][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	 
				  ad->accDatabase[ad->count1].hours[1][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].minutes[1][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].seconds[1][i] = atoi(s); //reads the whole text before |, then converts to int 
						
				}
				ad->count3[1]++;
				
				fPtr = fopen("tempmed.tmp","w");
					
				fprintf(fPtr,"%i\n",ad->count3[1]);
				for(int i = 0 ; i<ad->count3[1]-1; i++){
					fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[1][i],
				 	ad->accDatabase[ad->count1].month[1][i],ad->accDatabase[ad->count1].day[1][i],ad->accDatabase[ad->count1].year[1][i],
					ad->accDatabase[ad->count1].hours[1][i],ad->accDatabase[ad->count1].minutes[1][i],
				 	ad->accDatabase[ad->count1].seconds[1][i]);
				}
				fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					
				fclose(fp);
				fclose(fPtr);
				
				remove(customFile);
				rename("tempmed.tmp",customFile);
				
			}
			else{
				ad->count3[1]++;
				fT = fopen(customFile,"w");
				fprintf(fT,"%i\n",ad->count3[1]);
				fprintf(fT,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
				fclose(fT);
				}
			
			sprintf(csFile, "education%i.dat", ad->count1);
			fp1=fopen(csFile, "r");
			if(fp1 != NULL){
					
				getDelimitedItem(s1,'|',fp1);
				
				ad->count3[1] = atoi(s1);
						
				for(int i = 0; i<ad->count3[1];i++){
							
				      getDelimitedItem(ad->accDatabase[ad->count1].task_name[1][i], '|',fp1); //reads the whole text before | 
					  
					  getDelimitedItem(s1, '|',fp1);
					  ad->accDatabase[ad->count1].month[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
			          
			          getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].day[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].year[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	 
					  ad->accDatabase[ad->count1].hours[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].minutes[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].seconds[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
							
				}
				ad->count3[1]++;
				fPtr1 = fopen("educationtemp.tmp","w");
				fprintf(fPtr1,"%i\n",ad->count3[1]);
					for(int i = 0 ; i<ad->count3[1]-1 ; i++){
						fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[1][i],
					 	ad->accDatabase[ad->count1].month[1][i],
						 ad->accDatabase[ad->count1].day[1][i],ad->accDatabase[ad->count1].year[1][i],
						ad->accDatabase[ad->count1].hours[1][i],ad->accDatabase[ad->count1].minutes[1][i],
					 	ad->accDatabase[ad->count1].seconds[1][i]);
					}
					fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
						
					fclose(fp1);
					fclose(fPtr1);
					remove(csFile);
					rename("educationtemp.tmp",csFile);
						
				}
				else{
					count=0;
					count++;
					fT1 = fopen(csFile,"w");
					fprintf(fT1,"%i\n",count);
					fprintf(fT1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					fclose(fT1);	
					
			}
				fflush(stdin);
		}
		
		// FUNCTION NAME: addLow
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none        
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_4()
		//
		// 1. Get input from user: the name of the task
		// 2. Get input from user: date and time
		// 3. Store the data.
		// This function gets the input from user and saves to database.
		void addLow(accountDatabases *ad){

			char customFile[500], csFile[500],s[100],s1[100];  
			FILE *fp, *fPtr, *fT, *fp1, *fPtr1, *fT1;
	 		sprintf(customFile, "low%i.dat", ad->count1); //LOW PRIORITY DATABASE
			int month,day,year,hours,minutes,seconds,count;  
	 		char name[50];
	 		
	 		printf("Name of the task: ");
			gets(name);
			fflush(stdin);
			printf("Deadline of the task\n");
			printf("Date in format (MM/DD/YYYY): ");
			scanf("%i/%i/%i",&month,&day,&year);
			fflush(stdin); 
				
			printf("The time format uses a 24-hour format clock.\n");
			printf("Please enter the time in format (HH:MM:SS): ");
			scanf("%i:%i:%i",&hours,&minutes,&seconds);
				
			fp = fopen(customFile,"r");
				/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
				if(fp != NULL){
					getDelimitedItem(s,'|',fp);
					ad->count4[1] = atoi(s);
					for(int i = 0; i<ad->count4[1];i++){
						
						  getDelimitedItem(ad->accDatabase[ad->count1].task_name[2][i], '|',fp); //reads the whole text before | 
				  
						  getDelimitedItem(s, '|',fp);
						  ad->accDatabase[ad->count1].month[2][i] = atoi(s); //reads the whole text before |, then converts to int 
				          
				          getDelimitedItem(s, '|',fp);	
						  ad->accDatabase[ad->count1].day[2][i] = atoi(s); //reads the whole text before |, then converts to int 
						  
						  getDelimitedItem(s, '|',fp);	
						  ad->accDatabase[ad->count1].year[2][i] = atoi(s); //reads the whole text before |, then converts to int 
						  
						  getDelimitedItem(s, '|',fp);	 
						  ad->accDatabase[ad->count1].hours[2][i] = atoi(s); //reads the whole text before |, then converts to int 
						  
						  getDelimitedItem(s, '|',fp);	
						  ad->accDatabase[ad->count1].minutes[2][i] = atoi(s); //reads the whole text before |, then converts to int 
						  
						  getDelimitedItem(s, '|',fp);	
						  ad->accDatabase[ad->count1].seconds[2][i] = atoi(s); //reads the whole text before |, then converts to int 
						
					}
					ad->count4[1]++;
					
		
					fPtr = fopen("templow.tmp","w"); // temporary file
				
					fprintf(fPtr,"%i\n",ad->count4[1]); //put new content
					for(int i = 0 ; i<ad->count4[1]-1; i++){
						fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[2][i],
					 	ad->accDatabase[ad->count1].month[2][i],ad->accDatabase[ad->count1].day[2][i],ad->accDatabase[ad->count1].year[2][i],
						ad->accDatabase[ad->count1].hours[2][i],ad->accDatabase[ad->count1].minutes[2][i],
					 	ad->accDatabase[ad->count1].seconds[2][i]);
					}
					fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					
					fclose(fp);
					fclose(fPtr);
					remove(customFile); //remove original file 
					rename("templow.tmp",customFile); //rename temporary file to original file name
				
					
				}
				else{
					ad->count4[1]++;
					fT = fopen(customFile,"w");
					fprintf(fT,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,minutes,hours,seconds);
					fclose(fT);
				}
				sprintf(csFile, "education%i.dat", ad->count1);
				fp1=fopen(csFile, "r");
				
				/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
				if(fp1 != NULL){
					
					getDelimitedItem(s1,'|',fp1);

					ad->count4[1] = atoi(s1);
					
					
					for(int i = 0 ;i<ad->count4[1];i++){
						
						 getDelimitedItem(ad->accDatabase[ad->count1].task_name[2][i], '|',fp1); //reads the whole text before | 
				  
						  getDelimitedItem(s1, '|',fp1);
						  ad->accDatabase[ad->count1].month[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
				          
				          getDelimitedItem(s1, '|',fp1);	
						  ad->accDatabase[ad->count1].day[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
						  
						  getDelimitedItem(s1, '|',fp1);	
						  ad->accDatabase[ad->count1].year[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
						  
						  getDelimitedItem(s1, '|',fp1);	 
						  ad->accDatabase[ad->count1].hours[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
						  
						  getDelimitedItem(s1, '|',fp1);	
						  ad->accDatabase[ad->count1].minutes[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
						  
						  getDelimitedItem(s1, '|',fp1);	
						  ad->accDatabase[ad->count1].seconds[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
						
					}
					ad->count4[1]++;
					fPtr1 = fopen("educationtemp.tmp","w"); //temporary file
					fprintf(fPtr1,"%i\n",ad->count4[1]);
					for(int i = 0 ; i<ad->count4[1]-1; i++){
						fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[2][i],
					 	ad->accDatabase[ad->count1].month[2][i],ad->accDatabase[ad->count1].day[2][i],
						 ad->accDatabase[ad->count1].year[2][i],
						ad->accDatabase[ad->count1].hours[2][i],ad->accDatabase[ad->count1].minutes[2][i],
					 	ad->accDatabase[ad->count1].seconds[2][i]);
					}
					
					fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,minutes,hours,seconds);
					
					fclose(fp1);
					fclose(fPtr1);
					remove(csFile); //remove original file
					rename("educationtemp.tmp",csFile); //change file
						
					}
					else{
						count = 0;
						fT1 = fopen(csFile,"w");
						count++;
						fprintf(fT1,"%i\n",count);
						fprintf(fT1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,minutes,hours,seconds);
						fclose(fT1);	
						
					}
					fflush(stdin);
		}
		
		// FUNCTION NAME: categorySorted
		// CREDITS: Ivan Porcincula, Jack Catalan
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: getDelimitedItem()
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. Set custom file name according to the current user
		//	  
		// 2. Open the file and if the file is not null, read the file.
		//
		// This function reads the content of EDUCATION category file
		

		void categorySorted(accountDatabases *ad){
			FILE *fp;
		   int i;
		   char s[100];
		   char customFile[500];  
	 	   
		   sprintf(customFile, "education%i.dat", ad->count1);
		   fp = fopen(customFile,"r");
		   if (fp!=NULL) {
		      getDelimitedItem(s,'|',fp);
		      ad->count2[1] = atoi(s);       //reads the first text before |, then converts to int 
		      
			  for (i=0; i<ad->count2[1]; i++) {
			  	  getDelimitedItem(ad->accDatabase[ad->count1].task_name[1][i], '|',fp); //reads the whole text before | 
				  
				  getDelimitedItem(s, '|',fp);
				  ad->accDatabase[ad->count1].month[1][i] = atoi(s); //reads the whole text before |, then converts to int 
		          
		          getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].day[1][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].year[1][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	 
				  ad->accDatabase[ad->count1].hours[1][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].minutes[1][i] = atoi(s); //reads the whole text before |, then converts to int 
				  
				  getDelimitedItem(s, '|',fp);	
				  ad->accDatabase[ad->count1].seconds[1][i] = atoi(s); //reads the whole text before |, then converts to int 
				 
      		}
      		fclose(fp);
		   }
		   
		   
		   
	}
		// FUNCTION NAME: displayCategory
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. Using a for loop, display all the tasks under EDUCATION category.
		//
		// This function displays all the tasks under EDUCATION category
		void displayCategory(accountDatabases *ad){
		int i;
		printf("EDUCATION\n");
		for(i=0;i<ad->count2[1];i++){
			if(strlen(ad->accDatabase[ad->count1].task_name[1][i]) != 0){
				printf("Task name: %s",ad->accDatabase[ad->count1].task_name[1][i]);
				printf("\nDue on: %i/%i/%i %i:%i:%i\n\n",ad->accDatabase[ad->count1].month[1][i],
				ad->accDatabase[ad->count1].day[1][i],ad->accDatabase[ad->count1].year[1][i],
				ad->accDatabase[ad->count1].hours[1][i], ad->accDatabase[ad->count1].minutes[1][i],
				ad->accDatabase[ad->count1].seconds[1][i]);
			}
			
	}
}	
	

};

class Games:public Tasks{
	public:
		
		// FUNCTION NAME: addHigh
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none        
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_4()
		//
		// 1. Get input from user: the name of the task
		// 2. Get input from user: date and time
		// 3. Store the data.
		// This function gets the input from user and saves to database.
		void addHigh(accountDatabases *ad){
			
			char customFile[100], csFile[100],s[100],s1[100];  
			FILE *fp, *fPtr, *fT, *fp1, *fPtr1, *fT1;
	 		sprintf(customFile, "high%i.dat", ad->count1); //HIGH PRIORITY DATABASE
			int month,day,year,hours,minutes,seconds,count;  
	 		char name[50];
	 		
	 		printf("Name of the task: ");
			gets(name);
			fflush(stdin);
			printf("Deadline of the task\n");
			printf("Date in format (MM/DD/YYYY): ");
			scanf("%i/%i/%i",&month,&day,&year);
			fflush(stdin); 
				
			printf("The time format uses a 24-hour format clock.\n");
			printf("Please enter the time in format (HH:MM:SS): ");
			scanf("%i:%i:%i",&hours,&minutes,&seconds);
			
			fp = fopen(customFile,"r");
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp != NULL){
				getDelimitedItem(s,'|',fp);
				ad->count2[2] = atoi(s);
				for(int i = 0; i<ad->count2[2];i++){
						
					getDelimitedItem(ad->accDatabase[ad->count1].task_name[0][i], '|',fp); //reads the whole text before |, 
					  
					  getDelimitedItem(s, '|',fp);
					  ad->accDatabase[ad->count1].month[0][i] = atoi(s); //reads the whole text before |
			          
			          getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].day[0][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].year[0][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].hours[0][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].minutes[0][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].seconds[0][i] = atoi(s); //reads the whole text before |, then converts to int 
						
				}
				ad->count2[2]++;

					
				fPtr = fopen("temphigh.tmp","w");
					
				fprintf(fPtr,"%i\n",ad->count2[2]);
				for(int i = 0 ; i<ad->count2[2]-1; i++){
					fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[0][i],
				 	ad->accDatabase[ad->count1].month[0][i],ad->accDatabase[ad->count1].day[0][i],ad->accDatabase[ad->count1].year[0][i],
					ad->accDatabase[ad->count1].hours[0][i],ad->accDatabase[ad->count1].minutes[0][i],
				 	ad->accDatabase[ad->count1].seconds[0][i]);
				}
				fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					
				fclose(fp);
				fclose(fPtr);
				
				remove(customFile);
				rename("temphigh.tmp",customFile);
				
				
			}
			else{
				ad->count2[2]++;
				fT = fopen(customFile,"w");
				fprintf(fT,"%i\n",ad->count2[2]);
				fprintf(fT,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
				fclose(fT);
					
				}
				sprintf(csFile, "games%i.dat", ad->count1);
				fp1=fopen(csFile, "r");
				/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
				
				if(fp1 != NULL){
					
					getDelimitedItem(s1,'|',fp1);
					ad->count2[2] = atoi(s1);
					
		
					for(int i = 0; i<ad->count2[2];i++){
							
						  getDelimitedItem(ad->accDatabase[ad->count1].task_name[0][i], '|',fp1); //reads the whole text before |, 
						  
						  getDelimitedItem(s1, '|',fp1);
						  ad->accDatabase[ad->count1].month[0][i] = atoi(s1); //reads the whole text before |
				          
				          getDelimitedItem(s1, '|',fp1);	
						  ad->accDatabase[ad->count1].day[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
						  
						  getDelimitedItem(s1, '|',fp1);	
						  ad->accDatabase[ad->count1].year[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
						  
						  getDelimitedItem(s1, '|',fp1);	
						  ad->accDatabase[ad->count1].hours[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
						  
						  getDelimitedItem(s1, '|',fp1);	
						  ad->accDatabase[ad->count1].minutes[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
						  
						  getDelimitedItem(s1, '|',fp1);	
						  ad->accDatabase[ad->count1].seconds[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
							
					}
					ad->count2[2]++;
					fPtr1 = fopen("gamestemp.tmp","w");
					fprintf(fPtr1,"%i\n",ad->count2[2]);
					
					for(int i = 0 ; i<ad->count2[2]-1; i++){
						fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[0][i],
					 	ad->accDatabase[ad->count1].month[0][i],
						ad->accDatabase[ad->count1].day[0][i],ad->accDatabase[ad->count1].year[0][i],
						ad->accDatabase[ad->count1].hours[0][i],ad->accDatabase[ad->count1].minutes[0][i],
					 	ad->accDatabase[ad->count1].seconds[0][i]);
					}
					
					fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					fclose(fp1);
					fclose(fPtr1);
					remove(csFile);
					rename("gamestemp.tmp",csFile);
						
				}
				else{
					count = 0;
					fT1 = fopen(csFile,"w");
					count++;
					fprintf(fT1,"%i\n",count);
					fprintf(fT1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					fclose(fT1);	
			}
			fflush(stdin);
		}
		// FUNCTION NAME: addMed
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none        
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_4()
		//
		// 1. Get input from user: the name of the task
		// 2. Get input from user: date and time
		// 3. Store the data.
		// This function gets the input from user and saves to database.
		
		void addMed(accountDatabases *ad){
			char customFile[100], csFile[100],s[100],s1[100];  
			FILE *fp, *fPtr, *fT, *fp1, *fPtr1, *fT1;
	 		sprintf(customFile, "medium%i.dat", ad->count1); //MEDIUM PRIORITY DATABASE
				
			fp = fopen(customFile,"r");
			
			int month,day,year,hours,minutes,seconds,count;  
	 		char name[50];
	 		
	 		printf("Name of the task: ");
			gets(name);
			fflush(stdin);
			printf("Deadline of the task\n");
			printf("Date in format (MM/DD/YYYY): ");
			scanf("%i/%i/%i",&month,&day,&year);
			fflush(stdin); 
				
			printf("The time format uses a 24-hour format clock.\n");
			printf("Please enter the time in format (HH:MM:SS): ");
			scanf("%i:%i:%i",&hours,&minutes,&seconds);
			
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp != NULL){
				getDelimitedItem(s,'|',fp);
				ad->count3[2] = atoi(s);
				for(int i = 0; i<ad->count3[2];i++){
						
					getDelimitedItem(ad->accDatabase[ad->count1].task_name[1][i], '|',fp); //reads the whole text before |, 
					  
					  getDelimitedItem(s, '|',fp);
					  ad->accDatabase[ad->count1].month[1][i] = atoi(s); //reads the whole text before |
			          
			          getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].day[1][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].year[1][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].hours[1][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].minutes[1][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].seconds[1][i] = atoi(s); //reads the whole text before |, then converts to int 
						
				}
				ad->count3[2]++;				
				fPtr = fopen("tempmed.tmp","w");
					
					
				fprintf(fPtr,"%i\n",ad->count3[2]);
				for(int i = 0 ; i<ad->count3[2]-1; i++){
					fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[1][i],
				 	ad->accDatabase[ad->count1].month[1][i],ad->accDatabase[ad->count1].day[1][i],ad->accDatabase[ad->count1].year[1][i],
					ad->accDatabase[ad->count1].hours[1][i],ad->accDatabase[ad->count1].minutes[1][i],
				 	ad->accDatabase[ad->count1].seconds[1][i]);
				}
				fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					
				fclose(fp);
				fclose(fPtr);
				
				remove(customFile);
				rename("tempmed.tmp",customFile);
				
				
			}
			else{
				ad->count3[2]++;
				fT = fopen(customFile,"w");
				fprintf(fT,"%i\n",ad->count3[2]);
				fprintf(fT,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
				fclose(fT);
				}
			sprintf(csFile, "games%i.dat", ad->count1);
			fp1=fopen(csFile, "r");
			
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp1 != NULL){
					
				getDelimitedItem(s1,'|',fp1);
				ad->count3[2] = atoi(s1);
				
					
				for(int i = 0 ;i<ad->count3[2];i++){
						
					getDelimitedItem(ad->accDatabase[ad->count1].task_name[1][i], '|',fp1); //reads the whole text before |, 
					  
					  getDelimitedItem(s1, '|',fp1);
					  ad->accDatabase[ad->count1].month[1][i] = atoi(s1); //reads the whole text before |
			          
			          getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].day[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].year[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].hours[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].minutes[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].seconds[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
						
				}
				ad->count3[2]++;
				
				fPtr1 = fopen("gamestemp.tmp","w");
				fprintf(fPtr1,"%i\n",ad->count3[2]);
				for(int i = 0 ; i<ad->count3[2]-1; i++){
					fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[1][i],
				 	ad->accDatabase[ad->count1].month[1][i],
					 ad->accDatabase[ad->count1].day[1][i],ad->accDatabase[ad->count1].year[1][i],
					ad->accDatabase[ad->count1].hours[1][i],ad->accDatabase[ad->count1].minutes[1][i],
				 	ad->accDatabase[ad->count1].seconds[1][i]);
				}
				
				fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					
				fclose(fp1);
				fclose(fPtr1);
					
				remove(csFile);
				rename("gamestemp.tmp",csFile);
						
				}
				else{
					count = 0;
					fT1 = fopen(csFile,"w");
					count++;
					fprintf(fT1,"%i\n",count);
					fprintf(fT1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					fclose(fT1);
						
			}
			fflush(stdin);	
		}
		
		// FUNCTION NAME: addLow
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none        
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_4_Home(), Menu_4_Education(), Menu_4_Meeting(), Menu_4_Games()
		//
		// 1. Get input from user: the name of the task
		// 2. Get input from user: date and time
		// 3. Store the data.
		// This function gets the input from user and saves to database.
		void addLow(accountDatabases *ad){
			char customFile[100], csFile[100],s[100],s1[100];  
			FILE *fp, *fPtr, *fT, *fp1, *fPtr1, *fT1;
	 		sprintf(customFile, "low%i.dat", ad->count1); //LOW PRIORITY DATABASE
	 		
	 		int month,day,year,hours,minutes,seconds,count;  
	 		char name[50];
	 		
	 		printf("Name of the task: ");
			gets(name);
			fflush(stdin);
			printf("Deadline of the task\n");
			printf("Date in format (MM/DD/YYYY): ");
			scanf("%i/%i/%i",&month,&day,&year);
			fflush(stdin); 
				
			printf("The time format uses a 24-hour format clock.\n");
			printf("Please enter the time in format (HH:MM:SS): ");
			scanf("%i:%i:%i",&hours,&minutes,&seconds);
				
			fp = fopen(customFile,"r");
			
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp != NULL){
				getDelimitedItem(s,'|',fp);
				ad->count4[2] = atoi(s);
				for(int i = 0 ;i<ad->count4[2];i++){
						
					getDelimitedItem(ad->accDatabase[ad->count1].task_name[2][i], '|',fp); //reads the whole text before |, 
					  
					  getDelimitedItem(s, '|',fp);
					  ad->accDatabase[ad->count1].month[2][i] = atoi(s); //reads the whole text before |
			          
			          getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].day[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].year[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].hours[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].minutes[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].seconds[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					
					}
				ad->count4[2]++;
				
		
				fPtr = fopen("templow.tmp","w");
					
					
				fprintf(fPtr,"%i\n",ad->count4[2]);
				for(int i = 0 ; i<ad->count4[2]-1; i++){
					fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[2][i],
				 	ad->accDatabase[ad->count1].month[2][i],ad->accDatabase[ad->count1].day[2][i],ad->accDatabase[ad->count1].year[2][i],
					ad->accDatabase[ad->count1].hours[2][i],ad->accDatabase[ad->count1].minutes[2][i],
				 	ad->accDatabase[ad->count1].seconds[2][i]);
				}
				fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);	
				fclose(fp);
				fclose(fPtr);
					
				remove(customFile);
					rename("templow.tmp",customFile);
				
					
			}
			else{
				ad->count4[2]++;
				fT = fopen(customFile,"w");
				fprintf(fT,"%i\n",ad->count4[2]);
				fprintf(fT,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
				fclose(fT);	
			}
			sprintf(csFile, "games%i.dat", ad->count1);
			fp1=fopen(csFile, "r");
			
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp1 != NULL){
					
				getDelimitedItem(s1,'|',fp1);
				ad->count4[2] = atoi(s1);
					
				for(int i = 0; i<ad->count4[2];i++){
						
					getDelimitedItem(ad->accDatabase[ad->count1].task_name[2][i], '|',fp1); //reads the whole text before |, 
					  
					  getDelimitedItem(s1, '|',fp1);
					  ad->accDatabase[ad->count1].month[2][i] = atoi(s1); //reads the whole text before |
			          
			          getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].day[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].year[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].hours[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].minutes[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].seconds[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
						
					}
				ad->count4[2]++;
				fPtr1 = fopen("gamestemp.tmp","w");
				fprintf(fPtr1,"%i\n",ad->count4[2]);
				for(int i = 0 ; i<ad->count4[2]-1; i++){
					fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[2][i],
				 	ad->accDatabase[ad->count1].month[2][i],ad->accDatabase[ad->count1].day[2][i],ad->accDatabase[ad->count1].year[2][i],
					ad->accDatabase[ad->count1].hours[2][i],ad->accDatabase[ad->count1].minutes[2][i],
				 	ad->accDatabase[ad->count1].seconds[2][i]);
				}
				fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
				fclose(fp1);
				fclose(fPtr1);	
				remove(csFile);
				rename("gamestemp.tmp",csFile);
						
				}
				else{
					count = 0;
					fT1 = fopen(csFile,"w");
					count++;
					fprintf(fT1,"%i\n",count);
					fprintf(fT1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					fclose(fT1);	
				}
				fflush(stdin);
		}
		
		// FUNCTION NAME: categorySorted
		// CREDITS: Ivan Porcincula, Jack Catalan
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: getDelimitedItem()
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. Set custom file name according to the current user
		//	  
		// 2. Open the file and if the file is not null, read the file.
		//
		// This function reads the content of GAMES category file
		void categorySorted(accountDatabases *ad){
			   FILE *fp;
			   int i;
			   char s[100];
			   char customFile[500];  
			   sprintf(customFile, "games%i.dat", ad->count1);
			   fp = fopen(customFile,"r");
			   if (fp!=NULL) {
			     getDelimitedItem(s,'|',fp);
			      ad->count2[2] = atoi(s);       //reads the first text before |, then converts to int 
			      
				  for (i=0; i<ad->count2[2]; i++) {
				  	  getDelimitedItem(ad->accDatabase[ad->count1].task_name[2][i], '|',fp); //reads the whole text before |, 
					  
					  getDelimitedItem(s, '|',fp);
					  ad->accDatabase[ad->count1].month[2][i] = atoi(s); //reads the whole text before |
			          
			          getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].day[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].year[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].hours[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].minutes[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].seconds[2][i] = atoi(s); //reads the whole text before |, then converts to int 
	      		}
	      		fclose(fp);
			   }
		}
		
		// FUNCTION NAME: displayCategory
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. Using a for loop, display all the tasks under GAMES category.
		//
		// This function displays all the tasks under GAMES category.
		void displayCategory(accountDatabases *ad){
			int i;
			printf("GAMES\n");
			for(i=0;i<ad->count2[2];i++){
				if(strlen(ad->accDatabase[ad->count1].task_name[2][i]) != 0){
					printf("Task name: %s",ad->accDatabase[ad->count1].task_name[2][i]);
					printf("\nDue on: %i/%i/%i %i:%i:%i\n\n",ad->accDatabase[ad->count1].month[2][i],
					ad->accDatabase[ad->count1].day[2][i],ad->accDatabase[ad->count1].year[2][i],
					ad->accDatabase[ad->count1].hours[2][i], ad->accDatabase[ad->count1].minutes[0][i],
					ad->accDatabase[ad->count1].seconds[2][i]);
				}
				
				}
	}
	
};

class Meeting:public Tasks{
	public:
		// FUNCTION NAME: addHigh
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none        
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_4_Home(), Menu_4_Education(), Menu_4_Meeting(), Menu_4_Games()
		//
		// 1. Get input from user: the name of the task
		// 2. Get input from user: date and time
		// 3. Store the data.
		// This function gets the input from user and saves to database.
		
		
		void addHigh(accountDatabases *ad){
			char customFile[100], csFile[100],s[100],s1[100];  
			FILE *fp, *fPtr, *fT, *fp1, *fPtr1, *fT1;
	 		sprintf(customFile, "high%i.dat", ad->count1); //HIGH PRIORITY DATABASE
			
			int month,day,year,hours,minutes,seconds,count;  
	 		char name[50];
	 		
	 		printf("Name of the task: ");
			gets(name);
			fflush(stdin);
			printf("Deadline of the task\n");
			printf("Date in format (MM/DD/YYYY): ");
			scanf("%i/%i/%i",&month,&day,&year);
			fflush(stdin); 
				
			printf("The time format uses a 24-hour format clock.\n");
			printf("Please enter the time in format (HH:MM:SS): ");
			scanf("%i:%i:%i",&hours,&minutes,&seconds);
				
			fp = fopen(customFile,"r");
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp != NULL){
				getDelimitedItem(s,'|',fp);
				ad->count2[3] = atoi(s);
				for(int i = 0; i<ad->count2[3];i++){
						
					  getDelimitedItem(ad->accDatabase[ad->count1].task_name[0][i], '|',fp);	
					  
					  getDelimitedItem(s, '|',fp);
					  ad->accDatabase[ad->count1].month[0][i] = atoi(s); //reads the whole text before |
			          
			          getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].day[0][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].year[0][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].hours[0][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].minutes[0][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].seconds[0][i] = atoi(s); //reads the whole text before |, then converts to int 
						
				}
				ad->count2[3]++;
					
			
				fPtr = fopen("temphigh.tmp","w");
				fprintf(fPtr,"%i\n",ad->count2[3]);
				for(int i = 0 ; i<ad->count2[3]-1; i++){
					fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[0][i],
				 	ad->accDatabase[ad->count1].month[0][i],ad->accDatabase[ad->count1].day[0][i],ad->accDatabase[ad->count1].year[0][i],
					ad->accDatabase[ad->count1].hours[0][i],ad->accDatabase[ad->count1].minutes[0][i],
				 	ad->accDatabase[ad->count1].seconds[0][i]);
				}
				
				fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds,count);
				fclose(fp);
				fclose(fPtr);
				remove(customFile);
				rename("temphigh.tmp",customFile);
				
				
			}
			else{
				ad->count2[3]++;
				fT = fopen(customFile,"w");
				fprintf(fT, "%i\n",ad->count2[3]);
				fprintf(fT,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds,count);
				fclose(fT);
					
				}
			sprintf(csFile, "meeting%i.dat", ad->count1);
			fp1=fopen(csFile, "r");
			if(fp1 != NULL){
					
				getDelimitedItem(s1,'|',fp1);
				 ad->count2[3] = atoi(s1);
				
					
				for(int i = 0; i<ad->count2[3];i++){
						
					getDelimitedItem(ad->accDatabase[ad->count1].task_name[0][i], '|',fp1);	
					  
					  getDelimitedItem(s1, '|',fp1);
					  ad->accDatabase[ad->count1].month[0][i] = atoi(s1); //reads the whole text before |
			          
			          getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].day[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].year[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].hours[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].minutes[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].seconds[0][i] = atoi(s1); //reads the whole text before |, then converts to int 
						
				}
				ad->count2[3]++;
				
				fPtr1 = fopen("meetingtemp.tmp","w");
				fprintf(fPtr1,"%i\n",ad->count2[3]);
				for(int i = 0 ; i<ad->count2[3]-1; i++){
					fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[0][i],
				 	ad->accDatabase[ad->count1].month[0][i],
					ad->accDatabase[ad->count1].day[0][i],ad->accDatabase[ad->count1].year[0][i],
					ad->accDatabase[ad->count1].hours[0][i],ad->accDatabase[ad->count1].minutes[0][i],
				 	ad->accDatabase[ad->count1].seconds[0][i]);
				}
				fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds,count);
					
				fclose(fp1);
				fclose(fPtr1);
					
				remove(csFile);
				rename("meetingtemp.tmp",csFile);
						
				}
				else{
					count = 0;
					fT1 = fopen(csFile,"w");
					count++;
					fprintf(fT1,"%i\n",count);
					fprintf(fT1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds,count);
					fclose(fT1);
						
			}
			fflush(stdin);
			 
		}
		
		// FUNCTION NAME: addMed
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none        
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_4_Home(), Menu_4_Education(), Menu_4_Meeting(), Menu_4_Games()
		//
		// 1. Get input from user: the name of the task
		// 2. Get input from user: date and time
		// 3. Store the data.
		// This function gets the input from user and saves to database.
		void addMed(accountDatabases *ad){
			char customFile[100], csFile[100],s[100],s1[100];  
			FILE *fp, *fPtr, *fT, *fp1, *fPtr1, *fT1;
	 		sprintf(customFile, "medium%i.dat", ad->count1); //MEDIUM PRIORITY DATABASE
	 		
	 		int month,day,year,hours,minutes,seconds,count;  
	 		char name[50];
	 		
	 		printf("Name of the task: ");
			gets(name);
			fflush(stdin);
			printf("Deadline of the task\n");
			printf("Date in format (MM/DD/YYYY): ");
			scanf("%i/%i/%i",&month,&day,&year);
			fflush(stdin); 
				
			printf("The time format uses a 24-hour format clock.\n");
			printf("Please enter the time in format (HH:MM:SS): ");
			scanf("%i:%i:%i",&hours,&minutes,&seconds);
	 		
				
			fp = fopen(customFile,"r");
			
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp != NULL){
				getDelimitedItem(s,'|',fp);
				ad->count3[3] = atoi(s);
				for(int i = 0 ;i<ad->count3[3];i++){
						
					getDelimitedItem(ad->accDatabase[ad->count1].task_name[1][i], '|',fp);	
					  
					  getDelimitedItem(s, '|',fp);
					  ad->accDatabase[ad->count1].month[1][i] = atoi(s); //reads the whole text before |
			          
			          getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].day[1][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].year[1][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].hours[1][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].minutes[1][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].seconds[1][i] = atoi(s); //reads the whole text before |, then converts to int 
						
				}
				ad->count3[3]++;
				
					
				fPtr = fopen("tempmed.tmp","w");
					
					
				fprintf(fPtr,"%i\n",ad->count3[3]);
				for(int i = 0 ; i<ad->count3[3]-1; i++){
					fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[1][i],
				 	ad->accDatabase[ad->count1].month[1][i],ad->accDatabase[ad->count1].day[1][i],ad->accDatabase[ad->count1].year[1][i],
					ad->accDatabase[ad->count1].hours[1][i],ad->accDatabase[ad->count1].minutes[1][i],
				 	ad->accDatabase[ad->count1].seconds[1][i]);
				}
				fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
				fclose(fp);
				fclose(fPtr);
				remove(customFile);
				rename("tempmed.tmp",customFile);
				
			}
			else{
				ad->count3[3]++;
				fT = fopen(customFile,"w");		
				fprintf(fT, "%i\n",ad->count3[3]);	
				fprintf(fT,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
				fclose(fT);
				}
			sprintf(csFile, "meeting%i.dat", ad->count1);
			fp1=fopen(csFile, "r");
			
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp1 != NULL){
					
				getDelimitedItem(s1,'|',fp1);
				ad->count3[3] = atoi(s1);
					
				for(int i = 0 ;i<ad->count3[3];i++){
						
					getDelimitedItem(ad->accDatabase[ad->count1].task_name[1][i], '|',fp1);	
					  
					  getDelimitedItem(s1, '|',fp1);
					  ad->accDatabase[ad->count1].month[1][i] = atoi(s1); //reads the whole text before |
			          
			          getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].day[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].year[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].hours[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].minutes[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].seconds[1][i] = atoi(s1); //reads the whole text before |, then converts to int 
						
				}
				ad->count3[3]++;
				fPtr1 = fopen("meetingtemp.tmp","w");
				fprintf(fPtr1,"%i\n",ad->count3[3]);
				for(int i = 0 ; i<ad->count3[3]-1; i++){
					fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[1][i],
				 	ad->accDatabase[ad->count1].month[1][i],
					ad->accDatabase[ad->count1].day[1][i],ad->accDatabase[ad->count1].year[1][i],
					ad->accDatabase[ad->count1].hours[1][i],ad->accDatabase[ad->count1].minutes[1][i],
				 	ad->accDatabase[ad->count1].seconds[1][i]);
				}
				
				fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					
				fclose(fp1);
				fclose(fPtr1);
					
				remove(csFile);
				rename("meetingtemp.tmp",csFile);
						
				}
				else{
					count = 0;
					fT1 = fopen(csFile,"w");
					count++;
					fprintf(fT1,"%i\n",count);
					fprintf(fT1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds);
					fclose(fT1);
							
			}
			fflush(stdin);
		}
		
		// FUNCTION NAME: addLow
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none        
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_4_Home(), Menu_4_Education(), Menu_4_Meeting(), Menu_4_Games()
		//
		// 1. Get input from user: the name of the task
		// 2. Get input from user: date and time
		// 3. Store the data.
		// This function gets the input from user and saves to database.
		void addLow(accountDatabases *ad){
			char customFile[100], csFile[100],s[100],s1[100];  
			FILE *fp, *fPtr, *fT, *fp1, *fPtr1, *fT1;
	 		sprintf(customFile, "low%i.dat", ad->count1); //LOW PRIORITY DATABASE
	 		
	 		int month,day,year,hours,minutes,seconds,count;  
	 		char name[50];
	 		
	 		printf("Name of the task: ");
			gets(name);
			fflush(stdin);
			printf("Deadline of the task\n");
			printf("Date in format (MM/DD/YYYY): ");
			scanf("%i/%i/%i",&month,&day,&year);
			fflush(stdin); 
				
			printf("The time format uses a 24-hour format clock.\n");
			printf("Please enter the time in format (HH:MM:SS): ");
			scanf("%i:%i:%i",&hours,&minutes,&seconds);
				
			fp = fopen(customFile,"r");
			
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp != NULL){
				getDelimitedItem(s,'|',fp);
				ad->count4[3] = atoi(s);
				for(int i = 0 ;i<ad->count4[3];i++){
						
					getDelimitedItem(ad->accDatabase[ad->count1].task_name[2][i], '|',fp);	
					  
					  getDelimitedItem(s, '|',fp);
					  ad->accDatabase[ad->count1].month[2][i] = atoi(s); //reads the whole text before |
			          
			          getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].day[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].year[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].hours[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].minutes[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].seconds[2][i] = atoi(s); //reads the whole text before |, then converts to int 
					
					}
				ad->count4[3]++;
				
				fPtr = fopen("templow.tmp","w");
		
				fprintf(fPtr,"%i\n",ad->count4[3]);
				for(int i = 0 ; i<ad->count4[3]-1; i++){
					fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[2][i],
				 	ad->accDatabase[ad->count1].month[2][i],ad->accDatabase[ad->count1].day[2][i],ad->accDatabase[ad->count1].year[2][i],
					ad->accDatabase[ad->count1].hours[2][i],ad->accDatabase[ad->count1].minutes[2][i],
				 	ad->accDatabase[ad->count1].seconds[2][i]);
				}
				
				fprintf(fPtr,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds,count);
					
				fclose(fp);
				fclose(fPtr);
					
				remove(customFile);
					rename("templow.tmp",customFile);
				
					
			}
			else{

				ad->count4[3]++;
				fT = fopen(customFile,"w");
				fprintf(fT, "%i\n",ad->count4[3]);
				fprintf(fT,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds,count);
				fclose(fT);
				
			}
			sprintf(csFile, "meeting%i.dat", ad->count1);
			fp1=fopen(csFile, "r");
			
			/*checks if the data file exists, if it does, then it is in read mode, after reading it we store it in array variables
			  then add the new entry to the array and then print the new data and overwrite the old data, else we create a new file 
			  for that database.*/
			if(fp1 != NULL){
					
				getDelimitedItem(s1,'|',fp1);
				ad->count4[3] = atoi(s1);
				
				for(int i = 0 ;i<ad->count4[3];i++){
						
					getDelimitedItem(ad->accDatabase[ad->count1].task_name[2][i], '|',fp1);	
					  
					  getDelimitedItem(s1, '|',fp1);
					  ad->accDatabase[ad->count1].month[2][i] = atoi(s1); //reads the whole text before |
			          
			          getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].day[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].year[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].hours[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].minutes[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s1, '|',fp1);	
					  ad->accDatabase[ad->count1].seconds[2][i] = atoi(s1); //reads the whole text before |, then converts to int 
						
					}
				ad->count4[3]++;
				fPtr1 = fopen("meetingtemp.tmp","w");
				fprintf(fPtr1,"%i\n",ad->count4[3]);
				for(int i = 0 ; i<ad->count4[3]-1; i++){
					fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",ad->accDatabase[ad->count1].task_name[2][i],
				 	ad->accDatabase[ad->count1].month[2][i],ad->accDatabase[ad->count1].day[2][i],ad->accDatabase[ad->count1].year[2][i],
					ad->accDatabase[ad->count1].hours[2][i],ad->accDatabase[ad->count1].minutes[2][i],
				 	ad->accDatabase[ad->count1].seconds[2][i]);
				}
				fprintf(fPtr1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds,count);
					
				fclose(fp1);
				fclose(fPtr1);
					
				remove(csFile);
				rename("meetingtemp.tmp",csFile);
		
				}
				else{
					count = 0;
					fT1 = fopen(csFile,"w");
					count++;
					fprintf(fT1,"%i\n",count);
					fprintf(fT1,"%s|%d/%d/%d|%d:%d:%d\n",name,month,day,year,hours,minutes,seconds,count);
					fclose(fT1);	
					
				}
				fflush(stdin);
		}
		
		// FUNCTION NAME: categorySorted
		// CREDITS: Ivan Porcincula, Jack Catalan
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: getDelimitedItem()
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. Set custom file name according to the current user
		//	  
		// 2. Open the file and if the file is not null, read the file.
		//
		// This function reads the content of MEETING category file
		
		
		void categorySorted(accountDatabases *ad){
				FILE *fp;
			   int i;
			   char s[100];
			   char customFile[500];  
			   sprintf(customFile, "meeting%i.dat", ad->count1);
			   fp = fopen(customFile,"r");
			   
			   if (fp!=NULL) {
			      getDelimitedItem(s,'|',fp);
			      ad->count2[3] = atoi(s);       //reads the first text before |, then converts to int 
			      
				  for (i=0; i<ad->count2[3]; i++) {
				  	  getDelimitedItem(ad->accDatabase[ad->count1].task_name[3][i], '|',fp);	
					  
					  getDelimitedItem(s, '|',fp);
					  ad->accDatabase[ad->count1].month[3][i] = atoi(s); //reads the whole text before |
			          
			          getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].day[3][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].year[3][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].hours[3][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].minutes[3][i] = atoi(s); //reads the whole text before |, then converts to int 
					  
					  getDelimitedItem(s, '|',fp);	
					  ad->accDatabase[ad->count1].seconds[3][i] = atoi(s); //reads the whole text before |, then converts to int 
	      		}
	      		fclose(fp);
			   }
		}
		
		// FUNCTION NAME: displayCategory
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none     
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_5()
		//
		// METHOD:
		// 1. Using a for loop, display all the tasks under GAMES category.
		//
		// This function displays all the tasks under GAMES category.
		void displayCategory(accountDatabases *ad){
			int i;
			printf("MEETING\n");
			for(i=0;i<ad->count2[3];i++){
				if(strlen(ad->accDatabase[ad->count1].task_name[3][i]) != 0){
					printf("Task name: %s",ad->accDatabase[ad->count1].task_name[3][i]);
					printf("\nDue on: %i/%i/%i %i:%i:%i\n\n",ad->accDatabase[ad->count1].month[3][i],
					ad->accDatabase[ad->count1].day[3][i],ad->accDatabase[ad->count1].year[3][i],
					ad->accDatabase[ad->count1].hours[3][i], ad->accDatabase[ad->count1].minutes[3][i],
					ad->accDatabase[ad->count1].seconds[3][i]);
					
				}
				}
	}
};

class Account{
	
	private:
		Home home;
		// FUNCTION NAME: getDelimitedItem
		// CREDITS: J. Catalan
		//           
		// PARAMETERS: char s[], char d, FILE *fp
		//
		// RETURN VALUE: integer         
		//
		// CALLS TO: none
		//
		// CALLED FROM: loginAccount()
		//
		// METHOD:
		// 1. Reads the content of the file.
		// This function reads the content of a file.
		int getDelimitedItem(char s[],char d, FILE *fp) {
		    int c;
		    int i=0;
		    c=0;
		    s[i]=0;
		    
		    while (!feof(fp)) {
		        c=fgetc(fp);
		        if (c==d||c=='\n'||c==10||c==EOF) return i;
		        else {
		            s[i]=c;
		            i++;
		            s[i]=0;
		        }
		    }
		    return i;
	}
	
	public:
	
		// FUNCTION NAME: createAccount
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none         
		//
		// CALLS TO: none
		//
		// CALLED FROM: Menu_1()
		//
		// METHOD:
		// 1. Prompt user to input desired username and password
		// 2. Ask user if they want to register their account
		//	  to the database already
		// This function asks the user to create their account
	void createAccount(accountDatabases *ad){
		FILE *fp, *fPtr, *fT;
		char write,s[100], user[40],pass[40];
		
		printf("\nEnter desired username: ");
		gets(user);
		printf("Enter desired password: ");
		gets(pass);
		
		fp = fopen("accountDatabase.dat","r");
		if(fp != NULL){
			getDelimitedItem(s,'|',fp);
			ad->count = atoi(s);
			for(int i=0;i<ad->count;i++){
	      		getDelimitedItem(ad->accDatabase[i].username,'|',fp);
				getDelimitedItem(ad->accDatabase[i].password,'|',fp);  
		  	}
			ad->count++;
		    fPtr = fopen("tempfile.tmp","w");
		  	fprintf(fPtr,"%i\n",ad->count);
		  	for(int i=0; i<ad->count-1;i++){
		  		fprintf(fPtr,"%s|%s\n",ad->accDatabase[i].username,ad->accDatabase[i].password);
			  }
			  fprintf(fPtr,"%s|%s\n",user,pass);
		 	fclose(fp);
		 	fclose(fPtr);
		 	remove("accountDatabase.dat");
		 	rename("tempfile.tmp","accountDatabase.dat");
		 	printf("You have successfully registered!\n\n");
		  }
		else{
			fT = fopen("accountDatabase.dat","w");
			ad->count++;
			fprintf(fT,"%i\n",ad->count);
	   		fprintf(fT,"%s|%s\n",user,pass);
			fclose(fT);
			printf("You have successfully registered!\n\n");
		}
		
	
		fflush(stdin);
	}
		
		// FUNCTION NAME: loginAccount
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none         
		//
		// CALLS TO: getDelimitedItem()
		//
		// CALLED FROM: Menu_1()
		//
		// METHOD:
		// 1. Prompt user to input their existing username and password
		// 2. Allow the user to enter the program
		// 3. If the user inputs a wrong username or password,
		//	  ask the user to input their credentials again.
		// This function asks the user to login to their exising account
		
	void loginAccount(accountDatabases *ad){
	 	FILE *fp;
	 	char user[100],pass[100],s[100];
	login:	 	
	 	int i;
	 	fp = fopen("accountDatabase.dat","r");
	 	printf("\nEnter your username: ");
		scanf("%s",&user);
		printf("Enter your password: ");
		scanf("%s",&pass);
		
		if (fp==NULL) {
	      printf("No registered accounts yet. Register now!\n");
	   }
	   else {
	      getDelimitedItem(s,'|',fp);
	      ad->count = atoi(s);    
	      for(i=0;i<ad->count;i++){
	      	getDelimitedItem(ad->accDatabase[i].username,'|',fp);
			getDelimitedItem(ad->accDatabase[i].password,'|',fp);  
		  }
		  fclose(fp);
		  
		  for(i=0;i<ad->count;i++){
			if(strcmp(user, ad->accDatabase[i].username) == 0 && strcmp(pass, ad->accDatabase[i].password) == 0) {
		
				ad->count1=i;
				printf("\nLogin successful!\n");
				break;
				}
		}
		 fflush(stdin);
		 if(strcmp(user, ad->accDatabase[ad->count1].username) != 0 && strcmp(pass, ad->accDatabase[ad->count1].password) != 0) {
				printf("\nInvalid username or password. Please try again.\n");
				goto login;
				}
	    }
	    
	    
	}
			
};

class AllMenu{
	private:
		Account accDb;
	public:
		// FUNCTION NAME: Menu_1()
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none         
		//
		// CALLS TO: createAccount(), loginAccount
		//
		// CALLED FROM: int main()
		//
		// METHOD:
		// 1. Prompt user to choose the choice from the display
		// This function asks to input a choice
		void Menu_1(accountDatabases *ad){
			char choice;
			ad->count2[0]={};
			ad->count3[0]={};
			ad->count4[0]={};
			ad->count2[0]=0;
			ad->count3[0]=0;
			ad->count4[0]=0;
			
			ad->count2[1]={};
			ad->count3[1]={};
			ad->count4[1]={};
			ad->count2[1]=0;
			ad->count3[1]=0;
			ad->count4[1]=0;
			
			ad->count2[2]={};
			ad->count3[2]={};
			ad->count4[2]={};
			ad->count2[2]=0;
			ad->count3[2]=0;
			ad->count4[2]=0;
			
			ad->count2[3]={};
			ad->count3[3]={};
			ad->count4[3]={};
			ad->count2[3]=0;
			ad->count3[3]=0;
			ad->count4[3]=0;
			do {
		        printf(" _____________________________________________\n");
				printf("|             TO-DO LIST TRACKER              |\n");
				printf("|_____________________________________________|\n");
				printf("|           [1] Create a new account          |\n");
				printf("|     [2] Login with an existing account      |\n");
				printf("|                [3]EXIT PROGRAM              |\n");
				printf("-----------------------------------------------\n");
		        printf("\nChoice: ");
		        choice=getchar();
		        getchar();
		        
		
		        switch (choice) {
		          case '1':
		          	 accDb.createAccount(ad);
		             break;
		          case '2':
		             accDb.loginAccount(ad);
		             Menu_2(ad);
		             break;
		          case '3':
		             return;
		        }
		
		    } while (choice != '3');
	}
	private:
		// FUNCTION NAME: Menu_2()
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none         
		//
		// CALLS TO: Menu_3(), taskRemoval(), Menu_5(), displayAccomplished()
		//
		// CALLED FROM: Menu_1()
		//
		// METHOD:
		// 1. Prompt user to choose the choice from the display
		void Menu_2(accountDatabases *ad){
			char choice;
			Tasks tasks;
			do {
		        printf(" _________________________________________________\n");
				printf("|               TO-DO LIST TRACKER                |\n");
				printf("|_________________________________________________|\n");
				printf("|             [1] Add new Tasks to do             |\n");
				printf("|            [2] Update finished tasks            |\n");
				printf("|    [3] List of all tasks needed to accomplish   |\n");
				printf("|           [4] List all accomplished tasks       |\n");
				printf("|                  [5] LOGOUT                     |\n"); 
				printf("---------------------------------------------------\n");
		
		
		        printf("\nChoice: ");
		        choice=getchar();
		        getchar();
		        
		        switch (choice) {
		          case '1':
		          	Menu_3(ad);
		             break;
		          case '2':
		          	tasks.taskRemoval(ad);
		             break;
		          case '3':
		          	 Menu_5(ad);
		             break;
		          case '4':
		          	tasks.displayAccomplished(ad);
		          	break;
		          case '5':
		          	return;
		        }
		    } while (choice != '5');
		   
		
		}
		// FUNCTION NAME: Menu_3()
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none         
		//
		// CALLS TO: Menu_4_Home(), Menu_4_Education(), Menu_4_Games(), Menu_4_Meeting(), saveToFile()
		//
		// CALLED FROM: Menu_2()
		//
		// METHOD:
		// 1. Prompt user to choose the choice from the display
		
		void Menu_3(accountDatabases *ad){
			char choice;
			Home home;
			Education educ;
			Games games;
			Meeting meeting;
			do {
		       printf(" __________________________\n");
				printf("|    TO-DO LIST TRACKER   |\n");
				printf("|_________________________|\n");
				printf("|        [1] Home         |\n");
				printf("|     [2] Education       |\n");
				printf("|       [3] Games         |\n");
				printf("|      [4] Meeting        |\n");
				printf("|        [5] Back         |\n"); 
				printf("---------------------------\n");
		        printf("\nChoice: ");
		        choice=getchar();
		        getchar();
		        
		
		        switch (choice) {
		          case '1':
		          	Menu_4(ad,home);
		             break;
		          case '2':
		          	Menu_4(ad,educ);
		             break;
		          case '3':
		          	Menu_4(ad,games);
		             break;
		          case '4':
		          	Menu_4(ad,meeting);
		          	break;
		          case '5':
		          	return;
		          
		        }
		    } while (choice != '6'); 
		
		}
		// FUNCTION NAME: Menu_4()
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad, Tasks &tasks
		//
		// RETURN VALUE: none         
		//
		// CALLS TO: addHigh(), addMed(), addLow()
		//
		// CALLED FROM: Menu_3()
		//
		// METHOD:
		// 1. Prompt user to choose the choice from the display
		
		void Menu_4(accountDatabases *ad, Tasks &tasks){
			char choice;
	
			do {
		        printf(" _____________________________________________\n");
				printf("|               TO-DO LIST TRACKER            |\n");
				printf("|_____________________________________________|\n");
				printf("|               [1] High Priority             |\n");
				printf("|               [2] Medium Priority           |\n");
				printf("|               [3] Low Priority              |\n");
				printf("|               [4] Back                      |\n");
				printf("----------------------------------------------\n");

		        
		        printf("\nChoice: ");
		        choice=getchar();
		        getchar();
		        
		
		        switch (choice) {
		          case '1':
		          	tasks.addHigh(ad);
		             break;
		          case '2':
		          	tasks.addMed(ad);
		             break;
		          case '3':
		          	tasks.addLow(ad);
		             break;
		          case '4':
		            return;
		        
		        }
		    } while (choice != '5');
		    
	
		}
		

		
		// FUNCTION NAME: Menu_5()
		// CREDITS: Ivan Porcincula
		//           
		// PARAMETERS: accountDatabases *ad
		//
		// RETURN VALUE: none         
		//
		// CALLS TO: categorySorted(),storeTimeAndDate(),highPrioritySort(),medPrioritySort(),
		//			lowPrioritySort(),displayTaskPriority(), displayCateogry(), sortTimeAndDateHigh(),
		//			sortTimeAndDateMedium(), sortTimeAndDateLow()
		//
		// CALLED FROM: Menu_2()
		//
		// METHOD:
		// 1. Prompt user to choose the choice from the display
		
		
		void Menu_5(accountDatabases *ad){
			char choice;
			Home home;
			Education education;
			Games games;
			Meeting meeting;
			Tasks tasks;
			do {
		        printf(" _________________________________________________\n");
				printf("|               TO-DO LIST TRACKER                |\n");
				printf("|_________________________________________________|\n");
				printf("|        [1] Sort according to Date & Time        |\n");
				printf("|        [2] Sort according to Priority           |\n");
				printf("|        [3] Sort according to Category           |\n");
				printf("|   [4] Suggested order on accomplishing tasks    |\n");
				printf("|                  [5] Back                       |\n"); 
				printf("---------------------------------------------------\n");
				
		
		        printf("\nChoice: ");
		        choice=getchar();
		        getchar();
		        
		
		        switch (choice) {
		          case '1':
		          	ad->count2[0]={};
					ad->count3[0]={};
					ad->count4[0]={};
					ad->count2[0]=0;
					ad->count3[0]=0;
					ad->count4[0]=0;
		          	
		          	ad->count2[1]={};
					ad->count3[1]={};
					ad->count4[1]={};
					ad->count2[1]=0;
					ad->count3[1]=0;
					ad->count4[1]=0;
		          	
		          	ad->count2[2]={};
					ad->count3[2]={};
					ad->count4[2]={};
					ad->count2[2]=0;
					ad->count3[2]=0;
					ad->count4[2]=0;
		          	
		          	ad->count2[3]={};
					ad->count3[3]={};
					ad->count4[3]={};
					ad->count2[3]=0;
					ad->count3[3]=0;
					ad->count4[3]=0;
					
					/*the array initialization above is to clear the buffer memory of the array variables.
					  so that the program during the whole runtime, when a user logs out, the next user's variables
					  will not have the same memory to the previous user.*/
		          	
		          	 home.categorySorted(ad);
		          	 education.categorySorted(ad);
		          	 games.categorySorted(ad);
		          	 meeting.categorySorted(ad);
		          	 tasks.storeTimeAndDate(ad);
		          	 if(ad->count2[0]==0 && ad->count2[1]==0 && ad->count2[2] == 0 && ad->count2[3]==0 ){
					 	printf("No plans added yet. Add some now!\n\n");
					 }
		             break;
		          case '2':
		          	ad->count2[0]={};
					ad->count3[0]={};
					ad->count4[0]={};
					ad->count2[0]=0;
					ad->count3[0]=0;
					ad->count4[0]=0;
					
					/*the array initialization above is to clear the buffer memory of the array variables.
					  so that the program during the whole runtime, when a user logs out, the next user's variables
					  will not have the same memory to the previous user.*/
					
		          	tasks.highPrioritySort(ad);
		          	tasks.medPrioritySort(ad);
		          	tasks.lowPrioritySort(ad);
		          	tasks.displayTaskPriority(ad);
		          	
		          	if(ad->count2[0] == 0 && ad->count3[0] == 0  && ad->count4[0] == 0 ){
		          		printf("No plans added yet. Add some now!\n\n");
					  }
		             break;
		          case '3':
		          	ad->count2[0]={};
					ad->count3[0]={};
					ad->count4[0]={};
					ad->count2[0]=0;
					ad->count3[0]=0;
					ad->count4[0]=0;
		          	
		          	ad->count2[1]={};
					ad->count3[1]={};
					ad->count4[1]={};
					ad->count2[1]=0;
					ad->count3[1]=0;
					ad->count4[1]=0;
		          	
		          	ad->count2[2]={};
					ad->count3[2]={};
					ad->count4[2]={};
					ad->count2[2]=0;
					ad->count3[2]=0;
					ad->count4[2]=0;
		          	
		          	ad->count2[3]={};
					ad->count3[3]={};
					ad->count4[3]={};
					ad->count2[3]=0;
					ad->count3[3]=0;
					ad->count4[3]=0;
					
					/*the array initialization above is to clear the buffer memory of the array variables.
					  so that the program during the whole runtime, when a user logs out, the next user's variables
					  will not have the same memory to the previous user.*/
		          	 
					 home.categorySorted(ad);
		          	 education.categorySorted(ad);
		          	 games.categorySorted(ad);
		          	 meeting.categorySorted(ad);
		          	 if(ad->count2[0]!=0){
		          	 	home.displayCategory(ad);
					   }
					 if(ad->count2[1]!=0){
					 	education.displayCategory(ad);
					   }
					 if(ad->count2[2]!=0){
					 	games.displayCategory(ad);
					   }
					 if(ad->count2[3]!=0){
					 	meeting.displayCategory(ad);
					   }
					 if(ad->count2[0]==0 && ad->count2[1]==0 && ad->count2[2] == 0 && ad->count2[3]==0 ){
					 	printf("No plans added yet. Add some now!\n\n");
					 }
		             break;
		          case '4':
		          	ad->count2[0]={};
					ad->count3[0]={};
					ad->count4[0]={};
					ad->count2[0]=0;
					ad->count3[0]=0;
					ad->count4[0]=0;
					
					/*the array initialization above is to clear the buffer memory of the array variables.
					  so that the program during the whole runtime, when a user logs out, the next user's variables
					  will not have the same memory to the previous user.*/
					  
		          	tasks.highPrioritySort(ad);
		          	tasks.sortTimeAndDateHigh(ad);
		          	tasks.medPrioritySort(ad);
		          	tasks.sortTimeAndDateMedium(ad);
		        	tasks.lowPrioritySort(ad);
		        	tasks.sortTimeAndDateLow(ad);
		        	if(ad->count2[0] == 0 && ad->count3[0] == 0  && ad->count4[0] == 0 ){
		          		printf("No plans added yet. Add some now!\n\n");
					  }
		          	 break;
		          case '5':
		          	return;
		        }
		    } while (choice != '5');
		
		}

};

void promptWelcome();


int main(void){
	
	accountDatabases adType={0,0}; //initialize variable count and count1 
								   //set adType as structre accountDatabases
	promptWelcome(); 
	AllMenu allMenu; //object allMenu of class AllMenu
	allMenu.Menu_1(&adType); //pass adType as a parameter pointer to Menu_1() function
}




// FUNCTION NAME: Menu_5()
// CREDITS: Ivan Porcincula
//           
// PARAMETERS: none
//
// RETURN VALUE: none         
//
// CALLS TO: none
//
// CALLED FROM: int main()
//
// METHOD:
// 1. Display Welcome Message
void promptWelcome(){
				printf(" ______________________________________________\n");
				printf("|               TO-DO LIST TRACKER            |\n");
				printf("|_____________________________________________|\n");
				printf("|                    WELCOME                  |\n");
				printf("|                      TO                     |\n");
				printf("|              TO-DO LIST TRACKER             |\n");
				printf("|        Plan out your schedule properly!     |\n");
				printf("|                                             |\n"); 
				printf("|                 Created by:                 |\n");
				printf("|               Ivan Porcincula               |\n");  
				printf("-----------------------------------------------\n\n\n");
}






