#include "common.h"

static void
print_name(const Eolian_Event *event, FILE *file)
{
        print_var_string_opt("Event.name", eolian_event_name_get(event), file);
}

void
print_event(const Eolian_Event *event, FILE *file)
{
        fprintf(file, "{");
        print_name(event, file);
        fprintf(file, "}");
}

