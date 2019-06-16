#ifndef DMTFTONE_H
#define DMTFTONE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>
#include <math.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <stdio.h>
#include "mainwindow.h"

class dmtftone:public MainWindow{

public:
  /**
   * Constructor
   */
    dmtftone();
    /**
     * Tone Generator Function
     */
     static void DFTM(int Number);
    /**
     * Play Tone Function
     */
    ~dmtftone();

};
#endif // DMTFTONE_H
