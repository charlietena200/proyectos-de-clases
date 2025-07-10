void OrionCallbacks::saveLoadCancelFn(DialogView *view, MenuObject *item) {
	OrionMenuView *vw = (OrionMenuView *) view;

	if (view->_selectedSlot != -1) {
		// Pressed cancel with a save selected, so revert back to no selection

		// Re-enable all the other slots

		for (int index = 0; index < SL_NUM_VISIBLE_SLOTS; ++index) {
			if (index != view->_selectedSlot) {
				MenuSaveLoadText *currentItem = (MenuSaveLoadText *) view->getItem(SLTAG_SLOTS_START + index);
				currentItem->setState(OS_NORMAL);
			}
		}

		// Show the previously hidden slot again
		MenuSaveLoadText *slot = (MenuSaveLoadText *) view->getItem(SLTAG_SLOTS_START + view->_selectedSlot);
		slot->setVisible(true);
		slot->setState(OS_NORMAL);

		// Remove the text selection
		MenuTextField *textField = (MenuTextField *) view->getItem(SLTAG_TEXTFIELD);
		delete textField;
		vw->items().remove(textField);

		// Set button enablement
		MenuButton *btn = (MenuButton *) view->getItem(SLTAG_SAVELOAD);
		btn->setState(OS_GREYED);
		btn = (MenuButton *) view->getItem(SLTAG_CANCEL);
		btn->setState(OS_NORMAL);

		// Re-enable the slider

		MenuVertSlider *slider = (MenuVertSlider *) view->getItem(SLTAG_VSLIDER);
		slider->setState(OS_NORMAL);

		view->_selectedSlot = -1;

	} else {
		// Close the dialog
		if (vw->_loadSaveFromHotkey)
			// Since dialog was called from hotkey, return directly to the game
			closeMenuFn(view, item);
		else {
			// Return to the game menu
			view->vm()->loadMenu(GAME_MENU);
			view->close();
		}
	}
}
