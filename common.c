#include "common.h"

void
print_string_option(Eina_Stringshare *s, FILE *file)
{
      if(s == NULL) fprintf(file, "None");
      else fprintf(file, "Some \"%s\"", s);
}

void
print_var_string(
        Eina_Stringshare *var,
        Eina_Stringshare *value,
        FILE *file)
{
        if(value == NULL) {
                fprintf(stderr, "%s should not be NULL\n", var);
                exit(1);
        }
        fprintf(file, "%s = \"%s\";\n", var, value);
}
 
void
print_var_string_opt(
        Eina_Stringshare *var,
        Eina_Stringshare *value,
        FILE             *file)
{
        fprintf(file, "%s = ", var);
        print_string_option(value, file);
        fprintf(file, ";\n");
}

