module Function_type = struct
 type t =
    | Unresolved
    | Property
    | Prop_set
    | Prop_get
    | Method
end

module Parameter_dir = struct
  type t =
    | In_param
    | Out_param
    | Inout_param
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

module Type_type = struct
   type t =
    | Unknown_type
    | Void
    | Regular
    | Regular_struct
    | Regular_enum
    | Complex
    | Pointer
    | Struct
    | Struct_opaque
    | Enum
    | Alias
    | Class
end
 
module Expression = struct
  type t = {
      literal : string;
  }
end

module Struct_type_field = struct
  type 'a t = {
    name : string option;
    description : string option;
    ty : 'a;
  }
end

module Enum_type_field = struct
  type t = {
    name : string;
    description : string option;
    value : Expression.t
  }
end

module Type = struct
  type t = {
    ty : Type_type.t;
    subtypes : t list;
    struct_fields : t Struct_type_field.t list;
    enum_fields : Enum_type_field.t list;
  }
end

module Function_parameter = struct
  type t = {
    direction : Parameter_dir.t;
    ty : Type.t;
  }
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
    virtual_pure_unresolved : bool;
    virtual_pure_property : bool;
    virtual_pure_prop_get : bool;
    virtual_pure_prop_set : bool;
    virtual_pure_method : bool;
    auto_unresolved : bool;
    auto_property : bool;
    auto_prop_get : bool;
    auto_prop_set : bool;
    auto_method : bool;
    empty_unresolved : bool;
    empty_property : bool;
    empty_prop_get : bool;
    empty_prop_set : bool;
    empty_method : bool;
    legacy_only_unresolved : bool;
    legacy_only_property : bool;
    legacy_only_prop_get : bool;
    legacy_only_prop_set : bool;
    legacy_only_method : bool;
    cl : bool;
    c_only : bool;
    constructor :bool;
    parameters : Function_parameter.t list;
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

