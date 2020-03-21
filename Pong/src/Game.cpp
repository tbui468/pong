#include "Game.h"


Game::Game() : m_screen(nullptr), m_round(nullptr), m_player1_score(0), m_player2_score(0), m_play(true) {

}

void Game::init() {
	m_screen = new Screen;
	m_screen->init();
}

void Game::loop() {
	using namespace std::literals::chrono_literals; //for pausing thread
	while (m_play) {
		m_screen->set_color(0, 0, 0);
		m_screen->draw_background();
		m_screen->draw_title(125, 200);
		m_screen->update_screen();
		std::this_thread::sleep_for(1.5s);


		int score_1 = 0;
		int score_2 = 0;

		while (m_play) {
			Round round(*m_screen, score_1, score_2);
			int point = round.start();
			switch (point) {
			case Point_player_1:
				score_1++;
				break;
			case Point_player_2:
				score_2++;
				break;
			case Point_quit:
				m_play = false;
				break;
			default:
				break;
			}
			std::this_thread::sleep_for(.2s);
			if (score_1 > 9 || score_2 > 9)
				break;

		}
	}
}

void Game::end() {
	m_screen->close();
	if(m_screen != nullptr) delete m_screen;
	if(m_round != nullptr) delete m_round;
}