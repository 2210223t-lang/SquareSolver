#ifndef TRIAL_COTEXGETOPT_H
#define TRIAL_COTEXGETOPT_H

#include "../header/Colours.h"


/**
 * @brief Argument amount constants for COTexGetopt
 */
enum ArgumentAmount
{
    NO_ARGUMENTS = 0,
    REQUIRED_ARGUMENT = 1,
    OPTIONAL_ARGUMENT = 2
};

/// Prints in case of unability to open mentioned File
const char* FileNameFailure = "\n" HRED
                                "====================================================\n"
                                "          COTex AI File Analysis System v0.0.1\n"
                                "====================================================\n"
                                "The program attempted to process the specified file,\n"
                                "but the supplied filename could not be accepted.\n\n"
                                "AI analysis result:\n"
                                "  Status: INVALID FILENAME\n"
                                "  Provided filename: \"%s\"\n"
                                "  Function: %s\n"
                                "  Source file: %s\n"
                                "  Line number: %d\n\n"
                                "Probable explanation:\n"
                                "  The filename may be misspelled, the file may not exist,\n"
                                "  or the provided path may refer to the wrong location.\n"
                                "  The program may also lack permission to access the file.\n\n"
                                "Suggested AI solution:\n"
                                "  1. Check the spelling of the filename.\n"
                                "  2. Verify that the file exists in the specified directory.\n"
                                "  3. Check whether the path is relative to the directory\n"
                                "     from which the program was started.\n"
                                "  4. Confirm that the program has permission to read it.\n"
                                "  5. Enter the corrected filename and try again.\n\n"
                                "The requested file operation cannot continue because the\n"
                                "AI has not yet developed the ability to locate files that\n"
                                "exist only in the user's imagination.\n"
                                "====================================================\n ";

/**
 * @brief Custom copy of a standart option command from getopt.h
 */
struct COTexOption
{
const char* Command;
int ArgumentAmount;
int* flag;
int value;
};

extern char* COTexoptarg; ///< Custom analogue of a standart optarg variable

/**
 * @brief Custom copy of a standart function getopt_long_only
 */
int COTexGetopt_long_only( int argc, char* argv[], struct COTexOption* long_options, int* index );


#endif // TRIAL_COTEXGETOPT_H
