#pragma once
#include "GLib.h"
#include <assert.h>

void* LoadFile(const char* i_pFilename, size_t& o_sizeFile);
GLib::Sprite* CreateSprite(const char* i_pFilename);