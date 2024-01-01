
    if(read_button(ARROW_KEY_PIN_NUM)) {
      lcd_clear();
      lcd_set_cursor(1, 1);
      lcd_write_string("Arrow key");
      __delay_ms(100); // without this the lcd will fuck up

      charge_CD();

    }

    if(read_button(ENTER_KEY_PIN_NUM)) {
      lcd_clear();
      lcd_set_cursor(1, 1);
      lcd_write_string("Enter key");
      __delay_ms(100); // without this the lcd will fuck up

      discharge_CD();

    }

    if(read_button(WELD_KEY_PIN_NUM)) {
      lcd_clear();
      lcd_set_cursor(1, 1);
      lcd_write_string("Weld key");
      __delay_ms(100); // without this the lcd will fuck up
                       //
    }



