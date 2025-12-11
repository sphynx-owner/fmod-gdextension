#ifndef GODOTFMOD_FMOD_LISTENER_3D_H
#define GODOTFMOD_FMOD_LISTENER_3D_H

#include "scene/main/node.h"
#include "scene/3d/node_3d.h"
#include "fmod_listener.h"

//namespace godot {
    class FmodListener3D : public FmodListener<FmodListener3D, Node3D> {
        GDCLASS(FmodListener3D, Node3D)

    protected:
        static void _bind_methods();
    };
//}

#endif// GODOTFMOD_FMOD_LISTENER_3D_H
