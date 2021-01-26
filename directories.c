#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>  

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
		printf("%s", nread);
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
	char * f;
	
	


	/*
	struct dirent *aDir;
*/
	int size;
	struct movie * first;
	//get_smallest(currDir, &file);
	printf("what is the file: %s", file);
	//head = getMovies(file, &size);
	
	printf("What is size in MAIN: %d \n", size);

	
	getInput();

	//num_years = get_num_years(head, size, array);
	









}
/****
Uses parts of the directories exploration.

****/ 
void get_smallest(char ** file){
	DIR* currDir = opendir(".");
	if(currDir == NULL){
		printf("error opening directory");
		
	}
	// char * file = NULL;
	struct stat dirStat;
	struct dirent * dir = readdir(currDir);
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
	dir = readdir(currDir);
	printf("what is the file_name %s \n", min);
	
	}
	*file = malloc(strlen(min)+1);
	strcpy(*file, min);
	closedir(currDir);
	
	
}

void get_largest(char ** file){
	DIR* currDir = opendir(".");
	if(currDir == NULL){
		printf("error opening directory");
		
	}
	// char * file = NULL;
	struct stat dirStat;
	struct dirent * dir = readdir(currDir);
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
	dir = readdir(currDir);
	printf("what is the file_name %s \n", min);
	
	}
	*file = malloc(strlen(min)+1);
	strcpy(*file, min);
	closedir(currDir);
	
	
}


int * get_num_years(struct movie * head, int size, int * c){
		
    int * array = (int *) malloc(size * sizeof(int));

	struct movie * first; 
	
	int curr_year;
	
	struct movie * temp = NULL;
	
	char * title = NULL;
	first = head;
	int s = size;
	printf("the size is: %d", size);
	
	
	int year_marked = 0;
	int count = 0;
	first = head;
 	for(int i = 0; i < size; i++){
				array[i] = 0;
				
			}
	for(int x = 0; x < size; x++){
	
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
	*c = count;
	return array;
	
}


void mk_directory(int num_years, int * array){
	int fd;
	int curr_year;
	int count;
	int year_marked;
	struct movie * first;
	srand(time(NULL));
	int random = rand() % 10000;
	printf("random %d \n", random);
	char * r;
	char file_x[5] = ".txt";
	char * file_s;
	char * year;
	char * t;

	//char * r = (char *) malloc(sizeof(char) * (sizeof(random)/ sizeof(int)));
	//r = itoa(random, r, 10); 
	const char dir_name[19]= "hajl_movies.movies.";
	char * pathname;
	//char * int_to_char = (char)random;
	
	//pathname = strcat(name, r);
	//printf("pathname is %s", pathname);
	sprintf(&r, "%d", random);
	pathname = strcat(dir_name, &r);
	mkdir(pathname, 0750);
	int cdir = chdir(pathname);
	for(int i = 0; i < num_years; i++){
	sprintf(&file_s, "%d", array[i]);
	printf("string %s:", &file_s);
	year = strcat(&file_s, ".txt");
	printf("file_s %s", &file_s);
	fd = open(year, O_RDWR | O_CREAT | O_APPEND, 0640);
	if(fd < 0){
		printf("error");
	}
		first = head;
		while(head != NULL){
			if(head->year == array[i]){
			int written = write(fd, head->title, strlen(head->title));
			written = write(fd, "\n", sizeof(char));
			}
			head = head->next;
			
			
	}
	close(fd);
		head = first;
	}
	chdir("..");

}






int getInput(){
	int n;
	int n_yrs = 0;
	int error = 0;
	int file_err = 0;
	FILE * number; 
	char * file = NULL;
	int size = 0;
	char * f;
	int first_menu = 0;
	int * a;
	struct movie * first;
	char ** lang;
	do{
	printf("1. Select file to process \n");
	printf("2. Exit the program \n");
	printf("Enter a choice 1 or 2: \n");
	scanf("%d", &first_menu);
	if(first_menu == 2){
		free(a);
		while(head !=NULL){
		first = head;
		free(head->title);
		
		
		lang = head->languages;
			free(lang);
			
		
		free(first);
		head = head->next;
	}
		exit(1);
		
	}
	do{
	error = 0;
	printf("Which file you want to process? \n");
	printf("Enter 1 to pick the largest file \n");
	printf("Enter 2 to pick the smallest file \n");
	printf("Enter 3 to specify the name of a file \n");
	printf("Enter a choice from 1 to 3: \n");
	scanf("%d", &n);

	
	if(n == 1){
	get_largest(&file);

	head = getMovies(file, &size, &file_err);
	printf("Now processing the chosen file named %s", file);

	free(file);
	 a = get_num_years(head, size, &n_yrs);
	mk_directory(n_yrs, a);
		size = 0;
	n_yrs = 0; 

	//head = NULL;
	}
	else if(n == 2){
	get_smallest(&file);
	head = getMovies(file, &size, &file_err);
	printf("Now processing the chosen file named %s", file);
	free(file);
	 a = get_num_years(head, size,&n_yrs);
	mk_directory(n_yrs, a);
	n_yrs = 0;
		size = 0;

 
		
	}
	else if(n == 3){
	
	int found = 0;
	  printf("what is the name of the file? \n");
	
	scanf("%s", &f);
	
	int fd = open(&f, O_RDWR);
	printf("fd is: %d", fd);
	if(fd < 0){
		printf("No such file \n");
		file_err = 1;
		close(fd);

		
	}
	else{
		file_err = 0;
		close(fd);
	printf("Now processing the chosen file named %s \n ", &f);
 

 
	head = getMovies(&f, &size, &file_err);
	a = get_num_years(head, size, &n_yrs);
	mk_directory(n_yrs, a);
		n_yrs = 0;
		size = 0;
	}
	}
	}while(file_err == 1);
	
	}while(first_menu == 1);
}