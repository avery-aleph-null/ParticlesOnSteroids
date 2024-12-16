#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Particle.h"
#include "Matrix.h"

using namespace std;

class Engine {
private:
    sf::RenderWindow m_Window;
    vector<Particle> m_Particles;

    unique_ptr<Matrix> rotation;
    unique_ptr<Matrix> scale;
    unique_ptr<Matrix> translate;

    void processEvents();
    void update(float dt);
    void render();

    void spawnFirework(float x, float y);

public:
    Engine(int w, int h, const string &title);
    void run();
};

#endif
