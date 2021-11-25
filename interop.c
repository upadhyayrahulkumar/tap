/**
 * Copyright (c) 2018, Tiny Mesh AS - https://tiny-mesh.com
 * All rights reserved.
 */

#include "event-queue.h"
#include "debug.h"

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#define INPUT_COMMAND_LEN    20

int recv_byte(unsigned char c) {

  static unsigned char buf[INPUT_COMMAND_LEN];
  static unsigned char nbytes = 0;
  event ev;

  if(nbytes < INPUT_COMMAND_LEN){
    buf[nbytes++] = c;
  }

  if ('\n' != c && 0 != c){
    return 0;
  }

  ev.type = event_input;
  ev.data = &buf;
  ev.size = nbytes;

  queue_insert(ev);
  nbytes = 0;
  return 1;
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
