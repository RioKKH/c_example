#include <gtk/gtk.h>

// The game board
static int board[8][8] = {0};

// Initialize the board with the initial game state

// The current player
static int current_player = 1;

// Function to check if a move is valid
static gboolean is_valid_move(int player, int x, int y) {
    // Check if the square is empty
    if (board[x][y] != 0) {
        return FALSE;
    }

    // Directions to check for valid moves
    int dx[] = {-1,  0,  1, -1,  1, -1,  0,  1};
    int dy[] = {-1, -1, -1,  0,  0,  1,  1,  1};

    // Check each direction
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        g_print("%d, %d\n", nx, ny);

        // Check if the next square is inside the board and contains the other player's stone
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == 3 - player) {
            g_print("Next square is inside the board and contains the other player's stone.\n");
            // Keep moving in this direction untile we find an empty square, reach the edge of the
            // board, or find our own stone
            do {
                nx += dx[i];
                ny += dy[i];
            } while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == 3 - player);

            // Check if we found a valid move
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == player) {
                g_print("Found a valid move.\n");
                return TRUE;
            }
        }
    }

    // No valid move found
    return FALSE;
}

// Function to place a stone and flip the opponent's stones
static void place_stone(int player, int x, int y) {
    // Place the stone
    board[x][y] = player;
    
    // Directions to check for valid moves
    int dx[] = {-1,  0,  1, -1,  1, -1,  0,  1};
    int dy[] = {-1, -1, -1,  0,  0,  1,  1,  1};

    // Check each direction
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // Check if the next square is inside the board and contains the other player's stone
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == 3 - player) {
            // Keep moving in this direction
            do {
                nx += dx[i];
                ny += dy[i];
            } while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == 3 - player);

            // Check if we found a valid move
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == player) {
                // Flip the opponent's stones
                do {
                    nx -= dx[i];
                    ny -= dy[i];
                    board[nx][ny] =player;
                } while (nx != x || ny != y);
            }
        }
    }
}


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
    context = gtk_widget_get_style_context(widget);

    // Get the position of the button
    int *position = (int *)user_data;

    // Check if the move is valid
    if (is_valid_move(current_player, position[0], position[1])) {
        g_print("Move is valid.\n");
        // Place a stone and flip the opponent's stones
        place_stone(current_player, position[0], position[1]);

        // Change the color of the button according to the current player
        if (current_player == 1) {
            if (gtk_style_context_has_class(context, "destructive-action")) {
                gtk_style_context_remove_class(context, "destructive-action");
            }
            gtk_style_context_add_class(context, "suggested-action");
        } else {
            if (gtk_style_context_has_class(context, "suggested-action")) {
                gtk_style_context_remove_class(context, "suggested-action");
            }
            gtk_style_context_add_class(context, "destructive-action");
        }

        // Switch the current player
        // このプログラムではプレイヤー1とプレイヤー2をそれぞれ整数の1と2で表現しています。
        // 従って、current_player変数は1か2の値を持ちます。
        // current_player = 3 - current_playerという式は、現在のプレイヤーを切り替える為の
        // 簡単な方法です。現在のプレイヤーが１であれば、3 - 1 = 2となり、プレイヤー2に
        // 切り替わります。逆に、現在のプレイヤーが2であれば、3 - 2 = 1となり、プレイヤー1
        // に切り替わります。
        current_player = 3 - current_player;
    } else {
        g_print("Move is not valid.\n");
    }

    // Print the position of the button and the state of the board
    g_print("Button at position (%d, %d) was clicked.\n", position[0], position[1]);
    g_print("Board state:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            g_print("%d ", board[i][j]);
        }
        g_print("\n");
    }
}

// Function to switch the current player
static void switch_player() {
    current_player = 3 - current_player;
}

// Function to check if the board is full
static gboolean is_board_full() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 0) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

// Function to check if a player has a valid move
static gboolean has_valid_move(int player) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (is_valid_move(player, i, j)) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

// Function to check if the game is over
static gboolean is_game_over() {
    return is_board_full() || (!has_valid_move(1) && !has_valid_move(2));
}

// Function to display the score
static void display_score() {
    int score1 = 0; // Score for player 1
    int score2 = 0; // Score for player 2

    // Count the number of stones for each player
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 1) {
                score1++;
            } else if (board[i][j] == 2) {
                score2++;
            }
        }
    }

    // Display the score
    g_print("Score: Player 1 = %d, Player 2 = %d\n", score1, score2);
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

    // Initialize the board with the initial game state
    board[3][3] = 1;
    board[3][4] = 2;
    board[4][3] = 2;
    board[4][4] = 1;

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
