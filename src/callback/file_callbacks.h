#ifndef GODOTFMOD_FILE_CALLBACKS_H
#define GODOTFMOD_FILE_CALLBACKS_H

#include <fmod_common.h>
#include <fmod_studio_common.h>

#include <core/io/file_access.h>
#include <core/object/ref_counted.h>
#include <cstring>// This include is required for both Linux and MacOS targets as they don't include the necessary headers for 'memcpy' by default

#if !defined(WEB_ENABLED)
#include <condition_variable>
#include <thread>
#include <mutex>
#endif

namespace Callbacks {
    //using namespace godot;
    struct GodotFileHandle {
        Ref<FileAccess> file;
    };

    class GodotFileRunner {
    public:
        static GodotFileRunner* get_singleton();

        enum ReadPriority {
            NORMAL,
            HIGH
        };

        ~GodotFileRunner() = default;

    private:
#if !defined(WEB_ENABLED)
        std::thread fileThread;

        std::condition_variable read_cv;
        std::mutex read_mut;

        std::condition_variable cancel_cv;
        std::mutex cancel_mut;

        bool stop = false;
        FMOD_ASYNCREADINFO* current_request = nullptr;
        List<FMOD_ASYNCREADINFO*> requests = List<FMOD_ASYNCREADINFO*>();

        GodotFileRunner() = default;
        GodotFileRunner(const GodotFileRunner&) = delete;
        GodotFileRunner& operator=(const GodotFileRunner&) = delete;
        void run();
#endif
    public:
        void queueReadRequest(FMOD_ASYNCREADINFO* request, ReadPriority priority);
        FMOD_RESULT cancelReadRequest(FMOD_ASYNCREADINFO* request);
        void start();
        void finish();
    };
    FMOD_RESULT F_CALL godotFileOpen(const char* name, unsigned int* filesize, void** handle, void* userdata);

    FMOD_RESULT F_CALL godotFileClose(void* handle, void* userdata);

    FMOD_RESULT F_CALL godotFileRead(void* handle, void* buffer, unsigned int sizebytes, unsigned int* bytesread, void* userdata);

    FMOD_RESULT F_CALL godotFileSeek(void* handle, unsigned int pos, void* userdata);

    FMOD_RESULT F_CALL godotSyncRead(FMOD_ASYNCREADINFO* info, void* userdata);

    FMOD_RESULT F_CALL godotSyncCancel(FMOD_ASYNCREADINFO* info, void* userdata);
}// namespace Callbacks

#endif// GODOTFMOD_FILE_CALLBACKS_H
