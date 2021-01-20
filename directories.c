#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

struct movie {
	char* title;
	int year;
	char** languages;
	double rating;
	struct movie *next;
	
	
};

struct movie * head = NULL;


struct movie * getMovies(char *argv[]){
	FILE *number = fopen(argv[1], "r");
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
		struct movie * ptr;
		getline(&nread, &len, number);

		while(getline(&nread, &len, number) != -1){
		
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
		if(token[0] == ','){
			token++;
			break;
		}
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
	
	DIR* currDir = opendir(".");
	struct dirent *aDir;















);
/****
Uses parts of the directories exploration.

****/ 
void get_smallest(struct dirent *aDir){
	Dir *opendir(".");
	while(readdir(opendir) != NULL){
		if(opendir
		
		
		
		
	}
	
	
	
	
}

void mk_directories(){
	int mkdir(const char * pathname, mode_t mode);








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
	if(!((n == 1) || (n == 2) || (n == 3)){
		error = 1;
		printf("Sorry need an integer 1-3! \n");

	}
	//printf("%d", n);
	}while(error == 1);
	

	if(n == 1){

		
		
		
	} 
			
	else if(n == 2){

		
	}
	else if(n == 3){
	

		
	}
	else{
	
		
		
		
	}
	}while(n != 4);
}