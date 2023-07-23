#include <gtk/gtk.h>

/**
 * @brief Callback function for the button click event.
 *
 * This function is called when the button is clicked.
 * It prints a message to the console.
 *
 * @param widget The widget that received the event (the button).
 * @param user_data User data. Not used in this function.
 */
static void on_button_clicked(GtkWidget *widget, gpointer user_data)
{
    g_print("Button clicked\n");
}

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
    GtkWidget *grid;
    GtkWidget *button1;
    GtkWidget *button2;

    // gtk_application_window_new() creates a new GTK application window.
    // As its parameter, it takes the GtkApplication the window belongs to.
    window = gtk_application_window_new(app);

    // gtk_window_set_title() sets the title of the GTK window.
    // The parameters are the window and the title string.
    gtk_window_set_title(GTK_WINDOW(window), "Window");

    // gtk_window_set_default_size() sets the default size of the GTK window.
    // The parameters are the window and the width and height.
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    // Create a new grid
    grid = gtk_grid_new();

    button1 = gtk_button_new_with_label("Button 1");
    button2 = gtk_button_new_with_label("Button 2");

    // Connect the "clicked" signal of the buttons to the callback function
    g_signal_connect(button1, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button2, "clicked", G_CALLBACK(on_button_clicked), NULL);

    // Add the buttons to the grid
    // void gtk_grid_attach(GtkGrid *grid, GtkWidget *child,
    //                      gint left, gint top, gint width, gint height);
    //  left: ウィジェットを追加する位置の列番号。最初の列は0
    //  top:  ウィジェットを追加する位置の行番号。最初の行は0
    //  width: ウィジェットが占める列の数。通常は1ですが、ウィジェットが
    //  複数の列にまたがる場合はその数を指定します。
    //  height: ウィジェットが占める行の数。通常は1ですが、ウィジェットが
    //  複数の行にまたがる場合はその数を指定します。
    gtk_grid_attach(GTK_GRID(grid), button1, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button2, 1, 0, 1, 1);

    // Add the grid to the window
    gtk_container_add(GTK_CONTAINER(window), grid);
    // gtk_container_add(GTK_CONTAINER(window), button);

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
