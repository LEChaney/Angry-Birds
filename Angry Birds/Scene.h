#pragma once

#include <memory>
#include <vector>

class b2World;
class b2Body;
class Object;
struct NVGcontext;

class Scene
{
public:
	virtual ~Scene();
	Scene(const Scene&) = delete;
	Scene(Scene&&) = delete;

	void update();
	b2Body* addObject(std::unique_ptr<Object>);
	void draw(NVGcontext*);

	static const float s_kPixelsPerMeter;
	static const float s_kGravity;

protected:
	Scene();

	std::vector<std::unique_ptr<Object>> m_objs;
	std::unique_ptr<b2World> m_world;
};

