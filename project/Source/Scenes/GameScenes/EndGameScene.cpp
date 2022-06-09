/*
** EPITECH PROJECT, 2022
** project
** File description:
** EndGameScene
*/

#include "EndGameScene.hpp"

void Scene::EndGameScene::goToMainMenu()
{
    _nextScene = Scene::Scenes::MAIN_MENU;
}

Scene::EndGameScene::EndGameScene(std::shared_ptr<Settings> settings, std::shared_ptr<GameSettings> gameSettings) : AScene(settings)
{
    _buttons = loadObjects<Object::Button>("Conf/Scenes/EndGameScene/button.json");
    _buttons.at(0)->setCallBack(std::bind(&Scene::EndGameScene::goToMainMenu, this));
    _parallax = loadObjects<Object::Image>("Conf/Scenes/parallax.json");

    _nextScene = Scene::Scenes::END_GAME;
}

Scene::Scenes Scene::EndGameScene::handleEvent()
{
    _nextScene = Scene::Scenes::END_GAME;

    for (auto &button : _buttons)
        button->checkHover(GetMousePosition());
    return _nextScene;
}

Scene::EndGameScene::~EndGameScene()
{
}

void Scene::EndGameScene::draw()
{
    for (auto &parallax : _parallax)
        parallax->draw();
    for (auto &button : _buttons)
        button->draw();
}