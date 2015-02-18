#include "common.h"

void
print_ml_variant_Eolian_Object_Scope(Eolian_Object_Scope x, FILE *file)
{
        fprintf(file, "Object_Scope.");
        switch(x) {
        case EOLIAN_SCOPE_PUBLIC:
                fprintf(file, "Public");
                break;
        case EOLIAN_SCOPE_PRIVATE:
                fprintf(file, "Private");
                break;
        case EOLIAN_SCOPE_PROTECTED:
                fprintf(file, "Protected");
                break;
        }
}

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

