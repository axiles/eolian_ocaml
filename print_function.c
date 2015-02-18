#include "common.h"

static void
print_ml_variant_Eolian_Function_Type(Eolian_Function_Type x, FILE *file)
{
        fprintf(file, "Function_type.");
        switch(x) {
        case EOLIAN_UNRESOLVED:
                fprintf(file, "Unresolved");
                break;
        case EOLIAN_PROPERTY:
                fprintf(file, "Property");
                break;
        case EOLIAN_PROP_SET:
                fprintf(file, "Prop_set");
                break;
        case EOLIAN_PROP_GET:
                fprintf(file, "Prop_get");
                break;
        case EOLIAN_METHOD:
                fprintf(file, "Method");
                break;
        }
}

static void
print_function_type(const Eolian_Function *f, FILE *file)
{
        fprintf(file, "Function.ty = ");
        print_ml_variant_Eolian_Function_Type(eolian_function_type_get(f),
                file);
        fprintf(file, ";\n");
}

static void
print_function_scope(const Eolian_Function *f, FILE *file)
{
        fprintf(file, "scope = ");
        print_ml_variant_Eolian_Object_Scope(eolian_function_scope_get(f),
                file);
        fprintf(file, ";\n");
}

static void
print_function_name(const Eolian_Function *f, FILE *file)
{
        print_var_string("name", eolian_function_name_get(f), file);
}

static void
print_function_full_c_name(const Eolian_Function *f, FILE *file)
{
        Eina_Stringshare* s;
        s = eolian_function_full_c_name_get(f);
        print_var_string("full_c_name", s, file);
        eina_stringshare_del(s);
}

void
print_function(const Eolian_Function *f, FILE *file)
{
        fprintf(file, "{\n");
        print_function_type(f, file);
        print_function_scope(f, file);
        print_function_name(f, file);
        print_function_full_c_name(f, file);
        fprintf(file, "}\n");
}

