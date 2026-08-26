#ifndef TRIAL_COTEXGETOPT_H
#define TRIAL_COTEXGETOPT_H

enum ArgumentAmount{ NO_ARGUMENTS = 0, REQUIRED_ARGUMENT = 1, OPTIONAL_ARGUMENT = 2 };

struct COTexOption
{
const char* Command;
int ArgumentAmount;
int* flag;
int value;
};

int COTexGetopt_long_only( int argc, char* argv[], struct COTexOption* long_options, int* index );

extern char* COTexoptarg;

#endif // TRIAL_COTEXGETOPT_H
