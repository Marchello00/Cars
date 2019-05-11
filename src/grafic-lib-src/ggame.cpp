#include "src/grafic-lib/ggame.h"

Game::Game() :
        m_window("Cars", sf::Vector2u(128 * 8, 128 * 8)) {
    m_level.loadFromFile("maps/norm_test.tmx");
}

Game::~Game() {}

void Game::handleInput() {

}

void Game::update() {
    m_window.update();
}

void Game::render() {
    m_window.beginDraw();
    m_window.draw(m_level);
    m_window.endDraw();
}

Window *Game::getWindow() {
    return &m_window;
}
