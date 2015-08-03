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
# @file o8_link_generator.py
#

import o8_file_generator

def _write_includes(definition, file, indent):
	for interface in definition.interfaces:
		file.write("\n");
		file.write(indent.get())
		file.write("#include \"");
		file.write(interface.name)
		file.write(".hpp\"");
					
def _write_link(definition, file, indent):
	routines = [];
	for interface in definition.interfaces:
		for routine in interface.routines:
			routines.append(routine);
		
	alignment = 0;
	i = 0;
	n_routines = len(routines)
	
	for routine in routines:
		length = len(routine.name)
		if (alignment < length):
			alignment = length;
	
	if (0 != n_routines):
		file.write(indent.get())
		file.write("/* **** Routines **** */\n")
		for routine in routines:
			file.write(indent.get())
			file.write("extern PFN_");
			file.write(definition.name.upper());
			file.write(" ");
			file.write(definition.name);
			file.write(";\n");
		file.write("\n")
	
	file.write(indent.get())
	file.write("/* **** Static routines for DL loading and linking **** */\n")
	file.write(indent.get())
	file.write("int  Load_dl(const char * file_path);\n")
	file.write(indent.get())
	file.write("void Unload_dl();\n")
	file.write(indent.get())
	file.write("void Link_")
	file.write(definition.name.lower())
	file.write("(");
	indent.increase();
	for routine in routines:
		file.write("\n");
		file.write(indent.get())
		file.write("PFN_")
		file.write(routine.name.upper())
		file.write(" ");
		file.write(routine.name.lower())
		i += 1;
		if (i != n_routines):
			file.write(",");
			
	indent.decrease();
	file.write(")\n");
	
		
def generate_link(module):
	o8_file_generator.generate_file(module.namespace, module.name, True, _write_link, _write_includes, module);