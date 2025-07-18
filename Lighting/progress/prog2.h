#pragma once
#include "../global.h"
#include "../Camera.h"
#include "../frameRate.h"
#include "../Shader.h"
#include "../Texture.h"


class prog2
{
public:
	prog2();
	prog2(int width, int height);
    prog2(bool fullScreen);
    ~prog2();

public: // examples
    void colors(); // 1
    void basicLighting();

    void materials();

    void lighting_maps();
public: // practices
    void moveLightSourceUsingSinOrCos();
    void playAroundThe3Lighting_Ambient_Diffuse_Specular();
    void doShadingInViewSpaceInsteadOfWorldSpace();
    void implementGouraudShading(); // basically a phone shading that is implemented in the vertex shader or .vert

    void changeLightSourceColor();
    void simulateRealWorldObjects();
private:
    prog2(const prog2&) = delete;
    prog2& operator=(const prog2&) = delete;
    prog2(prog2&&) = delete;
    prog2& operator=(prog2&&) = delete;

private:
	void initGLFW();
    void glfwSets();
	void processInput(GLFWwindow* window);


private:
	GLFWwindow* m_window;
	int m_height, m_width;

private:
    // defaults
	constexpr static int m_defaultSize[2] = { 800, 800 }; // Width , Height
	constexpr static const char* m_defaultTitle = "Lighting";

private:
   bool firstMouse = true;
   float lastX;
   float lastY;
   void initLastXY();

private:
    Camera cam{ glm::vec3(0.0f,0.0f,3.0f) };
    frameRate fr;

private: // light
    glm::vec3 lightPos{ 1.2f, 1.0f, 2.0f };

private:
    // callbacks
    void framebuffer_size_callback(int width, int heigth);
    void scroll_callback(double xoffset, double yoffset);
    void mouse_callback(double xpos, double ypos);

private:
    // Static wrapper functions
    static void framebuffer_size_callback_wrapper(GLFWwindow* win, int width, int height);
    static void scroll_callback_wrapper(GLFWwindow* win, double xoffset, double yoffset);
    static void mouse_callback_wrapper(GLFWwindow* win, double xpos, double ypos);

private:
    void printMat4(const glm::mat4& mat, const std::string& name) const;

private:
    constexpr static float s_nearPlane = 0.1f;
    constexpr static float s_farPlane = 100.0f;
};
