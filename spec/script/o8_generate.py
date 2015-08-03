# -*- coding: utf-8 -*-

# License
#
# Copyright (c) 2015 Adam Œmigielski
#
#
#  Permission is hereby granted, free of charge, to any person obtaining a
#      copy of this software and associated documentation files (the
#      "Software"), to deal in the Software without restriction, including
#      without limitation the rights to use, copy, modify, merge, publish,
#      distribute, sublicense, and/or sell copies of the Software, and to
#      permit persons to whom the Software is furnished to do so, subject to
#      the following conditions: The above copyright notice and this permission
#      notice shall be included in all copies or substantial portions of the
#      Software.
#
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
#      OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#      MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
#      IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
#      CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
#      TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
#      SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
#

#
# @file o8_generate.py
#

from o8_definition import Module
import o8_link_generator
import o8_spec_generator
import o8_parser
#import o8_generator
import xml.dom.minidom



def parse(definition, in_path):
	doc = xml.dom.minidom.parse( in_path );
	node = doc.getElementsByTagName( "module" );
	o8_parser.parse_module(definition, node[0])

module_name = "Scene";
xml_path    = "..\\";
header_path = "..\\include\\";

in_file  = xml_path    + module_name + ".xml";
out_file = header_path + module_name + ".hpp";
	
module = Module();
parse(module, in_file);

#o8_generator.use_static_loader = False;

o8_spec_generator.generate_spec(module);	
o8_link_generator.generate_link(module);

