#include <nodes/fmod_event_emitter_3d.h>

// using namespace godot;

void FmodEventEmitter3D::set_space_attribute_impl(const Ref<FmodEvent>& p_event) const {
    p_event->set_3d_attributes(get_global_transform());
}

void FmodEventEmitter3D::_notification(int p_what) {
    FmodEventEmitter<FmodEventEmitter3D, Node3D>::_notification(p_what);
}

void FmodEventEmitter3D::_bind_methods() {
    FmodEventEmitter<FmodEventEmitter3D, Node3D>::_bind_methods();

    ADD_SIGNAL(MethodInfo(BEAT_SIGNAL_STRING, PropertyInfo(Variant::DICTIONARY, "params")));
    ADD_SIGNAL(MethodInfo(MARKER_SIGNAL_STRING, PropertyInfo(Variant::DICTIONARY, "params")));
    ADD_SIGNAL(MethodInfo(START_FAILED_SIGNAL_STRING));
    ADD_SIGNAL(MethodInfo(STARTED_SIGNAL_STRING));
    ADD_SIGNAL(MethodInfo(RESTARTED_SIGNAL_STRING));
    ADD_SIGNAL(MethodInfo(STOPPED_SIGNAL_STRING));
}

void FmodEventEmitter3D::free_impl() {
    queue_free();
}
