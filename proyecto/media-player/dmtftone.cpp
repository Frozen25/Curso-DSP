#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>
#include <math.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <stdio.h>
#include "dmtftone.h"



/* These are the audio card settings */
#define FREQ 44100
#define SAMPLES 8192
float sinPos;
float sinPos1;
float sinStep;
float senal1;
float senal2;
int Low,High;
/* This is basically an arbitrary number */
#define VOLUME 127.0


void populate(void* data, Uint8 *stream, int len) {

  int i=0;
  for (i=0; i<len; i++) {
    /* Just fill the stream with sine! */
    stream[i] = (Uint8) VOLUME*(0.5*sin(sinPos)+0.5*sin(sinPos1))+127;
    sinPos += senal1;
    sinPos1 += senal2;
  }
}

void dmtftone::DFTM(int Number){
  /* This will hold our data */
  SDL_AudioSpec spec;
  /* This will hold the requested frequency */
  /* This is the duration to hold the note for */


  if (Number==0){
      Low=941;
      High=1336;
    }

    if (Number== 1){
    Low=697;
    High=1209;}
    if (Number== 2){
    Low=697;
    High=1336;}
    if (Number== 3){
    Low=697;
    High=1336;}
    if (Number== 4){
    Low=770;
    High=1209;}
    if (Number== 5){
    Low=770;
    High=1336;}
    if (Number== 6){
    Low=770;
    High=1336;}
    if (Number== 7){
    Low=852;
    High=1209;}
    if (Number== 8){
    Low=852;
    High=1336;}
    if (Number== 9){
    Low=852;
    High=1336;}
    if  (Number==10){
    Low=697;
    High=1633;}
    if  (Number==11){
    Low=770;
    High=1633;}
    if  (Number==12){
    Low=852;
    High=1633;}
    if  (Number==13){
    Low=941;
    High=1633;}
    if  (Number==14){
    Low=1209;
    High=1633;}
    if  (Number==15){
    Low=941;
    High=1209;}


  /* Set up the requested settings */
  spec.freq = FREQ;
  spec.format = AUDIO_U8;
  spec.channels = 1;
  spec.samples = SAMPLES;
  spec.callback = (*populate);
  spec.userdata =0;

  /* Open the audio channel */
  if (SDL_OpenAudio(&spec, 0) < 0) {
    /* FAIL! */
    fprintf(stderr, "Failed to open audio: %s \n", SDL_GetError());
    exit(1);
  }

   /* Initialize the position of our sine wave */
  sinPos = 0;
  /* Calculate the step of our sin wave */
  senal1=2*M_PI*Low/FREQ;
  senal2=2*M_PI*High/FREQ;

  /* Now, run this thing */
  SDL_PauseAudio(0);
  /* Delay for the requested number of seconds */
  sleep(1);
  /* Then turn it off again */
  SDL_PauseAudio(0);

  /* Close audio channel */
  SDL_CloseAudio();

}
