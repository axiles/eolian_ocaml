#include "common.h"

extern void
print_function(const Eolian_Function* f, FILE *file);

static void
print_ml_variant_Eolian_Class_Type(Eolian_Class_Type x, FILE *file)
{
        fprintf(file, "Class_type.");
        switch(x) {
        case EOLIAN_CLASS_UNKNOWN_TYPE:
                fprintf(file, "Unknown_type");
                break;
        case EOLIAN_CLASS_REGULAR:
                fprintf(file, "Regular");
                break;
        case EOLIAN_CLASS_ABSTRACT:
                fprintf(file, "Abstract");
                break;
        case EOLIAN_CLASS_MIXIN:
                fprintf(file, "Mixin");
                break;
        case EOLIAN_CLASS_INTERFACE:
                fprintf(file, "Interface");
                break;
        }
}

static void
print_class_full_name(const Eolian_Class *cl, FILE *file)
{
        print_var_string("Class.full_name",
                eolian_class_full_name_get(cl), file);
}

static void
print_class_name(const Eolian_Class *cl, FILE *file)
{
        print_var_string("name", eolian_class_name_get(cl), file);
}

static void
print_class_namespaces(const Eolian_Class *cl, FILE *file)
{
        Eina_Stringshare *s;
        Eina_Iterator *it;
        it = eolian_class_namespaces_get(cl);
        fprintf(file, "namespaces = [\n");
        EINA_ITERATOR_FOREACH(it, s) fprintf(file, "\"%s\";\n", s);
        fprintf(file, "];\n");
}

static void
print_class_type(const Eolian_Class *cl, FILE *file)
{
        fprintf(file, "ty = ");
        print_ml_variant_Eolian_Class_Type(eolian_class_type_get(cl), file);
        fprintf(file, ";\n");
}
 
static void
print_class_description(const Eolian_Class *cl, FILE *file)
{
        print_var_string_opt("description",
                eolian_class_description_get(cl), file);
}

static void
print_class_legacy_prefix(const Eolian_Class *cl, FILE *file)
{
        print_var_string_opt("legacy_prefix",
                eolian_class_legacy_prefix_get(cl), file);
}

static void
print_class_eo_prefix(const Eolian_Class *cl, FILE *file)
{
        print_var_string("eo_prefix", eolian_class_eo_prefix_get(cl),
                file);
}

static void
print_class_data_type(const Eolian_Class *cl, FILE *file)
{
        print_var_string_opt("data_type", eolian_class_data_type_get(cl),
                file);
}

static void
print_class_inherits(const Eolian_Class *cl, FILE *file)
{
        Eina_Stringshare *s;
        Eina_Iterator *it;
        it = eolian_class_inherits_get(cl);
        fprintf(file, "inherits = [\n");
        EINA_ITERATOR_FOREACH(it, s) fprintf(file, "\"%s\";\n", s);
        fprintf(file, "];\n");
}

static void
print_class_functions(
        const Eolian_Class* cl,
        Eolian_Function_Type ty,
        Eina_Stringshare* name,
        FILE *file)
{
        Eina_Iterator *it;
        Eolian_Function *f;
        it = eolian_class_functions_get(cl, ty);
        fprintf(file, "functions_%s = [\n", name);
        EINA_ITERATOR_FOREACH(it, f) {
                print_function(f, file);
                fprintf(file, ";\n");
        }
        fprintf(file, "];\n");
}

static void
print_class_functions_all(const Eolian_Class *cl, FILE *file)
{
        print_class_functions(cl, EOLIAN_UNRESOLVED, "unresolved", file);
        print_class_functions(cl, EOLIAN_PROPERTY, "property", file);
        print_class_functions(cl, EOLIAN_PROP_SET, "prop_set", file);
        print_class_functions(cl, EOLIAN_PROP_GET, "prop_get", file);
        print_class_functions(cl, EOLIAN_METHOD, "method", file);
}

void
print_class(const Eolian_Class *cl, FILE *file)
{
        fprintf(file, "{\n");
        print_class_full_name(cl, file);
        print_class_name(cl, file);
        print_class_namespaces(cl, file);
        print_class_type(cl, file);
        print_class_description(cl, file);
        print_class_legacy_prefix(cl, file);
        print_class_eo_prefix(cl, file);
        print_class_data_type(cl, file);
        print_class_inherits(cl, file);
        print_class_functions_all(cl, file);
        fprintf(file, "}\n");
}

