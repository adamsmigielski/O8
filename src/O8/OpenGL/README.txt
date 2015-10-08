To generate files:
1 Get gl.xml: https://www.opengl.org/registry
2 parse.py gl.xml gl.json
3 command_list.py gl.json white_list.json 4.5
4 generate.py gl.json white_list.json gl.hpp Gl_loader.cpp