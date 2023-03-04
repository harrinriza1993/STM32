void lcd_send_cmd (char cmd);

void lcd_send_data (char data);

void lcd_init (void);

void lcd_send_string (char *str, int line_selection);

void lcd_put_cur(int row, int col);

