#include "common.h"

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
print_type(const Eolian_Type *ty, FILE *file)
{
        fprintf(file, "{\n");
        print_type_type(ty, file);
        fprintf(file, "}");
}

