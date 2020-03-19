#pragma once

#include <cstdint>
#include "Unit.hpp"
#include "widget.hpp"
#include "window.hpp"
#include "button.hpp"
#include "EventCatcher.hpp"

class ItemChooserDialog {
public:
	using Callback = void (*)(void *ptr, bool updated, uint8_t newval);
	ItemChooserDialog(const char *title, const char * const *items,
			uint8_t initial_selection, Callback cb, void *ptr);
	~ItemChooserDialog();
private:
	void ButtonPressed(Widget *w);
	void EventCaught(Widget *w, GUIEvent_t *ev);
	Window *w;
	Callback cb;
	void *ptr;
	uint8_t value;
};
