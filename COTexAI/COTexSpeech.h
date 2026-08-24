#ifndef TRIAL_COTEXSPEECH_H
#define TRIAL_COTEXSPEECH_H
#include "../header/Colours.h"

const char GOOD_MOOD[] = "\"" HCYN "<---Unfortunately you've enterred wrong variable, "
                         "I hope that you will try again and your next trial would be better :)\n" reset;
const char NEUTRAL_MOOD[] = "\"" CYN "<---I guess that you'have woken up on the wrong side of the bed,"
                            " 'cause you've enterred incorrect data, try again please \n" reset;

const char ANGRY_MOOD[] = "\"" HCYN "<---Are you kidding me, that's too much. How you can make mistakes even in such trivial task,"
                          " this is you last attempt! \nType variable: " reset;

const char FURY_MOOD[] = "\"" HCYN "<---You don't believe me, that i'll stop running after one more mistake?" HRED "\nEnter your variable: " reset ;

const char FRIED_MOOD[] = "\"" HCYN "<---I'm fried, " HRED " FUCK OUT!!!" reset;

enum mood{ GOOD = 4, NEUTRAL = 3, ANGRY = 2, FURY = 1, FRIED = 0 };

#endif // TRIAL_COTEXSPEECH_H
