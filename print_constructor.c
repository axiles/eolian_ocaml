#include "common.h"

static void
print_full_name(const Eolian_Constructor *ctor, FILE *file)
{
        print_var_string("Constructor.full_name",
                eolian_constructor_full_name_get(ctor), file);
}

void
print_constructor(const Eolian_Constructor *ctor, FILE *file)
{
        fprintf(file, "{\n");
        print_full_name(ctor, file);
        fprintf(file, "}");
}

