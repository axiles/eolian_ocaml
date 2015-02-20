#include "common.h"

extern void
print_function(const Eolian_Function *f, const Eolian_Class *cl, FILE *file);

static void
print_full_name(const Eolian_Constructor *ctor, FILE *file)
{
        print_var_string("Constructor.full_name",
                eolian_constructor_full_name_get(ctor), file);
}

/* TODO: eolian_constructor_class_get ? */

static void
print_ctor_function(const Eolian_Constructor *ctor, FILE *file)
{
        const Eolian_Function *f;
        f = eolian_constructor_function_get(ctor);
        fprintf(file, "func = ");
        if(f == NULL) fprintf(file, "None");
        else {
                fprintf(file, "Some ");
                print_function(f, eolian_constructor_class_get(ctor), file);
        }
        fprintf(file, ";\n");
}

static void
print_optional(const Eolian_Constructor *ctor, FILE *file)
{
        print_var_bool("optional", eolian_constructor_is_optional(ctor), file);
}

void
print_constructor(const Eolian_Constructor *ctor, FILE *file)
{
        fprintf(file, "{\n");
        print_full_name(ctor, file);
        print_ctor_function(ctor, file);
        print_optional(ctor, file);
        fprintf(file, "}");
}

