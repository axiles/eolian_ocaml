#include "common.h"

static void
print_expr_literal(const Eolian_Expression *expr, FILE *file)
{
        Eina_Stringshare *s;
        Eolian_Value v;
        v = eolian_expression_eval(expr, EOLIAN_MASK_ALL);
        s = eolian_expression_value_to_literal(&v);
        print_var_string("Expression.literal", s, file);
        eina_stringshare_del(s);
}

void
print_expression(const Eolian_Expression *expr, FILE *file)
{
        fprintf(file, "{\n");
        print_expr_literal(expr, file);
        fprintf(file, "}");
}

