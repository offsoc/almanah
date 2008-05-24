/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/*
 * Diary
 * Copyright (C) Philip Withnall 2008 <philip@tecnocode.co.uk>
 * 
 * Diary is free software.
 * 
 * You may redistribute it and/or modify it under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 * 
 * Diary is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Diary.  If not, write to:
 * 	The Free Software Foundation, Inc.,
 * 	51 Franklin Street, Fifth Floor
 * 	Boston, MA  02110-1301, USA.
 */

#include <glib.h>
#include <gtk/gtk.h>
#include <string.h>

#include "link.h"
#include "add-link-dialog.h"

void
ald_destroy_cb (GtkWindow *window, gpointer user_data)
{
	gtk_widget_hide_all (GTK_WIDGET (window));
}

void
ald_response_cb (GtkDialog *self, gint response_id, gpointer user_data)
{
	/* If the second value entry is hidden, empty it to keep the database clean */
	if (GTK_WIDGET_VISIBLE (GTK_WIDGET (diary->ald_value2_entry)) == FALSE)
		gtk_entry_set_text (diary->ald_value2_entry, "");
}

void
ald_type_combo_box_changed_cb (GtkComboBox *self, gpointer user_data)
{
	/* TODO: Hide/Show the entries as appropriate */
	GtkTreeIter iter;
	gchar *type;
	DiaryLinkType link_type;

	if (gtk_combo_box_get_active_iter (self, &iter) == FALSE)
		return;

	gtk_tree_model_get (gtk_combo_box_get_model (self), &iter, 1, &type, -1);

	

	g_free (type);
}
