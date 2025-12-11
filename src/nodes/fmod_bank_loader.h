#ifndef GODOTFMOD_FMOD_BANK_LOADER_H
#define GODOTFMOD_FMOD_BANK_LOADER_H

#include "scene/main/node.h"
#include "studio/fmod_bank.h"

//namespace godot {
    class FmodBankLoader : public Node {
        GDCLASS(FmodBankLoader, Node)

    public:
        //virtual void _enter_tree() override;

        void set_bank_paths(const Array& p_paths);
        const Array& get_bank_paths() const;

        bool _property_can_revert(const StringName& p_property) const;
        bool _property_get_revert(const StringName& p_property, Variant& result) const;

    protected:
        void _notification(int p_notification);
    private:
        Vector<Ref<FmodBank>> bank;
        Array bank_paths;

    public:
        static void _bind_methods();
    };
//}

#endif// GODOTFMOD_FMOD_BANK_LOADER_H
