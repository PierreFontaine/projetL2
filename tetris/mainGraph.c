#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include <gtk/gtk.h>

int main( int   argc,char *argv[] ){
    GtkWidget *window;
    GtkWidget *button_quit;
    GtkWidget* hbox1;
    GtkWidget* label;

    button_quit = gtk_button_new_with_label("Quitter");
    hbox1 = gtk_hbox_new (TRUE, 10);
    label = gtk_label_new( "Grille TETRIS" );
    g_signal_connect(button_quit,"clicked",G_CALLBACK(gtk_main_quit),NULL);
    gtk_container_add(GTK_CONTAINER(window),button_quit);
    gtk_container_add ( GTK_CONTAINER (hbox1), label );
    gtk_widget_show(button_quit);

    /* Passe les arguments à GTK, pour qu'il extrait ceux qui le concernent. */
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_show  (window);


    gtk_main ();
    return 0;
}
