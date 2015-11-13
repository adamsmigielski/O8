import subprocess;

print("Execute tests for Math\n\n");
math_result = subprocess.call(["..\\..\\Build\\O8\\bin\\Debug\\math_Test.exe", "log=math_tests.txt"]);

print("Execute tests for Containers\n\n");
containers_result = subprocess.call(["..\\..\\Build\\O8\\bin\\Debug\\containers_Test.exe", "log=math_tests.txt"]);

print("\n\nExecute tests for WS\n\n");
ws_result = subprocess.call(["..\\..\\Build\\O8\\bin\\Debug\\WS_Test.exe", "log=ws_tests.txt"]);

print("\n\nExecute tests for GI\n\n");
gi_result = subprocess.call(["..\\..\\Build\\O8\\bin\\Debug\\GI_Test.exe", "log=gi_tests.txt"]);

print("\n\nSummary\n");

if 0 != math_result:
	print("Math failed");

if 0 != containers_result:
	print("Containers failed");
	

if 0 != ws_result:
	print("WS failed");
	

if 0 != gi_result:
	print("GI failed");
	

