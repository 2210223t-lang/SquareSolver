#ifndef TRIAL_COTEXSPEECH_H
#define TRIAL_COTEXSPEECH_H
#include "Colours.h"

const char GOOD_MOOD[] = "\"<---Unfortunately you've enterred wrong variable, "
                         "I hope that you will try again and your next trial would be better :)\n";
const char NEUTRAL_MOOD[] = "\"<---I guess that you'have woken up on the wrong side of the bed,"
                            " 'cause you've enterred incorrect data, try again please \n";

const char ANGRY_MOOD[] = "\"<---Are you kidding me, that's too much how you can make mistakes even in such trivial task,"
                          " this is you last attempt! Type variable:\n";

const char FURY_MOOD[] = "\"<---You don't believe me, that i'll stop running after one more mistake?" RED "Enter your variable:\n" reset ;

const char FRIED_MOOD[] = "\"<---I'm fried, " HRED " Fuck out!!!" reset;

enum mood{ GOOD = 4, NEUTRAL = 3, ANGRY = 2, FURY = 1, FRIED = 0 };

#endif // TRIAL_COTEXSPEECH_H
