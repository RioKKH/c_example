#include <gtk/gtk.h>

/**
 * @brief Callback function for the button click event.
 *
 * This function is called when the button is clicked.
 * It prints a message to the console.
 *
 * @param widget The widget that received the event (the button).
 * @param user_data User data. This should be a pointer to an array
 * of two integers representing the position of the button.
 */
static void on_button_clicked(GtkWidget *widget, gpointer user_data)
{
    GtkStyleContext *context;
    // gtk_widget_get_style_context()関数を使用して、クリックされたボタン
    // widgetのスタイルコンテキストを取得sるう。スタイルコンテキストは
    // widgetの見た目（色、フォント、パディング）を制御するための情報を
    // 保持している
    context = gtk_widget_get_style_context(widget);

    // Check if the button already has the "suggested-action" class
    if (gtk_style_context_has_class(context, "suggested-action")) {
        // If it does, remove the "suggested-action" class and add the
        // "destructive-action" class.
        gtk_style_context_remove_class(context, "suggested-action");
        gtk_style_context_add_class(context, "destructive-action");
    } else if (gtk_style_context_has_class(context, "destructive-action")) {
        // If it has the "destructive-action" class, remote it
        gtk_style_context_remove_class(context, "destructive-action");
    } else {
        // If it has neither class, add the "suggested-action" class
        gtk_style_context_add_class(context, "suggested-action");
    }

    // Print the position of the button
    int *position = (int *)user_data;
    g_print("Button at position (%d, %d) was clicked.\n", position[0], position[1]);
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
    GtkWidget *button;
    int *position;
    int i, j;

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

    // Create a button for each cell of the grid
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            button = gtk_button_new();
            // GLibライブラリの関数で、指定された型の新し配列を動的に確保(メモリを割り当て)します。
            // この関数はC言語のmalloc()関数と似ていますが、型のサイズを自動的に計算し、エラー
            // チェックを行います。
            // g_new(int, 2)はint型の要素を2つもつ新しい配列を確保します。
            position = g_new(int, 2);
            position[0] = i; // 行を表す
            position[1] = j; // 列を表す
            // g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
            g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), position);
            // g_signal_connect_swapped()関数を利用して、ボタンのdestroyシグナルをg_free()
            // 関数に接続する。destroyシグナルはウィジェットが破棄されるときに発生する。
            // g_signal_connect_swapped()関数は、シグナルが発生したときに呼び出される
            // コールバック関数の引数を入れ替えることが出来る。ここでは、g_free()関数の
            // 引数としてposition配列へのポインタをw田あたしている。従って、このコードを
            // 利用すると、各ボタンがはきされるとき、例えばウィンドウが閉じられるときに、
            // そのボタンのposition配列のメモリが解放される
            g_signal_connect_swapped(button, "destroy", G_CALLBACK(g_free), position);
            gtk_grid_attach(GTK_GRID(grid), button, j, i, 1, 1);
        }
    }

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
