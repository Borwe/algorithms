#ifndef NAME_OF_FILE

//for windows OS
#ifdef _WIN32
#ifdef DYNAMIC_DLL
#define DYNAMIC_SPEC __declspec(dllexport)
#else
#define DYNAMIC_SPEC __declspec(dllimport)
#endif
#endif

//meaning probably not on windows os
#ifndef DYNAMIC_DLL
#define DYNAMIC_SPEC  
#endif

#endif
