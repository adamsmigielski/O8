from o8_indent import Indent
from o8_definition import Namespace
from o8_definition import Platform

use_static_loader = True;

def _write_variable(definition, file):
	generate_type(definition.type, file);
	
	file.write(" ");
	file.write(definition.name);

	
def generate_attribute(definition, file, indent):
	if (None != definition.description):
		file.write(indent.get())
		file.write("/**\n")
		file.write(indent.get())
		file.write(" *")
		file.write(definition.description);
		file.write("\n")
		file.write(indent.get())
		file.write(" **/\n")
		
	file.write(indent.get())
	
	_write_variable(definition, file);
	file.write(";\n");
	
def generate_description(definition, file, indent):
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
	
def generate_attributes(definition, file, indent):
	if (0 == len(definition.attributes)):
		return
		
	file.write("\n\n");
	file.write(indent.get());
	file.write("/* **** Attributes **** */\n");
	for attribute in definition.attributes:
		generate_attribute(attribute);
		file.write("\n");

def generate_method(definition, file, indent):
	generate_description(definition, file, indent);
		
	file.write(indent.get())
	file.write("virtual ");
	
	generate_type(definition.result, file);
	
	file.write(" ");
	file.write(definition.name);
	file.write("(");
		
	generate_parameters(definition, file, indent)
	
	file.write(") = 0;\n");
	
def generate_methods(definition, file, indent):
	if (0 == len(definition.methods)):
		return
		
	file.write("\n\n");
	file.write(indent.get());
	file.write("/* **** Methods **** */");
	for method in definition.methods:
		file.write("\n");
		generate_method(method, file, indent);
		
def generate_interfaces(definition, file, indent) :
	file.write(indent.get())
	file.write("/* **** Interfaces **** */\n")
	generate_interface(interface, file, indent);
		
	if (0 != len(definition.routines)):
		file.write("\n\n")
	file.write(indent.get())
	file.write("/* **** Routines **** */")
	skip_lines = True;
	for routine in definition.routines:
		file.write("\n")
		generate_routine(routine, file, indent);
		
def generate_loader(if (False == use_static_loader and True == definition.define_loader):
		i = 0;
		n_routines = len(definition.routines);
		if (True == skip_lines):
			file.write("\n\n")
		file.write(indent.get())
		file.write("/* **** Static routines for DL loading and linking **** */\n")
		skip_lines = True;
		file.write(indent.get())
		file.write("int  LoadDL(const char * file_path);\n")
		file.write(indent.get())
		file.write("void UnloadDL();\n")
		file.write(indent.get())
		file.write("void Link_")
		file.write(definition.name.lower())
		file.write("(");
		indent.increase();
		for routine in definition.routines:
			file.write("\n");
			file.write(indent.get())
			file.write("PFN_")
			file.write(routine.name.upper())
			i += 1;
			if (i != n_routines):
				file.write(",");
			else:
				file.write(")\n");
			
		indent.decrease();

def generate_module(definition, file, indent):
	generate_namespace(definition.namespace, generate_platforms, definifition.platforms, file, indent)
	for interface in definition.interfaces:
		generate_namespace(definition.namespace, generate_interfaces, interface, file, indent)

def generate_namespace(definition, fun, obj, file, indent):
	file.write(indent.get())
	file.write("namespace ")
	file.write(definition.name)
	file.write("\n")
	file.write(indent.get())
	file.write("{\n")
	indent.increase();
	
	if (None != definition.child) :
		generate_namespace(definition.child, fun, obj, file, indent);
	else :
		fun(obj, file, indent);
	
	indent.decrease();
	file.write(indent.get())
	file.write("} /* namespace ")
	file.write(definition.name)
	file.write(" */\n")
		
def generate_parameters(definition, file, indent) :
	i = 0;
	n_parameters = len(definition.parameters);
	
	indent.increase();
	
	for parameter in definition.parameters:
		file.write("\n")
		_write_variable(parameter, file);
		i += 1;
		if (i < n_parameters):
			file.write(",\n");	
		
	indent.decrease();

def generate_platform (definition, file, indent) :
	type = get_type(definition.type, definition.size);
	type_len = len(type);
	
	name_align = 9;
	fill_length = name_align - type_len;
	
	file.write(indent.get());
	file.write("typedef ");
	file.write(type);
	file.write(' ' * fill_length);
	file.write(definition.name);
	file.write( ';\n' );

def generate_platforms (definitions, file, indent) :
	if (0 == len(definitions)
		return;
	file.write(indent.get())
	file.write("/* **** Defintions **** */")
	for definition in definitions:
		file.write("\n")
		generate_platform(definition, file, indent);

def generate_routine(definition, file, indent):
	generate_description(definition, file, indent);
		
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
	
	generate_parameters(definition, file, indent)
	
	file.write(");\n");
	
	if (False == use_static_loader):
		file.write(indent.get())
		file.write("extern PFN_");
		file.write(definition.name.upper());
		file.write(" ");
		file.write(definition.name);
		file.write(";\n");
	
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
		
	