#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
  char *action = argv[1];
  char *path = argv[2];

  if (!strcmp(action, "pack") && path) {
    FILE *input_file = fopen(path, "r");
    FILE *output_file = fopen("./workspace/output.vlc", "w+");

    regex_t regex;
    int reti;

    char str[128];
    char *content, *new_content;

    if (input_file == NULL) {
      printf("Cannot open file.\n");
      exit(1);
    }

    content = fgets(str, 126, input_file);
    int i = 0;
    int k = 0;
    char upper_formated[128];

    while(content[i] != '\0') {
      char symb[1];
      char upper[2] = "!";
      *symb = content[i];

      reti = regcomp(&regex, "[A-Z]", 0);
      reti = regexec(&regex, symb, 0, NULL, 0);
      if (!reti) {
        upper_formated[k] = '!';
        upper_formated[k + 1] = tolower(*symb);
        k += 2;
      } else {
        upper_formated[k] = content[i];
        k++;
      }
      i++;
    }
    printf("%s", upper_formated);

    fclose(input_file);
  } else {
    printf("pack <path to file> \n");
    exit(1);
  }

  return 0;
}
