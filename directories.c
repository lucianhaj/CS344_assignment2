#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>


#define PREFIX "movies_"

struct movie {
	char* title;
	int year;
	char** languages;
	double rating;
	struct movie *next;
	
	
};

struct movie * head = NULL;


struct movie * getMovies(char * file, int * size, int * err){
	
	FILE *number = fopen(file, "r");
	if(number == NULL){
		*err = 1;
		
	}
	char * nread;
	size_t len = 0;
	struct movie * beginning;
	char **array;
	int y;
	char * token;
	char * token2;
	//	struct movie * b;

	//n = getInput();
	struct movie * first;
	char * t;
//	const struct movie First;
	char ** pn;
	pn = &nread;
	struct movie Movie;
	int greater_than = 0;
		struct movie * ptr;
	
		getline(&nread, &len, number);

		while(getline(&nread, &len, number) != -1){
		*size = *size + 1;
		struct movie *ptr = (struct movie *) malloc(sizeof(struct movie));

	//lseek(fp, 1, SEEK_SET);
	
	int i = 1;
			//	printf("The pointer is: %d \n", *ptr);

		//printf("%s", nread);
		token = strtok(nread, ",");
		ptr->title = malloc(strlen(token) + 1);
		strcpy(ptr->title, token);
		//printf("The title is: %s \n", ptr->title);
		token = strtok(NULL, ",");
		ptr->year = atoi(token);
		//printf("The year is: %d \n", ptr->year); 
		array = (char **) malloc(5 * sizeof(char *));
		y=0;

		while(token != NULL){
		//ptr->languages[y] = &token;
		token = strtok(NULL, "[ ; ]");
		//if(greater_than == 1){
		if(token[0] == ','){
			token++;
			break;
		}
		//}
		greater_than = 1;
		array[y] = malloc(strlen(token) +1);
		strcpy(array[y], token);
	
		//printf("The language(s): %s \n", array[y]);

		y++;
		
		}

		//getline(&nread, &len, fp);
		//token = strtok(nread, ",");
		//token = strtok(NULL,",");

	    ptr->rating = atof(token);
		ptr->languages = array;
		y= 0;
	
		ptr->next = head;
		head = ptr;
		//printf("The title is 100: %s \n",  head->title);

		
		
		
	}
	return head;
		// add languages

//	free(nread);
	//*/


}






main(int argc, char *argv[]){ 
	const char* pathname;
	char * file;

	
	DIR* currDir = opendir(".");
	if(currDir == NULL){
		printf("error opening directory");
		
	}


	/*
	struct dirent *aDir;
*/
	int size;
	int num_years;
	struct movie * first;
	//get_smallest(currDir, &file);
	printf("what is the file: %s", file);
	head = getMovies(file, &size);
	
	printf("What is size in MAIN: %d \n", size);

	int * array = (int *) malloc(size * sizeof(int));
	


	num_years = get_num_years(head, size, array);



	closedir(currDir);








}
/****
Uses parts of the directories exploration.

****/ 
void get_smallest(DIR * Opened, char ** file){
	// char * file = NULL;
	struct stat dirStat;
	struct dirent * dir = readdir(Opened);
	struct dirent * min;
	min = dir;
	char buffer[256];
	int smallest = 1000000;
	char * extension = ".csv";
	char * pch = NULL;
	char * directory_name = NULL;
	while(dir != NULL){
		
		
		directory_name = &(dir->d_name);
	
	pch = strstr(directory_name, extension);
	if(pch != NULL){

	
		stat(dir->d_name, &dirStat);
		if((dirStat.st_size < smallest) && strncmp(PREFIX, dir->d_name, strlen(PREFIX)) == 0){
		min = malloc(sizeof(dir->d_name));
		min = dir->d_name;
		smallest = dirStat.st_size; 
		}
		
	}
	dir = readdir(Opened);
	printf("what is the file_name %s \n", min);
	
	}
	*file = malloc(strlen(min)+1);
	strcpy(*file, min);
	
	
	
}

