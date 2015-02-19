#include "common.h"

extern void
print_type(const Eolian_Type *ty, FILE *file);

extern void
print_expression(const Eolian_Expression *expr, FILE *file);

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

static void
print_param_default_value(const Eolian_Function_Parameter *param, FILE *file)
{
        const Eolian_Expression *expr;
        fprintf(file, "default_value = ");
        expr = eolian_parameter_default_value_get(param);
        if(expr == NULL) fprintf(file, "None");
        else {
                fprintf(file, "Some ");
                print_expression(expr, file);
        }
        fprintf(file, ";\n");
}

static void
print_param_name(const Eolian_Function_Parameter *param, FILE *file)
{
        print_var_string("name", eolian_parameter_name_get(param), file);
}

static void
print_param_description(const Eolian_Function_Parameter *param, FILE *file)
{
        print_var_string_opt("description",
                eolian_parameter_description_get(param), file);
}

static void
print_param_const_attribute(const Eolian_Function_Parameter *param, FILE *file)
{
        print_var_bool("const_attribute_get",
                eolian_parameter_const_attribute_get(param, EINA_TRUE), file);
        print_var_bool("const_attribute_set",
                eolian_parameter_const_attribute_get(param, EINA_FALSE), file);
}

static void
print_param_nonull(const Eolian_Function_Parameter *param, FILE *file)
{
        print_var_bool("nonull", eolian_parameter_is_nonull(param), file);
}

void
print_param(const Eolian_Function_Parameter *param, FILE *file)
{
        fprintf(file, "{\n");
        print_param_direction(param, file);
        print_param_type(param, file);
        print_param_default_value(param, file);
        print_param_name(param, file);
        print_param_description(param, file);
        print_param_const_attribute(param, file);
        print_param_nonull(param, file);
        fprintf(file, "}");
}

