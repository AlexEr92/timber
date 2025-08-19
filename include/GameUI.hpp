#pragma once

#include <string>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

#include "Timebar.hpp"

class GameUI : public sf::Drawable {
public:
    GameUI();

    // Load font
    bool loadFont(const std::string &fontPath);

    // Update score display
    void updateScore(int newScore);

    void setScorePosition(float x, float y);

    void setMessage(const std::string &text);

    void setMessagePosition(float x, float y);

    void centerMessage();

    void showMessage(bool show);

    void reset();

    Timebar &getTimebar() { return m_timebar; }

    void setupTimebar(float totalTime, float width, float height, const sf::Color &color, const sf::Vector2f &position);

private:
    sf::Font m_font;
    sf::Text m_scoreText;
    sf::Text m_messageText;
    bool m_showMessage = true;
    Timebar m_timebar;

    bool isFontLoaded() const { return !m_font.getInfo().family.empty(); }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
