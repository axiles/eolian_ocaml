#include "common.h"

extern void
print_type(const Eolian_Type *ty, FILE *file);

static void
print_ml_variant_Eolian_Parameter_Dir(Eolian_Parameter_Dir x, FILE *file)
{
        fprintf(file, "Parameter_dir.");
        switch(x) {
        case EOLIAN_IN_PARAM:
                fprintf(file, "In_param");
                break;
        case EOLIAN_OUT_PARAM:
                fprintf(file, "Out_param");
                break;
        case EOLIAN_INOUT_PARAM:
                fprintf(file, "Inout_param");
                break;
        }
}

static void
print_param_direction(const Eolian_Function_Parameter *param, FILE *file)
{
        fprintf(file, "Function_parameter.direction = ");
        print_ml_variant_Eolian_Parameter_Dir(
                eolian_parameter_direction_get(param), file);
        fprintf(file, ";\n");
}

static void
print_param_type(const Eolian_Function_Parameter *param, FILE *file)
{
        fprintf(file, "ty = ");
        print_type(eolian_parameter_type_get(param), file);
        fprintf(file, ";\n");
}

void
print_param(const Eolian_Function_Parameter *param, FILE *file)
{
        fprintf(file, "{\n");
        print_param_direction(param, file);
        print_param_type(param, file);
        fprintf(file, "}");
}

