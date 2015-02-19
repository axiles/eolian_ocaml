#include "common.h"

void
print_expression(const Eolian_Expression *expr, FILE *file);

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

static void
print_field_value(const Eolian_Enum_Type_Field *field, FILE *file)
{
        fprintf(file, "value = ");
        print_expression(eolian_type_enum_field_value_get(field), file);
        fprintf(file, ";\n");
}

void
print_enum_type_field(const Eolian_Enum_Type_Field *field, FILE *file)
{
        fprintf(file, "{\n");
        print_field_name(field, file);
        print_field_description(field, file);
        print_field_value(field, file);
        fprintf(file, "}");
}

