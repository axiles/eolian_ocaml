bin_PROGRAMS=eolian_ocaml_parse

eolian_ocaml_parse_SOURCES=parse.c common.c print_class.c print_function.c \
	print_parameter.c print_type.c print_struct_type_field.c \
	print_enum_type_field.c print_expression.c print_implement.c \
	print_constructor.c print_event.c common.h

eolian_ocaml_parse_CFLAGS=$(EOLIAN_CFLAGS)
eolian_ocaml_parse_LDFLAGS=$(EOLIAN_LIBS)

EXTRA_DIST=eo_file.ml

