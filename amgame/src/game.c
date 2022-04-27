#include <game.h>
#include <string.h>

// Operating system is a C program!
int main(const char *args) {
  ioe_init();

  puts("mainargs = \"");
  puts(args); // make run mainargs=xxx
  puts("\"\n");

  splash();
  char str[] = "hello world";
  printf("before is %s\n", str);
  memset(str, 'f', strlen(str));
  printf("atfer is %s\n", str);
  puts("Press any key to see its key code...\n");
  while (1) {
    print_key();
  }
  return 0;
}
