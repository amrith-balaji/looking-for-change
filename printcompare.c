#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	FILE* snpptr;
	FILE* resultsptr;
	char needle[500];
	char haystack[500];
	char str[500];
	char* token;
	char* ret;
	char* result;
	char* lastcall;
	char* lastrank;
	int res	;
	int lastres = 0;
	int flag = 0;	
	int compareflag = 0;	
	snpptr = fopen("snp.txt","r");
	if (snpptr == NULL) {
		printf("file not found\n");
		return 1;
	}
	resultsptr = fopen("results.txt","r");
	if (resultsptr == NULL) {
		printf("file not found\n");
		return 1;
	}
	fclose(resultsptr);
	while (fgets(needle,500,snpptr) != NULL) {
		needle[strlen(needle)-1] = '\0';
		resultsptr = fopen("results.txt","r");
		if (resultsptr == NULL) {
			printf("file not found\n");
			return 1;
		}
		printf("%s : \n", needle);
		while (fgets(haystack,500,resultsptr) != NULL) {
			haystack[strlen(haystack)-1] = '\0';
			ret = strstr(haystack,needle);
			if (ret != NULL) {
				token = strtok(haystack , "|");
				printf("%s  ",token);
				token = strtok(NULL , "|");
				token = strtok(NULL , "|");
				printf("%s  ",token);
				token = strtok(NULL , "|");
				printf("%s  ",token);
				token = strtok(NULL , "|");
				printf("%s\n",token);
				if (flag > 2) {
					res = strcmp(token,lastrank);
					//printf("res : %d",res);
					//printf("lastres : %d",lastres);	
					}
				if (flag > 2) {
					if (res - lastres == 0) {
						compareflag = 0;
					}
					else {
						compareflag = 1;
					}
					//printf("comap : %d",compareflag);
					//printf("dif : %d",res - lastres);
				}
				if  (flag > 2 ) {
					strcpy(token,lastrank);
					lastres = res;
				}
				flag = flag + 1;
			}
		}
		if (compareflag == 0) {
 	               printf("\n");
                	printf("^^^^^No change\n");
          	}
          	else {
                	printf("\n");
        	       printf(">>>>>there is a change\n");
          	}
	fclose(resultsptr);
	}	
return 0;
}
