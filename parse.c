#include "common.h"

extern void
print_class(const Eolian_Class *cl, FILE* file);

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

void
print_function(const Eolian_Function *f, FILE *file)
{
        fprintf(file, "{\n");
        print_function_type(f, file);
        fprintf(file, "}\n");
}

int parse_class(const char *filename, FILE *file)
{
        const Eolian_Class *cl;
        if(!eolian_eo_file_parse(filename)) {
                fprintf(stderr, "Could not parse file %s\n", filename);
                exit(1);
        }
        if((cl = eolian_class_get_by_file(filename)) == NULL) {
                fprintf(stderr, "Could not find class in %s\n", filename);
                exit(1);
        }
        print_class(cl, file);
        return 1;
}
 
int main(int argc, char** argv)
{
        eolian_init();
        eolian_directory_scan("/home/alexis/src/efl-1.13/efl-1.13.0/src/lib/eo");
        eolian_directory_scan("/home/alexis/src/efl-1.13/efl-1.13.0/src/lib/ecore");
        eolian_directory_scan("/home/alexis/src/efl-1.13/efl-1.13.0/src/lib/efl");
        eolian_directory_scan("/home/alexis/src/efl-1.13/efl-1.13.0/src/lib/eet");
        eolian_directory_scan("/home/alexis/src/efl-1.13/efl-1.13.0/src/lib/edje");
        eolian_directory_scan("/home/alexis/src/efl-1.13/efl-1.13.0/src/lib/eina");
        eolian_directory_scan("/home/alexis/src/efl-1.13/efl-1.13.0/src/lib/evas");
        eolian_directory_scan("/home/alexis/src/efl-1.13/elementary-1.13.0/src/lib");
        parse_class("elm_button.eo", stdout);
        fflush(stdout);
        eolian_shutdown();
        return 0;
}

