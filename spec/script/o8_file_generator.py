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
# @file o8_file_generator.py
#

import os
import sys
from o8_indent import Indent

def _expand_module_path(namespace, separator) :
	expanded = "";
	if (None != namespace):
		expanded = namespace.name;
		expanded += separator;
		expanded += _expand_module_path(namespace.child, separator);
	return expanded

def _prepare_guard(namespace, interface_name) :
	guard = _expand_module_path(namespace, "_");
	guard += interface_name;
	guard += "_hpp";
	return guard.upper();

def _prepare_module_path(namespace) :
	path = _expand_module_path(namespace, "\\");
	return path

def _write_copyright_notice(file) :
	file.write(
	"/** License\n"
    "*\n"
    "* Copyright (c) 2015 Adam Œmigielski\n"
    "*\n"
    "*\n"
    "*  Permission is hereby granted, free of charge, to any person obtaining a\n"
    "*      copy of this software and associated documentation files (the\n"
    "*      \"Software\"), to deal in the Software without restriction, including\n"
    "*      without limitation the rights to use, copy, modify, merge, publish,\n"
    "*      distribute, sublicense, and/or sell copies of the Software, and to\n"
    "*      permit persons to whom the Software is furnished to do so, subject to\n"
    "*      the following conditions: The above copyright notice and this permission\n"
    "*      notice shall be included in all copies or substantial portions of the\n"
    "*      Software.\n"
    "*\n"
    "*\n"
    "*  THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS\n"
    "*      OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF\n"
    "*      MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.\n"
    "*      IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY\n"
    "*      CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,\n"
    "*      TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE\n"
    "*      SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n"
    "*\n"
    "**/\n"
    "\n");
	
def _write_doxy_and_guard(interface_name, guard, file) :
	file.write(
    "/**\n"
    "* @file ");
	file.write(interface_name);
	if (None == guard):
		file.write(".cpp");
	else:
		file.write(".hpp");	
	file.write("\n**/\n"
	"\n"
	"/* This file was generated */\n\n");
	
	if (None != guard):
		file.write("#ifndef ");
		file.write(guard);
		file.write("\n#define ");
		file.write(guard);
		file.write("\n\n");
		
def _write_guard_end(guard, file) :
	if (None != guard):
		file.write("#endif /* ");
		file.write(guard);
		file.write(" */\n\n");
		
def _write_namespace(definition, fun, obj, file, indent):
	file.write(indent.get())
	file.write("namespace ")
	file.write(definition.name)
	file.write("\n")
	file.write(indent.get())
	file.write("{\n")
	indent.increase();
	
	if (None != definition.child) :
		_write_namespace(definition.child, fun, obj, file, indent);
	else :
		fun(obj, file, indent);
	
	indent.decrease();
	file.write(indent.get())
	file.write("} /* namespace ")
	file.write(definition.name)
	file.write(" */\n\n")
		
def generate_file(namespace, interface_name, is_header, code_fun, incl_fun, obj):
	guard = None;
	module_path = _prepare_module_path(namespace);
		
	try:
		os.makedirs(module_path);
	except os.error:
		pass;
		
	file_path = module_path;
	file_path += "\\";
	file_path += interface_name;
	if (True == is_header):
		file_path += ".hpp";
		guard = _prepare_guard(namespace, interface_name);
	else:
		file_path +=".cpp";
		
	file = open(file_path, 'w');
	
	_write_copyright_notice(file);
	_write_doxy_and_guard(interface_name, guard, file);
	indent = Indent();
	file.write("/* **** Include directives **** */");
	incl_fun(obj, file, indent);
	file.write("\n\n/* **** Definitions **** */\n");
	_write_namespace(namespace, code_fun, obj, file, indent);
	_write_guard_end(guard, file);