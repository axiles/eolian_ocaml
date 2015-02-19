#include "common.h"

static void
print_field_name(const Eolian_Enum_Type_Field *field, FILE *file)
{
        print_var_string("Enum_type_field.name",
                eolian_type_enum_field_name_get(field), file);
}

static void
print_field_description(const Eolian_Enum_Type_Field *field, FILE *file)
{
        print_var_string_opt("description",
                eolian_type_enum_field_description_get(field), file);
}

void
print_enum_type_field(const Eolian_Enum_Type_Field *field, FILE *file)
{
        fprintf(file, "{\n");
        print_field_name(field, file);
        print_field_description(field, file);
        fprintf(file, "}");
}

