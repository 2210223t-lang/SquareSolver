#ifndef TRIAL_COTEXUTILITY_H
#define TRIAL_COTEXUTILITY_H

/**
 * @brief Immitates a loading process of AI
 *
 * @param[ out ] Text const char* Text what should be loading
 *
 * @param time int time how many times loading needs to be visualised
 */
void Thinking( const char* Text, int time );

/**
 * @brief Prints all available functions that COTex have now
 */
void PrintAIFunctions();

/**
 * @brief Prints sentence by one letter
 *
 * @param[ out ] text const char* text is a sentence that must be printed
 *
 * @param colour const char* colour One of the colours' codes const, defined in Colours.h
 */
void PrintAI( const char* text, const char* colour );

#endif // TRIAL_COTEXUTILITY_H
