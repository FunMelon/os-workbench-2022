#include <game.h>
#include <string.h>

// Operating system is a C program!
int main(const char *args) {
  ioe_init();

  puts("mainargs = \"");
  puts(args); // make run mainargs=xxx
  puts("\"\n");

  splash();
  char str[5] = "hello";
  printf("before is %s", str);
  memset(str, 0, 1);
  printf("%s", str);
  puts("Press any key to see its key code...\n");
  while (1) {
    print_key();
  }
  return 0;
}
