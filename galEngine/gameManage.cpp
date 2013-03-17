#include "gameManage.h"
#include "parse.h"
#include "keyManager.h"

gameManager::gameManager()
{
}

gameManager::~gameManager()
{

}

void gameManager::update()
{
	if (keyManager::press)
	{
		keyManager::press = false;
		if (_str.get_string_status() == galString::oneToOne)
		{
			_str.set_string_status(galString::Finish);
		}else
		{
			script s = Parse::read_next_script();
			if (s.kind == PARSE::draw)
			{
				_pic.set_layer(s.layer, s);
			}else if (s.kind == PARSE::drawbg)
			{
				_pic.set_bg(s);
			}else if (s.kind == PARSE::print)
			{
				_str.add_string(s.str);
			}else if (s.kind == PARSE::clear)
			{
				_pic.clear_layer(s.layer);
			}
		}
	}
	_pic.update();
	_str.update();
}

void gameManager::draw()
{
	_pic.draw();
	_str.draw();
}