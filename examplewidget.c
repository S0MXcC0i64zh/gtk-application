#include <gtk/gtk.h>

#include "examplewidget.h"

struct _ExampleWidget
{
  GtkWidget parent_type;

  GtkWidget* entry;
  GtkWidget* button;
};

G_DEFINE_TYPE(ExampleWidget, example_widget, GTK_TYPE_WIDGET)

static void
example_widget_init(ExampleWidget* self) {
  gtk_widget_init_template(GTK_WIDGET(self));

  // It is now possible to access self->entry and self->button
}

static void
example_widget_dispose(GObject* gobject) {
  gtk_widget_dispose_template(GTK_WIDGET(gobject), EXAMPLE_TYPE_WIDGET);

  G_OBJECT_CLASS(example_widget_parent_class)->dispose(gobject);
}

static void
example_widget_class_init(ExampleWidgetClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = example_widget_dispose;

  GtkWidgetClass* widget_class = GTK_WIDGET_CLASS(klass);

  gtk_widget_class_set_template_from_resource(
    widget_class, "/org/gtk/exampleapp/widget.ui");

  gtk_widget_class_bind_template_child(widget_class, ExampleWidget, entry);
  gtk_widget_class_bind_template_child(widget_class, ExampleWidget, button);
}

GtkWidget*
example_widget_new(void) {
  return GTK_WIDGET(g_object_new(EXAMPLE_TYPE_WIDGET, NULL));
}