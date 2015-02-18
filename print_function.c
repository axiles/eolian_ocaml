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

static void
print_function_legacy(
        const Eolian_Function *f,
        Eina_Stringshare      *name,
        Eolian_Function_Type   ty,
        FILE                  *file)
{
        print_var_string_opt(name, eolian_function_legacy_get(f, ty), file);
}

static void
print_function_legacy_all(const Eolian_Function *f, FILE *file)
{
        print_function_legacy(f, "legacy_unresolved", EOLIAN_UNRESOLVED, file);
        print_function_legacy(f, "legacy_property", EOLIAN_PROPERTY, file);
        print_function_legacy(f, "legacy_prop_get", EOLIAN_PROP_GET, file);
        print_function_legacy(f, "legacy_prop_set", EOLIAN_PROP_SET, file);
        print_function_legacy(f, "legacy_method", EOLIAN_PROP_GET, file);
}

static void
print_function_description(
        const Eolian_Function *f,
        Eina_Stringshare      *name,
        Eolian_Function_Type   ty,
        FILE                  *file)
{
        print_var_string_opt(name, eolian_function_description_get(f, ty),
                file);
}

static void
print_function_description_all(const Eolian_Function *f, FILE *file)
{
        print_function_description(f, "description_unresolved",
                EOLIAN_UNRESOLVED, file);
        print_function_description(f, "description_property", EOLIAN_PROPERTY,
                file);
        print_function_description(f, "description_prop_get", EOLIAN_PROP_GET,
                file);
        print_function_description(f, "description_prop_set", EOLIAN_PROP_SET,
                file);
        print_function_description(f, "description_method", EOLIAN_METHOD,
                file);
}

static void
print_function_virtual_pure(
        const Eolian_Function *f,
        Eina_Stringshare      *name,
        Eolian_Function_Type   ty,
        FILE                  *file)
{
        print_var_bool(name, eolian_function_is_virtual_pure(f, ty), file);
}

static void
print_function_virtual_pure_all(const Eolian_Function *f, FILE *file)
{
        print_function_virtual_pure(f, "virtual_pure_unresolved",
                EOLIAN_UNRESOLVED, file);
        print_function_virtual_pure(f, "virtual_pure_property", EOLIAN_PROPERTY,
                file);
        print_function_virtual_pure(f, "virtual_pure_prop_get", EOLIAN_PROP_GET,
                file);
        print_function_virtual_pure(f, "virtual_pure_prop_set", EOLIAN_PROP_SET,
                file);
        print_function_virtual_pure(f, "virtual_pure_method", EOLIAN_METHOD,
                file);
}

static void
print_function_auto(
        const Eolian_Function *f,
        Eina_Stringshare      *name,
        Eolian_Function_Type   ty,
        FILE                  *file)
{
        print_var_bool(name, eolian_function_is_auto(f, ty), file);
}

static void
print_function_auto_all(const Eolian_Function *f, FILE *file)
{
        print_function_auto(f, "auto_unresolved", EOLIAN_UNRESOLVED, file);
        print_function_auto(f, "auto_property", EOLIAN_PROPERTY, file);
        print_function_auto(f, "auto_prop_get", EOLIAN_PROP_GET, file);
        print_function_auto(f, "auto_prop_set", EOLIAN_PROP_SET, file);
        print_function_auto(f, "auto_method", EOLIAN_METHOD, file);
}

static void
print_function_empty(
        const Eolian_Function *f,
        Eina_Stringshare      *name,
        Eolian_Function_Type   ty,
        FILE *file)
{
        print_var_bool(name, eolian_function_is_empty(f, ty), file);
}

static void
print_function_empty_all(const Eolian_Function *f, FILE *file)
{
        print_function_empty(f, "empty_unresolved", EOLIAN_UNRESOLVED, file);
        print_function_empty(f, "empty_property", EOLIAN_PROPERTY, file);
        print_function_empty(f, "empty_prop_get", EOLIAN_PROP_GET, file);
        print_function_empty(f, "empty_prop_set", EOLIAN_PROP_SET, file);
        print_function_empty(f, "empty_method", EOLIAN_METHOD, file);
}

static void
print_function_legacy_only(
        const Eolian_Function *f,
        Eina_Stringshare      *name,
        Eolian_Function_Type   ty,
        FILE                  *file)
{
        print_var_bool(name, eolian_function_is_legacy_only(f, ty), file);
}

static void
print_function_legacy_only_all(const Eolian_Function *f, FILE *file)
{
        print_function_legacy_only(f, "legacy_only_unresolved",
                EOLIAN_UNRESOLVED, file);
        print_function_legacy_only(f, "legacy_only_property", EOLIAN_PROPERTY,
                file);
        print_function_legacy_only(f, "legacy_only_prop_get", EOLIAN_PROP_GET,
                file);
        print_function_legacy_only(f, "legacy_only_prop_set", EOLIAN_PROP_SET,
                file);
        print_function_legacy_only(f, "legacy_only_method", EOLIAN_METHOD,
                file);
}

static void
print_function_class(const Eolian_Function *f, FILE *file)
{
        print_var_bool("cl", eolian_function_is_class(f), file);
}

static void
print_function_c_only(const Eolian_Function *f, FILE *file)
{
        print_var_bool("c_only", eolian_function_is_c_only(f), file);
}

static void
print_function_constructor(
        const Eolian_Function *f,
        const Eolian_Class *cl,
        FILE *file)
{
        print_var_bool("constructor", eolian_function_is_constructor(f, cl),
                file);
}

void
print_function(const Eolian_Function *f, const Eolian_Class *cl, FILE *file)
{
        fprintf(file, "{\n");
        print_function_type(f, file);
        print_function_scope(f, file);
        print_function_name(f, file);
        print_function_full_c_name(f, file);
        print_function_legacy_all(f, file);
        print_function_description_all(f, file);
        print_function_virtual_pure_all(f, file);
        print_function_auto_all(f, file);
        print_function_empty_all(f, file);
        print_function_legacy_only_all(f, file);
        print_function_class(f, file);
        print_function_c_only(f, file);
        print_function_constructor(f, cl, file);
        fprintf(file, "}\n");
}

