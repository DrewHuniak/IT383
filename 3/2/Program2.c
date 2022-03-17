#include <stdlib.h>
#include <stdio.h>

int main()
{
  FILE *file;
  char *filename = "/tmp/dnhunia_foo";

  file = fopen(filename, "r");
  if(file == NULL)
  {
    fprintf(stderr, "File %s could not be opened\n", filename);
    exit(1);
  }

  while(1)
  {
    char buffer[80];
    fgets(buffer, 80, file);

    if(feof(file))
    {
      break;
    }
    printf("%s", buffer);
  }

  fclose(file);

  return 0;
}
