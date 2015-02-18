#ifndef COMMON_H
#define COMMON_H

#define EFL_BETA_API_SUPPORT

#include <Eolian.h>

extern void
print_string_option(Eina_Stringshare *s, FILE *file);

extern void
print_var_string(Eina_Stringshare *var, Eina_Stringshare *value, FILE* file);

extern void
print_var_string_opt(
        Eina_Stringshare *var,
        Eina_Stringshare *value,
        FILE* file);

#endif

