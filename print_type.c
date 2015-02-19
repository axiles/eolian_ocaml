#include "common.h"

extern void
print_struct_type_field(const Eolian_Struct_Type_Field *field, FILE *file);

extern void
print_enum_type_field(const Eolian_Enum_Type_Field *field, FILE *file);

static void
print_ml_variant_Eolian_Type_Type(Eolian_Type_Type x, FILE *file)
{
        fprintf(file, "Type_type.");
        switch(x) {
        case EOLIAN_TYPE_UNKNOWN_TYPE:
                fprintf(file, "Unknown_type");
                break;
        case EOLIAN_TYPE_VOID:
                fprintf(file, "Void");
                break;
        case EOLIAN_TYPE_REGULAR:
                fprintf(file, "Regular");
                break;
        case EOLIAN_TYPE_REGULAR_STRUCT:
                fprintf(file, "Regular_struct");
                break;
        case EOLIAN_TYPE_REGULAR_ENUM:
                fprintf(file, "Regular_enum");
                break;
        case EOLIAN_TYPE_COMPLEX:
                fprintf(file, "Complex");
                break;
        case EOLIAN_TYPE_POINTER:
                fprintf(file, "Pointer");
                break;
        case EOLIAN_TYPE_STRUCT:
                fprintf(file, "Struct");
                break;
        case EOLIAN_TYPE_STRUCT_OPAQUE:
                fprintf(file, "Struct_opaque");
                break;
        case EOLIAN_TYPE_ENUM:
                fprintf(file, "Enum");
                break;
        case EOLIAN_TYPE_ALIAS:
                fprintf(file, "Alias");
                break;
        case EOLIAN_TYPE_CLASS:
                fprintf(file, "Class");
                break;
        }
}

static void
print_type_type(const Eolian_Type *ty, FILE *file)
{
        fprintf(file, "Type.ty = ");
        print_ml_variant_Eolian_Type_Type(eolian_type_type_get(ty), file);
        fprintf(file, ";\n");
}

void
print_type(const Eolian_Type *ty, FILE *file);

static void
print_type_subtypes(const Eolian_Type *ty, FILE *file)
{
        Eina_Iterator *it;
        Eolian_Type *ty1;
        if(eolian_type_type_get(ty) != EOLIAN_TYPE_COMPLEX) {
                fprintf(file, "subtypes = [];\n");
                return;
        }
        it = eolian_type_subtypes_get(ty);
        fprintf(file, "subtypes = [\n");
        EINA_ITERATOR_FOREACH(it, ty1) {
                print_type(ty1, file);
                fprintf(file, ";\n");
        }
        fprintf(file, "];\n");
}

static void
print_type_struct_fields(const Eolian_Type *ty, FILE *file)
{
        Eina_Iterator *it;
        Eolian_Struct_Type_Field *field;
        if(eolian_type_type_get(ty) != EOLIAN_TYPE_STRUCT) {
                fprintf(file, "struct_fields = [];\n");
                return;
        }
        it = eolian_type_struct_fields_get(ty);
        fprintf(file, "struct_fields = [\n");
        EINA_ITERATOR_FOREACH(it, field) {
                print_struct_type_field(field, file);
                fprintf(file, ";\n");
        }
        fprintf(file, "];\n");
}

static void
print_type_enum_fields(const Eolian_Type *ty, FILE *file)
{
        Eina_Iterator *it;
        Eolian_Enum_Type_Field *field;
        if(eolian_type_type_get(ty) != EOLIAN_TYPE_ENUM) {
                fprintf(file, "enum_fields = [];\n");
                return;
        }
        it = eolian_type_enum_fields_get(ty);
        fprintf(file, "enum_fields = [\n");
        EINA_ITERATOR_FOREACH(it, field) {
                print_enum_type_field(field, file);
                fprintf(file, ";\n");
        }
        fprintf(file, "];\n");
}

static void
print_type_enum_legacy_prefix(const Eolian_Type *ty, FILE *file)
{
        if(eolian_type_type_get(ty) != EOLIAN_TYPE_ENUM) {
                fprintf(file, "enum_legacy_prefix = None;\n");
                return;
        }
        print_var_string_opt("enum_legacy_prefix",
                eolian_type_enum_legacy_prefix_get(ty), file);
}

void
print_type(const Eolian_Type *ty, FILE *file)
{
        fprintf(file, "{\n");
        print_type_type(ty, file);
        print_type_subtypes(ty, file);
        print_type_struct_fields(ty, file);
        print_type_enum_fields(ty, file);
        print_type_enum_legacy_prefix(ty, file);
        fprintf(file, "}");
}

