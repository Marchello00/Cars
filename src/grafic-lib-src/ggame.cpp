#include "src/grafic-lib/ggame.h"

#include "genums.h"
#include "ground.h"

Game::Game() :
        m_window("Cars", sf::Vector2u(128 * 8, 128 * 8)),
        m_accumulate_elapsed(0) {
    m_textShow.setFont("images/ColumbiaRandomBoldItalic.ttf");
    m_level.loadFromFile("maps/norm_test.tmx");
    m_player.setImage("images/bc.png");
    m_player.setField(sf::Vector2f(128 * 8, 128 * 8));
    m_level.addRacer(&m_player);
    auto player_obj = m_level.getAllObjects("Player")[0];
    auto prect = player_obj.rect;
    m_player.setPosition({prect.left + prect.width / 2, prect.top + prect.height / 2});
    auto direction = player_obj.getPropertyString("orientation");
    m_player.setDirection(enums::getDirection(direction));
    IStreetCarBuilder carBuilder;
    carBuilder.create(ECarName::PEPPER);
//    ISuperCarBuilder carBuilder;
//    carBuilder.create(ECarName::THUNDERBOLT);
    m_player.setCar(carBuilder.getCar());
}

Game::~Game() {}

void Game::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_player.moveForward();
    } else {
        m_player.reactForward();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_player.moveBackward();
    } else {
        m_player.reactBackward();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_player.leftTurn(getElapsed().asSeconds());
    } else {
        m_player.reactLeft(getElapsed().asSeconds());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_player.rightTurn(getElapsed().asSeconds());
    } else {
        m_player.reactRight(getElapsed().asSeconds());
    }
}

void Game::update() {
    m_window.update();
    m_level.notify();
    m_player.update(getElapsed().asSeconds(), getAccumulateElapsed());
    m_textShow.clear();
    m_textShow.addText(m_player.getText());
}

void Game::render() {
    m_window.beginDraw();
    m_level.render(*m_window.getRenderWindow());
    m_player.render(*m_window.getRenderWindow());
    m_textShow.draw(*m_window.getRenderWindow());
    m_window.endDraw();
}

Window *Game::getWindow() {
    return &m_window;
}

sf::Time Game::getElapsed() {
    return m_elapsed;
}

void Game::restartClock() {
    m_elapsed = m_clock.restart();
    m_accumulate_elapsed += m_elapsed.asSeconds();
}

float &Game::getAccumulateElapsed() {
    return m_accumulate_elapsed;
}

void TextShow::clear() {
    text.clear();
}

void TextShow::addText(const std::string &ntext) {
    text += ntext;
}

void TextShow::draw(sf::RenderWindow &window) {
    sf::Text tobj;
    tobj.setFont(font);
    tobj.setString(text);
    tobj.setCharacterSize(FONT_SIZE);
    tobj.setFillColor(sf::Color::Black);
    window.draw(tobj);
}

bool TextShow::setFont(const std::string &path) {
    return font.loadFromFile(path);
}
