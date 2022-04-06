#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

//print num recursizely
void print_num(int num) {
  if (num < 10) {
    putch(num + '0');
  } else {
    print_num(num / 10);
    putch(num % 10 + '0');
  }
}

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  //panic("Not implemented");
  va_list ap;
  va_start(ap, fmt);
  char c; // the char to be printed at board
  char *p; // the pointer point at str to be print 
  int num; // the num to be print
  while ((c = *fmt++))
  {
    if (c != '%') {
      putch(c);
    } else {
      // last char is '%'
      switch (*fmt++)
      {
      case 'd':
        num = va_arg(ap, int);
        print_num(num);
        break;
      case 'c':
        putch(va_arg(ap, int));
        break;
      case 's':
        p = va_arg(ap, char *);
        while ((c = *p++)) {
          putch(c);
        }
        break;
      default:
        break;
      }
    }
  }
  va_end(ap);
  return 1;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  panic("Not implemented");
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
