/**
 * Copyright (c) 2018, Tiny Mesh AS - https://tiny-mesh.com
 * All rights reserved.
 */

#include "event-queue.h"
#include "debug.h"

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

int recv_byte(unsigned char c) {
  return 0;
}

void reset_input(void) {
}

int write_byte(char c) {
  return putchar(c);
}



void set_term_raw(void) {
  struct termios raw;

  tcgetattr(STDIN_FILENO, &raw);

  raw.c_lflag &= ~(ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
