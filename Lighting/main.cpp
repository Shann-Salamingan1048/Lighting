#include "progress/prog2.h"
int main()
{
	bool fullscreen = false;
	prog2 p2(fullscreen);
	//p2.colors();
	//p2.basicLighting();
	//p2.moveLightSourceUsingSinOrCos();
	//p2.playAroundThe3Lighting_Ambient_Diffuse_Specular();
	//p2.doShadingInViewSpaceInsteadOfWorldSpace();
	//p2.implementGouraudShading();
	//p2.materials();
	//p2.changeLightSourceColor(); // still has issues in light source. for example the color of the light is green then the cube object is green
	//p2.simulateRealWorldObjects();
	p2.lighting_maps();
	
	return 0;
}
// 130/523