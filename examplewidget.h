#ifndef __EXAMPLEWIDGET_H
#define __EXAMPLEWIDGET_H

#include <gtk/gtk.h>

// GType example_widget_get_type(void);

#define EXAMPLE_TYPE_WIDGET (example_widget_get_type())

G_DECLARE_FINAL_TYPE(ExampleWidget, example_widget, EXAMPLE, WIDGET, GtkWidget)

GtkWidget* example_widget_new();
#endif /* __EXAMPLEWIDGET_H */