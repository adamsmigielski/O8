import xml.dom.minidom

from o8_definition import Class
from o8_definition import Interface
from o8_definition import Method
from o8_definition import Module
from o8_definition import Namespace
from o8_definition import Parameter
from o8_definition import Platform
from o8_definition import Routine
from o8_definition import Type

def parse_class(definition, node) :
	if True == node.hasAttributes() :		
		attributes = node.attributes;
		for i in range(attributes.length) :
			attr = attributes.item(i);
			if "name" == attr.name :
				definition.name = attr.value;
			elif "description" == attr.name :
				definition.description = attr.value;
			else :
				raise Exception("Unknown attribute", attr.name);
				
	for child in node.childNodes :
		if xml.dom.Node.ELEMENT_NODE == child.nodeType :
			if "attribute" == child.nodeName :
				attribute = Routine();					
				parse_attribute(attribute, child);					
				definition.attributes.append(attribute);
			elif "method" == child.nodeName :
				method = Method();					
				parse_method(method, child);					
				definition.methods.append(method);
			else :
				raise Exception("Unknown tag", child.nodeName);

def parse_interface(definition, node) :
	if True == node.hasAttributes() :		
		attributes = node.attributes;
		for i in range(attributes.length) :
			attr = attributes.item(i);
			if "name" == attr.name :
				definition.name = attr.value;
			else :
				raise Exception("Unknown attribute", attr.name);
				
	for child in node.childNodes :
		if xml.dom.Node.ELEMENT_NODE == child.nodeType :
			if "class" == child.nodeName :
				obj = Class();					
				parse_class(obj, child);					
				definition.classes.append(obj);
			elif "routine" == child.nodeName :
				routine = Routine();					
				parse_routine(routine, child);					
				definition.routines.append(routine);
			else :
				raise Exception("Unknown tag", child.nodeName);
	

def parse_method(definition, node) :
	if True == node.hasAttributes() :
		type = None;
		reference = False;
		constant = False;
	
		attributes = node.attributes;
		for i in range(attributes.length) :
			attr = attributes.item(i);
			if "name" == attr.name :
				definition.name = attr.value;
			elif "type" == attr.name :
				type = attr.value;
			elif "reference" == attr.name :
				if ("true" == attr.value) :
					reference = True;
			elif "constant" == attr.name :
				if ("true" == attr.value) :
					constant = True;
			elif "description" == attr.name :
				definition.description = attr.value;
			elif "rdescription" == attr.name :
				definition.rdescription = attr.value;
			else :
				raise Exception("Unknown attribute", attr.name);
				
		if (None != type) :
			definition.result = Type();
			definition.result.name = type;
			definition.result.constant = constant;
			definition.result.reference = reference;
				
	for child in node.childNodes :
		if xml.dom.Node.ELEMENT_NODE == child.nodeType :
			if "param" == child.nodeName :
				parameter = Parameter();					
				parse_parameter(parameter, child);					
				definition.parameters.append(parameter);
			else :
				raise Exception("Unknown tag", child.nodeName);
				
def parse_module(definition, node) :
	if True == node.hasAttributes() :		
		attributes = node.attributes;
		for i in range(attributes.length) :
			attr = attributes.item(i);
			if "name" == attr.name :
				definition.name = attr.value;
			else :
				raise Exception("Unknown attribute", attr.name);
				
	for child in node.childNodes :
		if xml.dom.Node.ELEMENT_NODE == child.nodeType :
			if "interface" == child.nodeName :
				interface = Interface();					
				parse_interface(interface, child);					
				definition.interfaces.append(interface);
			elif "namespace" == child.nodeName :
				namespace = Namespace();					
				parse_namespace(namespace, child);					
				definition.namespace = namespace;
			elif "platform" == child.nodeName :
				platform = Platform();					
				parse_platform(platform, child);					
				definition.platforms.append(platform);
			else :
				raise Exception("Unknown tag", child.nodeName);

def parse_namespace(definition, node) :
	if True == node.hasAttributes() :		
		attributes = node.attributes;
		for i in range(attributes.length) :
			attr = attributes.item(i);
			if "name" == attr.name :
				definition.name = attr.value;
			else :
				raise Exception("Unknown attribute", attr.name);
				
	for child in node.childNodes :
		if xml.dom.Node.ELEMENT_NODE == child.nodeType :
			if "namespace" == child.nodeName :
				namespace = Namespace();					
				parse_namespace(namespace, child);					
				definition.child = namespace;
			else :
				raise Exception("Unknown tag", child.nodeName);
	

def parse_parameter(definition, node) :
	if True == node.hasAttributes() :
		attributes = node.attributes;
		for i in range(attributes.length) :
			attr = attributes.item(i);
			if "name" == attr.name :
				definition.name = attr.value;
			elif "type" == attr.name :
				definition.type.name = attr.value;
			elif "reference" == attr.name :
				if ("true" == attr.value) :
					definition.type.reference = True;
			elif "constant" == attr.name :
				if ("true" == attr.value) :
					definition.type.constant = True;
			elif "description" == attr.name :
					definition.description = attr.value;
			else :
				raise Exception("Unknown attribute", attr.name);
					
				
def parse_platform (definition, node) :
	if True == node.hasAttributes() :		
		attributes = node.attributes;
		for i in range(attributes.length) :
			attr = attributes.item(i);
			if "name" == attr.name :
				definition.name = attr.value;
			elif "size" == attr.name :
				definition.size = attr.value;
			elif "type" == attr.name :
				definition.type = attr.value;
			else :
				raise Exception("Unknown attribute", attr.name);
	

def parse_routine(definition, node) :
	if True == node.hasAttributes() :
		type = "";
		reference = False;
		constant = False;
	
		attributes = node.attributes;
		for i in range(attributes.length) :
			attr = attributes.item(i);
			if "name" == attr.name :
				definition.name = attr.value;
			elif "type" == attr.name :
				type = attr.value;
			elif "reference" == attr.name :
				if ("true" == attr.value) :
					reference = True;
			elif "constant" == attr.name :
				if ("true" == attr.value) :
					constant = True;
			elif "description" == attr.name :
				definition.description = attr.value;
			elif "rdescription" == attr.name :
				definition.rdescription = attr.value;
			else :
				raise Exception("Unknown attribute", attr.name);
				
		if ("" != type) :
			definition.result = Type();
			definition.result.name = type;
			definition.result.constant = constant;
			definition.result.reference = reference;
				
	for child in node.childNodes :
		if xml.dom.Node.ELEMENT_NODE == child.nodeType :
			if "param" == child.nodeName :
				parameter = Parameter();					
				parse_parameter(parameter, child);					
				definition.parameters.append(parameter);
			else :
				raise Exception("Unknown tag", child.nodeName);
					