#include "SceneManager.h"

#include "Scene.h"

#include <sstream>
#include <memory>

SceneManager::SceneManager()
	: m_currentScene(nullptr)
{
}


SceneManager::~SceneManager()
{
}

Scene* SceneManager::getCurrentScene() const
{
	return m_currentScene;
}

void SceneManager::addScene(std::unique_ptr<Scene> newScene, std::string sceneName)
{
	if (m_currentScene == nullptr)
		m_currentScene = newScene.get();

	m_sceneMap[sceneName] = std::move(newScene);
}

void SceneManager::loadNewScene(std::string _newScene)
{
	m_currentScene = m_sceneMap[_newScene].get();
}

void SceneManager::restartLevel()
{
	std::unique_ptr<Scene> restartedScene = m_currentScene->createNew();
	m_currentScene = restartedScene.get();

	std::stringstream ss;
	ss << "Level " << (m_currentScene->getLevelNum() + 1);
	m_sceneMap[ss.str()] = std::move(restartedScene);
}
