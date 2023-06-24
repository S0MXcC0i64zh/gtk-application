#include <gtk/gtk.h>

#include "exampleapp.h"
#include "exampleappwin.h"
#include "examplewidget.h"

struct _ExampleAppWindow
{
  GtkApplicationWindow parent;

  GtkWidget* examplewidget;
};

G_DEFINE_TYPE(
  ExampleAppWindow,
  example_app_window,
  GTK_TYPE_APPLICATION_WINDOW);

static void
example_app_window_init(ExampleAppWindow* win) {
  g_type_ensure(EXAMPLE_TYPE_WIDGET);
  gtk_widget_init_template(GTK_WIDGET(win));
}

static void
example_app_window_class_init(ExampleAppWindowClass* class) {
  gtk_widget_class_set_template_from_resource(
    GTK_WIDGET_CLASS(class), "/org/gtk/exampleapp/window.ui");

  gtk_widget_class_bind_template_child(
    GTK_WIDGET_CLASS(class), ExampleAppWindow, examplewidget);
}

ExampleAppWindow*
example_app_window_new(ExampleApp* app) {
  return g_object_new(EXAMPLE_APP_WINDOW_TYPE, "application", app, NULL);
}

void
example_app_window_open(ExampleAppWindow* win, GFile* file) {}
