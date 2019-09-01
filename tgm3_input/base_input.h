#pragma once

#include <vector>

class config;
struct tagRAWINPUT;

class base_input {
protected:
	// Game button bitmasks
	static const int mask_up = 32;
	static const int mask_down = 16;
	static const int mask_left = 8;
	static const int mask_right = 4;

	static const int mask_A = 2;
	static const int mask_B = 1;
	static const int mask_C = 32768;
	static const int mask_D = 16384;
	static const int mask_start = 128;

public:
	// Usage for raw input device
	virtual std::vector<int> get_usage() = 0;

	// Called every time a WM_INPUT message is received
	virtual void update(const tagRAWINPUT *input) = 0;

	// Return TGM3 buttons
	virtual unsigned short get_buttons_1p() const = 0;
	virtual unsigned short get_buttons_2p() const = 0;

	// Must be used on alt tab
	virtual void clear_buttons() = 0;

	// Initialize from config
	virtual void init(const config &cfg) = 0;
};
