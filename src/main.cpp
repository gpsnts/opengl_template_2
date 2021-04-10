// #include <glm/glm.hpp>

#include "headers/shader.hpp"
#include "headers/renderer.hpp"
#include "headers/resources.hpp"
#include "headers/application.hpp"

int main(int argc, char *argv[])
{
	bool show_fps = false;

	if (argc >= 2)
	{
		string show_fps_flag(argv[1]);
		if (show_fps_flag == "show_fps") show_fps = true;
	}
	
	Application *app = new Application(800, 600, "Test");
	Renderer render;
	
	if (!app->init()) return -1;

	Resources::assign_shader(
		"../src/shaders/triangle_vs.glsl",
		"../src/shaders/triangle_fs.glsl",
		"shader"
	);

	Resources::assign_shader(
		"../src/shaders/triangle_vs.glsl",
		"../src/shaders/triangle_fs_uniform.glsl",
		"shader_uniform"
	);

	// Positions
	render.set_data(
		POSITION,
		"Positions_1",
		{
			 0.0f,  0.0f,  0.0f,
       0.33f, 0.50f, 0.0f,
      -0.33f, 0.50f, 0.0f,

       0.0f,   0.0f,  0.0f,
      -0.33f, -0.50f, 0.0f,
       0.33f, -0.50f, 0.0f
		}
	);

	render.set_data(
		POSITION,
		"Positions_2",
		{
			 0.0f,  0.0f,  0.0f,
       0.33f, 0.50f, 0.0f,
      -0.33f, 0.50f, 0.0f,

       0.0f,   0.0f,  0.0f,
      -0.33f, -0.50f, 0.0f,
       0.33f, -0.50f, 0.0f,

			 0.0f,   0.0f,  0.0f,
			 0.33f,  0.50f, 0.0f,
			 0.33f, -0.50f, 0.0f
		}
	);

	render.set_data(
		POSITION,
		"Positions_3b",
		{
			 0.0f,  0.0f,  0.0f,
       0.33f, 0.50f, 0.0f,
      -0.33f, 0.50f, 0.0f,

       0.0f,   0.0f,  0.0f,
      -0.33f, -0.50f, 0.0f,
       0.33f, -0.50f, 0.0f
		}
	);
	// End - Positions

	// Colors
	render.set_data(
		COLOR,
		"Colors_3b",
		{
			1.0f, 0.0f, 0.0f,
      1.0f, 0.0f, 1.0f,
      0.0f, 0.0f, 1.0f,

      0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 1.0f,
      0.0f, 1.0f, 0.0f
		}
	);
	// End - Colors

	// Data
	render.set_data(
		DATA,
		"Data_3a",
		{
			0.0f,  0.0f,  0.0f,
      0.33f, 0.50f, 0.0f,
     -0.33f, 0.50f, 0.0f,

      0.0f, 1.0f, 1.0f,
      0.0f, 1.0f, 1.0f,
      0.0f, 1.0f, 1.0f
		}
	);
	// End - Data

	render.set_data(
		POSITION,
		"Positions_4",
		{
			0.33f,  0.33f, 0.0f,
			0.50f, -0.50f, 0.0f,
		 -0.50f, -0.50f, 0.0f,
		 -0.33f,  0.33f, 0.0f 
		}
	);

	// EBO
	render.set_ebo_data(
		"EBO_4",
		{
			0, 1, 3,
			1, 2, 3
		}
	);
	// End - EBO


	// Attrib
	// Ex - 1
	render.bind_vertex("VAO_1");
	render.bind_buffer(POSITION, "VBO_Position_1", "Positions_1");
	render.vbo_attrib("VBO_Position_1", 0, 0, 0);
	//
	// Ex - 2
	render.bind_vertex("VAO_2");
	render.bind_buffer(POSITION, "VBO_Position_2", "Positions_2");
	render.vbo_attrib("VBO_Position_2", 0, 0, 0);
	//
	// Ex - 3a
	render.bind_vertex("VAO_3a");
	render.bind_buffer(DATA, "VBO_Data_3a", "Data_3a");
	render.vbo_attrib("VBO_Data_3a", 0, 0, 0);
	render.vbo_attrib("VBO_Data_3a", 1, 0, 9);
	//
	// Ex - 3b
	render.bind_vertex("VAO_3b");
	render.bind_buffer(POSITION, "VBO_Position_3b", "Positions_3b");
	render.bind_buffer(COLOR, "VBO_Color_3b", "Colors_3b");
	render.vbo_attrib("VBO_Position_3b", 0, 0, 0);
	render.vbo_attrib("VBO_Color_3b", 1, 0, 0);
	//
	// Ex - 4
	render.bind_vertex("VAO_4");
	render.bind_buffer(POSITION, "VBO_Position_4", "Positions_4");
	render.bind_ebo_buffer("EBO_Buffer_4", "EBO_4");
	render.vbo_attrib("VBO_Position_4", 0, 3, 0);
	//
	// End - Attrib

	bool show_1 = false,
			 show_2 = false, 
			 show_3a = false, 
			 show_3b = false,
			 show_4 = false;

	while (!glfwWindowShouldClose(app->get_window()))
	{
		if (show_fps) Application::frames_per_second(app->get_window());
		Application::process_input(app->get_window());

		if (glfwGetKey(app->get_window(), GLFW_KEY_Q) == GLFW_PRESS) show_1 = false;
		if (glfwGetKey(app->get_window(), GLFW_KEY_A) == GLFW_PRESS) show_1 = true;

		if (glfwGetKey(app->get_window(), GLFW_KEY_W) == GLFW_PRESS) show_2 = false;
		if (glfwGetKey(app->get_window(), GLFW_KEY_S) == GLFW_PRESS) show_2 = true;

		if (glfwGetKey(app->get_window(), GLFW_KEY_E) == GLFW_PRESS) show_3a = false;
		if (glfwGetKey(app->get_window(), GLFW_KEY_D) == GLFW_PRESS) show_3a = true;

		if (glfwGetKey(app->get_window(), GLFW_KEY_R) == GLFW_PRESS) show_3b = false;
		if (glfwGetKey(app->get_window(), GLFW_KEY_F) == GLFW_PRESS) show_3b = true;

		if (glfwGetKey(app->get_window(), GLFW_KEY_T) == GLFW_PRESS) show_4 = false;
		if (glfwGetKey(app->get_window(), GLFW_KEY_G) == GLFW_PRESS) show_4 = true;
		
		glClearColor(0.33f, 0.1f, 0.25f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT);

		if (show_1)
		{
			GLint colorLoc = glGetUniformLocation(
				Resources::get_current_shaders()["shader_uniform"].getProgram(),
				"inputColor"
			);
			glUseProgram(Resources::get_current_shaders()["shader_uniform"].getProgram());
			glBindVertexArray(render.get_vaos()["VAO_1"]);
			if (colorLoc > -1) glUniform4f(colorLoc, 1.0f, 0.0f, 0.0f, 1.0f);
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);
		}

		if (show_2)
		{
			GLint colorLoc = glGetUniformLocation(
				Resources::get_current_shaders()["shader_uniform"].getProgram(),
				"inputColor"
			);
			glUseProgram(Resources::get_current_shaders()["shader_uniform"].getProgram());
			glBindVertexArray(render.get_vaos()["VAO_2"]);
			if (colorLoc > -1) glUniform4f(colorLoc, 1.0f, 1.0f, 1.0f, 1.0f);
			glDrawArrays(GL_TRIANGLES, 0, 6);

			if (colorLoc > -1) glUniform4f(colorLoc, 0.0f, 0.0f, 1.0f, 1.0f);
			glDrawArrays(GL_LINE_LOOP, 3, 6);
			
			if (colorLoc > -1) glUniform4f(colorLoc, 0.0f, 1.0f, 1.0f, 1.0f);
			glDrawArrays(GL_LINE_LOOP, 6, 9);

			glBindVertexArray(0);
		}

		if (show_3a)
		{
			glUseProgram(Resources::get_current_shaders()["shader"].getProgram());
			glBindVertexArray(render.get_vaos()["VAO_3a"]);
  		glDrawArrays(GL_TRIANGLES, 0, 3);
			glBindVertexArray(0);
		}

		if (show_3b)
		{
			glLineWidth(15);
			glPointSize(10);

			glUseProgram(Resources::get_current_shaders()["shader"].getProgram());
			glBindVertexArray(render.get_vaos()["VAO_3b"]);
  		glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);
		}

		if (show_4)
		{
			GLint colorLoc = glGetUniformLocation(
				Resources::get_current_shaders()["shader_uniform"].getProgram(),
				"inputColor"
			);
			glUseProgram(Resources::get_current_shaders()["shader_uniform"].getProgram());
			glBindVertexArray(render.get_vaos()["VAO_4"]);
			if (colorLoc > -1) glUniform4f(colorLoc, 1.0f, 0.0f, 1.0f, 1.0f);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			if (colorLoc > -1) glUniform4f(colorLoc, 0.0f, 0.0f, 0.0f, 10.0f);
			glDrawElements(GL_LINE_LOOP, 6, GL_UNSIGNED_INT, 0);

			glBindVertexArray(0);
		}

		glfwSwapBuffers(app->get_window());
		glfwPollEvents();
	}

	Resources::clean();
	render.clean();
	delete app, render;
	glfwTerminate();
	return 0;
}