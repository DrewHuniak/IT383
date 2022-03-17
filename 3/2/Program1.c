#include <stdlib.h>
#include <stdio.h>
//Key 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
int main(){

FILE *file;
char *filename = "/tmp/dnhunia_foo";

file = fopen(filename, "w");
if (file == NULL){
  fprintf(stderr, "File %s could not be opened\n", filename);
  exit(1);
}

fprintf(file, "Hello World!\n");

fclose(file);

return 0;
}
