#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
  if (!strcmp(argv[1], "pack") && argv[2]) {
    FILE *file;
    char str[128];

    if ((file = fopen(argv[2], "r")) == NULL) {
      printf("Cannot open file.\n");
    }
    while(!feof(file)) {
      if (fgets(str, 126, file))
        printf("%s", str);
    }
    fclose(file);
  } else {
    printf("pack <path to file> \n");
  }

  return 0;
}
