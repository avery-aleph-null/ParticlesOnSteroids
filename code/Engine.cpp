#include "Engine.h"
#include "RotationMatrix.h"
#include "ScalingMatrix.h"
#include "TranslationMatrix.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>

Engine::Engine(int w, int h, const std::string &title)
    : m_Window(sf::VideoMode(w,h), title)
{
    m_Window.setFramerateLimit(60);
    srand((unsigned)time(nullptr));

    // Initialize transformations
    rotation = std::make_unique<RotationMatrix>(0.0); 
    scale = std::make_unique<ScalingMatrix>(1.0);
    translate = std::make_unique<TranslationMatrix>(0.0,0.0);
}

void Engine::run() {
    sf::Clock clock;
    while (m_Window.isOpen()) {
        float dt = clock.restart().asSeconds();
        processEvents();
        update(dt);
        render();
    }
}

void Engine::processEvents() {
    sf::Event event;
    while (m_Window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_Window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                float x = (float)event.mouseButton.x;
                float y = (float)event.mouseButton.y;
                spawnFirework(x, y);
            }
        }
    }
}

void Engine::update(float dt) {
    for (auto &p : m_Particles) {
        p.update(dt);
    }
    m_Particles.erase(std::remove_if(m_Particles.begin(), m_Particles.end(),
                                     [](const Particle &p){return !p.isAlive();}),
                      m_Particles.end());
}

void Engine::render() {
    m_Window.clear(sf::Color::Black);

    // If we want to apply transformations before drawing, we can:
    // Instead of applying them directly to sf::Drawable (which doesn't apply easily),
    // we can update the particle positions first.
    // For demonstration, let's rotate particles around the window center:
    float cx = m_Window.getSize().x / 2.0f;
    float cy = m_Window.getSize().y / 2.0f;

    for (auto &p : m_Particles) {
        float px, py;
        p.getPosition(px, py);
        // Translate position so center is (0,0)
        double dx = px - cx;
        double dy = py - cy;

        // Apply transformations
        rotation->apply(dx, dy);
        scale->apply(dx, dy);
        translate->apply(dx, dy);

        // Move back
        dx += cx;
        dy += cy;
        p.setPosition((float)dx, (float)dy);

        m_Window.draw(p);
    }

    m_Window.display();
}

void Engine::spawnFirework(float x, float y) {
    int numParticles = 50 + rand()%50;
    for(int i=0; i<numParticles; i++) {
        float angle = float(rand()%360) * 3.14159f/180.0f;
        float speed = 50.0f + (rand()%100)/100.0f * 100.0f;
        float vx = std::cos(angle)*speed;
        float vy = std::sin(angle)*speed - 150.0f;

        sf::Uint8 r = static_cast<sf::Uint8>(rand()%256);
        sf::Uint8 g = static_cast<sf::Uint8>(rand()%256);
        sf::Uint8 b = static_cast<sf::Uint8>(rand()%256);
        sf::Color c(r,g,b,255);

        m_Particles.emplace_back(x, y, vx, vy, 3.0f, c, 2.0f);
    }
}
