//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"",    "sb-forecast",					                                    60,		 0},
	{"",    "sb-cpu",					                                          60,		 0},
	{"",    "sb-internet",					                                     5,		 0},
	{"",    "sb-battery",					                                      60,		 0},
	{"",    "sb-clock",					                                         5,		 0},
	{"",    "sb-volume",					                                       0,		10},
	{"",    "sb-help-icon",					                                     0,		15},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 5;
