#ifndef FMOD_EVENT_EMITTER_2D_GODOT_FMOD_H
#define FMOD_EVENT_EMITTER_2D_GODOT_FMOD_H

#include "fmod_event_emitter.h"
#include "studio/fmod_event.h"

#include <scene/2d/node_2d.h>

//namespace godot {
    class FmodEventEmitter2D : public FmodEventEmitter<FmodEventEmitter2D, Node2D>  {
        friend class FmodEventEmitter<FmodEventEmitter2D, Node2D>;
        GDCLASS(FmodEventEmitter2D, Node2D)

    private:
        void set_space_attribute_impl(const Ref<FmodEvent>& p_event) const;
        void free_impl();

    public:
        FmodEventEmitter2D() = default;
        ~FmodEventEmitter2D() override = default;

        void _notification(int p_what);

    protected:
        static void _bind_methods();
    };
//}

#endif// FMOD_EVENT_EMITTER_2D_GODOT_FMOD_H
