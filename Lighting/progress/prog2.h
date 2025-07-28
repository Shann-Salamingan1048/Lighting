#pragma once
#include "../global.h"
#include "../Camera.h"
#include "../frameRate.h"
#include "../Shader.h"
#include "../Texture.h"
enum class themeChoices // use enum class instead of enum to prevents implicit conversions
// i.e. enum class Color { Red, Green, Blue };
//int x = Color::Red; // ERROR (must use static_cast)
{
    DESERT,
    FACTORY,
    HORROR,
    BIOCHEMICAL_LAB
};
constexpr float theme_Background_color[4][4] =
{
    {0.75f, 0.52f, 0.3f, 1.0f},
    {0.1f, 0.1f, 0.1f, 1.0f},
    {0.0f, 0.0f, 0.0f, 1.0f},
    {0.9f, 0.9f, 0.9f, 1.0f}
};
constexpr glm::vec3 pointLightColorsChoices[4][4] =
{
    {
        glm::vec3(1.0f, 0.6f, 0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f),
        glm::vec3(1.0f, 1.0, 0.0),
        glm::vec3(0.2f, 0.2f, 1.0f)
    },
    {
        glm::vec3(0.2f, 0.2f, 0.6f),
        glm::vec3(0.3f, 0.3f, 0.7f),
        glm::vec3(0.0f, 0.0f, 0.3f),
        glm::vec3(0.4f, 0.4f, 0.4f)
    },
    {
        glm::vec3(0.1f, 0.1f, 0.1f),
        glm::vec3(0.1f, 0.1f, 0.1f),
        glm::vec3(0.1f, 0.1f, 0.1f),
        glm::vec3(0.3f, 0.1f, 0.1f)
    },
    {
        glm::vec3(0.4f, 0.7f, 0.1f),
        glm::vec3(0.4f, 0.7f, 0.1f),
        glm::vec3(0.4f, 0.7f, 0.1f),
        glm::vec3(0.4f, 0.7f, 0.1f)
    }
};
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
    void specular_maps();

    void light_caster();
    void attenuation();
    void spot();
    void spot_soft();

    void multiple_lights();
public: // practices
    void moveLightSourceUsingSinOrCos();
    void playAroundThe3Lighting_Ambient_Diffuse_Specular();
    void doShadingInViewSpaceInsteadOfWorldSpace();
    void implementGouraudShading(); // basically a phone shading that is implemented in the vertex shader or .vert

    void changeLightSourceColor();
    void simulateRealWorldObjects(); // diffuse became the rgb value 
    // ambient is the dark side color 
    //specular is the bright spot of the light

    void Wood_Metal(); // the metal wont shine and wood will shine
    void emissionMap();

    void desert_factory_horror_biochemical(themeChoices tc);
    
    void desert(const Shader& shader, const glm::vec3 pointLightPositions[], const glm::vec3 pointLightColors[]) const;
    void factory(const Shader& shader, const glm::vec3 pointLightPositions[], const glm::vec3 pointLightColors[]) const;
    void horror(const Shader& shader, const glm::vec3 pointLightPositions[], const glm::vec3 pointLightColors[]) const;
    void biochemical(const Shader& shader, const glm::vec3 pointLightPositions[], const glm::vec3 pointLightColors[]) const;


public: // experiments
    void trySpecularMapColored();
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
