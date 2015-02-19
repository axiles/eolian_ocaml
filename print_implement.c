#include "common.h"

static void
print_full_name(const Eolian_Implement *impl, FILE *file)
{
        print_var_string("Implement.full_name",
                eolian_implement_full_name_get(impl), file);
}

void
print_implement(const Eolian_Implement *impl, FILE *file)
{
        fprintf(file, "{\n");
        print_full_name(impl, file);
        fprintf(file, "}");
}

