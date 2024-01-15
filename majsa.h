#ifndef MAJSA_H
#define MAJSA_H

#include "Trans.h"
#include "AgariChecker.h"
#include "YakuChecker.h"

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif // STDLIB_H

#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif // STRING_H

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif // STDIO_H

Result *majsa(Status *);

#endif // MAJSA_H