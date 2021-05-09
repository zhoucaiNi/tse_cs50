/*
 * 
 * indextest.c
 *
 */


 #include <stdlib.h>
 #include <stdio.h>
 #include "index.c"
 #include "file.h"

 static void parseArgs(const int argc, char* argv[], char** oldFileName, char** newFileName);
 
int main(const int argc, const char* argv[]){

char** oldFileName = NULL;
char** newFileName = NULL; 

parseArgs(argc, argv, oldFileName, newFileName);
index_t* index = file2index(&oldFileName);
index_save(index, &newFileName);
index_delete(index);

}


static void parseArgs(const int argc, char* argv[], char** oldFileName, char** newFileName){

if(argc != 3){
  fprintf("invalid arguments | valid format: ./indextest oldFileName newFileName");
  exit(1);
} else {
  FILE *fp;
    if((fp = fopen(argv[2], "r") ) != NULL){
      *oldFileName = argv[2];
      fclose(fp);
      // 
    } else {
      free(*oldFileName);
      fprintf(stderr, "invalid oldFileName\n");
      exit(2);
    }

    if((fp = fopen(argv[3], "w") ) != NULL){
      *newFileName = argv[2];
      fclose(fp);
      // 
    } else {
      free(*oldFileName);
      fprintf(stderr, "invalid newFileName\n");
      exit(3);
    }

}

}


