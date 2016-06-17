#include <PCD8544.h>

/*
 *  Amon Special Badge
 */

#include <ESP8266WiFi.h>

static const byte AA[5] = {
  0x00, 0x00, 0x60, 0x97, 0x95
};

static const byte AB[5] = {
  0x97, 0x94, 0x68, 0x00, 0x00
};

static const byte BA[5] = {
  0x00, 0x00, 0x38, 0x92, 0x92
};

static const byte BB[5] = {
  0x92, 0x44, 0x38, 0x00, 0x00
};

static const byte CA[5] = {
  0x00, 0x00, 0x7C, 0x40, 0x7C
};

static const byte CB[5] = {
  0x40, 0x7C, 0x00, 0x00, 0x00
};

static const byte DA[5] = {
  0x00, 0x00, 0x40, 0x00, 0xFC
};

static const byte DB[5] = {
  0x04, 0x17, 0x00, 0x00, 0x00
};

static const byte EA[5] = {
  0x00, 0x00, 0x7E, 0x20, 0x10
};

static const byte EB[5] = {
  0x08, 0x04, 0x7E, 0x00, 0x00
};

static const byte FA[5] = {
  0x00, 0xFE, 0x82, 0x9E, 0x90
};

static const byte FB[5] = {
  0x90, 0x9E, 0x82, 0xFE, 0x00
};

static const byte GA[5] = {
  0x00, 0x00, 0xEE, 0xAA, 0xAA
};

static const byte GB[5] = {
  0xBA, 0xAA, 0xEE, 0x00, 0x00
};

static const byte HA[5] = {
  0x00, 0x00, 0x52, 0x42, 0x7E
};

static const byte HB[5] = {
  0x7E, 0x42, 0x52, 0x00, 0x00
};

static const byte IA[5] = {
  0x00, 0x30, 0x28, 0x24, 0x3E
};

static const byte IB[5] = {
  0x3E, 0x24, 0x28, 0x30, 0x00
};

static const byte JA[5] = {
  0x00, 0x00, 0x42, 0x66, 0x5A
};

static const byte JB[5] = {
  0x5A, 0x66, 0x42, 0x00, 0x00
};

static const byte KA[5] = {
  0x00, 0x7C, 0x44, 0x28, 0x10
};

static const byte KB[5] = {
  0x7C, 0x10, 0x7C, 0x00, 0x00
};

static const byte LA[5] = {
  0x00, 0x00, 0x7E, 0x42, 0x5A
};

static const byte LB[5] = {
  0x5A, 0x42, 0x7E, 0x00, 0x00
};

static const byte MA[5] = {
  0x00, 0x00, 0x00, 0xE0, 0xAE
};

static const byte MB[5] = {
  0xAA, 0xEE, 0x00, 0x00, 0x00
};

static const byte NA[5] = {
  0x00, 0x00, 0x00, 0xEE, 0x28
};

static const byte NB[5] = {
  0xAA, 0x38, 0x00, 0x00, 0x00
};

static const byte OA[5] = {
  0x00, 0x00, 0x18, 0x14, 0x72
};

static const byte OB[5] = {
  0x72, 0x14, 0x18, 0x00, 0x00
};

static const byte PA[5] = {
  0x00, 0x03, 0x03, 0x04, 0x18
};

static const byte PB[5] = {
  0x18, 0x20, 0xC0, 0xC0, 0x00
};

static const byte QA[5] = {
  0x00, 0x00, 0x1E, 0x50, 0x5C
};

static const byte QB[5] = {
  0x42, 0x42, 0x7C, 0x00, 0x00
};

static const byte RA[5] = {
  0x00, 0x00, 0x10, 0x20, 0x44
};

static const byte RB[5] = {
  0x8A, 0x41, 0x22, 0x14, 0x08
};

static const byte SA[5] = {
  0x0C, 0x14, 0x24, 0x44, 0x84
};

static const byte SB[5] = {
  0x44, 0x24, 0x14, 0x0C, 0x00
};

static const byte TA[5] = {
  0x00, 0x00, 0x88, 0xCC, 0xAA
};

static const byte TB[5] = {
  0xCC, 0x88, 0x00, 0x00, 0x00
};

static const byte UA[5] = {
  0x00, 0x00, 0x92, 0x92, 0x92
};

static const byte UB[5] = {
  0x92, 0x92, 0xFE, 0x00, 0x00
};

static const byte VA[5] = {
  0x00, 0x00, 0x0E, 0xFA, 0x8E
};

static const byte VB[5] = {
  0x80, 0x80, 0x80, 0x00, 0x00
};

static const byte WA[5] = {
  0x00, 0x10, 0x28, 0x44, 0x82
};

static const byte WB[5] = {
  0x44, 0x28, 0x10, 0x00, 0x00
};

