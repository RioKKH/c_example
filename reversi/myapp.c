#include <gtk/gtk.h>

/**
 * @brief Callback function to initialize and show the window.
 *
 * This function is called when the application is activated.
 * It creates a new window GTK window, sets its title and default size,
 * and then shows it.
 *
 * @param app The GTK application.
 * @param user_data User data. Not used in this function.
 */
static void activate(GtkApplication* app, gpointer user_data)
{
    GtkWidget *window;

    // gtk_application_window_new() creates a new GTK application window.
    // As its parameter, it takes the GtkApplication the window belongs to.
    window = gtk_application_window_new(app);

    // gtk_window_set_title() sets the title of the GTK window.
    // The parameters are the window and the title string.
    gtk_window_set_title(GTK_WINDOW(window), "Window");

    // gtk_window_set_default_size() sets the default size of the GTK window.
    // The parameters are the window and the width and height.
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    // gtk_widget_show_all() makes a widget and all its sub widgets visible.
    // This function should be called when all widgets have been packed into the window.
    gtk_widget_show_all(window);
}

/**
 * @brief The main function of the application.
 *
 * This function creates a new GTK application, connects the "activate" signal
 * to the activate() function, and then runs the application.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return The status code of the application.
 */
int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    // gtk_application_new() creates a new GtkApplication object.
    // The parameters are the application ID and flags.
    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);

    // g_signal_connect() connects a GCallback function to a signal for a particular object.
    // The parameters are the instance to connect to, the name of the signal,
    // the GCallback to connect, and user data to pass to the callback function.
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    // g_application_run() run the application.
    // The parameters are the application instance, the argc and argv.
    // This function will block until the application exits.
    status = g_application_run(G_APPLICATION(app), argc, argv);

    // g_object_unref() decreases the reference count of the object.
    // When its reference count drops to 0, the object is finalized
    // (i.e. its memory is freed).
    g_object_unref(app);

    return status;
}
