#ifdef nDEBUG_AI

#define COTexAssert( condition ) continue;

#endif


#ifndef TRIAL_COTEXASSERT_H
#define TRIAL_COTEXASSERT_H
#include <stdlib.h>

#define COTexAssert( condition )                                           \
    do {                                                                   \
        if (!(condition)) {                                                \
            fprintf(stderr, HRED                                           \
                "\n"                                                       \
                "====================================================\n"   \
                "       COTex AI Diagnostic System v0.0.1\n"               \
                "====================================================\n"   \
                "Unfortunately, the program encountered a condition\n"     \
                "that it was emotionally and technically unprepared\n"     \
                "to process.\n\n"                                          \
                "AI analysis result:\n"                                    \
                "  Status: CRITICAL FAILURE\n"                             \
                "  Failed condition: %s\n"                                \
                "  Function: %s\n"                                        \
                "  Source file: %s\n"                                     \
                "  Line number: %d\n\n"                                   \
                "Probable explanation:\n"                                  \
                "  A required pointer may be NULL, an assumption may\n"    \
                "  be incorrect, or reality may have refused to follow\n"  \
                "  the programmer's expectations.\n\n"                     \
                "Suggested AI solution:\n"                                 \
                "  1. Inspect the failed condition.\n"                     \
                "  2. Check all relevant pointers and arguments.\n"        \
                "  3. Question every decision that led to this moment.\n"  \
                "  4. Fix the bug and pretend this never happened.\n\n"    \
                "The program will now terminate to prevent further\n"      \
                "damage and unnecessary consumption of your tokens.\n"     \
                "====================================================\n",  \
                #condition, __func__, __FILE__, __LINE__);                 \
            abort();                                                       \
        }                                                                  \
    } while (0)

#endif // TRIAL_COTEXASSERT_H