void get_largest(DIR * Opened, char ** file){
	// char * file = NULL;
	struct stat dirStat;
	struct dirent * dir = readdir(Opened);
	struct dirent * min;
	min = dir;
	char buffer[256];
	int largest = -1;
	char * extension = ".csv";
	char * pch = NULL;
	char * directory_name = NULL;
	while(dir != NULL){
		
		
		directory_name = &(dir->d_name);
	
	pch = strstr(directory_name, extension);
	if(pch != NULL){

	
		stat(dir->d_name, &dirStat);
		if((dirStat.st_size > largest) && strncmp(PREFIX, dir->d_name, strlen(PREFIX)) == 0){
		min = malloc(sizeof(dir->d_name));
		min = dir->d_name;
		largest = dirStat.st_size; 
		}
		
	}
	dir = readdir(Opened);
	printf("what is the file_name %s \n", min);
	
	}
	*file = malloc(strlen(min)+1);
	strcpy(*file, min);
	
	
	
}
char * get_input_file(){
	// char * file = NULL;
	char * file;
	printf("what is the name of the file? \n");
	scanf("%s", &file);
	return file;
	
	
	
}

int get_num_years(struct movie * head, int size, int * array){
		
               
	struct movie * first; 
	
	int curr_year;
	
	struct movie * temp = NULL;
	
	char * title = NULL;
	//struct movie * head_ratings;
	first = head;
	int s = size;
	printf("the size is: %d", size);
	
	/* for(int i = 0; i < size; i++){
				array[i] = 0;
				
			} */
	int year_marked = 0;
	int count = 1;
	first = head;
	printf("What is head: %p", head);
	for(int i = 0; i < size; i++){
				array[i] = 0;
				
			}
	while(head != NULL){
	//temp = head;
	
		curr_year = head->year;
	for(int i = 0; i < size; i++){
				if(array[i] == curr_year){
					year_marked = 1;
				}
				
			}
	
		
		if(year_marked == 0){
			array[count] = curr_year;
			count++;
	
		}
		else{
			year_marked = 0;
		}
		//head = temp;
		
			head = head->next; 
	
		
	} 
	head = first;
	printf("the count is: %d", count);
	return count;
	//*/
}

void mk_directories(struct movie * head, int num_years, int size){
	int fd;
	int curr_year;
	int count;
	int year_marked;
		int s = size;

	char * newFile;
	const char * pathname = "hajl_movies";

	mkdir(pathname, 0750);

	
	fd = open(newFile, O_RDWR | O_CREAT);
			



	}







int getInput(DIR* currDir, struct movie * head){
	int n;
	int error = 0;
	int file_err = 0;
	char * file = NULL;
	int size;
	int first_menu = 0;
	do{
	printf("1. Select file to process \n");
	printf("2. Exit the program \n");
	printf("Enter a choice 1 or 2: \n");
	scanf("%d", &first_menu);
	
	do{
	file_err = 0;
	error = 0;
	printf("Which file you want to process? \n");
	printf("Enter 1 to pick the largest file \n");
	printf("Enter 2 to pick the smallest file \n");
	printf("Enter 3 to specify the name of a file \n");
	printf("Enter a choice from 1 to 3: \n");
	scanf("%d", &n);
	if(n == 1){
	get_largest(currDir, &file);
	head = getMovies(file, &size, &file_err);
		
	} 
			
	else if(n == 2){
	get_smallest(currDir, &file);
	head = getMovies(file, &size, &file_err);

		
	}
	else if(n == 3){
	file = get_input_file();
	head = getMovies(file, &size, &file_err);

		
	}
	else{
		printf("incorrect input");
		error = 1;
	}
	}while(file_err == 1 || error == 1);
		
	
	}while(first_menu == 1);
}