#include "common.h"

extern void
print_class(const Eolian_Class *cl, FILE* file);

static void
print_all_classes(FILE *file)
{
        Eina_Iterator *it;
        Eolian_Class *cl;
        it = eolian_all_classes_get();
        fprintf(file, "[");
        if(it != NULL) fprintf(file, "\n");
        EINA_ITERATOR_FOREACH(it, cl) {
                fprintf(file, "(* %s *)", eolian_class_name_get(cl));
                print_class(cl, file);
                fprintf(file, ";\n");
        }
        fprintf(file, "]");
}

static void
parse_all(int argc, char* argv[])
{
        int i;
        for(i = 1; i < argc; i++) eolian_directory_scan(argv[i]);
        eolian_all_eo_files_parse();
}
int main(int argc, char *argv[])
{
        eolian_init();
        parse_all(argc, argv);
        fprintf(stdout, "let world = ");
        print_all_classes(stdout);
        fprintf(stdout, "\n");
        fflush(stdout);
        eolian_shutdown();
        return 0;
}

