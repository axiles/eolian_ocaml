#include "common.h"

extern void
print_type(const Eolian_Type *ty, FILE *file);

static void
print_name(const Eolian_Event *event, FILE *file)
{
        print_var_string_opt("Event.name", eolian_event_name_get(event), file);
}

static void
print_event_type(const Eolian_Event *event, FILE *file)
{
        const Eolian_Type *ty;
        ty = eolian_event_type_get(event);
        fprintf(file, "ty = ");
        if(ty == NULL) fprintf(file, "None");
        else {
                fprintf(file, "Some ");
                print_type(ty, file);
        }
        fprintf(file, ";");
}

static void
print_description(const Eolian_Event *event, FILE *file)
{
        print_var_string_opt("description", eolian_event_description_get(event),
                file);
}

static void
print_scope(const Eolian_Event *event, FILE *file)
{
        fprintf(file, "scope = ");
        print_ml_variant_Eolian_Object_Scope(eolian_event_scope_get(event),
                file);
        fprintf(file, ";\n");
}

static void
print_c_name(const Eolian_Event *event, FILE *file)
{
        Eina_Stringshare *s;
        s = eolian_event_c_name_get(event);
        print_var_string("c_name", s, file);
        eina_stringshare_del(s);
}

void
print_event(const Eolian_Event *event, FILE *file)
{
        fprintf(file, "{");
        print_name(event, file);
        print_event_type(event, file);
        print_description(event, file);
        print_scope(event, file);
        print_c_name(event, file);
        fprintf(file, "}");
}

