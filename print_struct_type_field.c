#include "common.h"

extern void
print_type(const Eolian_Type *ty, FILE *file);

static void
print_field_name(const Eolian_Struct_Type_Field *field, FILE *file)
{
        print_var_string_opt("Struct_type_field.name",
                eolian_type_struct_field_name_get(field), file);
}

static void
print_field_description(const Eolian_Struct_Type_Field *field, FILE *file)
{
        print_var_string_opt("description",
                eolian_type_struct_field_description_get(field), file);
}

static void
print_field_type(const Eolian_Struct_Type_Field *field, FILE *file)
{
        fprintf(file, "ty = ");
        print_type(eolian_type_struct_field_type_get(field), file);
        fprintf(file, ";\n");
}

void
print_struct_type_field(const Eolian_Struct_Type_Field *field, FILE *file)
{
        fprintf(file, "{\n");
        print_field_name(field, file);
        print_field_description(field, file);
        print_field_type(field, file);
        fprintf(file, "}");
}

