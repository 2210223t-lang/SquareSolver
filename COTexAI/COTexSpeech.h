#ifndef TRIAL_COTEXSPEECH_H
#define TRIAL_COTEXSPEECH_H

/**
 * @brief Mood sentemce, for the 1st mistake
 */
#define GOOD_MOOD "<---Unfortunately you've enterred wrong variable. \n"\
                    "I hope that you will try again and your next trial would be better :)\n"

/**
 * @brief Mood sentence for the 2nd mistake
 */
#define NEUTRAL_MOOD "<---I guess that you'have woken up on the wrong side of the bed,"\
                       " 'cause you've enterred incorrect data.\n Try again please: "

/**
 * @brief Mood sentence for the 3rd mistake
 */
#define ANGRY_MOOD "<---Are you kidding me, that's too much. How you can make mistakes even in such trivial task.\n"\
                      "This is you last attempt! \nType variable: "

/**
 * @brief Mood sentence for the 4th mistake */
#define FURY_MOOD "<---You don't believe me, that i'll stop running after one more mistake?"\
                  "\nEnter your variable: "

/**
 * @brief Mood flags, that are used in MistakesReaction
 */
enum mood{ GOOD = 4, NEUTRAL = 3, ANGRY = 2, FURY = 1, FRIED = 0 };

#endif // TRIAL_COTEXSPEECH_H
