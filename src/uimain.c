#include <stdio.h>


int main() {
  char input[20];

  
  printf("Please enter your first name");

  fgets(input, sizeof(input), stdin);
  printf("%s", input);
}
