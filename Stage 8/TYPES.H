#ifndef TYPES_H
#define TYPES_H

#define ASTEROID_HEIGHT 8
#define SPACESHIP_HEIGHT 32
#define NUMBER_HEIGHT 32
#define HEART_HEIGHT 16
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define FIRST_DIGIT 550
#define SECOND_DIGIT 580
#define THIRD_DIGIT 610
#define SCORE_ROW 15
#define HEART_ROW 55
#define w 119
#define s 115
#define ESC 27
#define SPACE 32
#define FALSE 0
#define TRUE 1
#define NO_INPUT -1
#define BUFFER_SIZE 32000
#define ALIGNMENT 256
#define MAX_ASTEROID_SPEED 10
#define MIN_ASTEROID_SPEED 2
#define MAX_ASTEROIDS 33
#define TEST_DURATION 3000
#define MELODY_LENGTH 31
#define BLACK 1
#define WHITE 0
#define VIDEO_BASE_HIGH ((volatile UINT8 *)0xFFFF8201)
#define VIDEO_BASE_MID  ((volatile UINT8 *)0xFFFF8203)

typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;

#endif
