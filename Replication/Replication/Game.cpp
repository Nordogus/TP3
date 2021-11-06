#include "Game.h"

using namespace uqac::game;

Game* Game::GetInstance()
{
	if (singleton == nullptr)
		singleton = std::make_unique<Game>();

	return singleton.get();
}

template<typename T>
void Game::Init()
{
	AddClassId(Player);
}

template<typename T>
void Game::AddClassId(T type)
{
	if (!classIds.find(type))
	{
		classIds[type.classId] = type;
		classCount++;
	}
}

bool Game::EntityExist(Entity entity)
{
	return (std::find(_entities.begin(), _entities.end(), entity) != _entities.end());
}

Entity uqac::game::Game::GetEntity(int id)
{
	std::vector<Entity>::iterator it = _entities.begin();
	for (it; it != _entities.end(); it++)
	{
		if (it->entityID == id)
			return *it;
	}
}