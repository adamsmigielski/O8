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
# @file o8_spec_generator.py
#

import o8_file_generator

use_static_loader = False;

	
def _write_attribute(definition, file, indent):
	_write_description(definition, file, indent);
		
	file.write(indent.get())	
	_write_variable(definition, file);
	file.write(";\n");
	
def _write_attributes(definition, file, indent):
	if (0 == len(definition.attributes)):
		return
		
	file.write("\n\n");
	file.write(indent.get());
	file.write("/* **** Attributes **** */\n");
	for attribute in definition.attributes:
		_write_attribute(attribute);
		file.write("\n");
		
def _write_class(definition, file, indent):
	_write_description(definition, file, indent);
	
	file.write(indent.get())
	file.write("class ");
	file.write(definition.name);
	file.write("\n");
	file.write(indent.get());
	file.write("{\n");
	
	indent.increase();
	
	file.write(indent.get());
	file.write("/* **** Dtr **** */\n");
	file.write(indent.get());
	file.write("virtual ~");
	file.write(definition.name);
	file.write("();\n");
	
	_write_methods(definition, file, indent)
	
	_write_attributes(definition, file, indent)
	
	indent.decrease();
	
	file.write("\n");
	file.write(indent.get());
	file.write("protected:\n");
	
	indent.increase();
	
	file.write(indent.get());
	file.write("/* **** Ctr & copy **** */\n");
	file.write(indent.get());
	file.write(definition.name);
	file.write("() = delete;\n");
	file.write(indent.get());
	file.write(definition.name);
	file.write(" & operator = (const ");
	file.write(definition.name);
	file.write(" & obj) = delete;\n");
	
	indent.decrease();
	
	file.write(indent.get());
	file.write("};\n");
	
def _write_description(definition, file, indent):
	if (None != definition.description):
		file.write(indent.get())
		file.write("/**\n")
		file.write(indent.get())
		file.write(" * ")
		file.write(definition.description);
		file.write("\n")
		try:
			for parameter in definition.parameters:
				file.write(indent.get())
				file.write(" * @param ")
				file.write(parameter.name)
				file.write(" ")
				file.write(parameter.description)
				file.write("\n")
			if (None != definition.rdescription):
				file.write(indent.get())
				file.write(" * @return ")
				file.write(definition.rdescription);
				file.write("\n")
		except AttributeError:
			pass;
		file.write(indent.get())
		file.write(" **/\n")
		
def _write_includes(definition, file, indent):
	pass;
		
def _write_interface(definition, file, indent):
	skip_lines = False;
	if (0 != len(definition.classes)):
		skip_lines = True;
		file.write(indent.get())
		file.write("/* **** Interfaces **** */\n")
		for obj in definition.classes:
			_write_class(obj, file, indent);
		
	if (0 != len(definition.routines)):
		if (True == skip_lines):
			file.write("\n\n")
		skip_lines = True;
		file.write(indent.get())
		file.write("/* **** Routines **** */")
		for routine in definition.routines:
			file.write("\n")
			_write_routine(routine, file, indent);

def _write_method(definition, file, indent):
	_write_description(definition, file, indent);
		
	file.write(indent.get())
	file.write("virtual ");
	
	generate_type(definition.result, file);
	
	file.write(" ");
	file.write(definition.name);
	file.write("(");
		
	_write_parameters(definition, file, indent)
	
	file.write(") = 0;\n");
	
def _write_methods(definition, file, indent):
	if (0 == len(definition.methods)):
		return
		
	file.write("\n\n");
	file.write(indent.get());
	file.write("/* **** Methods **** */");
	for method in definition.methods:
		file.write("\n");
		_write_method(method, file, indent);
		
def _write_parameters(definition, file, indent) :
	i = 0;
	n_parameters = len(definition.parameters);
	
	indent.increase();
	
	indent_str = indent.get();
	
	for parameter in definition.parameters:
		file.write("\n")
		file.write(indent_str)
		_write_variable(parameter, file);
		i += 1;
		if (i < n_parameters):
			file.write(",");	
		
	indent.decrease();
	
def _write_routine(definition, file, indent):
	_write_description(definition, file, indent);
		
	file.write(indent.get())
	
	if (False == use_static_loader):
		file.write("typedef ");
	
	generate_type(definition.result, file);	
	file.write(" ");
	
	if (False == use_static_loader):
		file.write("(O8_API * PFN_");
		file.write(definition.name.upper());
		file.write(")");
	else :
		file.write(definition.name);
			
	file.write("(");
	
	_write_parameters(definition, file, indent)
	
	file.write(");\n");	

def _write_variable(definition, file):
	generate_type(definition.type, file);
	
	file.write(" ");
	file.write(definition.name);
	
def generate_type(type, file):
	if (None == type) :
		file.write("void");
		return;
		
	if (True == type.constant):
		file.write("const ")
		
	file.write(type.name);
	
	if (True == type.reference):
		file.write(" *");
	
def get_type (type, size) :
	if "int" == type :
		if "8" == size :
			return "int8_t";
		elif "16" == size :
			return "int16_t";
		elif "32" == size :
			return "int32_t";
		elif "64" == size :
			return "int64_t";
	elif "unsigned int" == type :
		if "8" == size :
			return "uint8_t";
		elif "16" == size :
			return "uint16_t";
		elif "32" == size :
			return "uint32_t";
		elif "64" == size :
			return "uint64_t";
	elif "float" == type :
		if "32" == size :
			return "float";
		elif "64" == size :
			return "double";
		
def generate_spec(module):
	for interface in module.interfaces:
		o8_file_generator.generate_file(module.namespace, interface.name, True, _write_interface, _write_includes, interface);