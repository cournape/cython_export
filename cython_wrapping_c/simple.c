#include <stdio.h>

#include "simple.h"

static const char _VERSION[] = "0.0.1";

void PySimple_Hello(const char* message)
{
    printf("%s\n", message);
}

const char* PySimple_GetVersion(void)
{
    return _VERSION;
}
