/*
 * Licensed under the MIT License (MIT)
 *
 * Copyright (c) 2013 AudioScience Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * avb_interface_descriptor_imp.h
 *
 * AVB Interface descriptor implementation class
 */

#pragma once
#ifndef _AVB_INTERFACE_DESCRIPTOR_IMP_H_
#define _AVB_INTERFACE_DESCRIPTOR_IMP_H_

#include "descriptor_base_imp.h"
#include "avb_interface_descriptor.h"

namespace avdecc_lib
{
        class avb_interface_descriptor_imp : public virtual avb_interface_descriptor, public virtual descriptor_base_imp
        {
        private:
                struct jdksavdecc_descriptor_avb_interface avb_interface_desc; // Structure containing the avb_interface_desc fields
                int desc_avb_interface_read_returned; // Status of extracting AVB Interface descriptor information from a network buffer

        public:
                /**
                 * An empty constructor for avb_interface_descriptor_imp
                 */
                avb_interface_descriptor_imp();

                /**
                 * Constructor for avb_interface_descriptor_imp used for constructing an object with  a base End Station, frame, position offest,
                 * and memory buffer length.
                 */
                avb_interface_descriptor_imp(end_station_imp *base_end_station_imp_ref, uint8_t *frame, size_t pos, size_t mem_buf_len);

                /**
                 * Destructor for avb_interface_descriptor_imp used for destroying objects
                 */
                virtual ~avb_interface_descriptor_imp();

                /**
                 * Get the descriptor_type of the avb_interface_descriptor object.
                 */
                AVDECC_LIB_API uint16_t STDCALL get_descriptor_type();

                /**
                 * Get the descriptor_index of the avb_interface_descriptor object.
                 */
                AVDECC_LIB_API uint16_t STDCALL get_descriptor_index();

                /**
                 * Get the object_name of the avb_interface_descriptor object.
                 */
                AVDECC_LIB_API uint8_t * STDCALL get_object_name();

                /**
                 * Get the localized_description of the avb_interface_descriptor object.
                 */
                AVDECC_LIB_API uint16_t STDCALL get_localized_description();

                /**
                 * Get the mac_address of the avb_interface_descriptor object.
                 */
                AVDECC_LIB_API struct jdksavdecc_eui48 STDCALL get_mac_address();

                /**
                 * Get the interface_flags of the avb_interface_descriptor object.
                 */
                AVDECC_LIB_API uint16_t STDCALL get_interface_flags();

                /**
                 * Get the clock_identity of the avb_interface_descriptor object.
                 */
                AVDECC_LIB_API uint64_t STDCALL get_clock_identity();

                /**
                 * Get the priority1 of the avb_interface_descriptor object.
                 */
                AVDECC_LIB_API uint32_t STDCALL get_priority1();

                /**
                 * Get the clock_class of the avb_interface_descriptor object.
                 */
                AVDECC_LIB_API uint32_t STDCALL get_clock_class();

                /**
                 * Get the offset_scaled_log_variance of the avb_interface_descriptor object.
                 */
                AVDECC_LIB_API uint16_t STDCALL get_offset_scaled_log_variance();

                /**
                 * Get the clock_accuracy of the avb_interface_descriptor object.
                 */
                AVDECC_LIB_API uint32_t STDCALL get_clock_accuracy();

                /**
                 * Get the priority2 of the avb_interface_descriptor object.
                 */
                AVDECC_LIB_API uint32_t STDCALL get_priority2();

                /**
                 * Get the domain_number of the avb_interface_descriptor object.
                 */
                AVDECC_LIB_API uint32_t STDCALL get_domain_number();

                /**
                 * Get the log_sync_interval of the avb_interface_descriptor object.
                 */
                AVDECC_LIB_API uint32_t STDCALL get_log_sync_interval();

                /**
                 * Print out AVB Interface Descriptor fields.
                 */
                //	void print_avb_interface_desc_info();
        };
}

#endif