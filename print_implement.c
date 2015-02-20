#include "common.h"

extern void
print_function(const Eolian_Function *f, const Eolian_Class *cl, FILE *file);

extern void
print_ml_variant_Eolian_Function_Type(Eolian_Function_Type ty, FILE *file);

static void
print_full_name(const Eolian_Implement *impl, FILE *file)
{
        print_var_string("Implement.full_name",
                eolian_implement_full_name_get(impl), file);
}

/* TODO: eolian_implement_class_get ? */

static void
print_impl_function(const Eolian_Implement *impl, FILE *file)
{
        Eolian_Function_Type ty;
        const Eolian_Function     *f;
        f = eolian_implement_function_get(impl, &ty);
        fprintf(file, "func = ");
        if(f == NULL) fprintf(file, "None;\n");
        else {
                fprintf(file, " Some (");
                print_ml_variant_Eolian_Function_Type(ty, file);
                fprintf(file, ", ");
                print_function(f, eolian_implement_class_get(impl), file);
                fprintf(file, ");\n");
        }
}

static void
print_auto(const Eolian_Implement *impl, FILE *file)
{
        print_var_bool("auto", eolian_implement_is_auto(impl), file);
}

static void
print_empty(const Eolian_Implement *impl, FILE *file)
{
        print_var_bool("empty", eolian_implement_is_empty(impl), file);
}

static void
print_virtual(const Eolian_Implement *impl, FILE *file)
{
        print_var_bool("virt", eolian_implement_is_virtual(impl), file);
}

static void
print_prop_get(const Eolian_Implement *impl, FILE *file)
{
        print_var_bool("prop_get", eolian_implement_is_prop_set(impl), file);
}

static void
print_prop_set(const Eolian_Implement *impl, FILE *file)
{
        print_var_bool("prop_set", eolian_implement_is_prop_set(impl), file);
}

void
print_implement(const Eolian_Implement *impl, FILE *file)
{
        fprintf(file, "{\n");
        print_full_name(impl, file);
        print_impl_function(impl, file);
        print_auto(impl, file);
        print_empty(impl, file);
        print_virtual(impl, file);
        print_prop_get(impl, file);
        print_prop_set(impl, file);
        fprintf(file, "}");
}

