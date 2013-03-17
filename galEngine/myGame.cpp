#include "fps.h"
#include "font.h"
#include "sysConfig.h"
#include "fontString.h"
#include "keyManager.h"
#include "stringManager.h"
#include "resourceManager.h"
#include "parse.h"
#include "gameManage.h"
void init()
{
	al_init();
	al_install_mouse();
	al_install_keyboard();
	al_install_audio();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_acodec_addon();
	al_init_primitives_addon();
	CharFont::loadFont();
	sysConfig::init();
	Parse::init();
	wcout.imbue(locale(".936"));
}

int main(int argc, char** argv)
{
	init();
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_DISPLAY* display; 
	bool redraw = true;
	display = al_create_display(sysConfig::width, sysConfig::height);
	al_set_window_title(display, "test");
	fps f;
	timer = al_create_timer(1.0/60);
	queue = al_create_event_queue();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_start_timer(timer);
	ResourceManager::Instance();
#if _DEBUG_
	gameManager g;
	/*xiayuInt t;
	stringManager s1;
	s1.init();
	xiayuWString str(L"a.b");
	string str1 = str.ToString();
	ResourceManager* r = ResourceManager::Instance();
	script s = Parse::read_next_script();
	while (1)
	{
		s = Parse::read_next_script();
	}*/
#endif
	while (true)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			break;
		if (event.type == ALLEGRO_EVENT_TIMER)
			redraw = true;
		if (event.type == ALLEGRO_EVENT_KEY_DOWN 
			&& event.keyboard.keycode != ALLEGRO_KEY_ESCAPE)
		{
			keyManager::keyDown[event.keyboard.keycode] = true;
		}
		if (event.type == ALLEGRO_EVENT_KEY_UP 
			&& event.keyboard.keycode != ALLEGRO_KEY_ESCAPE)
		{
			keyManager::keyDown[event.keyboard.keycode] = false;
			keyManager::keyUP[event.keyboard.keycode] = true;
			keyManager::press = true;
		}
		if (event.type == ALLEGRO_EVENT_KEY_DOWN 
			&& event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			keyManager::keyDown[ALLEGRO_KEY_ESCAPE] = !keyManager::keyDown[ALLEGRO_KEY_ESCAPE];
		}
		if (redraw && al_is_event_queue_empty(queue)) 
		{
			redraw = false;
			f.updata();
			g.update();
			al_clear_to_color(al_map_rgb_f(1, 0, 0));
			f.draw();
			g.draw();
			al_flip_display();
		}
	}
}