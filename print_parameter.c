#include "common.h"

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

void
print_param(const Eolian_Function_Parameter *param, FILE *file)
{
        fprintf(file, "{\n");
        print_param_direction(param, file);
        fprintf(file, "}");
}

