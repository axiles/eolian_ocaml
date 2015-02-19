#include "common.h"

static void
print_field_name(const Eolian_Struct_Type_Field *field, FILE *file)
{
        print_var_string_opt("Struct_type_field.name",
                eolian_type_struct_field_name_get(field), file);
}

void
print_struct_type_field(const Eolian_Struct_Type_Field *field, FILE *file)
{
        fprintf(file, "{\n");
        print_field_name(field, file);
        fprintf(file, "}");
}

