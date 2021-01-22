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


struct movie * getMovies(char * file, int * size){
	
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
		size++;
		struct movie *ptr = (struct movie *) malloc(sizeof(struct movie));

	//lseek(fp, 1, SEEK_SET);
	
	int i = 1;
				printf("The pointer is: %d \n", *ptr);

		printf("%s", nread);
		token = strtok(nread, ",");
		ptr->title = malloc(strlen(token) + 1);
		strcpy(ptr->title, token);
		printf("The title is: %s \n", ptr->title);
		token = strtok(NULL, ",");
		ptr->year = atoi(token);
		printf("The year is: %d \n", ptr->year); 
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
	
		printf("The language(s): %s \n", array[y]);

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
		printf("The title is 100: %s \n",  head->title);

		
		
		
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
	struct movie * first;

	get_smallest(currDir, &file);
	printf("what is the file: %s", file);
	head = getMovies(file, &size);

	int * array = (int *) malloc(size * sizeof(int));
	


	get_num_years(head, size, array);



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

int get_num_years(int y, struct movie * head, int size, int * array){
		
               
	struct movie * first; 
	
	int curr_year = 0;
	
	double max_rating = 0.0;
	struct movie * temp = NULL;
	
	int max_year = 0;
	char * title = NULL;
	//struct movie * head_ratings;
	first = head;
	int s = size;
	
	
	/* for(int i = 0; i < size; i++){
				array[i] = 0;
				
			} */
	int year_marked = 0;
	int count = 0;
	first = head;
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
		//head = temp;
		
			head = head->next; 
		year_marked = 0;
	
		
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







int getInput(struct movie * head, int size){
	int n;
	int error = 0;
	do{
	do{
	printf("Which file you want to process? \n");
	printf("Enter 1 to pick the largest file \n");
	printf("Enter 2 to pick the smallest file \n");
	printf("Enter 3 to specify the name of a file \n");
	printf("Enter a choice from 1 to 3: \n");





	scanf("%d", &n);
	error = 0;
	if(!((n == 1) || (n == 2) || (n == 3))){
		error = 1;
		printf("Sorry need an integer 1-3! \n");

	}
	//printf("%d", n);
	}while(error == 1);
	

	if(n == 1){

		
		
		
	} 
			
	else if(n == 2){

		
	}
	else{
	
		
		
		
	}
	}while(n != 2);
}