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
	//p2.lighting_maps();
	//p2.specular_maps();
	//p2.Wood_Metal();
	//p2.trySpecularMapColored();
	//p2.emissionMap();
	//p2.light_caster();
	//p2.attenuation();
	//p2.spot();
	//p2.spot_soft();
	//p2.multiple_lights();
	p2.desert_factory_horror_biochemical(themeChoices::BIOCHEMICAL_LAB);
	return 0;
}
// 153/523