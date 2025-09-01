#include "Axe.hpp"
#include "Bee.hpp"
#include "Branches.hpp"
#include "Clouds.hpp"
#include "GameUI.hpp"
#include "Log.hpp"
#include "Player.hpp"
#include "Rip.hpp"
#include "Tree.hpp"

#include <exception>
#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

int main() {
    // Create a video mode object
    sf::VideoMode vm(1920, 1080);

    // Create and open a window for the game
    sf::RenderWindow window(vm, "Timber", sf::Style::Default);
    // Set FPS limit
    window.setFramerateLimit(60);

    // Create background texture and sprite
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/graphics/background.png")) {
        std::cerr << "Error when loading background texture" << std::endl;
        return -1;
    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    try {
        // Create clouds
        Clouds clouds("assets/graphics/cloud.png");
        clouds.spawnClouds(3);

        // Create a tree
        Tree tree("assets/graphics/tree.png");
        tree.centerHorizontally(window);

        // Create a bee
        Bee bee("assets/graphics/bee.png");
        bee.setPosition(0, 800);

        // Create branches
        Branches branches("assets/graphics/branch.png", 6);

        // Create player
        Player player("assets/graphics/player.png");

        // Create axe
        Axe axe("assets/graphics/axe.png");

        // Create flying log
        Log log("assets/graphics/log.png");

        // Create rip gravestone
        Rip rip("assets/graphics/rip.png");

        // Create UI
        GameUI ui("assets/fonts/KOMIKAP_.ttf");
        ui.setScorePosition(20, 20);
        ui.setMessagePosition(1920 / 2.0f, 1080 / 2.0f);
        ui.centerMessage();
        ui.setupTimebar(6.0f, 400.0f, 80.0f, sf::Color::Red, sf::Vector2f(1920.0f / 2 - 200, 980.0f));

        // Track whether the game is running
        bool paused = true;

        // Control player input
        bool acceptInput = false;

        // Game score
        int score = 0;

        sf::Clock clock;

        // Main game loop
        while (window.isOpen()) {

            // Event handling
            sf::Event event;
            while (window.pollEvent(event)) {
                if ((event.type == sf::Event::Closed) ||
                    (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                    paused = false;
                    acceptInput = true;
                    score = 0;
                    player.reset();
                    rip.hide();
                    branches.reset();
                    // Reset UI
                    ui.reset();
                    // Reset game clock
                    clock.restart();
                }

                if (event.type == sf::Event::KeyReleased &&
                    (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)) {
                    axe.hide();
                }

                if (acceptInput) {
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
                        score++;
                        player.setPosition(Side::LEFT);
                        axe.setPositionBySide(Side::LEFT);
                        branches.updateBranches(score);
                        log.launch(Side::LEFT);
                    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
                        score++;
                        player.setPosition(Side::RIGHT);
                        axe.setPositionBySide(Side::RIGHT);
                        branches.updateBranches(score);
                        log.launch(Side::RIGHT);
                    }
                }
            }

            if (!paused) {
                sf::Time dt = clock.restart();
                // Update timebar
                ui.updateTimebar(dt.asSeconds());
                if (ui.isTimeUp()) {
                    paused = true;
                    acceptInput = false;
                    ui.setMessage("Out of time");
                    ui.showMessage(true);
                    ui.centerMessage();
                }
                // Update game objects position
                clouds.update(dt.asSeconds());
                bee.update(dt.asSeconds());
                log.update(dt.asSeconds());
                ui.updateScore(score);

                // Check if player is squished
                if (branches.isPlayerSquished(player.getCurrentSide())) {
                    paused = true;
                    acceptInput = false;
                    player.hide();
                    rip.show(player.getPosition().x, player.getPosition().y, player.getCurrentSide());
                    log.reset();
                    ui.setMessage("WASTED!!!");
                    ui.showMessage(true);
                    ui.centerMessage();
                }
            }

            // Clear everything from the last frame
            window.clear();

            // Draw game scene
            window.draw(backgroundSprite);
            window.draw(clouds);
            window.draw(tree);
            window.draw(player);
            window.draw(axe);
            window.draw(branches);
            window.draw(log);
            window.draw(rip);
            window.draw(bee);
            window.draw(ui);

            // Show everything we just draw
            window.display();
        }

    } catch (const std::exception &e) {
        std::cerr << "Error during game initialization: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
