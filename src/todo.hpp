#pragma once
#include <AppCore/AppCore.h>

using namespace ultralight;

class TodoApp : public AppListener,
                public WindowListener,
                public LoadListener,
                public ViewListener {
public:
    TodoApp();

    virtual ~TodoApp();

    // Fetch
    JSValue fetchAllTasks(const JSObject&, const JSArgs&);
    JSValue fetchTaskByID(const JSObject&, const JSArgs&);
    JSValue fetchClosestTask(const JSObject&, const JSArgs&);
    JSValue fetchMonthTasksSinceDay(const JSObject&, const JSArgs&);

    // Insert
    void insertTask(const JSObject&, const JSArgs&);

    // Modify
    void modifyTask(const JSObject&, const JSArgs&);
    void markTaskAsDone(const JSObject&, const JSArgs&);
    void markTaskAsUndone(const JSObject&, const JSArgs&);

    // Remove
    void removeTask(const JSObject&, const JSArgs&);

    // Start the run loop.
    virtual void Run();

    // This is called continuously from the app's main loop.
    virtual void OnUpdate() override;

    // This is called when the window is closing.
    virtual void OnClose() override;

    // This is called whenever the window resizes.
    virtual void OnResize(uint32_t width, uint32_t height) override;

    // This is called when the page finishes a load in one of its frames.
    virtual void OnFinishLoading(ultralight::View* caller,
                                 uint64_t frame_id,
                                 bool is_main_frame,
                                 const String& url) override;

    // This is called when the DOM has loaded in one of its frames.
    virtual void OnDOMReady(ultralight::View* caller,
                            uint64_t frame_id,
                            bool is_main_frame,
                            const String& url) override;

    // This is called when the page requests to change the Cursor.
    virtual void OnChangeCursor(ultralight::View* caller,
                                Cursor cursor) override;

    virtual void OnChangeTitle(ultralight::View* caller,
                               const String& title) override;

protected:
    RefPtr<App> app_;
    RefPtr<Window> window_;
    RefPtr<Overlay> overlay_;
};
