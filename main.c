#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  char *action = argv[1];
  char *path = argv[2];

  if (!strcmp(action, "pack") && path) {
    FILE *input_file = fopen(path, "r");
    FILE *output_file = fopen("./workspace/output.vlc", "w+");

    char str[128];
    char *content, *new_content;

    if (input_file == NULL) {
      printf("Cannot open file.\n");
      exit(1);
    }

    content = fgets(str, 126, input_file);
    int i = 0;

    // while(content[i] != '\0') {
    //   if (content[i] == 'o') {
    //     printf("%c \n", content[i]);
    //   }
    //   i++;
    // }
    // fprintf(output_file, "%s", str);

    fclose(input_file);
  } else {
    printf("pack <path to file> \n");
    exit(1);
  }

  return 0;
}
