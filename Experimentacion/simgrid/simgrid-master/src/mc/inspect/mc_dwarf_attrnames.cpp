/* Copyright (c) 2014-2019. The SimGrid Team. All rights reserved.          */

/* This program is free software; you can redistribute it and/or modify it
 * under the terms of the license (GNU LGPL) which comes with this package. */

#include "src/mc/inspect/mc_dwarf.hpp"

#include <string>
#include <unordered_map>

namespace {
const std::unordered_map<int, const char*> attrname_map = {
    {0x01, "DW_AT_sibling"},
    {0x02, "DW_AT_location"},
    {0x03, "DW_AT_name"},
    {0x09, "DW_AT_ordering"},
    {0x0a, "DW_AT_subscr_data"},
    {0x0b, "DW_AT_byte_size"},
    {0x0c, "DW_AT_bit_offset"},
    {0x0d, "DW_AT_bit_size"},
    {0x0f, "DW_AT_element_list"},
    {0x10, "DW_AT_stmt_list"},
    {0x11, "DW_AT_low_pc"},
    {0x12, "DW_AT_high_pc"},
    {0x13, "DW_AT_language"},
    {0x14, "DW_AT_member"},
    {0x15, "DW_AT_discr"},
    {0x16, "DW_AT_discr_value"},
    {0x17, "DW_AT_visibility"},
    {0x18, "DW_AT_import"},
    {0x19, "DW_AT_string_length"},
    {0x1a, "DW_AT_common_reference"},
    {0x1b, "DW_AT_comp_dir"},
    {0x1c, "DW_AT_const_value"},
    {0x1d, "DW_AT_containing_type"},
    {0x1e, "DW_AT_default_value"},
    {0x20, "DW_AT_inline"},
    {0x21, "DW_AT_is_optional"},
    {0x22, "DW_AT_lower_bound"},
    {0x25, "DW_AT_producer"},
    {0x27, "DW_AT_prototyped"},
    {0x2a, "DW_AT_return_addr"},
    {0x2c, "DW_AT_start_scope"},
    {0x2e, "DW_AT_bit_stride"},
    {0x2f, "DW_AT_upper_bound"},
    {0x31, "DW_AT_abstract_origin"},
    {0x32, "DW_AT_accessibility"},
    {0x33, "DW_AT_address_class"},
    {0x34, "DW_AT_artificial"},
    {0x35, "DW_AT_base_types"},
    {0x36, "DW_AT_calling_convention"},
    {0x37, "DW_AT_count"},
    {0x38, "DW_AT_data_member_location"},
    {0x39, "DW_AT_decl_column"},
    {0x3a, "DW_AT_decl_file"},
    {0x3b, "DW_AT_decl_line"},
    {0x3c, "DW_AT_declaration"},
    {0x3d, "DW_AT_discr_list"},
    {0x3e, "DW_AT_encoding"},
    {0x3f, "DW_AT_external"},
    {0x40, "DW_AT_frame_base"},
    {0x41, "DW_AT_friend"},
    {0x42, "DW_AT_identifier_case"},
    {0x43, "DW_AT_macro_info"},
    {0x44, "DW_AT_namelist_item"},
    {0x45, "DW_AT_priority"},
    {0x46, "DW_AT_segment"},
    {0x47, "DW_AT_specification"},
    {0x48, "DW_AT_static_link"},
    {0x49, "DW_AT_type"},
    {0x4a, "DW_AT_use_location"},
    {0x4b, "DW_AT_variable_parameter"},
    {0x4c, "DW_AT_virtuality"},
    {0x4d, "DW_AT_vtable_elem_location"},
    {0x4e, "DW_AT_allocated"},
    {0x4f, "DW_AT_associated"},
    {0x50, "DW_AT_data_location"},
    {0x51, "DW_AT_byte_stride"},
    {0x52, "DW_AT_entry_pc"},
    {0x53, "DW_AT_use_UTF8"},
    {0x54, "DW_AT_extension"},
    {0x55, "DW_AT_ranges"},
    {0x56, "DW_AT_trampoline"},
    {0x57, "DW_AT_call_column"},
    {0x58, "DW_AT_call_file"},
    {0x59, "DW_AT_call_line"},
    {0x5a, "DW_AT_description"},
    {0x5b, "DW_AT_binary_scale"},
    {0x5c, "DW_AT_decimal_scale"},
    {0x5d, "DW_AT_small"},
    {0x5e, "DW_AT_decimal_sign"},
    {0x5f, "DW_AT_digit_count"},
    {0x60, "DW_AT_picture_string"},
    {0x61, "DW_AT_mutable"},
    {0x62, "DW_AT_threads_scaled"},
    {0x63, "DW_AT_explicit"},
    {0x64, "DW_AT_object_pointer"},
    {0x65, "DW_AT_endianity"},
    {0x66, "DW_AT_elemental"},
    {0x67, "DW_AT_pure"},
    {0x68, "DW_AT_recursive"},
    {0x69, "DW_AT_signature"},
    {0x6a, "DW_AT_main_subprogram"},
    {0x6b, "DW_AT_data_bit_offset"},
    {0x6c, "DW_AT_const_expr"},
    {0x6d, "DW_AT_enum_class"},
    {0x6e, "DW_AT_linkage_name"},
    {0x87, "DW_AT_noreturn"},
    {0x2000, "DW_AT_lo_user"},
    {0x2001, "DW_AT_MIPS_fde"},
    {0x2002, "DW_AT_MIPS_loop_begin"},
    {0x2003, "DW_AT_MIPS_tail_loop_begin"},
    {0x2004, "DW_AT_MIPS_epilog_begin"},
    {0x2005, "DW_AT_MIPS_loop_unroll_factor"},
    {0x2006, "DW_AT_MIPS_software_pipeline_depth"},
    {0x2007, "DW_AT_MIPS_linkage_name"},
    {0x2008, "DW_AT_MIPS_stride"},
    {0x2009, "DW_AT_MIPS_abstract_name"},
    {0x200a, "DW_AT_MIPS_clone_origin"},
    {0x200b, "DW_AT_MIPS_has_inlines"},
    {0x200c, "DW_AT_MIPS_stride_byte"},
    {0x200d, "DW_AT_MIPS_stride_elem"},
    {0x200e, "DW_AT_MIPS_ptr_dopetype"},
    {0x200f, "DW_AT_MIPS_allocatable_dopetype"},
    {0x2010, "DW_AT_MIPS_assumed_shape_dopetype"},
    {0x2011, "DW_AT_MIPS_assumed_size"},
    {0x2101, "DW_AT_sf_names"},
    {0x2102, "DW_AT_src_info"},
    {0x2103, "DW_AT_mac_info"},
    {0x2104, "DW_AT_src_coords"},
    {0x2105, "DW_AT_body_begin"},
    {0x2106, "DW_AT_body_end"},
    {0x2107, "DW_AT_GNU_vector"},
    {0x2108, "DW_AT_GNU_guarded_by"},
    {0x2109, "DW_AT_GNU_pt_guarded_by"},
    {0x210a, "DW_AT_GNU_guarded"},
    {0x210b, "DW_AT_GNU_pt_guarded"},
    {0x210c, "DW_AT_GNU_locks_excluded"},
    {0x210d, "DW_AT_GNU_exclusive_locks_required"},
    {0x210e, "DW_AT_GNU_shared_locks_required"},
    {0x210f, "DW_AT_GNU_odr_signature"},
    {0x2110, "DW_AT_GNU_template_name"},
    {0x2111, "DW_AT_GNU_call_site_value"},
    {0x2112, "DW_AT_GNU_call_site_data_value"},
    {0x2113, "DW_AT_GNU_call_site_target"},
    {0x2114, "DW_AT_GNU_call_site_target_clobbered"},
    {0x2115, "DW_AT_GNU_tail_call"},
    {0x2116, "DW_AT_GNU_all_tail_call_sites"},
    {0x2117, "DW_AT_GNU_all_call_sites"},
    {0x2118, "DW_AT_GNU_all_source_call_sites"},
    {0x2119, "DW_AT_GNU_macros"},
    {0x211a, "DW_AT_GNU_deleted"},
    {0x3fff, "DW_AT_hi_user"},
};
}

namespace simgrid {
namespace dwarf {

/** @brief Get the name of an attribute (DW_AT_*) from its code
 *
 *  @param attr attribute code (see the DWARF specification)
 *  @return name of the attribute
 */
XBT_PRIVATE
const char* attrname(int attr)
{
  auto name = attrname_map.find(attr);
  return name == attrname_map.end() ? "DW_AT_unknown" : name->second;
}

} // namespace dwarf
} // namespace simgrid
