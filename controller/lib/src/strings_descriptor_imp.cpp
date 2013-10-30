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
 * strings_descriptor_imp.cpp
 *
 * Strings descriptor implementation
 */

#include "enumeration.h"
#include "log.h"
#include "strings_descriptor_imp.h"

namespace avdecc_lib
{
	strings_descriptor_imp::strings_descriptor_imp() {}

	strings_descriptor_imp::strings_descriptor_imp(end_station_imp *base_end_station_imp_ref, uint8_t *frame, size_t pos, size_t mem_buf_len) : descriptor_base_imp(base_end_station_imp_ref)
	{
		desc_strings_read_returned = jdksavdecc_descriptor_strings_read(&strings_desc, frame, pos, mem_buf_len);

		if(desc_strings_read_returned < 0)
		{
			avdecc_lib::log_ref->logging(avdecc_lib::LOGGING_LEVEL_ERROR, "desc_strings_read error");
			assert(desc_strings_read_returned >= 0);
		}
	}

	strings_descriptor_imp::~strings_descriptor_imp() {}

	uint16_t STDCALL strings_descriptor_imp::get_descriptor_type()
	{
		assert(strings_desc.descriptor_type == JDKSAVDECC_DESCRIPTOR_STRINGS);
		return strings_desc.descriptor_type;
	}

	uint16_t STDCALL strings_descriptor_imp::get_descriptor_index()
	{
		return strings_desc.descriptor_index;
	}

	uint8_t * STDCALL strings_descriptor_imp::get_string_by_index(uint32_t string_index)
	{
		switch(string_index)
		{
			case 0:
				return strings_desc.string_0.value;
				break;

			case 1:
				return strings_desc.string_1.value;
				break;

			case 2:
				return strings_desc.string_1.value;
				break;

			case 3:
				return strings_desc.string_1.value;
				break;

			case 4:
				return strings_desc.string_1.value;
				break;

			case 5:
				return strings_desc.string_1.value;
				break;

			case 6:
				return strings_desc.string_1.value;
				break;

			default:
				avdecc_lib::log_ref->logging(avdecc_lib::LOGGING_LEVEL_ERROR, "get_string_by_index error");
				break;
		}

		return 0;
	}

#ifdef DEBUG_DESCRIPTOR_FIELD_INFORMATION
	void strings_descriptor_imp::print_strings_desc_info()
	{
		std::cout << "\nStrings Descriptor";
		std::cout << "\ndescriptor_type = 0x" << std::hex << get_descriptor_type();
		std::cout << "\ndescriptor_index = 0x" << std::hex << get_descriptor_index();
		std::cout << "\nget_string_0 = " << std::hex << get_string_0().value;
		std::cout << "\nget_string_1 = " << std::hex << get_string_1().value;
		std::cout << "\nget_string_2 = " << std::hex << get_string_2().value;
		std::cout << "\nget_string_3 = " << std::hex << get_string_3().value;
		std::cout << "\nget_string_4 = " << std::hex << get_string_4().value;
		std::cout << "\nget_string_5 = " << std::hex << get_string_5().value;
		std::cout << "\nget_string_6 = " << std::hex << get_string_6().value;
	}
#endif

}