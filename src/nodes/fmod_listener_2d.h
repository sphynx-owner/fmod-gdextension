#ifndef GODOTFMOD_FMOD_LISTENER_2D_H
#define GODOTFMOD_FMOD_LISTENER_2D_H

#include "scene/main/node.h"
#include "scene/2d/node_2d.h"
#include "fmod_listener.h"

//namespace godot {
    class FmodListener2D : public FmodListener<FmodListener2D, Node2D> {
        GDCLASS(FmodListener2D, Node2D)

    protected:

        static void _bind_methods();
    };
//}

#endif// GODOTFMOD_FMOD_LISTENER_2D_H