static const byte XA[5] = {
  0x00, 0x00, 0xEE, 0xAA, 0xAA
};

static const byte XB[5] = {
  0xBA, 0x82, 0xFE, 0x00, 0x00
};

static const byte YA[5] = {
  0x00, 0x00, 0xC3, 0xC3, 0x42
};

static const byte YB[5] = {
  0x24, 0x18, 0x18, 0x00, 0x00
};

static const byte ZA[5] = {
  0x00, 0x00, 0x92, 0xD6, 0x7C
};

static const byte ZB[5] = {
  0x00, 0x92, 0xD6, 0x7C, 0x00
};

static const byte * glyphs[] = {
  AA, AB, BA, BB, CA, CB, DA, DB, EA, EB, FA, FB, GA, GB, HA, HB, IA, IB, JA, JB, KA, KB, LA, LB, MA, MB, NA, NB, OA, OB, PA, PB, QA, QB, RA, RB, SA, SB, TA, TB, UA, UB, VA, VB, WA, WB, XA, XB, YA, YB, ZA, ZB
};

static int cursorx = 0;
static int cursory = 0;

static PCD8544 lcd;

WiFiServer server(1337);

void print_char(unsigned char c) {
  if (cursorx + 5 > 80) {
    cursorx = 0;
    cursory += 8;
  }
  int offset = (c - 0x41) * 2;
  lcd.createChar(0, glyphs[offset]);
  lcd.createChar(1, glyphs[offset + 1]);
  lcd.setCursor(cursorx, cursory);
  lcd.write(0);
  cursorx += 5;
  lcd.setCursor(cursorx, cursory);
  lcd.write(1);
  cursorx += 5;
}

void setup() {
  lcd.begin(84, 48);
  Serial.begin(115200);
  delay(100);

  WiFi.mode(WIFI_AP);
  WiFi.softAP("Amon's Badge", "amonsbadge");
  
  server.begin();
}

