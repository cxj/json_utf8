/*
 * File demo/example.cpp part of the SimpleJSON Library Demo - http://mjpa.in/json
 *
 * Copyright (C) 2010 Mike Anchor
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <string>
#include <sstream>
#include <time.h>
#include "../JSON.h"
#include "functions.h"

using namespace std;

// Just some sample JSON text, feel free to change but could break demo
const char* EXAMPLE = "\
{ \
	\"string_name\" : \"string\tvalue and a \\\"quote\\\" and a unicode char \\u00BE and a c:\\\\path\\\\ or a \\/unix\\/path\\/ :D\", \
	\"bool_name\" : true, \
	\"bool_second\" : FaLsE, \
	\"null_name\" : nULl, \
	\"negative\" : -34.276, \
	\"sub_object\" : { \
						\"foo\" : \"abc\", \
						 \"bar\" : 1.35e2, \
						 \"blah\" : { \"a\" : \"A\", \"b\" : \"B\", \"c\" : \"C\" } \
					}, \
	\"array_letters\" : [ \"a\", \"b\", \"c\", [ 1, 2, 3  ]  ] \
}    ";

// Example 1
void example1()
{
	// Parse example data
	JSONValue *value = JSON::Parse(EXAMPLE);

	// Did it go wrong?
	if (value == NULL)
	{
		print_out("Example code failed to parse, did you change it?\r\n");
	}
	else
	{
		// Retrieve the main object
		JSONObject root;
		if (value->IsObject() == false)
		{
			print_out("The root element is not an object, did you change the example?\r\n");
		}
		else
		{
			root = value->AsObject();

			// Retrieving a string
			if (root.find("string_name") != root.end() && root["string_name"]->IsString())
			{
				print_out("string_name:\r\n");
				print_out("------------\r\n");
				print_out(root["string_name"]->AsString().c_str());
				print_out("\r\n\r\n");
			}

			// Retrieving a boolean
			if (root.find("bool_second") != root.end() && root["bool_second"]->IsBool())
			{
				print_out("bool_second:\r\n");
				print_out("------------\r\n");
				print_out(root["bool_second"]->AsBool() ? "it's true!" : "it's false!");
				print_out("\r\n\r\n");
			}

			// Retrieving an array
			if (root.find("array_letters") != root.end() && root["array_letters"]->IsArray())
			{
				JSONArray array = root["array_letters"]->AsArray();
				print_out("array_letters:\r\n");
				print_out("--------------\r\n");
				for (unsigned int i = 0; i < array.size(); i++)
				{
					stringstream output;
					output << "[" << i << "] => " << array[i]->Stringify() << "\r\n";
					print_out(output.str().c_str());
				}
				print_out("\r\n");
			}

			// Retrieving nested object
			if (root.find("sub_object") != root.end() && root["sub_object"]->IsObject())
			{
				print_out("sub_object:\r\n");
				print_out("-----------\r\n");
				print_out(root["sub_object"]->Stringify().c_str());
				print_out("\r\n\r\n");
			}
		}

		delete value;
	}
}

// Example 2
void example2()
{
	JSONObject root;

	// Adding a string
	root["test_string"] = new JSONValue("hello world");

	// Create a random integer array
	JSONArray array;
	srand((unsigned)time(0));
	for (int i = 0; i < 10; i++)
		array.push_back(new JSONValue((double)(rand() % 100)));
	root["sample_array"] = new JSONValue(array);

	// Create a value
	JSONValue *value = new JSONValue(root);

	// Print it
	print_out(value->Stringify().c_str());

	// Clean up
	delete value;
}
