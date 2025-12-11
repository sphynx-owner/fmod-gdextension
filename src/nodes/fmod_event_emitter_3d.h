#ifndef GODOTFMOD_FMOD_EVENT_EMITTER_3D_H
#define GODOTFMOD_FMOD_EVENT_EMITTER_3D_H

#include "scene/main/node.h"
#include "scene/3d/node_3d.h"
#include "fmod_event_emitter.h"

//namespace godot {
    class FmodEventEmitter3D : public FmodEventEmitter<FmodEventEmitter3D, Node3D> {
        friend class FmodEventEmitter<FmodEventEmitter3D, Node3D>;
        GDCLASS(FmodEventEmitter3D, Node3D)

    private:
        void set_space_attribute_impl(const Ref<FmodEvent>& p_event) const;
        void free_impl();

    public:
        FmodEventEmitter3D() = default;
        ~FmodEventEmitter3D() override = default;

        void _notification(int p_what);

        static void _bind_methods();
    };
//}

#endif// GODOTFMOD_FMOD_EVENT_EMITTER_3D_H