void loop() {
  cursorx = 0;
  cursory = 0;
  print_char('I');
  print_char('A');
  print_char('M');
  print_char('T');
  print_char('H');
  print_char('E');
  print_char('G');
  print_char('O');
  print_char('D');
  print_char('O');
  print_char('F');
  print_char('D');
  print_char('E');
  print_char('S');
  print_char('T');
  print_char('R');
  print_char('U');
  print_char('C');
  print_char('T');
  print_char('I');
  print_char('O');
  print_char('N');

  
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  client.println("MESSAGE: APPROACH ME AND SHOW ME THIS MESSAGE TO TAKE A LOOK AT MY BADGE. o>-<");
  client.println("TVRoZAAAAAYAAQAFAGBNVHJrAAAACwD/UQMFpsIA/y8ATVRyawAAA48A/wMITUlESSBvdXQAsQpA");
  client.println("ALEHZADhAEAAsWUAALFkAACxBgwAsQpAALEHZADhAEAAwVAAsWUAALFkAACxBgwAsQpAALEHZADh");
  client.println("AEAAwVAAsWUAALFkAACxBgwAsQpAALEHZADhAEAAwVAAkUFkL4FBQAGRPmQvgT5AAZE5ZC+BOUAB");
  client.println("kT5kL4E+QAGRQWQvgUFAAZE+ZC+BPkABkTlkL4E5QAGRPmQvgT5AAZFBZC+BQUABkTxkL4E8QAGR");
  client.println("OWQvgTlAAZE8ZC+BPEABkUFkL4FBQAGRPGQvgTxAAZE5ZC+BOUABkTxkL4E8QAGRQGQvgUBAAZE9");
  client.println("ZC+BPUABkTlkL4E5QAGRPWQvgT1AAZFAZC+BQEABkT1kL4E9QAGROWQvgTlAAZE9ZC+BPUABkUBk");
  client.println("L4FAQAGRPWQvgT1AAZE5ZC+BOUABkT1kL4E9QAGRQGQvgUBAAZE9ZC+BPUABkTlkL4E5QAGRPWQv");
  client.println("gT1AAZE+ZIIfgT5AAZFAZF+BQEABkUFkgn+BQUABkUVkgQ+BRUABkUNkgQ+BQ0ABkUVkX4FFQAGR");
  client.println("PGSCf4E8QAGRPmSCH4E+QAGRQGRfgUBAAZFBZIE/gUFAAZFAZIE/gUBAAZFDZIE/gUNAAZFFZIE/");
  client.println("gUVAAZFDZIE/gUNAAZFBZIE/gUFAYZFBZF+BQUABkUFkX4FBQAGRQWRfgUFAAZFFZF+BRUABkUVk");
  client.println("X4FFQAGRQ2RfgUNAAZFBZF+BQUBhkUVkX4FFQAGRRWRfgUVAAZFFZF+BRUABkUNkX4FDQAGRRWRf");
  client.println("gUVAAZFDZF+BQ0ABkUFkX4FBQGGRQWRfgUFAAZFBZF+BQUABkUFkX4FBQAGRRWRfgUVAAZFFZF+B");
  client.println("RUABkUNkX4FDQAGRQWRfgUFAYZFFZF+BRUABkUVkX4FFQAGRRWRfgUVAYZFJZF+BSUABkUlkX4FJ");
  client.println("QAGRSWRfgUlAYZFBZF+BQUABkUFkX4FBQAGRQWRfgUFAAZFFZF+BRUABkUVkX4FFQAGRQ2RfgUNA");
  client.println("AZFBZF+BQUBhkUZgX4FGQAGRRmRfgUZAAZFGZF+BRkABkUVggT+BRUABkUhggT+BSEABkUVggT+B");
  client.println("RUABkUlggT+BSUCGAbFlAACxZAAAsQYMALEKQACxB2QA4QBAAMFQAbFlAACxZAAAsQYMALEKQACx");
  client.println("B2QA4QBAAMFQALFlAACxZAAAsQYMALEKQACxB2QA4QBAAMFQAP8vAE1UcmsAABCDAP8DC01JREkg");
  client.println("b3V0ICMyALIKQACyB2QA4gBAALJlAACyZAAAsgYMALIKQACyB2QA4gBAAMIBALJlAACyZAAAsgYM");
  client.println("ALIKQACyB2QA4gBAAMIBALJlAACyZAAAsgYMALIKQACyB2QA4gBAAMIBjACSNUAAkjlAAJIyQC+C");
  client.println("MkAAgjlAAII1QAGSMkAAkjlAAJI1QC+CNUAAgjlAAIIyQAGSMkAAkjlAAJI1QC+CMkAAgjVAAII5");
  client.println("QAGSNUAAkjlAAJIyQC+CMkAAgjlAAII1QAGSNUAAkjlAAJIyQC+CMkAAgjlAAII1QAGSMkAAkjlA");
  client.println("AJI1QC+CMkAAgjVAAII5QAGSNUAAkjlAAJIyQC+CMkAAgjlAAII1QAGSNUAAkjlAAJIyQC+CMkAA");
  client.println("gjlAAII1QAGSMkAAkjlAAJI1QC+CNUAAgjlAAIIyQAGSNUAAkjlAAJIyQC+CMkAAgjlAAII1QAGS");
  client.println("NUAAkjlAAJIyQC+CNUAAgjJAAII5QAGSNUAAkjlAAJIyQC+CNUAAgjJAAII5QAGSNUAAkjlAAJIy");
  client.println("QC+CMkAAgjlAAII1QAGSNUAAkjlAAJIyQC+CMkAAgjlAAII1QAGSNUAAkjlAAJIyQC+CMkAAgjlA");
  client.println("AII1QAGSMkAAkjlAAJI1QC+CNUAAgjlAAIIyQAGSPEAAkjlAAJI1QC+CNUAAgjlAAII8QAGSPEAA");
  client.println("kjlAAJI1QC+CNUAAgjlAAII8QAGSPEAAkjlAAJI1QC+CNUAAgjlAAII8QAGSPEAAkjlAAJI1QC+C");
  client.println("NUAAgjlAAII8QAGSPEAAkjlAAJI1QC+CNUAAgjlAAII8QAGSNUAAkjlAAJI8QC+CPEAAgjlAAII1");
  client.println("QAGSNUAAkjlAAJI8QC+CPEAAgjlAAII1QAGSPEAAkjlAAJI1QC+CNUAAgjlAAII8QAGSPEAAkjlA");
  client.println("AJI1QC+CNUAAgjlAAII8QAGSNUAAkjlAAJI8QC+CPEAAgjlAAII1QAGSPEAAkjlAAJI1QC+CPEAA");
  client.println("gjVAAII5QAGSNUAAkjlAAJI8QC+CNUAAgjxAAII5QAGSNUAAkjlAAJI8QC+CPEAAgjlAAII1QAGS");
  client.println("NUAAkjlAAJI8QC+CPEAAgjlAAII1QAGSPEAAkjlAAJI1QC+CNUAAgjlAAII8QAGSNUAAkjlAAJI8");
  client.println("QC+CPEAAgjlAAII1QAGSLkAAkjJAAJI1QC+CNUAAgjJAAIIuQAGSLkAAkjJAAJI1QC+CNUAAgjJA");
  client.println("AIIuQAGSLkAAkjJAAJI1QC+CNUAAgjJAAIIuQAGSNUAAkjJAAJIuQC+CLkAAgjJAAII1QAGSLkAA");
  client.println("kjJAAJI1QC+CNUAAgjJAAIIuQAGSNUAAkjJAAJIuQC+CLkAAgjJAAII1QAGSLkAAkjJAAJI1QC+C");
  client.println("NUAAgjJAAIIuQAGSLkAAkjJAAJI1QC+CNUAAgjJAAIIuQAGSLkAAkjJAAJI1QC+CNUAAgjJAAIIu");
  client.println("QAGSNUAAkjJAAJIuQC+CLkAAgjJAAII1QAGSNUAAkjJAAJIuQC+CLkAAgjJAAII1QAGSLkAAkjJA");
  client.println("AJI1QC+CLkAAgjVAAIIyQAGSLkAAkjJAAJI1QC+CNUAAgjJAAIIuQAGSLkAAkjJAAJI1QC+CNUAA");
  client.println("gjJAAIIuQAGSNUAAkjJAAJIuQC+CLkAAgjJAAII1QAGSLkAAkjJAAJI1QC+CNUAAgjJAAIIuQAGS");
  client.println("MEAAkjRAAJI3QC+CN0AAgjRAAIIwQAGSN0AAkjRAAJIwQC+CMEAAgjRAAII3QAGSMEAAkjRAAJI3");
  client.println("QC+CN0AAgjRAAIIwQAGSN0AAkjRAAJIwQC+CMEAAgjRAAII3QAGSMEAAkjRAAJI3QC+CN0AAgjRA");
  client.println("AIIwQAGSN0AAkjRAAJIwQC+CMEAAgjRAAII3QAGSN0AAkjRAAJIwQC+CN0AAgjBAAII0QAGSMEAA");
  client.println("kjRAAJI3QC+CN0AAgjRAAIIwQAGSLUAAkjFAAJI0QC+CNEAAgjFAAIItQAGSNEAAkjFAAJItQC+C");
  client.println("LUAAgjFAAII0QAGSLUAAkjFAAJI0QC+CLUAAgjRAAIIxQAGSLUAAkjFAAJI0QC+CLUAAgjRAAIIx");
  client.println("QAGSLUAAkjFAAJI0QC+CNEAAgjFAAIItQAGSLUAAkjFAAJI0QC+CNEAAgjFAAIItQAGSNEAAkjFA");
  client.println("AJItQC+CLUAAgjFAAII0QAGSLUAAkjFAAJI0QC+CNEAAgjFAAIItQAGSMkAAkjlAAJI1QC+CNUAA");
  client.println("gjlAAIIyQAGSMkAAkjlAAJI1QC+CNUAAgjlAAIIyQAGSMkAAkjlAAJI1QC+CMkAAgjVAAII5QAGS");
  client.println("NUAAkjlAAJIyQC+CMkAAgjlAAII1QAGSMkAAkjlAAJI1QC+CNUAAgjlAAIIyQAGSNUAAkjlAAJIy");
  client.println("QC+CMkAAgjlAAII1QAGSNUAAkjlAAJIyQC+CMkAAgjlAAII1QAGSNUAAkjlAAJIyQC+CMkAAgjlA");
  client.println("AII1QAGSNUAAkjlAAJIyQC+CMkAAgjlAAII1QAGSNUAAkjlAAJIyQC+CMkAAgjlAAII1QAGSNUAA");
  client.println("kjlAAJIyQC+CMkAAgjlAAII1QAGSNUAAkjlAAJIyQC+CMkAAgjlAAII1QAGSNUAAkjlAAJIyQC+C");
  client.println("MkAAgjlAAII1QAGSMkAAkjlAAJI1QC+CNUAAgjlAAIIyQAGSNUAAkjlAAJIyQC+CNUAAgjJAAII5");
  client.println("QAGSNUAAkjlAAJIyQC+CMkAAgjlAAII1QAGSPEAAkjlAAJI1QC+CPEAAgjVAAII5QAGSPEAAkjlA");
  client.println("AJI1QC+CNUAAgjlAAII8QAGSNUAAkjlAAJI8QC+CPEAAgjlAAII1QAGSNUAAkjlAAJI8QC+CPEAA");
  client.println("gjlAAII1QAGSNUAAkjlAAJI8QC+CPEAAgjlAAII1QAGSPEAAkjlAAJI1QC+CNUAAgjlAAII8QAGS");
  client.println("PEAAkjlAAJI1QC+CNUAAgjlAAII8QAGSNUAAkjlAAJI8QC+CPEAAgjlAAII1QAGSNUAAkjlAAJI8");
  client.println("QC+CNUAAgjxAAII5QAGSNUAAkjlAAJI8QC+CPEAAgjlAAII1QAGSPEAAkjlAAJI1QC+CNUAAgjlA");
  client.println("AII8QAGSNUAAkjlAAJI8QC+CNUAAgjxAAII5QAGSPEAAkjlAAJI1QC+CNUAAgjlAAII8QAGSPEAA");
  client.println("kjlAAJI1QC+CPEAAgjVAAII5QAGSNUAAkjlAAJI8QC+CPEAAgjlAAII1QAGSNUAAkjlAAJI8QC+C");
  client.println("PEAAgjlAAII1QAGSLkAAkjJAAJI1QC+CNUAAgjJAAIIuQAGSNUAAkjJAAJIuQC+CLkAAgjJAAII1");
  client.println("QAGSNUAAkjJAAJIuQC+CLkAAgjJAAII1QAGSLkAAkjJAAJI1QC+CNUAAgjJAAIIuQAGSNUAAkjJA");
  client.println("AJIuQC+CLkAAgjJAAII1QAGSNUAAkjJAAJIuQC+CNUAAgi5AAIIyQAGSNUAAkjJAAJIuQC+CLkAA");
  client.println("gjJAAII1QAGSLkAAkjJAAJI1QC+CNUAAgjJAAIIuQAGSLkAAkjJAAJI1QC+CNUAAgjJAAIIuQAGS");
  client.println("LkAAkjJAAJI1QC+CNUAAgjJAAIIuQAGSNUAAkjJAAJIuQC+CLkAAgjJAAII1QAGSNUAAkjJAAJIu");
  client.println("QC+CLkAAgjJAAII1QAGSLkAAkjJAAJI1QC+CNUAAgjJAAIIuQAGSLkAAkjJAAJI1QC+CNUAAgjJA");
  client.println("AIIuQAGSLkAAkjJAAJI1QC+CNUAAgjJAAIIuQAGSLkAAkjJAAJI1QC+CNUAAgjJAAIIuQAGSN0AA");
  client.println("kjRAAJIwQC+CN0AAgjBAAII0QAGSMEAAkjRAAJI3QC+CN0AAgjRAAIIwQAGSN0AAkjRAAJIwQC+C");
  client.println("MEAAgjRAAII3QAGSN0AAkjRAAJIwQC+CMEAAgjRAAII3QAGSN0AAkjRAAJIwQC+CMEAAgjRAAII3");
  client.println("QAGSN0AAkjRAAJIwQC+CN0AAgjBAAII0QAGSN0AAkjRAAJIwQC+CMEAAgjRAAII3QAGSN0AAkjRA");
  client.println("AJIwQC+CMEAAgjRAAII3QAGSNEAAkjFAAJItQC+CLUAAgjFAAII0QAGSLUAAkjFAAJI0QC+CNEAA");
  client.println("gjFAAIItQAGSNEAAkjFAAJItQC+CLUAAgjFAAII0QAGSLUAAkjFAAJI0QC+CNEAAgjFAAIItQAGS");
  client.println("LUAAkjFAAJI0QC+CNEAAgjFAAIItQAGSNEAAkjFAAJItQC+CLUAAgjFAAII0QAGSLUAAkjFAAJI0");
  client.println("QC+CNEAAgjFAAIItQAGSLUAAkjFAAJI0QC+CNEAAgjFAAIItQAGSNUAAkjlAAJIyQC+CMkAAgjlA");
  client.println("AII1QAGSNUAAkjlAAJIyQC+CMkAAgjlAAII1QAGSNUAAkjlAAJIyQC+CNUAAgjJAAII5QAGSMkAA");
  client.println("kjlAAJI1QC+CMkAAgjVAAII5QAGSNUAAkjlAAJIyQC+CMkAAgjlAAII1QAGSNUAAkjlAAJIyQC+C");
  client.println("NUAAgjJAAII5QAGSMkAAkjlAAJI1QC+CNUAAgjlAAIIyQAGSMkAAkjlAAJI1QC+CNUAAgjlAAIIy");
  client.println("QAGSNUAAkjxAAJI5QC+COUAAgjxAAII1QAGSNUAAkjxAAJI5QC+COUAAgjxAAII1QAGSNUAAkjxA");
  client.println("AJI5QC+CNUAAgjlAAII8QAGSOUAAkjxAAJI1QC+COUAAgjVAAII8QAGSNUAAkjxAAJI5QC+COUAA");
  client.println("gjxAAII1QAGSOUAAkjxAAJI1QC+COUAAgjVAAII8QAGSNUAAkjxAAJI5QC+CNUAAgjlAAII8QAGS");
  client.println("OUAAkjxAAJI1QC+CNUAAgjxAAII5QAGSLkAAkjJAAJI1QC+CLkAAgjVAAIIyQAGSLkAAkjJAAJI1");
  client.println("QC+CNUAAgjJAAIIuQAGSNUAAkjJAAJIuQC+CNUAAgi5AAIIyQAGSLkAAkjJAAJI1QC+CLkAAgjVA");
  client.println("AIIyQAGSNUAAkjJAAJIuQC+CLkAAgjJAAII1QAGSLkAAkjJAAJI1QC+CLkAAgjVAAIIyQAGSNUAA");
  client.println("kjJAAJIuQC+CLkAAgjJAAII1QAGSNUAAkjJAAJIuQC+CLkAAgjJAAII1QAGSN0AAkjRAAJIwQC+C");
  client.println("MEAAgjRAAII3QAGSMEAAkjRAAJI3QC+CN0AAgjRAAIIwQAGSMEAAkjRAAJI3QC+CMEAAgjdAAII0");
  client.println("QAGSN0AAkjRAAJIwQC+CN0AAgjBAAII0QAGSMEAAkjRAAJI3QC+CN0AAgjRAAIIwQAGSN0AAkjRA");
  client.println("AJIwQC+CMEAAgjRAAII3QAGSMEAAkjRAAJI3QC+CN0AAgjRAAIIwQAGSMEAAkjRAAJI3QC+CN0AA");
  client.println("gjRAAIIwQAGSLUAAkjFAAJI0QC+CNEAAgjFAAIItQAGSLUAAkjFAAJI0QC+CNEAAgjFAAIItQAGS");
  client.println("LUAAkjFAAJI0QC+CNEAAgjFAAIItQAGSLUAAkjFAAJI0QC+CNEAAgjFAAIItQAGSNEAAkjFAAJIt");
  client.println("QC+CLUAAgjFAAII0QAGSNEAAkjFAAJItQC+CLUAAgjFAAII0QAGSNEAAkjFAAJItQC+CLUAAgjFA");
  client.println("AII0QAGSLUAAkjFAAJI0QC+CNEAAgjFAAIItQIYBsmUAALJkAACyBgwAsgpAALIHZADiAEAAwgEB");
  client.println("smUAALJkAACyBgwAsgpAALIHZADiAEAAwgEAsmUAALJkAACyBgwAsgpAALIHZADiAEAAwgEA/y8A");
  client.println("TVRyawAAARQA/wMLTUlESSBvdXQgIzMAsgpAALIHZADiAEAAsmUAALJkAACyBgwAsgpAALIHZADi");
  client.println("AEAAwhgAsmUAALJkAACyBgwAsgpAALIHZADiAEAAwhgAsmUAALJkAACyBgwAsgpAALIHZADiAEAA");
  client.println("whjLAJI+QC+CPkABkkFAL4JBQAGSRUAvgkVAAZJIQC+CSEABkj1AL4I9QAGSQEAvgkBAAZJFQC+C");
  client.println("RUABkkhAL4JIQAGSPkAvgj5AgRGSMkAvgjJAgRGyZQAAsmQAALIGDACyCkAAsgdkAOIAQADCGAGy");
  client.println("ZQAAsmQAALIGDACyCkAAsgdkAOIAQADCGACyZQAAsmQAALIGDACyCkAAsgdkAOIAQADCGAD/LwBN");
  client.println("VHJrAAAMhgD/AwhNSURJIE91dAC5CkAAuQdkAOkAQAC5ZQAAuWQAALkGDAC5CkAAuQdkAOkAQAC5");
  client.println("ZQAAuWQAALkGDAC5CkAAuQdkAOkAQAC5ZQAAuWQAALkGDAC5CkAAuQdkAOkAQACZJWUAmSVlL4kl");
  client.println("QACJJUABmSUxAJklMS+JJUAAiSVAAZklMQCZJTEviSVAAIklQAGZJWIAmSViL4klQACJJUABmSUu");
  client.println("AJklLi+JJUAAiSVAAZklMQCZJTEviSVAAIklQAGZJWQAmSVkMJklLBeJJUABmSUsF4klQACJJUAA");
  client.println("iSVAAZklZQCZJWUviSVAAIklQAGZJTEAmSUxL4klQACJJUABmSUxAJklMS+JJUAAiSVAAZklYgCZ");
  client.println("JWIviSVAAIklQAGZJS4AmSUuL4klQACJJUABmSUxAJklMS+JJUAAiSVAAZklZACZJWQwmSUyF4kl");
  client.println("QAGZJTIXiSVAAIklQACJJUABmSVlAJklZS+JJUAAiSVAAZklMQCZJTEviSVAAIklQAGZJTEAmSUx");
  client.println("L4klQACJJUABmSViAJklYi+JJUAAiSVAAZklLgCZJS4viSVAAIklQAGZJTEAmSUxL4klQACJJUAB");
  client.println("mSVkAJklZDCZJSwXiSVAAZklLBeJJUAAiSVAAIklQAGZJWUAmSVlL4klQACJJUABmSUxAJklMS+J");
  client.println("JUAAiSVAAZklMQCZJTEviSVAAIklQAGZJWIAmSViL4klQACJJUABmSYEAJklLgCZJS4XiSZAAZkm");
  client.println("EReJJUAAiSVAAIkmQAGZJh4AmSUxAJklMReJJkABmSYrF4klQACJJUAAiSZAAZkmOACZJWQAmSVk");
  client.println("F4kmQAGZJkUXiSZAAZkmUgCZJTIXiSVAAIkmQAGZJlwAmSUyF4klQACJJUAAiSVAAIkmQAGZJGQA");
  client.println("mSpkAJk3TwCZMU8XiSRAGIkxQACJN0AAiSpAAZkqOC+JKkABmSZkAJkqZBeJJkAYiSpAAZkqVACZ");
  client.println("JGQXiSRAGIkqQAGZKmQviSpAAZkkZACZKi8XiSRAGIkqQAGZKmQAmSZkF4kmQBiJKkABmSpVL4kq");
  client.println("QAGZKmQAmSRkF4kkQBiJKkABmSozL4kqQAGZJmQAmSpkF4kmQBiJKkABmSRkAJkqWReJJEAYiSpA");
  client.println("AZkqZC+JKkABmSoxAJkkZBeJJEAYiSpAAZkqZACZJmQXiSZAGIkqQAGZKk8viSpAAZkkZACZKmQX");
client.println("iSRAGIkqQAGZKjgviSpAAZkqZACZJmQXiSZAGIkqQAGZJGQAmSpUF4kkQBiJKkABmSpkL4kqQAGZ");
client.println("Ki8AmSRkF4kkQBiJKkABmSpkAJkmZBeJJkAYiSpAAZkqVS+JKkABmSpkAJkkZBeJJEAYiSpAAZkq");
client.println("My+JKkABmSZkAJkqZBeJJkAYiSpAAZkkZACZKlkXiSRAGIkqQAGZKmQviSpAAZkqMQCZJGQXiSRA");
client.println("GIkqQAGZKmQAmSZkF4kmQBiJKkABmSpPL4kqQAGZKmQAmSRkF4kkQBiJKkABmSo4L4kqQAGZJmQA");
client.println("mSpkF4kmQBiJKkABmSpUAJkkZBeJJEAYiSpAAZkqZC+JKkABmSovAJkkZBeJJEAYiSpAAZkmZACZ");
client.println("KmQXiSZAGIkqQAGZKlUviSpAAZkkZACZKmQXiSRAGIkqQAGZKjMviSpAAZkmZACZKmQXiSZAGIkq");
client.println("QAGZJGQAmSpZF4kkQBiJKkABmSpkL4kqQAGZKjEAmSRkF4kkQBiJKkABmSZkAJkqZBeJJkAYiSpA");
client.println("AZkqTy+JKkABmSRkAJkqZBeJJEAYiSpAAZkqOC+JKkABmSZkAJkqZBeJJkAYiSpAAZkkZACZKlQX");
client.println("iSRAGIkqQAGZKmQviSpAAZkkZACZKi8XiSRAGIkqQAGZKmQAmSZkF4kmQBiJKkABmSpVL4kqQAGZ");
client.println("JGQAmSpkF4kkQBiJKkABmSozL4kqQAGZKmQAmSZkF4kmQBiJKkABmSpZAJkkZBeJJEAYiSpAAZkm");
client.println("BACZKmQXiSZAAZkmEReJKkAAiSZAAZkmHgCZJGQAmSoxF4kkQACJJkABmSYrF4kqQACJJkABmSY4");
client.println("AJkmZACZKmQXiSZAAIkmQAGZJkUXiSpAAIkmQAGZJlIAmSpPF4kmQAGZJlwXiSpAAIkmQAGZN08A");
client.println("mTFPAJkkZACZKmQXiSRAGIkqQACJN0AAiTFAAZkqOC+JKkABmSpkAJkmZBeJJkAYiSpAAZkqVACZ");
client.println("JGQXiSRAGIkqQAGZKmQviSpAAZkkZACZKi8XiSRAGIkqQAGZKmQAmSZkF4kmQBiJKkABmSpVL4kq");
client.println("QAGZJGQAmSpkF4kkQBiJKkABmSozL4kqQAGZKmQAmSZkF4kmQBiJKkABmSpZAJkkZBeJJEAYiSpA");
client.println("AZkqZC+JKkABmSoxAJkkZBeJJEAYiSpAAZkmZACZKmQXiSZAGIkqQAGZKk8viSpAAZkqZACZJGQX");
client.println("iSRAGIkqQAGZKjgviSpAAZkmZACZKmQXiSZAGIkqQAGZKlQAmSRkF4kkQBiJKkABmSpkL4kqQAGZ");
client.println("JGQAmSovF4kkQBiJKkABmSpkAJkmZBeJJkAYiSpAAZkqVS+JKkABmSRkAJkqZBeJJEAYiSpAAZkq");
client.println("My+JKkABmSpkAJkmZBeJJkAYiSpAAZkkZACZKlkXiSRAGIkqQAGZKmQviSpAAZkqMQCZJGQXiSRA");
client.println("GIkqQAGZKmQAmSZkF4kmQBiJKkABmSpPL4kqQAGZJGQAmSpkF4kkQBiJKkABmSo4L4kqQAGZKmQA");
client.println("mSZkF4kmQBiJKkABmSRkAJkqVBeJJEAYiSpAAZkqZC+JKkABmSovAJkkZBeJJEAYiSpAAZkmZACZ");
client.println("KmQXiSZAGIkqQAGZKlUviSpAAZkkZACZKmQXiSRAGIkqQAGZKjMviSpAAZkqZACZJmQXiSZAGIkq");
client.println("QAGZJGQAmSpZF4kkQBiJKkABmSpkL4kqQAGZJGQAmSoxF4kkQBiJKkABmSZkAJkqZBeJJkAYiSpA");
client.println("AZkqTy+JKkABmSRkAJkqZBeJJEAYiSpAAZkqOC+JKkABmSpkAJkmZBeJJkAYiSpAAZkqVACZJGQX");
client.println("iSRAGIkqQAGZKmQviSpAAZkkZACZKi8XiSRAGIkqQAGZKmQAmSZkF4kmQBiJKkABmSpVL4kqQAGZ");
client.println("KmQAmSRkF4kkQBiJKkABmSozL4kqQAGZKmQAmSZkF4kmQBiJKkABmSpZAJkkZBeJJEAYiSpAAZkm");
client.println("BACZKmQXiSZAAZkmEReJKkAAiSZAAZkmHgCZKjEAmSRkF4kkQACJJkABmSYrF4kmQACJKkABmSY4");
client.println("AJkqZACZJmQXiSZAAIkmQAGZJkUXiSZAAIkqQAGZJlIAmSpPF4kmQAGZJlwXiSpAAIkmQAGZN08A");
client.println("mTFPAJkqZACZJGQXiSRAGIk3QACJKkAAiTFAAZkqOC+JKkABmSpkAJkmZBeJJkAYiSpAAZkkZACZ");
client.println("KlQXiSRAGIkqQAGZKmQviSpAAZkqLwCZJGQXiSRAGIkqQAGZJmQAmSpkF4kmQBiJKkABmSpVL4kq");
client.println("QAGZKmQAmSRkF4kkQBiJKkABmSozL4kqQAGZJmQAmSpkF4kmQBiJKkABmSRkAJkqWReJJEAYiSpA");
client.println("AZkqZC+JKkABmSRkAJkqMReJJEAYiSpAAZkmZACZKmQXiSZAGIkqQAGZKk8viSpAAZkqZACZJGQX");
client.println("iSRAGIkqQAGZKjgviSpAAZkqZACZJmQXiSZAGIkqQAGZJGQAmSpUF4kkQBiJKkABmSpkL4kqQAGZ");
client.println("Ki8AmSRkF4kkQBiJKkABmSpkAJkmZBeJJkAYiSpAAZkqVS+JKkABmSpkAJkkZBeJJEAYiSpAAZkq");
client.println("My+JKkABmSpkAJkmZBeJJkAYiSpAAZkkZACZKlkXiSRAGIkqQAGZKmQviSpAAZkkZACZKjEXiSRA");
client.println("GIkqQAGZKmQAmSZkF4kmQBiJKkABmSpPL4kqQAGZJGQAmSpkF4kkQBiJKkABmSo4L4kqQAGZKmQA");
client.println("mSZkF4kmQBiJKkABmSRkAJkqVBeJJEAYiSpAAZkmBACZKmQXiSZAAZkmEReJKkAAiSZAAZkmHgCZ");
client.println("JGQAmSovF4kkQACJJkABmSYrF4kqQACJJkABmSY4AJkmZACZKmQXiSZAAIkmQAGZJkUXiSpAAIkm");
client.println("QAGZJlIAmSpVF4kmQAGZJlwXiSpAAIkmQAGZN2QAmTFkAJkkZBeJJEAYiTdAAIkxQIQRmSRPL4kk");
client.println("QIERuWUAALlkAAC5BgwAuQpAALkHZADpAEABuWUAALlkAAC5BgwAuQpAALkHZADpAEAAuWUAALlk");
client.println("AAC5BgwAuQpAALkHZADpAEAA/y8A");
client.println("");
  delay(1);
}
    
