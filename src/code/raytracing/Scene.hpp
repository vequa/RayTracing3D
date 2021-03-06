#pragma once

class Camera;
class Object;
class Light;

//=======

class Scene
{
public:
	std::vector<Camera*> cameras;
	std::vector<Object*> objects;
	std::vector<Light*> lights;

public:
	void addCamera(Camera* camera);
	void addObject(Object* object);
	void addLight(Light* light);

	void calculateCameraImage(unsigned int nr);
	void calculateCameraImages();

	sf::Image getCameraImage(unsigned int nr);
	uint8_t* getCameraImageBuffer(unsigned int nr);

	float cameraGetScale(unsigned int nr);
	void cameraSetScale(unsigned int nr, float scale);

	void cameraMove(unsigned int nr, float xamount, float yamount, float zamount);
	void cameraMoveToDirection(unsigned int nr, float amount);
	void cameraMovePerpendicularToDirection(unsigned int nr, float amount);
	void cameraRotateYaw(unsigned int nr, float amount);
	void cameraRotatePitch(unsigned int nr, float amount);

	std::tuple<float, float, float, float, float> cameraGetPositionAndRotation(unsigned int nr);
};
