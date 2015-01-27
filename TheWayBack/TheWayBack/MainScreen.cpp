#include "MainScreen.h"
#include <iostream>

MainScreen::MainScreen(ContentManager* contentManager)
	: BaseScreen(contentManager)
{
	AnimationManager playerOne((*_pTextures)["char1"], _pContentManager->getTileSize());
	playerOne.addAnimation("walk_down", 1, 1, 3, 0.003f, LOOP, true);
	playerOne.addAnimation("walk_up", 4, 1, 3, 0.003f, LOOP, true);
	playerOne.addAnimation("walk_left", 2, 1, 3, 0.003f, LOOP, true);
	playerOne.addAnimation("walk_right", 3, 1, 3, 0.003f, LOOP, true);

	SoundManager playerSounds;
	playerSounds.addSound((*_pSounds)["collect"], "jump");

	_player = new Player(playerOne, playerSounds, 0.004f, sf::Vector2f(0, 0), sf::Vector2i(32, 32), _tileSize);

	TileMapLoader tileMap;
	tileMap.setMapsDir("Content/Maps");
	tileMap.load("map.tmx");
}

MainScreen::~MainScreen()
{
	delete _player;
	delete _animation;
}

void MainScreen::handleKeyPress(sf::Keyboard::Key key, bool isPressed)
{
	isPressed ? _player->handleKeyPress(key) : _player->handleKeyRelease(key);
}

// -----------------------------------------------------
// UPDATE FUNCTION--------------------------------------
// -----------------------------------------------------

void MainScreen::update(float gameTime)
{
	_player->update(gameTime);
}

// -----------------------------------------------------
// DRAW FUNCTION----------------------------------------
// -----------------------------------------------------

void MainScreen::draw(sf::RenderWindow &window)
{
	_player->draw(window);
}