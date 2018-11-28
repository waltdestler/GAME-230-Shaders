#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <cmath>

using namespace sf;

void update_state(float dt);
void render_frame();

RenderWindow window;

RectangleShape shape;
Texture tex;
Shader shader;

float total_time = 0;

int main()
{
	window.create(VideoMode(800, 600), "SFML Shaders Example");

	tex.loadFromFile("cowboy.png");
	shader.loadFromFile("vertex_shader.vert", "fragment_shader.frag");

	shape.setSize(Vector2f(300, 300));
	shape.setPosition(50, 50);
	shape.setTexture(&tex);

	Clock clock;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float dt = clock.restart().asSeconds();
		total_time += dt;

		update_state(dt);
		render_frame();
		window.display();
	}

	return 0;
}

void update_state(float dt)
{
	Vector2f pos = shape.getPosition();

	if (Keyboard::isKeyPressed(Keyboard::Left))
		pos.x -= 200 * dt;
	if (Keyboard::isKeyPressed(Keyboard::Right))
		pos.x += 200 * dt;
	if (Keyboard::isKeyPressed(Keyboard::Up))
		pos.y -= 200 * dt;
	if (Keyboard::isKeyPressed(Keyboard::Down))
		pos.y += 200 * dt;

	shape.setPosition(pos);
}

void render_frame()
{
	window.clear(Color::Black);

	shader.setUniform("texture", tex);
	window.draw(shape, &shader);
}