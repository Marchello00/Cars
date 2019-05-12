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
//    IStreetCarBuilder carBuilder;
//    carBuilder.create(ECarName::PEPPER);
    ISuperCarBuilder carBuilder;
    carBuilder.create(ECarName::THUNDERBOLT);
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
    if (m_player.getScore() == m_player.getGoal()) {
        bool need_msg = true;
        if (m_player.getGoal() &&
            m_player.getGoal() % HEALBONUS_SPAWN_PERIOD == 0) {
            generateHeal();
            m_player.setPieMessage();
            need_msg = false;
        }
        generatePoints();
        if (need_msg) m_player.setMissionScore();
    }
    for (auto &c : commands) {
        c->execute(*this);
    }
    commands.clear();
    m_window.update();
    for (const auto &b : bonus) {
        b->update();
    }
    m_level.notify();
    m_player.update(getElapsed().asSeconds(), getAccumulateElapsed(), bonus);
    m_textShow.clear();
    m_textShow.addText(m_player.getText());
    std::vector<std::shared_ptr<GBonus>> good;
    for (const auto &b : bonus) {
        if (!b->outOfDate()) {
            good.push_back(b);
        }
    }
    std::swap(good, bonus);
    good.clear();
}

void Game::render() {
    m_window.beginDraw();
    m_level.render(*m_window.getRenderWindow());
    m_player.render(*m_window.getRenderWindow());
    for (const auto &b : bonus) {
        b->render(*m_window.getRenderWindow());
    }
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

void Game::addBonus(const std::shared_ptr<GBonus> &b) {
    bonus.push_back(b);
}

void Game::generatePoints(int n) {
    for (int i = 0; i < n; ++i) {
        commands.push_back(std::make_shared<GeneratePointCommand>());
    }
    m_player.setGoal(m_player.getGoal() + n * POINT_SCORE);
}

void Game::generateHeal() {
    commands.push_back(std::make_shared<GenerateHealCommand>());
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
