module Function_type = struct
 type t =
    | Unresolved
    | Property
    | Prop_set
    | Prop_get
    | Method
end

module Class_type = struct
  type t =
    | Unknown_type
    | Regular
    | Abstract
    | Mixin
    | Interface
end

module Object_scope = struct
  type t =
    | Public
    | Private
    | Protected
end

module Function = struct
  type t = {
    ty : Function_type.t;
    scope : Object_scope.t;
    name : string;
    full_c_name : string;
    legacy_unresolved : string option;
    legacy_property : string option;
    legacy_prop_get : string option;
    legacy_prop_set : string option;
    legacy_method : string option;
    description_unresolved : string option;
    description_property : string option;
    description_prop_get : string option;
    description_prop_set : string option;
    description_method : string option;
  }
end

module Class = struct
  type t = {
    full_name : string;
    name : string;
    namespaces : string list;
    ty : Class_type.t;
    description : string option;
    legacy_prefix : string option;
    eo_prefix : string;
    data_type : string option;
    inherits : string list;
    functions_unresolved : Function.t list;
    functions_property : Function.t list;
    functions_prop_get : Function.t list;
    functions_prop_set : Function.t list;
    functions_method : Function.t list;
  }
end

