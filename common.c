#include "common.h"

void
print_quoted_string(Eina_Stringshare *s, FILE *file)
{
        int i, n;
        i = 0;
        n = eina_stringshare_strlen(s);
        fprintf(file, "\"");
        while(i < n) {
                if(s[i] == '\"') fprintf(file, "\\\"");
//                else if(s[i] == '\n') fprintf(file, "\\n");
                else fprintf(file, "%c", s[i]);
                i++;
        }
        fprintf(file, "\"");
}

void
print_ml_variant_Eolian_Object_Scope(Eolian_Object_Scope x, FILE *file)
{
        fprintf(file, "Object_scope.");
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
      else {
              fprintf(file, "Some ");
              print_quoted_string(s, file);
      }
}

void
print_var_string(Eina_Stringshare *var, Eina_Stringshare *value, FILE *file)
{
        if(value == NULL) {
                fprintf(stderr, "%s should not be NULL\n", var);
                exit(1);
        }
        fprintf(file, "%s = ", var);
        print_quoted_string(value, file);
        fprintf(file, ";\n");
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

void
print_var_bool(Eina_Stringshare *var, Eina_Bool value, FILE* file)
{
        fprintf(file, "%s = ", var);
        if(value) fprintf(file, "true");
        else fprintf(file, "false");
        fprintf(file, ";\n");
}

