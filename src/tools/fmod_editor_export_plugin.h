#ifdef TOOLS_ENABLED

#ifndef GODOTFMOD_FMOD_EDITOR_EXPORT_PLUGIN_H
#define GODOTFMOD_FMOD_EDITOR_EXPORT_PLUGIN_H

#include <resources/fmod_plugins_settings.h>
#include <editor/export/editor_export_platform.h>
#include <editor/export/editor_export_plugin.h>

//namespace godot {
    class FmodEditorExportPlugin : public EditorExportPlugin {
        GDCLASS(FmodEditorExportPlugin, EditorExportPlugin)

    public:
        void _export_begin(const HashSet<String> &features, bool is_debug, const String &path, int flags) override;
        String get_name() const override;
        virtual void _get_export_options(const Ref<EditorExportPlatform> &platform, List<EditorExportPlatform::ExportOption> *r_options) const override;

        static void _bind_methods();

        FmodEditorExportPlugin() = default;
        ~FmodEditorExportPlugin() = default;

    private:
        static PackedStringArray _get_libraries_to_export(const Ref<FmodPluginsSettings>& settings, const String& p_os_name, const String& p_extension, const String& p_arch = "");
    };
//}

#endif// GODOTFMOD_FMOD_EDITOR_EXPORT_PLUGIN_H

#endif
