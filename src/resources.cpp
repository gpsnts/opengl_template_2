#include "headers/resources.hpp"

// Instance (because it's a static)
std::map<std::string, Shader>	Resources::shaders;

Shader Resources::assign_shader(
	const char *vertex_shader_file,
	const char *fragment_shader_file,
	string key_shader
)
{
	Shader _shader;
	_shader.compile(vertex_shader_file, fragment_shader_file);
	shaders[key_shader] = _shader;
	return shaders[key_shader];
}

Shader Resources::get_shader(string key_shader)
{
	return shaders[key_shader];
}

void Resources::clean()
{
	for (auto iter_shaders : shaders)
	{
		std::cout << "Deleting - " << iter_shaders.first << std::endl;
		glDeleteProgram(iter_shaders.second.getProgram());
	}
}